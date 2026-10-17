#!/usr/bin/env python3
"""Test actual EarPods decoder/reporting code without loading a kernel module."""
import argparse
import json
from pathlib import Path
import re
import subprocess
import tempfile

repo = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--source-root', type=Path, default=repo)
parser.add_argument('--layout', choices=('legacy', 'current', 'both'), default='both')
args = parser.parse_args()

def function(path, name):
    source = path.read_text()
    match = re.search(r'^(?:static )?(?:void|int) ' + name + r'\([^;]*?\)\n\{', source, re.M)
    if not match:
        raise ValueError(f'{name} definition missing in {path}')
    start, pos, depth = match.start(), match.end(), 1
    while depth:
        if source[pos] == '{':
            depth += 1
        if source[pos] == '}':
            depth -= 1
        pos += 1
    return source[start:pos] + '\n'

# These are unmasked handler inputs from three labeled physical presses each
# on MacBookPro14,1 / Ubuntu 6.8.0-134. Raw center 0x1100 becomes 0x100 after
# the existing interrupt mask. No kernel logs or host identifiers are needed.
recordings = json.loads((repo / 'tests/earpods-events.json').read_text())
layouts = ('legacy', 'current') if args.layout == 'both' else (args.layout,)
for layout in layouts:
    apple = args.source_root / 'patch_cirrus' / (
        'patch_cirrus_apple.h' if layout == 'legacy' else 'cirrus_apple.h')
    cleanup = 'cs_8409_apple_free' if layout == 'legacy' else 'cs_8409_apple_remove'
    with tempfile.TemporaryDirectory(prefix='earpods-tests-') as directory:
        scratch = Path(directory)
        code = ''.join(function(apple, name) for name in (
            'cs_8409_earpods_reset', 'cs_8409_earpods_jack_free',
            'cs_8409_earpods_create', 'cs_8409_apple_suspend', cleanup))
        if layout == 'current':
            code = '#define snd_hda_gen_remove snd_hda_gen_free\n' + code.replace(
                'cs_8409_apple_remove', 'cs_8409_apple_free')
        code += function(args.source_root / 'patch_cirrus/patch_cirrus_real84.h',
                         'cs_8409_headset_button_event')
        (scratch / 'driver_under_test.h').write_text(code)
        (scratch / 'recordings.h').write_text(''.join(
            'static const unsigned int ' + label + '[] = {' +
            ', '.join(hex(value) for value in values) + '};\n'
            for label, values in recordings.items()))
        binary = scratch / 'test-earpods'
        subprocess.run(['gcc', '-std=c11', '-Wall', '-Wextra', '-Werror', '-O2',
                        '-I' + str(scratch),
                        '-I' + str(args.source_root / 'patch_cirrus'),
                        str(repo / 'tests/test-earpods.c'), '-o', str(binary)], check=True)
        print(f'Layout: {layout}', flush=True)
        subprocess.run([str(binary)], check=True)
