
// new feature to do a sequence of coef read/writes
// (seems to be used a lot for cs8409)
// note that we ignore the return for gets for the moment!!
// ooh - new idea - save the logged return and check
static const struct hda_coef cs8409_init_coef1[] = {
        //{0, 0x01, idx, 0x00, retdata, 0}, read
        //{1, 0x01, idx, param, dmydata, 0}, write
        //{2, 0x01, idx, param, retdata, 0}, write mask
        //{ 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 0 }, // coef read 1370
        //{ 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 0 }, // coef write 1374
        //{ 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 0 }, // coef read 1378
        //{ 1, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 0 }, // coef write 1382
        //{ 1, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 0 }, // coef write 1386
        //{ 1, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 0 }, // coef write 1390
        //{ 1, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000000, 0 }, // coef write 1394

        { 1, CS8409_VENDOR_NID, 0x0019, 0x8000, 0x00000000, 0 }, // coef write 1398
        { 1, CS8409_VENDOR_NID, 0x001a, 0x8000, 0x00000000, 0 }, // coef write 1402
        { 1, CS8409_VENDOR_NID, 0x001b, 0x8000, 0x00000000, 0 }, // coef write 1406
        { 1, CS8409_VENDOR_NID, 0x001c, 0x8000, 0x00000000, 0 }, // coef write 1410
        { 1, CS8409_VENDOR_NID, 0x001d, 0x8000, 0x00000000, 0 }, // coef write 1414
        { 1, CS8409_VENDOR_NID, 0x001e, 0x8000, 0x00000000, 0 }, // coef write 1418
        { 1, CS8409_VENDOR_NID, 0x001f, 0x8000, 0x00000000, 0 }, // coef write 1422
        { 1, CS8409_VENDOR_NID, 0x0020, 0x8000, 0x00000000, 0 }, // coef write 1426
        { 1, CS8409_VENDOR_NID, 0x0021, 0x8000, 0x00000000, 0 }, // coef write 1430
        { 1, CS8409_VENDOR_NID, 0x0022, 0x8000, 0x00000000, 0 }, // coef write 1434
        { 1, CS8409_VENDOR_NID, 0x0023, 0x8000, 0x00000000, 0 }, // coef write 1438
        { 1, CS8409_VENDOR_NID, 0x0024, 0x8000, 0x00000000, 0 }, // coef write 1442
        { 1, CS8409_VENDOR_NID, 0x0025, 0x8000, 0x00000000, 0 }, // coef write 1446
        { 1, CS8409_VENDOR_NID, 0x0026, 0x8000, 0x00000000, 0 }, // coef write 1450
        { 1, CS8409_VENDOR_NID, 0x0027, 0x8000, 0x00000000, 0 }, // coef write 1454
        { 1, CS8409_VENDOR_NID, 0x0028, 0x8000, 0x00000000, 0 }, // coef write 1458
        { 1, CS8409_VENDOR_NID, 0x0029, 0x8000, 0x00000000, 0 }, // coef write 1462
        { 1, CS8409_VENDOR_NID, 0x002a, 0x8000, 0x00000000, 0 }, // coef write 1466
        { 1, CS8409_VENDOR_NID, 0x002b, 0x8000, 0x00000000, 0 }, // coef write 1470
        { 1, CS8409_VENDOR_NID, 0x002c, 0x8000, 0x00000000, 0 }, // coef write 1474
        { 1, CS8409_VENDOR_NID, 0x002d, 0x8000, 0x00000000, 0 }, // coef write 1478
        { 1, CS8409_VENDOR_NID, 0x002e, 0x8000, 0x00000000, 0 }, // coef write 1482
        { 1, CS8409_VENDOR_NID, 0x002f, 0x8000, 0x00000000, 0 }, // coef write 1486
        { 1, CS8409_VENDOR_NID, 0x0030, 0x8000, 0x00000000, 0 }, // coef write 1490
        { 1, CS8409_VENDOR_NID, 0x0031, 0x8000, 0x00000000, 0 }, // coef write 1494
        { 1, CS8409_VENDOR_NID, 0x0032, 0x8000, 0x00000000, 0 }, // coef write 1498
        { 1, CS8409_VENDOR_NID, 0x0033, 0x8000, 0x00000000, 0 }, // coef write 1502
        { 1, CS8409_VENDOR_NID, 0x0034, 0x8000, 0x00000000, 0 }, // coef write 1506
        { 1, CS8409_VENDOR_NID, 0x0035, 0x8000, 0x00000000, 0 }, // coef write 1510
        { 1, CS8409_VENDOR_NID, 0x0036, 0x8000, 0x00000000, 0 }, // coef write 1514
        { 1, CS8409_VENDOR_NID, 0x0037, 0x8000, 0x00000000, 0 }, // coef write 1518
        { 1, CS8409_VENDOR_NID, 0x0038, 0x8000, 0x00000000, 0 }, // coef write 1522
        { 1, CS8409_VENDOR_NID, 0x0039, 0x8000, 0x00000000, 0 }, // coef write 1526
        { 1, CS8409_VENDOR_NID, 0x003a, 0x8000, 0x00000000, 0 }, // coef write 1530
        { 1, CS8409_VENDOR_NID, 0x003b, 0x8000, 0x00000000, 0 }, // coef write 1534
        { 1, CS8409_VENDOR_NID, 0x003c, 0x8000, 0x00000000, 0 }, // coef write 1538
        { 1, CS8409_VENDOR_NID, 0x003d, 0x8000, 0x00000000, 0 }, // coef write 1542
        { 1, CS8409_VENDOR_NID, 0x003e, 0x8000, 0x00000000, 0 }, // coef write 1546
        { 1, CS8409_VENDOR_NID, 0x003f, 0x8000, 0x00000000, 0 }, // coef write 1550
        { 1, CS8409_VENDOR_NID, 0x0040, 0x8000, 0x00000000, 0 }, // coef write 1554
        { 1, CS8409_VENDOR_NID, 0x0041, 0x8000, 0x00000000, 0 }, // coef write 1558
        { 1, CS8409_VENDOR_NID, 0x0042, 0x8000, 0x00000000, 0 }, // coef write 1562
        { 1, CS8409_VENDOR_NID, 0x0043, 0x8000, 0x00000000, 0 }, // coef write 1566
        { 1, CS8409_VENDOR_NID, 0x0044, 0x8000, 0x00000000, 0 }, // coef write 1570
        { 1, CS8409_VENDOR_NID, 0x0045, 0x8000, 0x00000000, 0 }, // coef write 1574
        { 1, CS8409_VENDOR_NID, 0x0046, 0x8000, 0x00000000, 0 }, // coef write 1578
        { 1, CS8409_VENDOR_NID, 0x0047, 0x8000, 0x00000000, 0 }, // coef write 1582
        { 1, CS8409_VENDOR_NID, 0x0048, 0x8000, 0x00000000, 0 }, // coef write 1586
        { 1, CS8409_VENDOR_NID, 0x0049, 0x8000, 0x00000000, 0 }, // coef write 1590
        { 1, CS8409_VENDOR_NID, 0x004a, 0x8000, 0x00000000, 0 }, // coef write 1594
        { 1, CS8409_VENDOR_NID, 0x004b, 0x8000, 0x00000000, 0 }, // coef write 1598
        { 1, CS8409_VENDOR_NID, 0x004c, 0x8000, 0x00000000, 0 }, // coef write 1602
        { 1, CS8409_VENDOR_NID, 0x004d, 0x8000, 0x00000000, 0 }, // coef write 1606
        { 1, CS8409_VENDOR_NID, 0x004e, 0x8000, 0x00000000, 0 }, // coef write 1610
        { 1, CS8409_VENDOR_NID, 0x004f, 0x8000, 0x00000000, 0 }, // coef write 1614
        { 1, CS8409_VENDOR_NID, 0x0050, 0x8000, 0x00000000, 0 }, // coef write 1618
        { 1, CS8409_VENDOR_NID, 0x0051, 0x8000, 0x00000000, 0 }, // coef write 1622
        { 1, CS8409_VENDOR_NID, 0x0052, 0x8000, 0x00000000, 0 }, // coef write 1626
        { 1, CS8409_VENDOR_NID, 0x0053, 0x8000, 0x00000000, 0 }, // coef write 1630
        { 1, CS8409_VENDOR_NID, 0x0054, 0x8000, 0x00000000, 0 }, // coef write 1634
        { 1, CS8409_VENDOR_NID, 0x0055, 0x8000, 0x00000000, 0 }, // coef write 1638
        { 1, CS8409_VENDOR_NID, 0x0056, 0x8000, 0x00000000, 0 }, // coef write 1642
        { 1, CS8409_VENDOR_NID, 0x0057, 0x8000, 0x00000000, 0 }, // coef write 1646

        //{ 1, CS8409_VENDOR_NID, 0x000a, 0x0000, 0x00000000, 0 }, // coef write 1650
        //{ 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 0 }, // coef write 1654
        //{ 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 0 }, // coef write 1658
        //{ 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 }, // coef write 1662
        //{ 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 0 }, // coef write 1666
};

static const struct hda_coef cs8409_init_coef2[] = {
        { 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 0 }, //   coef read 9193
        { 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 0 }, //   coef read 9197
        { 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 0 }, //   coef read 9201
        { 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 0 }, //   coef read 9205
        { 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008000, 0 }, //   coef read 9209
        { 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 0 }, //   coef read 9213
        { 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008000, 0 }, //   coef read 9217
        { 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 0 }, //   coef read 9221
        { 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 0 }, //   coef read 9225
        { 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 0 }, //   coef read 9229
        { 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 0 }, //   coef read 9233
        { 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 0 }, //   coef read 9237
        { 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 0 }, //   coef read 9241
        { 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 0 }, //   coef read 9245
        { 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 0 }, //   coef read 9249
        { 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 0 }, //   coef read 9253
        { 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 0 }, //   coef read 9257
        { 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 0 }, //   coef read 9261
        { 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 0 }, //   coef read 9265
        { 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 0 }, //   coef read 9269
        { 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 0 }, //   coef read 9273
        { 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 0 }, //   coef read 9277
        { 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 0 }, //   coef read 9281
        { 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 0 }, //   coef read 9285
        { 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 0 }, //   coef read 9289
        { 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 0 }, //   coef read 9293
        { 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 0 }, //   coef read 9297
        { 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 0 }, //   coef read 9301
        { 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 0 }, //   coef read 9305
        { 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 0 }, //   coef read 9309
        { 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 0 }, //   coef read 9313
        { 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 0 }, //   coef read 9317
        { 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 0 }, //   coef read 9321
        { 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 0 }, //   coef read 9325
        { 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 0 }, //   coef read 9329
        { 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 0 }, //   coef read 9333
        { 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 0 }, //   coef read 9337
        { 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 0 }, //   coef read 9341
        { 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 0 }, //   coef read 9345
        { 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 0 }, //   coef read 9349
        { 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 0 }, //   coef read 9353
        { 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 0 }, //   coef read 9357
        { 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 0 }, //   coef read 9361
        { 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 0 }, //   coef read 9365
        { 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 0 }, //   coef read 9369
        { 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 0 }, //   coef read 9373
        { 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 0 }, //   coef read 9377
        { 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 0 }, //   coef read 9381
        { 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 0 }, //   coef read 9385
        { 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 0 }, //   coef read 9389
        { 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 0 }, //   coef read 9393
        { 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 0 }, //   coef read 9397
        { 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 0 }, //   coef read 9401
        { 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 0 }, //   coef read 9405
        { 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 0 }, //   coef read 9409
        { 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 0 }, //   coef read 9413
        { 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 0 }, //   coef read 9417
        { 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 0 }, //   coef read 9421
        { 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 0 }, //   coef read 9425
        { 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 0 }, //   coef read 9429
        { 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 0 }, //   coef read 9433
        { 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 0 }, //   coef read 9437
        { 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 0 }, //   coef read 9441
};


static void gpio_set4(struct hda_codec *codec)
{
	int retval;
	dev_info(hda_codec_dev(codec), "start gpio_set4\n");
	snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x4);
        retval = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0);
	dev_info(hda_codec_dev(codec), "gpio_data 0x%x\n",retval);
	dev_info(hda_codec_dev(codec), "end   gpio_set4\n");
}

static void read_coefs_all(struct hda_codec *codec)
{

        // leave these in as check of state

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 804 ); //   coef read 804
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 808 ); //   coef read 808
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000080, 812 ); //   coef read 812
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0003, 0x0000, 0x0000801f, 816 ); //   coef read 816
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x0000083f, 820 ); //   coef read 820
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0005, 0x0000, 0x00000000, 824 ); //   coef read 824
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0006, 0x0000, 0x00008000, 828 ); //   coef read 828
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0007, 0x0000, 0x000028ff, 832 ); //   coef read 832
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0008, 0x0000, 0x00000000, 836 ); //   coef read 836
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x00000013, 840 ); //   coef read 840
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000a, 0x0000, 0x00000000, 844 ); //   coef read 844
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000b, 0x0000, 0x00000000, 848 ); //   coef read 848
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000c, 0x0000, 0x0000cccc, 852 ); //   coef read 852
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000d, 0x0000, 0x0000cccc, 856 ); //   coef read 856
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000e, 0x0000, 0x00000000, 860 ); //   coef read 860
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000f, 0x0000, 0x0000aaaa, 864 ); //   coef read 864
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0010, 0x0000, 0x0000cccc, 868 ); //   coef read 868
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0011, 0x0000, 0x00000000, 872 ); //   coef read 872
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0012, 0x0000, 0x0000cccc, 876 ); //   coef read 876
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0013, 0x0000, 0x0000cccc, 880 ); //   coef read 880
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0014, 0x0000, 0x00000000, 884 ); //   coef read 884
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0015, 0x0000, 0x0000aaaa, 888 ); //   coef read 888
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0016, 0x0000, 0x0000cccc, 892 ); //   coef read 892
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 896 ); //   coef read 896
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 900 ); //   coef read 900
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000400, 904 ); //   coef read 904
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000420, 908 ); //   coef read 908
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008c20, 912 ); //   coef read 912
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008000, 916 ); //   coef read 916
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008c40, 920 ); //   coef read 920
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 924 ); //   coef read 924
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008c60, 928 ); //   coef read 928
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 932 ); //   coef read 932
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 936 ); //   coef read 936
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 940 ); //   coef read 940
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 944 ); //   coef read 944
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 948 ); //   coef read 948
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 952 ); //   coef read 952
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 956 ); //   coef read 956
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 960 ); //   coef read 960
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 964 ); //   coef read 964
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 968 ); //   coef read 968
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 972 ); //   coef read 972
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 976 ); //   coef read 976
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 980 ); //   coef read 980
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 984 ); //   coef read 984
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 988 ); //   coef read 988
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 992 ); //   coef read 992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 996 ); //   coef read 996
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 1000 ); //   coef read 1000
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 1004 ); //   coef read 1004
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 1008 ); //   coef read 1008
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 1012 ); //   coef read 1012
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 1016 ); //   coef read 1016
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 1020 ); //   coef read 1020
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 1024 ); //   coef read 1024
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 1028 ); //   coef read 1028
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 1032 ); //   coef read 1032
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 1036 ); //   coef read 1036
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 1040 ); //   coef read 1040
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 1044 ); //   coef read 1044
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 1048 ); //   coef read 1048
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 1052 ); //   coef read 1052
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 1056 ); //   coef read 1056
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 1060 ); //   coef read 1060
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 1064 ); //   coef read 1064
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 1068 ); //   coef read 1068
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 1072 ); //   coef read 1072
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 1076 ); //   coef read 1076
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 1080 ); //   coef read 1080
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 1084 ); //   coef read 1084
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 1088 ); //   coef read 1088
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 1092 ); //   coef read 1092
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 1096 ); //   coef read 1096
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 1100 ); //   coef read 1100
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 1104 ); //   coef read 1104
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 1108 ); //   coef read 1108
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 1112 ); //   coef read 1112
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 1116 ); //   coef read 1116
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 1120 ); //   coef read 1120
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 1124 ); //   coef read 1124
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 1128 ); //   coef read 1128
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 1132 ); //   coef read 1132
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 1136 ); //   coef read 1136
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 1140 ); //   coef read 1140
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 1144 ); //   coef read 1144
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 1148 ); //   coef read 1148
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 1152 ); //   coef read 1152
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0058, 0x0000, 0x00000400, 1156 ); //   coef read 1156
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0059, 0x0000, 0x00000074, 1160 ); //   coef read 1160
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005a, 0x0000, 0x0000007f, 1164 ); //   coef read 1164
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005b, 0x0000, 0x00000010, 1168 ); //   coef read 1168
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000020, 1172 ); //   coef read 1172
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005d, 0x0000, 0x00002d7f, 1176 ); //   coef read 1176
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00002d7f, 1180 ); //   coef read 1180
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005f, 0x0000, 0x00001600, 1184 ); //   coef read 1184
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0060, 0x0000, 0x00000000, 1188 ); //   coef read 1188
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0061, 0x0000, 0x00000000, 1192 ); //   coef read 1192
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0062, 0x0000, 0x00000000, 1196 ); //   coef read 1196
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0063, 0x0000, 0x00000000, 1200 ); //   coef read 1200
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0064, 0x0000, 0x00000000, 1204 ); //   coef read 1204
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0065, 0x0000, 0x00000000, 1208 ); //   coef read 1208
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0066, 0x0000, 0x00000000, 1212 ); //   coef read 1212
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0067, 0x0000, 0x00000000, 1216 ); //   coef read 1216
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0068, 0x0000, 0x00000000, 1220 ); //   coef read 1220
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0069, 0x0000, 0x00000000, 1224 ); //   coef read 1224
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006a, 0x0000, 0x00000000, 1228 ); //   coef read 1228
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006b, 0x0000, 0x00000200, 1232 ); //   coef read 1232
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006c, 0x0000, 0x00000000, 1236 ); //   coef read 1236
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006d, 0x0000, 0x00000000, 1240 ); //   coef read 1240
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006e, 0x0000, 0x00000000, 1244 ); //   coef read 1244
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006f, 0x0000, 0x00000000, 1248 ); //   coef read 1248
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0070, 0x0000, 0x00000000, 1252 ); //   coef read 1252
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 1256 ); //   coef read 1256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0072, 0x0000, 0x00000000, 1260 ); //   coef read 1260
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0073, 0x0000, 0x00000000, 1264 ); //   coef read 1264
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0074, 0x0000, 0x0000000a, 1268 ); //   coef read 1268
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0075, 0x0000, 0x00000001, 1272 ); //   coef read 1272
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0076, 0x0000, 0x00000009, 1276 ); //   coef read 1276
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0077, 0x0000, 0x00000000, 1280 ); //   coef read 1280
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0078, 0x0000, 0x00000000, 1284 ); //   coef read 1284
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0079, 0x0000, 0x00000000, 1288 ); //   coef read 1288
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007a, 0x0000, 0x00000000, 1292 ); //   coef read 1292
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007b, 0x0000, 0x00000000, 1296 ); //   coef read 1296
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007c, 0x0000, 0x00000000, 1300 ); //   coef read 1300
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007d, 0x0000, 0x00000000, 1304 ); //   coef read 1304
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007e, 0x0000, 0x00000000, 1308 ); //   coef read 1308
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007f, 0x0000, 0x00000000, 1312 ); //   coef read 1312
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0080, 0x0000, 0x00000000, 1316 ); //   coef read 1316
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0081, 0x0000, 0x00000000, 1320 ); //   coef read 1320
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x0000ff00, 1324 ); //   coef read 1324

}

static void init_read_all_nodes(struct hda_codec *codec);
static void setup_beep(struct hda_codec *codec);
static void read_vendor_node(struct hda_codec *codec);

static void setup_node_alpha_reset_and_clear(struct hda_codec *codec)
{

	// so now really dont know whay I skipped all this - maybe because they
	// almost entirely reads??
	// - except it does clear all the pin configs
	// plus does a DBL init

        int retval;


        dev_info(hda_codec_dev(codec), "command nid start setup_node_alpha_reset_and_clear\n");


        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1);
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 2);
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 3);
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 4);
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00010001, 5);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00020046, 6);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000101, 7);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_SUBSYSTEM_ID, 0x00000000, 0x106b3900, 8);
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 9);
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 10);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000f, 0xe0000019, 11);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_DBL_CODEC_RESET, 0x00000000);
        snd_hda_double_reset(codec);

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 13);
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 14);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000101, 15);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000f, 0xe0000019, 16);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001a017f, 17);
//      snd_hda:     pcm params           1 bits: 16bit 24bit 32bit rates: 8kHz 11.025kHz 16kHz 22.05kHz 32kHz 44.1kHz 48kHz 96kHz
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 18);
//      snd_hda:     stream format params 1 pcm
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 19);
//      snd_hda:     amp capabilities 1 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 20);
//      snd_hda:     amp capabilities 1 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_SUBSYSTEM_ID, 0x00000000, 0x106b3900, 22);
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000008, 0x00010000, 23);

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DIRECTION, 0x00000000, 0x00000000, 24);
//      snd_hda:     gpio direction 1 0x00 in in in in in in in in
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000011, 0xc0000008, 25);
//      snd_hda:     gpio params 1 [('GPIO', 8), ('GPIO_WAKE', 1), ('GPO', 0), ('GPI', 0), ('GPIO_UNSOL', 1)]

        // get node count
        // note that there are 4 so called HiddenFeatureWidgets which are indexed after the 0x46 count from
        // the vendor node at 0x47
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00020046, 26);

        // read parameters from all nodes - excluding HiddenFeatureWidgets

        init_read_all_nodes(codec);

        setup_beep(codec);

        read_vendor_node(codec);

        // leave these in as check of state
        // now moved to separate function read_hidden_feature_widgets

        dev_info(hda_codec_dev(codec), "command nid end setup_node_alpha_reset_and_clear\n");

}

static void init_read_all_nodes(struct hda_codec *codec)
{
        int retval;

        // so apple reads parameters from all nodes
        // but setting pin nodes SET_PIN_WIDGET_CONTROL to 0

        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 27);
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 28);
//      snd_hda:     2 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 29);
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 30);
//      snd_hda:     pcm params           2 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 31);
//      snd_hda:     stream format params 2 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 32);
//      snd_hda:     amp capabilities 2 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 33);
//      snd_hda:     amp capabilities 2 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 34);
//      snd_hda:     2 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 36);
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 37);
//      snd_hda:     3 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 38);
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 39);
//      snd_hda:     pcm params           3 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 40);
//      snd_hda:     stream format params 3 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 41);
//      snd_hda:     amp capabilities 3 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 42);
//      snd_hda:     amp capabilities 3 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 43);
//      snd_hda:     3 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 45);
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 46);
//      snd_hda:     4 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 47);
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 48);
//      snd_hda:     pcm params           4 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 49);
//      snd_hda:     stream format params 4 
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 50);
//      snd_hda:     amp capabilities 4 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 51);
//      snd_hda:     amp capabilities 4 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 52);
//      snd_hda:     4 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 54);
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 55);
//      snd_hda:     5 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 56);
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 57);
//      snd_hda:     pcm params           5 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 58);
//      snd_hda:     stream format params 5 
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 59);
//      snd_hda:     amp capabilities 5 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 60);
//      snd_hda:     amp capabilities 5 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 61);
//      snd_hda:     5 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 63);
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 64);
//      snd_hda:     6 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 65);
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 66);
//      snd_hda:     pcm params           6 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 67);
//      snd_hda:     stream format params 6 
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 68);
//      snd_hda:     amp capabilities 6 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 69);
//      snd_hda:     amp capabilities 6 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 70);
//      snd_hda:     6 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 72);
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 73);
//      snd_hda:     7 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 74);
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 75);
//      snd_hda:     pcm params           7 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 76);
//      snd_hda:     stream format params 7 
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 77);
//      snd_hda:     amp capabilities 7 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 78);
//      snd_hda:     amp capabilities 7 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 79);
//      snd_hda:     7 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 81);
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 82);
//      snd_hda:     8 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 83);
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 84);
//      snd_hda:     pcm params           8 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 85);
//      snd_hda:     stream format params 8 
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 86);
//      snd_hda:     amp capabilities 8 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 87);
//      snd_hda:     amp capabilities 8 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 88);
//      snd_hda:     8 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 90);
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 91);
//      snd_hda:     9 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 92);
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 93);
//      snd_hda:     pcm params           9 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 94);
//      snd_hda:     stream format params 9 
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 95);
//      snd_hda:     amp capabilities 9 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 96);
//      snd_hda:     amp capabilities 9 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 97);
//      snd_hda:     9 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 99);
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 100);
//      snd_hda:     10 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 101);
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 102);
//      snd_hda:     pcm params           10 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 103);
//      snd_hda:     stream format params 10 
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 104);
//      snd_hda:     amp capabilities 10 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 105);
//      snd_hda:     amp capabilities 10 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 106);
//      snd_hda:     10 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 108);
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 109);
//      snd_hda:     11 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 110);
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 111);
//      snd_hda:     pcm params           11 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 112);
//      snd_hda:     stream format params 11 
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 113);
//      snd_hda:     amp capabilities 11 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 114);
//      snd_hda:     amp capabilities 11 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 115);
//      snd_hda:     11 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 117);
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 118);
//      snd_hda:     12 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 119);
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 120);
//      snd_hda:     pcm params           12 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 121);
//      snd_hda:     stream format params 12 
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 122);
//      snd_hda:     amp capabilities 12 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 123);
//      snd_hda:     amp capabilities 12 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 124);
//      snd_hda:     12 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 126);
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 127);
//      snd_hda:     13 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 128);
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 129);
//      snd_hda:     pcm params           13 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 130);
//      snd_hda:     stream format params 13 
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 131);
//      snd_hda:     amp capabilities 13 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 132);
//      snd_hda:     amp capabilities 13 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 133);
//      snd_hda:     13 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 135);
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 136);
//      snd_hda:     14 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 137);
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 138);
//      snd_hda:     pcm params           14 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 139);
//      snd_hda:     stream format params 14 
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 140);
//      snd_hda:     amp capabilities 14 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 141);
//      snd_hda:     amp capabilities 14 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 142);
//      snd_hda:     14 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 144);
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 145);
//      snd_hda:     15 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 146);
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 147);
//      snd_hda:     pcm params           15 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 148);
//      snd_hda:     stream format params 15 
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 149);
//      snd_hda:     amp capabilities 15 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 150);
//      snd_hda:     amp capabilities 15 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 151);
//      snd_hda:     15 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 153);
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 154);
//      snd_hda:     16 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 155);
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 156);
//      snd_hda:     pcm params           16 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 157);
//      snd_hda:     stream format params 16 
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 158);
//      snd_hda:     amp capabilities 16 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 159);
//      snd_hda:     amp capabilities 16 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 160);
//      snd_hda:     16 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 162);
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 163);
//      snd_hda:     17 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 164);
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 165);
//      snd_hda:     pcm params           17 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 166);
//      snd_hda:     stream format params 17 
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 167);
//      snd_hda:     amp capabilities 17 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 168);
//      snd_hda:     amp capabilities 17 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 169);
//      snd_hda:     17 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 171);
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 172);
//      snd_hda:     18 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 173);
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 174);
//      snd_hda:     pcm params           18 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 175);
//      snd_hda:     stream format params 18 
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 176);
//      snd_hda:     amp capabilities 18 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 177);
//      snd_hda:     amp capabilities 18 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 178);
//      snd_hda:     18 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 179);
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000034, 180);
//      snd_hda:     connection list 18 <- 52
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 182);
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 183);
//      snd_hda:     19 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 184);
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 185);
//      snd_hda:     pcm params           19 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 186);
//      snd_hda:     stream format params 19 
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 187);
//      snd_hda:     amp capabilities 19 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 188);
//      snd_hda:     amp capabilities 19 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 189);
//      snd_hda:     19 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 190);
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000035, 191);
//      snd_hda:     connection list 19 <- 53
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 193);
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 194);
//      snd_hda:     20 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 195);
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 196);
//      snd_hda:     pcm params           20 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 197);
//      snd_hda:     stream format params 20 
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 198);
//      snd_hda:     amp capabilities 20 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 199);
//      snd_hda:     amp capabilities 20 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 200);
//      snd_hda:     20 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 201);
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000036, 202);
//      snd_hda:     connection list 20 <- 54
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 204);
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 205);
//      snd_hda:     21 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 206);
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 207);
//      snd_hda:     pcm params           21 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 208);
//      snd_hda:     stream format params 21 
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 209);
//      snd_hda:     amp capabilities 21 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 210);
//      snd_hda:     amp capabilities 21 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 211);
//      snd_hda:     21 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 212);
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000037, 213);
//      snd_hda:     connection list 21 <- 55
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 215);
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 216);
//      snd_hda:     22 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 217);
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 218);
//      snd_hda:     pcm params           22 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 219);
//      snd_hda:     stream format params 22 
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 220);
//      snd_hda:     amp capabilities 22 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 221);
//      snd_hda:     amp capabilities 22 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 222);
//      snd_hda:     22 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 223);
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000038, 224);
//      snd_hda:     connection list 22 <- 56
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 226);
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 227);
//      snd_hda:     23 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 228);
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 229);
//      snd_hda:     pcm params           23 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 230);
//      snd_hda:     stream format params 23 
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 231);
//      snd_hda:     amp capabilities 23 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 232);
//      snd_hda:     amp capabilities 23 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 233);
//      snd_hda:     23 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 234);
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000039, 235);
//      snd_hda:     connection list 23 <- 57
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 237);
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 238);
//      snd_hda:     24 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 239);
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 240);
//      snd_hda:     pcm params           24 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 241);
//      snd_hda:     stream format params 24 
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 242);
//      snd_hda:     amp capabilities 24 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 243);
//      snd_hda:     amp capabilities 24 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 244);
//      snd_hda:     24 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 245);
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003a, 246);
//      snd_hda:     connection list 24 <- 58
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 248);
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 249);
//      snd_hda:     25 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 250);
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 251);
//      snd_hda:     pcm params           25 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 252);
//      snd_hda:     stream format params 25 
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 253);
//      snd_hda:     amp capabilities 25 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 254);
//      snd_hda:     amp capabilities 25 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 255);
//      snd_hda:     25 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 256);
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003b, 257);
//      snd_hda:     connection list 25 <- 59
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 259);
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 260);
//      snd_hda:     26 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 261);
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 262);
//      snd_hda:     pcm params           26 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 263);
//      snd_hda:     stream format params 26 
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 264);
//      snd_hda:     amp capabilities 26 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 265);
//      snd_hda:     amp capabilities 26 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 266);
//      snd_hda:     26 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 267);
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003c, 268);
//      snd_hda:     connection list 26 <- 60
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 270);
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 271);
//      snd_hda:     27 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 272);
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 273);
//      snd_hda:     pcm params           27 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 274);
//      snd_hda:     stream format params 27 
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 275);
//      snd_hda:     amp capabilities 27 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 276);
//      snd_hda:     amp capabilities 27 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 277);
//      snd_hda:     27 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 278);
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003d, 279);
//      snd_hda:     connection list 27 <- 61
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 281);
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 282);
//      snd_hda:     28 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 283);
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 284);
//      snd_hda:     pcm params           28 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 285);
//      snd_hda:     stream format params 28 
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 286);
//      snd_hda:     amp capabilities 28 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 287);
//      snd_hda:     amp capabilities 28 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 288);
//      snd_hda:     28 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 289);
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003e, 290);
//      snd_hda:     connection list 28 <- 62
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 292);
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 293);
//      snd_hda:     29 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 294);
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 295);
//      snd_hda:     pcm params           29 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 296);
//      snd_hda:     stream format params 29 
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 297);
//      snd_hda:     amp capabilities 29 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 298);
//      snd_hda:     amp capabilities 29 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 299);
//      snd_hda:     29 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 300);
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003f, 301);
//      snd_hda:     connection list 29 <- 63
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 303);
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 304);
//      snd_hda:     30 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 305);
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 306);
//      snd_hda:     pcm params           30 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 307);
//      snd_hda:     stream format params 30 
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 308);
//      snd_hda:     amp capabilities 30 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 309);
//      snd_hda:     amp capabilities 30 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 310);
//      snd_hda:     30 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 311);
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000040, 312);
//      snd_hda:     connection list 30 <- 64
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 314);
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 315);
//      snd_hda:     31 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 316);
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 317);
//      snd_hda:     pcm params           31 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 318);
//      snd_hda:     stream format params 31 
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 319);
//      snd_hda:     amp capabilities 31 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 320);
//      snd_hda:     amp capabilities 31 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 321);
//      snd_hda:     31 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 322);
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000041, 323);
//      snd_hda:     connection list 31 <- 65
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 325);
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 326);
//      snd_hda:     32 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 327);
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 328);
//      snd_hda:     pcm params           32 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 329);
//      snd_hda:     stream format params 32 
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 330);
//      snd_hda:     amp capabilities 32 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 331);
//      snd_hda:     amp capabilities 32 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 332);
//      snd_hda:     32 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 333);
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000042, 334);
//      snd_hda:     connection list 32 <- 66
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 336);
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 337);
//      snd_hda:     33 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 338);
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 339);
//      snd_hda:     pcm params           33 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 340);
//      snd_hda:     stream format params 33 
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 341);
//      snd_hda:     amp capabilities 33 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 342);
//      snd_hda:     amp capabilities 33 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 343);
//      snd_hda:     33 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 344);
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000043, 345);
//      snd_hda:     connection list 33 <- 67
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 347);
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 348);
//      snd_hda:     34 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 349);
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 350);
//      snd_hda:     pcm params           34 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 351);
//      snd_hda:     stream format params 34 pcm
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 352);
//      snd_hda:     amp capabilities 34 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 353);
//      snd_hda:     amp capabilities 34 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 354);
//      snd_hda:     34 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 356);
//      snd_hda:     pcm params           34 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 357);
//      snd_hda:     stream format params 34 pcm
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 358);
//      snd_hda:     amp capabilities 34 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 359);
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000044, 360);
//      snd_hda:     connection list 34 <- 68
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 361);

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 364);
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 365);
//      snd_hda:     35 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 366);
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 367);
//      snd_hda:     pcm params           35 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 368);
//      snd_hda:     stream format params 35 pcm
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 369);
//      snd_hda:     amp capabilities 35 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 370);
//      snd_hda:     amp capabilities 35 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 371);
//      snd_hda:     35 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 373);
//      snd_hda:     pcm params           35 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 374);
//      snd_hda:     stream format params 35 pcm
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 375);
//      snd_hda:     amp capabilities 35 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 376);
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000045, 377);
//      snd_hda:     connection list 35 <- 69
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 378);

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 381);
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 382);
//      snd_hda:     36 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 383);
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 384);
//      snd_hda:     amp capabilities 36 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 385);
//      snd_hda:     amp capabilities 36 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 386);
//      snd_hda:     36 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x90100110, 387);
//      snd_hda:     pin config default 0x90100110 port conn 2 location 0x10 loc ext 1 loc geom 0 default device 1 conn type 0 color 0 misc 1 def assoc 1 seq 0
//      snd_hda:     pin config default 0x90100110 port conn Fixed loc ext Int loc geom N/A default device Speaker conn type Unknown color Unknown misc Jack Detect Override def assoc 1 seq 0
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 388);
//      snd_hda:     36 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 389);
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000002, 390);
//      snd_hda:     connection list 36 <- 2
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 391);

        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     36 []

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 394);
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 395);
//      snd_hda:     37 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 396);
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 397);
//      snd_hda:     amp capabilities 37 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 398);
//      snd_hda:     amp capabilities 37 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 399);
//      snd_hda:     37 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x90100111, 400);
//      snd_hda:     pin config default 0x90100111 port conn 2 location 0x10 loc ext 1 loc geom 0 default device 1 conn type 0 color 0 misc 1 def assoc 1 seq 1
//      snd_hda:     pin config default 0x90100111 port conn Fixed loc ext Int loc geom N/A default device Speaker conn type Unknown color Unknown misc Jack Detect Override def assoc 1 seq 1
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 401);
//      snd_hda:     37 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 402);
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000003, 403);
//      snd_hda:     connection list 37 <- 3
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 404);

        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     37 []

        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 407);
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 408);
//      snd_hda:     38 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 409);
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 410);
//      snd_hda:     amp capabilities 38 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 411);
//      snd_hda:     amp capabilities 38 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 412);
//      snd_hda:     38 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 413);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 414);
//      snd_hda:     38 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 415);
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000004, 416);
//      snd_hda:     connection list 38 <- 4
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 417);

        snd_hda_codec_write(codec, 0x26, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     38 []

        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 420);
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 421);
//      snd_hda:     39 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 422);
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 423);
//      snd_hda:     amp capabilities 39 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 424);
//      snd_hda:     amp capabilities 39 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 425);
//      snd_hda:     39 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 426);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 427);
//      snd_hda:     39 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 428);
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000005, 429);
//      snd_hda:     connection list 39 <- 5
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 430);

        snd_hda_codec_write(codec, 0x27, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     39 []

        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 433);
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 434);
//      snd_hda:     40 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 435);
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 436);
//      snd_hda:     amp capabilities 40 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 437);
//      snd_hda:     amp capabilities 40 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 438);
//      snd_hda:     40 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 439);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 440);
//      snd_hda:     40 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 441);
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000006, 442);
//      snd_hda:     connection list 40 <- 6
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 443);

        snd_hda_codec_write(codec, 0x28, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     40 []

        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 446);
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 447);
//      snd_hda:     41 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 448);
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 449);
//      snd_hda:     amp capabilities 41 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 450);
//      snd_hda:     amp capabilities 41 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 451);
//      snd_hda:     41 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 452);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 453);
//      snd_hda:     41 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 454);
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000007, 455);
//      snd_hda:     connection list 41 <- 7
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 456);

        snd_hda_codec_write(codec, 0x29, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     41 []

        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 459);
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 460);
//      snd_hda:     42 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 461);
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 462);
//      snd_hda:     amp capabilities 42 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 463);
//      snd_hda:     amp capabilities 42 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 464);
//      snd_hda:     42 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 465);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 466);
//      snd_hda:     42 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 467);
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000008, 468);
//      snd_hda:     connection list 42 <- 8
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 469);

        snd_hda_codec_write(codec, 0x2a, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     42 []

        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 472);
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 473);
//      snd_hda:     43 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 474);
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 475);
//      snd_hda:     amp capabilities 43 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 476);
//      snd_hda:     amp capabilities 43 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 477);
//      snd_hda:     43 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 478);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 479);
//      snd_hda:     43 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 480);
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000009, 481);
//      snd_hda:     connection list 43 <- 9
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 482);

        snd_hda_codec_write(codec, 0x2b, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     43 []

        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 485);
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 486);
//      snd_hda:     44 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 487);
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 488);
//      snd_hda:     amp capabilities 44 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 489);
//      snd_hda:     amp capabilities 44 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 490);
//      snd_hda:     44 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x002b4020, 491);
//      snd_hda:     pin config default 0x002b4020 port conn 0 location 0x0 loc ext 0 loc geom 0 default device 2 conn type 11 color 4 misc 0 def assoc 2 seq 0
//      snd_hda:     pin config default 0x002b4020 port conn Jack loc ext Ext loc geom N/A default device HP Out conn type Combination color Green misc undef def assoc 2 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 492);
//      snd_hda:     44 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 493);
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000a, 494);
//      snd_hda:     connection list 44 <- 10
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 495);

        snd_hda_codec_write(codec, 0x2c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     44 []

        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 498);
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 499);
//      snd_hda:     45 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 500);
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 501);
//      snd_hda:     amp capabilities 45 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 502);
//      snd_hda:     amp capabilities 45 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 503);
//      snd_hda:     45 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 504);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 505);
//      snd_hda:     45 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 506);
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000b, 507);
//      snd_hda:     connection list 45 <- 11
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 508);

        snd_hda_codec_write(codec, 0x2d, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     45 []

        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 511);
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 512);
//      snd_hda:     46 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 513);
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 514);
//      snd_hda:     amp capabilities 46 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 515);
//      snd_hda:     amp capabilities 46 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 516);
//      snd_hda:     46 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 517);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 518);
//      snd_hda:     46 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 519);
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000c, 520);
//      snd_hda:     connection list 46 <- 12
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 521);

        snd_hda_codec_write(codec, 0x2e, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     46 []

        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 524);
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 525);
//      snd_hda:     47 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 526);
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 527);
//      snd_hda:     amp capabilities 47 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 528);
//      snd_hda:     amp capabilities 47 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 529);
//      snd_hda:     47 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 530);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 531);
//      snd_hda:     47 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 532);
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000d, 533);
//      snd_hda:     connection list 47 <- 13
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 534);

        snd_hda_codec_write(codec, 0x2f, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     47 []

        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 537);
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 538);
//      snd_hda:     48 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 539);
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 540);
//      snd_hda:     amp capabilities 48 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 541);
//      snd_hda:     amp capabilities 48 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 542);
//      snd_hda:     48 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 543);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 544);
//      snd_hda:     48 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 545);
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000e, 546);
//      snd_hda:     connection list 48 <- 14
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 547);

        snd_hda_codec_write(codec, 0x30, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     48 []

        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 550);
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 551);
//      snd_hda:     49 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 552);
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 553);
//      snd_hda:     amp capabilities 49 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 554);
//      snd_hda:     amp capabilities 49 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 555);
//      snd_hda:     49 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 556);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 557);
//      snd_hda:     49 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 558);
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000f, 559);
//      snd_hda:     connection list 49 <- 15
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 560);

        snd_hda_codec_write(codec, 0x31, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     49 []

        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 563);
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 564);
//      snd_hda:     50 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 565);
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 566);
//      snd_hda:     amp capabilities 50 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 567);
//      snd_hda:     amp capabilities 50 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 568);
//      snd_hda:     50 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 569);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 570);
//      snd_hda:     50 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 571);
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000010, 572);
//      snd_hda:     connection list 50 <- 16
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 573);

        snd_hda_codec_write(codec, 0x32, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     50 []

        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 576);
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 577);
//      snd_hda:     51 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 578);
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 579);
//      snd_hda:     amp capabilities 51 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 580);
//      snd_hda:     amp capabilities 51 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 581);
//      snd_hda:     51 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 582);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 583);
//      snd_hda:     51 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 584);
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000011, 585);
//      snd_hda:     connection list 51 <- 17
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 586);

        snd_hda_codec_write(codec, 0x33, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     51 []

        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 589);
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 590);
//      snd_hda:     52 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 591);
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 592);
//      snd_hda:     amp capabilities 52 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 593);
//      snd_hda:     amp capabilities 52 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 594);
//      snd_hda:     52 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 595);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 596);
//      snd_hda:     52 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 597);

        snd_hda_codec_write(codec, 0x34, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     52 []

        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 600);
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 601);
//      snd_hda:     53 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 602);
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 603);
//      snd_hda:     amp capabilities 53 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 604);
//      snd_hda:     amp capabilities 53 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 605);
//      snd_hda:     53 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 606);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 607);
//      snd_hda:     53 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 608);

        snd_hda_codec_write(codec, 0x35, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     53 []

        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 611);
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 612);
//      snd_hda:     54 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 613);
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 614);
//      snd_hda:     amp capabilities 54 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 615);
//      snd_hda:     amp capabilities 54 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 616);
//      snd_hda:     54 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 617);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 618);
//      snd_hda:     54 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 619);

        snd_hda_codec_write(codec, 0x36, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     54 []

        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 622);
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 623);
//      snd_hda:     55 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 624);
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 625);
//      snd_hda:     amp capabilities 55 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 626);
//      snd_hda:     amp capabilities 55 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 627);
//      snd_hda:     55 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 628);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 629);
//      snd_hda:     55 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 630);

        snd_hda_codec_write(codec, 0x37, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     55 []

        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 633);
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 634);
//      snd_hda:     56 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 635);
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 636);
//      snd_hda:     amp capabilities 56 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 637);
//      snd_hda:     amp capabilities 56 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 638);
//      snd_hda:     56 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 639);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 640);
//      snd_hda:     56 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 641);

        snd_hda_codec_write(codec, 0x38, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     56 []

        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 644);
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 645);
//      snd_hda:     57 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 646);
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 647);
//      snd_hda:     amp capabilities 57 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 648);
//      snd_hda:     amp capabilities 57 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 649);
//      snd_hda:     57 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 650);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 651);
//      snd_hda:     57 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 652);

        snd_hda_codec_write(codec, 0x39, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     57 []

        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 655);
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 656);
//      snd_hda:     58 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 657);
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 658);
//      snd_hda:     amp capabilities 58 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 659);
//      snd_hda:     amp capabilities 58 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 660);
//      snd_hda:     58 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 661);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 662);
//      snd_hda:     58 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 663);

        snd_hda_codec_write(codec, 0x3a, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     58 []

        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 666);
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 667);
//      snd_hda:     59 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 668);
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 669);
//      snd_hda:     amp capabilities 59 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 670);
//      snd_hda:     amp capabilities 59 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 671);
//      snd_hda:     59 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 672);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 673);
//      snd_hda:     59 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 674);

        snd_hda_codec_write(codec, 0x3b, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     59 []

        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 677);
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 678);
//      snd_hda:     60 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 679);
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 680);
//      snd_hda:     amp capabilities 60 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 681);
//      snd_hda:     amp capabilities 60 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 682);
//      snd_hda:     60 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x00ab9030, 683);
//      snd_hda:     pin config default 0x00ab9030 port conn 0 location 0x0 loc ext 0 loc geom 0 default device 10 conn type 11 color 9 misc 0 def assoc 3 seq 0
//      snd_hda:     pin config default 0x00ab9030 port conn Jack loc ext Ext loc geom N/A default device Mic In conn type Combination color Pink misc undef def assoc 3 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 684);
//      snd_hda:     60 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 685);

        snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     60 []

        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 688);
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 689);
//      snd_hda:     61 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 690);
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 691);
//      snd_hda:     amp capabilities 61 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 692);
//      snd_hda:     amp capabilities 61 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 693);
//      snd_hda:     61 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 694);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 695);
//      snd_hda:     61 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 696);

        snd_hda_codec_write(codec, 0x3d, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     61 []

        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 699);
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 700);
//      snd_hda:     62 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 701);
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 702);
//      snd_hda:     amp capabilities 62 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 703);
//      snd_hda:     amp capabilities 62 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 704);
//      snd_hda:     62 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 705);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 706);
//      snd_hda:     62 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 707);

        snd_hda_codec_write(codec, 0x3e, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     62 []

        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 710);
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 711);
//      snd_hda:     63 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 712);
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 713);
//      snd_hda:     amp capabilities 63 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 714);
//      snd_hda:     amp capabilities 63 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 715);
//      snd_hda:     63 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 716);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 717);
//      snd_hda:     63 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 718);

        snd_hda_codec_write(codec, 0x3f, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     63 []

        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 721);
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 722);
//      snd_hda:     64 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 723);
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 724);
//      snd_hda:     amp capabilities 64 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 725);
//      snd_hda:     amp capabilities 64 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 726);
//      snd_hda:     64 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 727);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 728);
//      snd_hda:     64 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 729);

        snd_hda_codec_write(codec, 0x40, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     64 []

        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 732);
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 733);
//      snd_hda:     65 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 734);
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 735);
//      snd_hda:     amp capabilities 65 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 736);
//      snd_hda:     amp capabilities 65 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 737);
//      snd_hda:     65 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 738);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 739);
//      snd_hda:     65 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 740);

        snd_hda_codec_write(codec, 0x41, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     65 []

        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 743);
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 744);
//      snd_hda:     66 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 745);
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 746);
//      snd_hda:     amp capabilities 66 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 747);
//      snd_hda:     amp capabilities 66 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 748);
//      snd_hda:     66 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 749);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 750);
//      snd_hda:     66 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 751);

        snd_hda_codec_write(codec, 0x42, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     66 []

        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 754);
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 755);
//      snd_hda:     67 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 756);
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 757);
//      snd_hda:     amp capabilities 67 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 758);
//      snd_hda:     amp capabilities 67 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 759);
//      snd_hda:     67 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 760);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 761);
//      snd_hda:     67 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 762);

        snd_hda_codec_write(codec, 0x43, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     67 []

        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 765);
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 766);
//      snd_hda:     68 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 767);
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 768);
//      snd_hda:     amp capabilities 68 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 769);
//      snd_hda:     amp capabilities 68 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 770);
//      snd_hda:     68 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0xa0a60100, 771);
//      snd_hda:     pin config default 0xa0a60100 port conn 2 location 0x20 loc ext 2 loc geom 0 default device 10 conn type 6 color 0 misc 1 def assoc 0 seq 0
//      snd_hda:     pin config default 0xa0a60100 port conn Fixed loc ext Sep loc geom N/A default device Mic In conn type Other Digital color Unknown misc Jack Detect Override def assoc 0 seq 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 772);
//      snd_hda:     68 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 773);
//      snd_hda:     amp capabilities 68 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 774);

        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     68 []

        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 777);
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 778);
//      snd_hda:     69 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 779);
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 780);
//      snd_hda:     amp capabilities 69 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 781);
//      snd_hda:     amp capabilities 69 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 782);
//      snd_hda:     69 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 783);
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 784);
//      snd_hda:     69 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 785);
//      snd_hda:     amp capabilities 69 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 786);

        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     69 []

        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 789);
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00700200, 790);
//      snd_hda:     70 AC_WID_BEEP ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_DIGITAL', 'AC_WCAP_TYPE'] 0 0 7
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 791);
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 792);
//      snd_hda:     amp capabilities 70 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 793);
//      snd_hda:     amp capabilities 70 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00700200, 794);
//      snd_hda:     70 AC_WID_BEEP ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_DIGITAL', 'AC_WCAP_TYPE'] 0 0 7

}

static void setup_beep(struct hda_codec *codec)
{
        snd_hda_codec_write(codec, 0x46, 0, AC_VERB_SET_BEEP_CONTROL, 0x00000000);
}

static void read_vendor_node(struct hda_codec *codec)
{
        int retval;

        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 797);
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00f002c1, 798);
//      snd_hda:     71 AC_WID_VENDOR ['AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_UNSOL_CAP', 'AC_WCAP_DELAY', 'AC_WCAP_PROC_WID', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DIGITAL'] 0 0 15
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 799);
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 800);
//      snd_hda:     amp capabilities 71 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 801);
//      snd_hda:     amp capabilities 71 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00f002c1, 802);
//      snd_hda:     71 AC_WID_VENDOR ['AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_UNSOL_CAP', 'AC_WCAP_DELAY', 'AC_WCAP_PROC_WID', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DIGITAL'] 0 0 15
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000010, 0x0000ff00, 803);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
}

static void read_hidden_feature_widgets(struct hda_codec *codec)
{
        // leave these in as check of state
        // now moved to separate function

        unsigned int retval;

        // following 2 commands here sequentially but removed to outer function as more appropriate

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);

        //snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

        // read parameters from the extra nodes NOT included in node list!!

        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1335);
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1336);
//      snd_hda:     72 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1337);
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1338);
//      snd_hda:     pcm params           72 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1339);
//      snd_hda:     stream format params 72 
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1340);
//      snd_hda:     amp capabilities 72 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1341);
//      snd_hda:     amp capabilities 72 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1342);
//      snd_hda:     72 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1344);
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1345);
//      snd_hda:     73 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1346);
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1347);
//      snd_hda:     pcm params           73 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1348);
//      snd_hda:     stream format params 73 
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1349);
//      snd_hda:     amp capabilities 73 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1350);
//      snd_hda:     amp capabilities 73 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1351);
//      snd_hda:     73 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1353);
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1354);
//      snd_hda:     74 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1355);
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1356);
//      snd_hda:     pcm params           74 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1357);
//      snd_hda:     stream format params 74 
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1358);
//      snd_hda:     amp capabilities 74 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1359);
//      snd_hda:     amp capabilities 74 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1360);
//      snd_hda:     74 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1362);
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1363);
//      snd_hda:     75 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1364);
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1365);
//      snd_hda:     pcm params           75 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1366);
//      snd_hda:     stream format params 75 
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1367);
//      snd_hda:     amp capabilities 75 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1368);
//      snd_hda:     amp capabilities 75 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1369);
//      snd_hda:     75 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0

        dev_info(hda_codec_dev(codec), "command nid end   read_hidden_feature_widgets\n");

}

static void putative_setup_mic(struct hda_codec *codec);
static void setup_amps(struct hda_codec *codec);
static void putative_setup_mic2(struct hda_codec *codec);
static void setup_jack_nids(struct hda_codec *codec);
static void setup_TDM(struct hda_codec *codec);
static void sync_converters(struct hda_codec *codec);
static void amps_disable(struct hda_codec *codec);
static void sync_converters2(struct hda_codec *codec);
static void sync_converters3(struct hda_codec *codec);
static void amps_disable2(struct hda_codec *codec);
static void read_coefs2(struct hda_codec *codec);
static void setup_amps2(struct hda_codec *codec);
static void setup_gpio2(struct hda_codec *codec);
static void setup_mic3(struct hda_codec *codec);
static void setup_mic_vol3(struct hda_codec *codec);
static void setup_mic_vol4(struct hda_codec *codec);
static void setup_mic4(struct hda_codec *codec);
static void setup_mic_vol5(struct hda_codec *codec);
static void setup_mic_vol6(struct hda_codec *codec);
static void setup_mic_vol7(struct hda_codec *codec);


static void setup_node_alpha(struct hda_codec *codec)
{

        int retval;

        int retwake;
        int retunsol;


        dev_info(hda_codec_dev(codec), "command nid start setup_node_alpha\n");


	// this likely a set to AC_PWRST_D0 but already in AC_PWRST_D0
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 1370);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


	// these 2 items seem to enable the i2c clock - but we havent enabled i2c yet!!
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1371 ); //   coef read 1371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1375 ); //   coef write 1375

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 1379 ); //   coef read 1379
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 1383 ); //   coef write 1383
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 1387 ); //   coef write 1387
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 1391 ); //   coef write 1391
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000000, 1395 ); //   coef write 1395


        // this does the following in a loop
        snd_hda_coef_sequence(codec, cs8409_init_coef1, "init_coef1");

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8000, 0x00000000, 1399 ); //   coef write 1399
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8000, 0x00000000, 1403 ); //   coef write 1403
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8000, 0x00000000, 1407 ); //   coef write 1407
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8000, 0x00000000, 1411 ); //   coef write 1411
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001d, 0x8000, 0x00000000, 1415 ); //   coef write 1415
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001e, 0x8000, 0x00000000, 1419 ); //   coef write 1419
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001f, 0x8000, 0x00000000, 1423 ); //   coef write 1423
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0020, 0x8000, 0x00000000, 1427 ); //   coef write 1427
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0021, 0x8000, 0x00000000, 1431 ); //   coef write 1431
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0022, 0x8000, 0x00000000, 1435 ); //   coef write 1435
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0023, 0x8000, 0x00000000, 1439 ); //   coef write 1439
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0024, 0x8000, 0x00000000, 1443 ); //   coef write 1443
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0025, 0x8000, 0x00000000, 1447 ); //   coef write 1447
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0026, 0x8000, 0x00000000, 1451 ); //   coef write 1451
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0027, 0x8000, 0x00000000, 1455 ); //   coef write 1455
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0028, 0x8000, 0x00000000, 1459 ); //   coef write 1459
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0029, 0x8000, 0x00000000, 1463 ); //   coef write 1463
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002a, 0x8000, 0x00000000, 1467 ); //   coef write 1467
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002b, 0x8000, 0x00000000, 1471 ); //   coef write 1471
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002c, 0x8000, 0x00000000, 1475 ); //   coef write 1475
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002d, 0x8000, 0x00000000, 1479 ); //   coef write 1479
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002e, 0x8000, 0x00000000, 1483 ); //   coef write 1483
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002f, 0x8000, 0x00000000, 1487 ); //   coef write 1487
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0030, 0x8000, 0x00000000, 1491 ); //   coef write 1491
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0031, 0x8000, 0x00000000, 1495 ); //   coef write 1495
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0032, 0x8000, 0x00000000, 1499 ); //   coef write 1499
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0033, 0x8000, 0x00000000, 1503 ); //   coef write 1503
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0034, 0x8000, 0x00000000, 1507 ); //   coef write 1507
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0035, 0x8000, 0x00000000, 1511 ); //   coef write 1511
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0036, 0x8000, 0x00000000, 1515 ); //   coef write 1515
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0037, 0x8000, 0x00000000, 1519 ); //   coef write 1519
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0038, 0x8000, 0x00000000, 1523 ); //   coef write 1523
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0039, 0x8000, 0x00000000, 1527 ); //   coef write 1527
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003a, 0x8000, 0x00000000, 1531 ); //   coef write 1531
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003b, 0x8000, 0x00000000, 1535 ); //   coef write 1535
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003c, 0x8000, 0x00000000, 1539 ); //   coef write 1539
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003d, 0x8000, 0x00000000, 1543 ); //   coef write 1543
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003e, 0x8000, 0x00000000, 1547 ); //   coef write 1547
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003f, 0x8000, 0x00000000, 1551 ); //   coef write 1551
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0040, 0x8000, 0x00000000, 1555 ); //   coef write 1555
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0041, 0x8000, 0x00000000, 1559 ); //   coef write 1559
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0042, 0x8000, 0x00000000, 1563 ); //   coef write 1563
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0043, 0x8000, 0x00000000, 1567 ); //   coef write 1567
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0044, 0x8000, 0x00000000, 1571 ); //   coef write 1571
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0045, 0x8000, 0x00000000, 1575 ); //   coef write 1575
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0046, 0x8000, 0x00000000, 1579 ); //   coef write 1579
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0047, 0x8000, 0x00000000, 1583 ); //   coef write 1583
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0048, 0x8000, 0x00000000, 1587 ); //   coef write 1587
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x8000, 0x00000000, 1591 ); //   coef write 1591
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x8000, 0x00000000, 1595 ); //   coef write 1595
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004b, 0x8000, 0x00000000, 1599 ); //   coef write 1599
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004c, 0x8000, 0x00000000, 1603 ); //   coef write 1603
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004d, 0x8000, 0x00000000, 1607 ); //   coef write 1607
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004e, 0x8000, 0x00000000, 1611 ); //   coef write 1611
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004f, 0x8000, 0x00000000, 1615 ); //   coef write 1615
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0050, 0x8000, 0x00000000, 1619 ); //   coef write 1619
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0051, 0x8000, 0x00000000, 1623 ); //   coef write 1623
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0052, 0x8000, 0x00000000, 1627 ); //   coef write 1627
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0053, 0x8000, 0x00000000, 1631 ); //   coef write 1631
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0054, 0x8000, 0x00000000, 1635 ); //   coef write 1635
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0055, 0x8000, 0x00000000, 1639 ); //   coef write 1639
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0056, 0x8000, 0x00000000, 1643 ); //   coef write 1643
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0057, 0x8000, 0x00000000, 1647 ); //   coef write 1647


        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x000a, 0x0000, 0x00000000, 1651 ); //   coef write 1651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 1655 ); //   coef write 1655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 1659 ); //   coef write 1659
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 1663 ); //   coef write 1663
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 1667 ); //   coef write 1667


        // so the following may be associated with the microphone(s)
        // - it does appear the SET_CONFIG_DEFAULTs set node 0x45 to a microphone

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000004);
//      snd_hda:     gpio enable 1 0x04
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000004, 1672);
//      snd_hda:     gpio data 1 0x04

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_0, 0x00000001);
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_1, 0x00000001);
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_2, 0x000000a0);
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_3, 0x00000090);
//      snd_hda:     pin config 0x90a00101 port conn 2 location 0x10 loc ext 1 loc geom 0 default device 10 conn type 0 color 0 misc 1 def assoc 0 seq 1
//      snd_hda:     pin config 0x90a00101 port conn Fixed loc ext Int loc geom N/A default device Mic In conn type Unknown color Unknown misc Jack Detect Override def assoc 0 seq 1


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // enable I2C

//      snd_hda: # AppleHDAFunctionGroupCS8409::enableI2C: 
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1691 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1691
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1695 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1695
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000000, 1699 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1699
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0002, 0x0080, 0x00000000, 1703 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1703
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000080, 1707 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1707
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005b, 0x0000, 0x00000010, 1711 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1711
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005b, 0x0010, 0x00000000, 1715 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1715
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1719 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1719
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1723 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1723

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // AppleHDAFunctionGroupCS8409::enableGPIforUR
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000005);
//      snd_hda:     gpio enable 1 0x05
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000000);
//      snd_hda:     gpio direction 1 0x00 in in in in in in in in
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_WAKE_MASK, 0x00000000, 0x00000000, 1735);
//      snd_hda:     gpio wake enable 1 0x00
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_WAKE_MASK, 0x00000001);
//      snd_hda:     gpio wake enable 1 0x01
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_UNSOLICITED_RSP_MASK, 0x00000000, 0x00000000, 1737);
//      snd_hda:     gpio unsol enable 1 0x00
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x00000001);
//      snd_hda:     gpio unsol enable 1 0x01

        // some unknown vendor command
        snd_hda_codec_write(codec, codec->core.afg, 0, 0x7f0, 0x000000b7);

        dev_info(hda_codec_dev(codec), "gpio_wake 0x%x\n",retwake);
        dev_info(hda_codec_dev(codec), "gpio_unsol 0x%x\n",retunsol);


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
	// this is duplicated
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

	// then re-power it back up??
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        putative_setup_mic(codec);

        setup_amps(codec);

        putative_setup_mic2(codec);

        setup_jack_nids(codec);

        setup_TDM(codec);

        sync_converters(codec);

        amps_disable(codec);

        sync_converters2(codec);

        sync_converters3(codec);

        amps_disable2(codec);

        read_coefs2(codec);

        setup_amps2(codec);

        setup_gpio2(codec);

        setup_mic3(codec);

        setup_mic_vol3(codec);

        setup_mic_vol4(codec);

        setup_mic4(codec);

        setup_mic_vol5(codec);

        setup_mic_vol6(codec);

        setup_mic_vol7(codec);


        // inserted boot code above

        dev_info(hda_codec_dev(codec), "command nid end   setup_node_alpha\n");
}

static void putative_setup_mic(struct hda_codec *codec)
{

        // very unsure about this but this could be setting up the GPIO for the headphone jack
        // based on proximity to headphone/mic setup

        // AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002);
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000000);
//      snd_hda:     gpio data 1 0x00
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000007);
//      snd_hda:     gpio enable 1 0x07

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002);
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000002);
//      snd_hda:     gpio data 1 0x02
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000007);
//      snd_hda:     gpio enable 1 0x07

	// and another power down/up
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);


	// these are i2c calls
        // so it seems Apple is using SET_COEF_INDEX, SET_PROC_COEF to write to the local i2c bus
        // writing to coef index 0x59 for the i2c address, reading from 0x5c for i2c status
        // and writing to 0x5d for i2c register, data writes (8 bit each in the 16 bit coef data with register in hi byte)
        // and writing/reading to 0x5e for i2c register, data reads - the write is register with lo byte 0x00
        // and read is data for i2c register (i2c register returned) with data in lo byte

        // based on info from bugs 195671 and 110561
        // and that writing to coef index 0x59 seems to be the i2c address hence the i2c address is 0x90
        // this is likely setting up the headphone/mic jack ic CS42L83A

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0100 i2c data 0x0100
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1301, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1769 ); // i2cPagedRead  coef read 1769
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1773 ); // i2cPagedRead  coef write 1773
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1777 ); // i2cPagedRead  coef write 1777
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1781 ); // i2cPagedRead  coef write 1781
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1785 ); // i2cPagedRead  coef read 1785
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 1789 ); // i2cPagedRead  coef write 1789
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1793 ); // i2cPagedRead  coef read 1793
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1797 ); // i2cPagedRead  coef read 1797
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000100, 1801 ); // i2cPagedRead  coef read 1801
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1805 ); // i2cPagedRead  coef read 1805
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1809 ); // i2cPagedRead  coef write 1809
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0200 i2c data 0x0200
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1302, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1820 ); // i2cPagedRead  coef read 1820
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1824 ); // i2cPagedRead  coef write 1824
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1828 ); // i2cPagedRead  coef write 1828
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1832 ); // i2cPagedRead  coef write 1832
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1836 ); // i2cPagedRead  coef read 1836
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 1840 ); // i2cPagedRead  coef write 1840
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1844 ); // i2cPagedRead  coef read 1844
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1848 ); // i2cPagedRead  coef read 1848
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000200, 1852 ); // i2cPagedRead  coef read 1852
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1856 ); // i2cPagedRead  coef read 1856
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1860 ); // i2cPagedRead  coef write 1860
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0300 i2c data 0x030c
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1303, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1871 ); // i2cPagedRead  coef read 1871
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1875 ); // i2cPagedRead  coef write 1875
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1879 ); // i2cPagedRead  coef write 1879
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1883 ); // i2cPagedRead  coef write 1883
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1887 ); // i2cPagedRead  coef read 1887
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0300, 0x00000000, 1891 ); // i2cPagedRead  coef write 1891
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1895 ); // i2cPagedRead  coef read 1895
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1899 ); // i2cPagedRead  coef read 1899
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000030c, 1903 ); // i2cPagedRead  coef read 1903
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1907 ); // i2cPagedRead  coef read 1907
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1911 ); // i2cPagedRead  coef write 1911
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0400 i2c data 0x0400
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1304, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1922 ); // i2cPagedRead  coef read 1922
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1926 ); // i2cPagedRead  coef write 1926
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1930 ); // i2cPagedRead  coef write 1930
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1934 ); // i2cPagedRead  coef write 1934
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1938 ); // i2cPagedRead  coef read 1938
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0400, 0x00000000, 1942 ); // i2cPagedRead  coef write 1942
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1946 ); // i2cPagedRead  coef read 1946
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1950 ); // i2cPagedRead  coef read 1950
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000400, 1954 ); // i2cPagedRead  coef read 1954
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1958 ); // i2cPagedRead  coef read 1958
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1962 ); // i2cPagedRead  coef write 1962
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0500 i2c data 0x0500
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1305, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1973 ); // i2cPagedRead  coef read 1973
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1977 ); // i2cPagedRead  coef write 1977
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1981 ); // i2cPagedRead  coef write 1981
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1985 ); // i2cPagedRead  coef write 1985
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1989 ); // i2cPagedRead  coef read 1989
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0500, 0x00000000, 1993 ); // i2cPagedRead  coef write 1993
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1997 ); // i2cPagedRead  coef read 1997
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2001 ); // i2cPagedRead  coef read 2001
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000500, 2005 ); // i2cPagedRead  coef read 2005
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2009 ); // i2cPagedRead  coef read 2009
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2013 ); // i2cPagedRead  coef write 2013
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2024 ); // i2cPagedRead  coef read 2024
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2028 ); // i2cPagedRead  coef write 2028
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2032 ); // i2cPagedRead  coef write 2032
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2036 ); // i2cPagedRead  coef write 2036
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2040 ); // i2cPagedRead  coef read 2040
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0b00, 0x00000000, 2044 ); // i2cPagedRead  coef write 2044
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2048 ); // i2cPagedRead  coef read 2048
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2052 ); // i2cPagedRead  coef read 2052
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000b60, 2056 ); // i2cPagedRead  coef read 2056
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2060 ); // i2cPagedRead  coef read 2060
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2064 ); // i2cPagedRead  coef write 2064
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0d00 i2c data 0x0d01
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130d, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2075 ); // i2cPagedRead  coef read 2075
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2079 ); // i2cPagedRead  coef write 2079
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2083 ); // i2cPagedRead  coef write 2083
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2087 ); // i2cPagedRead  coef write 2087
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2091 ); // i2cPagedRead  coef read 2091
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0d00, 0x00000000, 2095 ); // i2cPagedRead  coef write 2095
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2099 ); // i2cPagedRead  coef read 2099
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2103 ); // i2cPagedRead  coef read 2103
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000d01, 2107 ); // i2cPagedRead  coef read 2107
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2111 ); // i2cPagedRead  coef read 2111
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2115 ); // i2cPagedRead  coef write 2115
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0e00 i2c data 0x0e00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130e, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2126 ); // i2cPagedRead  coef read 2126
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2130 ); // i2cPagedRead  coef write 2130
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2134 ); // i2cPagedRead  coef write 2134
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2138 ); // i2cPagedRead  coef write 2138
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2142 ); // i2cPagedRead  coef read 2142
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0e00, 0x00000000, 2146 ); // i2cPagedRead  coef write 2146
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2150 ); // i2cPagedRead  coef read 2150
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2154 ); // i2cPagedRead  coef read 2154
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000e00, 2158 ); // i2cPagedRead  coef read 2158
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2162 ); // i2cPagedRead  coef read 2162
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2166 ); // i2cPagedRead  coef write 2166
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0800 i2c data 0x0801
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1308, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2177 ); // i2cPagedRead  coef read 2177
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2181 ); // i2cPagedRead  coef write 2181
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2185 ); // i2cPagedRead  coef write 2185
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2189 ); // i2cPagedRead  coef write 2189
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2193 ); // i2cPagedRead  coef read 2193
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0800, 0x00000000, 2197 ); // i2cPagedRead  coef write 2197
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2201 ); // i2cPagedRead  coef read 2201
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2205 ); // i2cPagedRead  coef read 2205
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000801, 2209 ); // i2cPagedRead  coef read 2209
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2213 ); // i2cPagedRead  coef read 2213
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2217 ); // i2cPagedRead  coef write 2217
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0f00 i2c data 0x0f00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2228 ); // i2cPagedRead  coef read 2228
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2232 ); // i2cPagedRead  coef write 2232
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2236 ); // i2cPagedRead  coef write 2236
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2240 ); // i2cPagedRead  coef write 2240
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2244 ); // i2cPagedRead  coef read 2244
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0f00, 0x00000000, 2248 ); // i2cPagedRead  coef write 2248
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2252 ); // i2cPagedRead  coef read 2252
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2256 ); // i2cPagedRead  coef read 2256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000f00, 2260 ); // i2cPagedRead  coef read 2260
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2264 ); // i2cPagedRead  coef read 2264
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2268 ); // i2cPagedRead  coef write 2268
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002);
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000000);
//      snd_hda:     gpio data 1 0x00
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000007);
//      snd_hda:     gpio enable 1 0x07

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002);
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000002);
//      snd_hda:     gpio data 1 0x02
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000007);
//      snd_hda:     gpio enable 1 0x07

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0100 i2c data 0x0142
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2299 ); // i2cPagedRead  coef read 2299
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2303 ); // i2cPagedRead  coef write 2303
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2307 ); // i2cPagedRead  coef write 2307
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0010, 0x00000000, 2311 ); // i2cPagedRead  coef write 2311
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2315 ); // i2cPagedRead  coef read 2315
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 2319 ); // i2cPagedRead  coef write 2319
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2323 ); // i2cPagedRead  coef read 2323
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2327 ); // i2cPagedRead  coef read 2327
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000142, 2331 ); // i2cPagedRead  coef read 2331
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2335 ); // i2cPagedRead  coef read 2335
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2339 ); // i2cPagedRead  coef write 2339
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0500 i2c data 0x05b0
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2350 ); // i2cPagedRead  coef read 2350
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2354 ); // i2cPagedRead  coef write 2354
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2358 ); // i2cPagedRead  coef write 2358
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0010, 0x00000000, 2362 ); // i2cPagedRead  coef write 2362
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2366 ); // i2cPagedRead  coef read 2366
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0500, 0x00000000, 2370 ); // i2cPagedRead  coef write 2370
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2374 ); // i2cPagedRead  coef read 2374
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2378 ); // i2cPagedRead  coef read 2378
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x000005b0, 2382 ); // i2cPagedRead  coef read 2382
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2386 ); // i2cPagedRead  coef read 2386
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2390 ); // i2cPagedRead  coef write 2390
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0300 i2c data 0x0320
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1103, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2401 ); // i2cPagedRead  coef read 2401
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2405 ); // i2cPagedRead  coef write 2405
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2409 ); // i2cPagedRead  coef write 2409
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2413 ); // i2cPagedRead  coef write 2413
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2417 ); // i2cPagedRead  coef read 2417
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0300, 0x00000000, 2421 ); // i2cPagedRead  coef write 2421
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2425 ); // i2cPagedRead  coef read 2425
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2429 ); // i2cPagedRead  coef read 2429
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000320, 2433 ); // i2cPagedRead  coef read 2433
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2437 ); // i2cPagedRead  coef read 2437
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2441 ); // i2cPagedRead  coef write 2441
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0322 i2c data 0x0022
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1103, 0x0022, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2452 ); // i2cPagedWrite  coef read 2452
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2456 ); // i2cPagedWrite  coef write 2456
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2460 ); // i2cPagedWrite  coef write 2460
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2464 ); // i2cPagedWrite  coef write 2464
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2468 ); // i2cPagedWrite  coef read 2468
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2472 ); // i2cPagedWrite  coef read 2472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0322, 0x00000000, 2476 ); // i2cPagedWrite  coef write 2476
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2480 ); // i2cPagedWrite  coef read 2480
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2484 ); // i2cPagedWrite  coef read 2484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2488 ); // i2cPagedWrite  coef read 2488
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2492 ); // i2cPagedWrite  coef write 2492
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2901 i2c data 0x0001
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1129, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2503 ); // i2cPagedWrite  coef read 2503
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2507 ); // i2cPagedWrite  coef write 2507
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2511 ); // i2cPagedWrite  coef write 2511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2515 ); // i2cPagedWrite  coef write 2515
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2519 ); // i2cPagedWrite  coef read 2519
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2523 ); // i2cPagedWrite  coef read 2523
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2901, 0x00000000, 2527 ); // i2cPagedWrite  coef write 2527
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2531 ); // i2cPagedWrite  coef read 2531
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2535 ); // i2cPagedWrite  coef read 2535
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2539 ); // i2cPagedWrite  coef read 2539
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2543 ); // i2cPagedWrite  coef write 2543
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x200f i2c data 0x000f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1320, 0x000f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2554 ); // i2cPagedWrite  coef read 2554
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2558 ); // i2cPagedWrite  coef write 2558
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2562 ); // i2cPagedWrite  coef write 2562
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2566 ); // i2cPagedWrite  coef write 2566
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2570 ); // i2cPagedWrite  coef read 2570
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2574 ); // i2cPagedWrite  coef read 2574
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x200f, 0x00000000, 2578 ); // i2cPagedWrite  coef write 2578
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2582 ); // i2cPagedWrite  coef read 2582
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2586 ); // i2cPagedWrite  coef read 2586
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2590 ); // i2cPagedWrite  coef read 2590
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2594 ); // i2cPagedWrite  coef write 2594
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1b00 i2c data 0x1b03
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x131b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2605 ); // i2cPagedRead  coef read 2605
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2609 ); // i2cPagedRead  coef write 2609
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2613 ); // i2cPagedRead  coef write 2613
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2617 ); // i2cPagedRead  coef write 2617
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2621 ); // i2cPagedRead  coef read 2621
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1b00, 0x00000000, 2625 ); // i2cPagedRead  coef write 2625
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2629 ); // i2cPagedRead  coef read 2629
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2633 ); // i2cPagedRead  coef read 2633
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001b03, 2637 ); // i2cPagedRead  coef read 2637
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2641 ); // i2cPagedRead  coef read 2641
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2645 ); // i2cPagedRead  coef write 2645
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1b03 i2c data 0x0003
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131b, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2656 ); // i2cPagedWrite  coef read 2656
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2660 ); // i2cPagedWrite  coef write 2660
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2664 ); // i2cPagedWrite  coef write 2664
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2668 ); // i2cPagedWrite  coef write 2668
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2672 ); // i2cPagedWrite  coef read 2672
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2676 ); // i2cPagedWrite  coef read 2676
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1b03, 0x00000000, 2680 ); // i2cPagedWrite  coef write 2680
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2684 ); // i2cPagedWrite  coef read 2684
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2688 ); // i2cPagedWrite  coef read 2688
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2692 ); // i2cPagedWrite  coef read 2692
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2696 ); // i2cPagedWrite  coef write 2696
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x23 lo 0x023f i2c data 0x003f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x2302, 0x003f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2707 ); // i2cPagedWrite  coef read 2707
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2711 ); // i2cPagedWrite  coef write 2711
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2715 ); // i2cPagedWrite  coef write 2715
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0023, 0x00000000, 2719 ); // i2cPagedWrite  coef write 2719
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2723 ); // i2cPagedWrite  coef read 2723
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2727 ); // i2cPagedWrite  coef read 2727
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x023f, 0x00000000, 2731 ); // i2cPagedWrite  coef write 2731
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2735 ); // i2cPagedWrite  coef read 2735
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2739 ); // i2cPagedWrite  coef read 2739
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2743 ); // i2cPagedWrite  coef read 2743
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2747 ); // i2cPagedWrite  coef write 2747
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0100 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f01, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2758 ); // i2cPagedWrite  coef read 2758
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2762 ); // i2cPagedWrite  coef write 2762
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2766 ); // i2cPagedWrite  coef write 2766
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001f, 0x00000000, 2770 ); // i2cPagedWrite  coef write 2770
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2774 ); // i2cPagedWrite  coef read 2774
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2778 ); // i2cPagedWrite  coef read 2778
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0100, 0x00000000, 2782 ); // i2cPagedWrite  coef write 2782
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2786 ); // i2cPagedWrite  coef read 2786
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2790 ); // i2cPagedWrite  coef read 2790
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2794 ); // i2cPagedWrite  coef read 2794
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2798 ); // i2cPagedWrite  coef write 2798
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x21a6 i2c data 0x00a6
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1121, 0x00a6, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2809 ); // i2cPagedWrite  coef read 2809
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2813 ); // i2cPagedWrite  coef write 2813
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2817 ); // i2cPagedWrite  coef write 2817
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2821 ); // i2cPagedWrite  coef write 2821
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2825 ); // i2cPagedWrite  coef read 2825
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2829 ); // i2cPagedWrite  coef read 2829
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x21a6, 0x00000000, 2833 ); // i2cPagedWrite  coef write 2833
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2837 ); // i2cPagedWrite  coef read 2837
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2841 ); // i2cPagedWrite  coef read 2841
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2845 ); // i2cPagedWrite  coef read 2845
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2849 ); // i2cPagedWrite  coef write 2849
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1600 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1316, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2860 ); // i2cPagedWrite  coef read 2860
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2864 ); // i2cPagedWrite  coef write 2864
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2868 ); // i2cPagedWrite  coef write 2868
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2872 ); // i2cPagedWrite  coef write 2872
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2876 ); // i2cPagedWrite  coef read 2876
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2880 ); // i2cPagedWrite  coef read 2880
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 2884 ); // i2cPagedWrite  coef write 2884
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2888 ); // i2cPagedWrite  coef read 2888
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2892 ); // i2cPagedWrite  coef read 2892
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2896 ); // i2cPagedWrite  coef read 2896
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2900 ); // i2cPagedWrite  coef write 2900
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1700 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1317, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2911 ); // i2cPagedWrite  coef read 2911
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2915 ); // i2cPagedWrite  coef write 2915
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2919 ); // i2cPagedWrite  coef write 2919
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2923 ); // i2cPagedWrite  coef write 2923
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2927 ); // i2cPagedWrite  coef read 2927
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2931 ); // i2cPagedWrite  coef read 2931
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1700, 0x00000000, 2935 ); // i2cPagedWrite  coef write 2935
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2939 ); // i2cPagedWrite  coef read 2939
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2943 ); // i2cPagedWrite  coef read 2943
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2947 ); // i2cPagedWrite  coef read 2947
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2951 ); // i2cPagedWrite  coef write 2951
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1800 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1318, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2962 ); // i2cPagedWrite  coef read 2962
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2966 ); // i2cPagedWrite  coef write 2966
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2970 ); // i2cPagedWrite  coef write 2970
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2974 ); // i2cPagedWrite  coef write 2974
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2978 ); // i2cPagedWrite  coef read 2978
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2982 ); // i2cPagedWrite  coef read 2982
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1800, 0x00000000, 2986 ); // i2cPagedWrite  coef write 2986
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2990 ); // i2cPagedWrite  coef read 2990
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2994 ); // i2cPagedWrite  coef read 2994
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2998 ); // i2cPagedWrite  coef read 2998
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3002 ); // i2cPagedWrite  coef write 3002
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1900 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1319, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3013 ); // i2cPagedWrite  coef read 3013
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3017 ); // i2cPagedWrite  coef write 3017
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3021 ); // i2cPagedWrite  coef write 3021
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3025 ); // i2cPagedWrite  coef write 3025
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3029 ); // i2cPagedWrite  coef read 3029
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3033 ); // i2cPagedWrite  coef read 3033
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 3037 ); // i2cPagedWrite  coef write 3037
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3041 ); // i2cPagedWrite  coef read 3041
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3045 ); // i2cPagedWrite  coef read 3045
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3049 ); // i2cPagedWrite  coef read 3049
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3053 ); // i2cPagedWrite  coef write 3053
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1a00 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131a, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3064 ); // i2cPagedWrite  coef read 3064
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3068 ); // i2cPagedWrite  coef write 3068
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3072 ); // i2cPagedWrite  coef write 3072
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3076 ); // i2cPagedWrite  coef write 3076
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3080 ); // i2cPagedWrite  coef read 3080
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3084 ); // i2cPagedWrite  coef read 3084
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1a00, 0x00000000, 3088 ); // i2cPagedWrite  coef write 3088
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3092 ); // i2cPagedWrite  coef read 3092
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3096 ); // i2cPagedWrite  coef read 3096
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3100 ); // i2cPagedWrite  coef read 3100
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3104 ); // i2cPagedWrite  coef write 3104
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1c00 i2c data 0x1c7f
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x131c, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3115 ); // i2cPagedRead  coef read 3115
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3119 ); // i2cPagedRead  coef write 3119
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3123 ); // i2cPagedRead  coef write 3123
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3127 ); // i2cPagedRead  coef write 3127
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3131 ); // i2cPagedRead  coef read 3131
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1c00, 0x00000000, 3135 ); // i2cPagedRead  coef write 3135
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3139 ); // i2cPagedRead  coef read 3139
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3143 ); // i2cPagedRead  coef read 3143
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001c7f, 3147 ); // i2cPagedRead  coef read 3147
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3151 ); // i2cPagedRead  coef read 3151
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3155 ); // i2cPagedRead  coef write 3155
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1c1a i2c data 0x001a
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131c, 0x001a, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3166 ); // i2cPagedWrite  coef read 3166
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3170 ); // i2cPagedWrite  coef write 3170
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3174 ); // i2cPagedWrite  coef write 3174
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3178 ); // i2cPagedWrite  coef write 3178
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3182 ); // i2cPagedWrite  coef read 3182
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3186 ); // i2cPagedWrite  coef read 3186
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1c1a, 0x00000000, 3190 ); // i2cPagedWrite  coef write 3190
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3194 ); // i2cPagedWrite  coef read 3194
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3198 ); // i2cPagedWrite  coef read 3198
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3202 ); // i2cPagedWrite  coef read 3202
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3206 ); // i2cPagedWrite  coef write 3206
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1e00 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131e, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3217 ); // i2cPagedWrite  coef read 3217
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3221 ); // i2cPagedWrite  coef write 3221
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3225 ); // i2cPagedWrite  coef write 3225
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3229 ); // i2cPagedWrite  coef write 3229
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3233 ); // i2cPagedWrite  coef read 3233
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3237 ); // i2cPagedWrite  coef read 3237
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1e00, 0x00000000, 3241 ); // i2cPagedWrite  coef write 3241
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3245 ); // i2cPagedWrite  coef read 3245
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3249 ); // i2cPagedWrite  coef read 3249
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3253 ); // i2cPagedWrite  coef read 3253
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3257 ); // i2cPagedWrite  coef write 3257
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1f00 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131f, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3268 ); // i2cPagedWrite  coef read 3268
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3272 ); // i2cPagedWrite  coef write 3272
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3276 ); // i2cPagedWrite  coef write 3276
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3280 ); // i2cPagedWrite  coef write 3280
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3284 ); // i2cPagedWrite  coef read 3284
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3288 ); // i2cPagedWrite  coef read 3288
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1f00, 0x00000000, 3292 ); // i2cPagedWrite  coef write 3292
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3296 ); // i2cPagedWrite  coef read 3296
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3300 ); // i2cPagedWrite  coef read 3300
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3304 ); // i2cPagedWrite  coef read 3304
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3308 ); // i2cPagedWrite  coef write 3308
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0100 i2c data 0x0100
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1301, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3319 ); // i2cPagedRead  coef read 3319
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3323 ); // i2cPagedRead  coef write 3323
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3327 ); // i2cPagedRead  coef write 3327
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3331 ); // i2cPagedRead  coef write 3331
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3335 ); // i2cPagedRead  coef read 3335
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 3339 ); // i2cPagedRead  coef write 3339
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3343 ); // i2cPagedRead  coef read 3343
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3347 ); // i2cPagedRead  coef read 3347
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000100, 3351 ); // i2cPagedRead  coef read 3351
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3355 ); // i2cPagedRead  coef read 3355
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3359 ); // i2cPagedRead  coef write 3359
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0200 i2c data 0x0200
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1302, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3370 ); // i2cPagedRead  coef read 3370
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3374 ); // i2cPagedRead  coef write 3374
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3378 ); // i2cPagedRead  coef write 3378
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3382 ); // i2cPagedRead  coef write 3382
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3386 ); // i2cPagedRead  coef read 3386
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 3390 ); // i2cPagedRead  coef write 3390
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3394 ); // i2cPagedRead  coef read 3394
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3398 ); // i2cPagedRead  coef read 3398
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000200, 3402 ); // i2cPagedRead  coef read 3402
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3406 ); // i2cPagedRead  coef read 3406
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3410 ); // i2cPagedRead  coef write 3410
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0300 i2c data 0x030c
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1303, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3421 ); // i2cPagedRead  coef read 3421
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3425 ); // i2cPagedRead  coef write 3425
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3429 ); // i2cPagedRead  coef write 3429
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3433 ); // i2cPagedRead  coef write 3433
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3437 ); // i2cPagedRead  coef read 3437
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0300, 0x00000000, 3441 ); // i2cPagedRead  coef write 3441
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3445 ); // i2cPagedRead  coef read 3445
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3449 ); // i2cPagedRead  coef read 3449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000030c, 3453 ); // i2cPagedRead  coef read 3453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3457 ); // i2cPagedRead  coef read 3457
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3461 ); // i2cPagedRead  coef write 3461
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0400 i2c data 0x0400
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1304, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3472 ); // i2cPagedRead  coef read 3472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3476 ); // i2cPagedRead  coef write 3476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3480 ); // i2cPagedRead  coef write 3480
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3484 ); // i2cPagedRead  coef write 3484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3488 ); // i2cPagedRead  coef read 3488
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0400, 0x00000000, 3492 ); // i2cPagedRead  coef write 3492
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3496 ); // i2cPagedRead  coef read 3496
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3500 ); // i2cPagedRead  coef read 3500
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000400, 3504 ); // i2cPagedRead  coef read 3504
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3508 ); // i2cPagedRead  coef read 3508
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3512 ); // i2cPagedRead  coef write 3512
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0500 i2c data 0x0500
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1305, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3523 ); // i2cPagedRead  coef read 3523
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3527 ); // i2cPagedRead  coef write 3527
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3531 ); // i2cPagedRead  coef write 3531
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3535 ); // i2cPagedRead  coef write 3535
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3539 ); // i2cPagedRead  coef read 3539
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0500, 0x00000000, 3543 ); // i2cPagedRead  coef write 3543
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3547 ); // i2cPagedRead  coef read 3547
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3551 ); // i2cPagedRead  coef read 3551
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000500, 3555 ); // i2cPagedRead  coef read 3555
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3559 ); // i2cPagedRead  coef read 3559
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3563 ); // i2cPagedRead  coef write 3563
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3574 ); // i2cPagedRead  coef read 3574
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3578 ); // i2cPagedRead  coef write 3578
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3582 ); // i2cPagedRead  coef write 3582
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3586 ); // i2cPagedRead  coef write 3586
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3590 ); // i2cPagedRead  coef read 3590
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0b00, 0x00000000, 3594 ); // i2cPagedRead  coef write 3594
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3598 ); // i2cPagedRead  coef read 3598
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3602 ); // i2cPagedRead  coef read 3602
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000b60, 3606 ); // i2cPagedRead  coef read 3606
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3610 ); // i2cPagedRead  coef read 3610
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3614 ); // i2cPagedRead  coef write 3614
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0d00 i2c data 0x0d01
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130d, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3625 ); // i2cPagedRead  coef read 3625
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3629 ); // i2cPagedRead  coef write 3629
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3633 ); // i2cPagedRead  coef write 3633
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3637 ); // i2cPagedRead  coef write 3637
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3641 ); // i2cPagedRead  coef read 3641
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0d00, 0x00000000, 3645 ); // i2cPagedRead  coef write 3645
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3649 ); // i2cPagedRead  coef read 3649
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3653 ); // i2cPagedRead  coef read 3653
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000d01, 3657 ); // i2cPagedRead  coef read 3657
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3661 ); // i2cPagedRead  coef read 3661
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3665 ); // i2cPagedRead  coef write 3665
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0e00 i2c data 0x0e00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130e, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3676 ); // i2cPagedRead  coef read 3676
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3680 ); // i2cPagedRead  coef write 3680
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3684 ); // i2cPagedRead  coef write 3684
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3688 ); // i2cPagedRead  coef write 3688
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3692 ); // i2cPagedRead  coef read 3692
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0e00, 0x00000000, 3696 ); // i2cPagedRead  coef write 3696
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3700 ); // i2cPagedRead  coef read 3700
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3704 ); // i2cPagedRead  coef read 3704
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000e00, 3708 ); // i2cPagedRead  coef read 3708
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3712 ); // i2cPagedRead  coef read 3712
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3716 ); // i2cPagedRead  coef write 3716
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0800 i2c data 0x0801
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1308, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3727 ); // i2cPagedRead  coef read 3727
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3731 ); // i2cPagedRead  coef write 3731
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3735 ); // i2cPagedRead  coef write 3735
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3739 ); // i2cPagedRead  coef write 3739
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3743 ); // i2cPagedRead  coef read 3743
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0800, 0x00000000, 3747 ); // i2cPagedRead  coef write 3747
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3751 ); // i2cPagedRead  coef read 3751
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3755 ); // i2cPagedRead  coef read 3755
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000801, 3759 ); // i2cPagedRead  coef read 3759
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3763 ); // i2cPagedRead  coef read 3763
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3767 ); // i2cPagedRead  coef write 3767
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0f00 i2c data 0x0f00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3778 ); // i2cPagedRead  coef read 3778
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3782 ); // i2cPagedRead  coef write 3782
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3786 ); // i2cPagedRead  coef write 3786
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3790 ); // i2cPagedRead  coef write 3790
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3794 ); // i2cPagedRead  coef read 3794
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0f00, 0x00000000, 3798 ); // i2cPagedRead  coef write 3798
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3802 ); // i2cPagedRead  coef read 3802
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3806 ); // i2cPagedRead  coef read 3806
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000f00, 3810 ); // i2cPagedRead  coef read 3810
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3814 ); // i2cPagedRead  coef read 3814
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3818 ); // i2cPagedRead  coef write 3818
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x01ff
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3829 ); // i2cPagedRead  coef read 3829
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3833 ); // i2cPagedRead  coef write 3833
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3837 ); // i2cPagedRead  coef write 3837
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 3841 ); // i2cPagedRead  coef write 3841
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3845 ); // i2cPagedRead  coef read 3845
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 3849 ); // i2cPagedRead  coef write 3849
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3853 ); // i2cPagedRead  coef read 3853
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3857 ); // i2cPagedRead  coef read 3857
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x000001ff, 3861 ); // i2cPagedRead  coef read 3861
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3865 ); // i2cPagedRead  coef read 3865
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3869 ); // i2cPagedRead  coef write 3869
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x01fe i2c data 0x00fe
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x00fe, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3880 ); // i2cPagedWrite  coef read 3880
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3884 ); // i2cPagedWrite  coef write 3884
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3888 ); // i2cPagedWrite  coef write 3888
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 3892 ); // i2cPagedWrite  coef write 3892
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3896 ); // i2cPagedWrite  coef read 3896
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3900 ); // i2cPagedWrite  coef read 3900
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x01fe, 0x00000000, 3904 ); // i2cPagedWrite  coef write 3904
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3908 ); // i2cPagedWrite  coef read 3908
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3912 ); // i2cPagedWrite  coef read 3912
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3916 ); // i2cPagedWrite  coef read 3916
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3920 ); // i2cPagedWrite  coef write 3920
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x751f
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3931 ); // i2cPagedRead  coef read 3931
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3935 ); // i2cPagedRead  coef write 3935
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3939 ); // i2cPagedRead  coef write 3939
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 3943 ); // i2cPagedRead  coef write 3943
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3947 ); // i2cPagedRead  coef read 3947
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7500, 0x00000000, 3951 ); // i2cPagedRead  coef write 3951
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3955 ); // i2cPagedRead  coef read 3955
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3959 ); // i2cPagedRead  coef read 3959
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000751f, 3963 ); // i2cPagedRead  coef read 3963
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3967 ); // i2cPagedRead  coef read 3967
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3971 ); // i2cPagedRead  coef write 3971
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x759f i2c data 0x009f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x009f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3982 ); // i2cPagedWrite  coef read 3982
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3986 ); // i2cPagedWrite  coef write 3986
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3990 ); // i2cPagedWrite  coef write 3990
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 3994 ); // i2cPagedWrite  coef write 3994
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3998 ); // i2cPagedWrite  coef read 3998
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4002 ); // i2cPagedWrite  coef read 4002
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x759f, 0x00000000, 4006 ); // i2cPagedWrite  coef write 4006
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4010 ); // i2cPagedWrite  coef read 4010
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4014 ); // i2cPagedWrite  coef read 4014
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4018 ); // i2cPagedWrite  coef read 4018
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4022 ); // i2cPagedWrite  coef write 4022
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_amps(struct hda_codec *codec)
{
        int retval;

        // again - this seems to be adding 0x020 to the existing 0x02 pin
        // assuming is associated with amps based on following i2c calls

        // this could be setting gpio 6 which based on info from bugs 195671 and 110561
        // is the SCLK of the local i2c bus 

        // so this done before each ampflier software reset

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000022);
//      snd_hda:     gpio direction 1 0x22 in in out in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000022);
//      snd_hda:     gpio data 1 0x22
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000027);
//      snd_hda:     gpio enable 1 0x27

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        // based on info from bugs 195671 and 110561
        // and that writing to coef index 0x59 seems to be the i2c address hence the i2c address following are
        // the amps 62, 64, 72, 74
        // also the data being sent does correpond to the registers of the MAX98372 from data sheet
        // which is supposedly similar to the actual MAX98706
        // all analysis of the i2cWrite data is based on the MAX98372 data sheet

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0051, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4043 ); // i2cWrite  coef read 4043
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4047 ); // i2cWrite  coef write 4047
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 4051 ); // i2cWrite  coef write 4051
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5101, 0x00000000, 4055 ); // i2cWrite  coef write 4055
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4059 ); // i2cWrite  coef read 4059
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4063 ); // i2cWrite  coef read 4063
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4067 ); // i2cWrite  coef read 4067
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4071 ); // i2cWrite  coef write 4071
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000022);
//      snd_hda:     gpio direction 1 0x22 in in out in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000022);
//      snd_hda:     gpio data 1 0x22
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000027);
//      snd_hda:     gpio enable 1 0x27

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0051, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4092 ); // i2cWrite  coef read 4092
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4096 ); // i2cWrite  coef write 4096
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 4100 ); // i2cWrite  coef write 4100
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5101, 0x00000000, 4104 ); // i2cWrite  coef write 4104
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4108 ); // i2cWrite  coef read 4108
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4112 ); // i2cWrite  coef read 4112
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4116 ); // i2cWrite  coef read 4116
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4120 ); // i2cWrite  coef write 4120
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000022);
//      snd_hda:     gpio direction 1 0x22 in in out in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000022);
//      snd_hda:     gpio data 1 0x22
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000027);
//      snd_hda:     gpio enable 1 0x27

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0051, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4141 ); // i2cWrite  coef read 4141
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4145 ); // i2cWrite  coef write 4145
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 4149 ); // i2cWrite  coef write 4149
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5101, 0x00000000, 4153 ); // i2cWrite  coef write 4153
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4157 ); // i2cWrite  coef read 4157
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4161 ); // i2cWrite  coef read 4161
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4165 ); // i2cWrite  coef read 4165
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4169 ); // i2cWrite  coef write 4169
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000022);
//      snd_hda:     gpio direction 1 0x22 in in out in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000022);
//      snd_hda:     gpio data 1 0x22
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000027);
//      snd_hda:     gpio enable 1 0x27

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0051, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4190 ); // i2cWrite  coef read 4190
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4194 ); // i2cWrite  coef write 4194
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 4198 ); // i2cWrite  coef write 4198
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5101, 0x00000000, 4202 ); // i2cWrite  coef write 4202
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4206 ); // i2cWrite  coef read 4206
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4210 ); // i2cWrite  coef read 4210
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4214 ); // i2cWrite  coef read 4214
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4218 ); // i2cWrite  coef write 4218
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void putative_setup_mic2(struct hda_codec *codec)
{
        int retval;

	// on osx this performs the GET_GPIO_DATA in power down state

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000027, 4224);
//      snd_hda:     gpio data 1 0x27


        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

        // on OSX each major function seems to power up at beginning and power down at end
	// except here we just seem to check if powered up between these i2cPagedRead/Write calls

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x759f
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4232 ); // i2cPagedRead  coef read 4232
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4236 ); // i2cPagedRead  coef write 4236
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4240 ); // i2cPagedRead  coef write 4240
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4244 ); // i2cPagedRead  coef write 4244
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4248 ); // i2cPagedRead  coef read 4248
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7500, 0x00000000, 4252 ); // i2cPagedRead  coef write 4252
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4256 ); // i2cPagedRead  coef read 4256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4260 ); // i2cPagedRead  coef read 4260
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000759f, 4264 ); // i2cPagedRead  coef read 4264
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4268 ); // i2cPagedRead  coef read 4268
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4272 ); // i2cPagedRead  coef write 4272
//      snd_hda i2cPagedRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4276);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4277);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x759f i2c data 0x009f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x009f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4279 ); // i2cPagedWrite  coef read 4279
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4283 ); // i2cPagedWrite  coef write 4283
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4287 ); // i2cPagedWrite  coef write 4287
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4291 ); // i2cPagedWrite  coef write 4291
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4295 ); // i2cPagedWrite  coef read 4295
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4299 ); // i2cPagedWrite  coef read 4299
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x759f, 0x00000000, 4303 ); // i2cPagedWrite  coef write 4303
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4307 ); // i2cPagedWrite  coef read 4307
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4311 ); // i2cPagedWrite  coef read 4311
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4315 ); // i2cPagedWrite  coef read 4315
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4319 ); // i2cPagedWrite  coef write 4319
//      snd_hda i2cPagedWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4276);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4277);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7300 i2c data 0x7302
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b73, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4326 ); // i2cPagedRead  coef read 4326
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4330 ); // i2cPagedRead  coef write 4330
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4334 ); // i2cPagedRead  coef write 4334
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4338 ); // i2cPagedRead  coef write 4338
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4342 ); // i2cPagedRead  coef read 4342
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7300, 0x00000000, 4346 ); // i2cPagedRead  coef write 4346
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4350 ); // i2cPagedRead  coef read 4350
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4354 ); // i2cPagedRead  coef read 4354
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007302, 4358 ); // i2cPagedRead  coef read 4358
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4362 ); // i2cPagedRead  coef read 4362
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4366 ); // i2cPagedRead  coef write 4366
//      snd_hda i2cPagedRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4276);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4277);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x73c0 i2c data 0x00c0
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b73, 0x00c0, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4373 ); // i2cPagedWrite  coef read 4373
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4377 ); // i2cPagedWrite  coef write 4377
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4381 ); // i2cPagedWrite  coef write 4381
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4385 ); // i2cPagedWrite  coef write 4385
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4389 ); // i2cPagedWrite  coef read 4389
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4393 ); // i2cPagedWrite  coef read 4393
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x73c0, 0x00000000, 4397 ); // i2cPagedWrite  coef write 4397
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4401 ); // i2cPagedWrite  coef read 4401
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4405 ); // i2cPagedWrite  coef read 4405
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4409 ); // i2cPagedWrite  coef read 4409
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4413 ); // i2cPagedWrite  coef write 4413
//      snd_hda i2cPagedWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4276);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4277);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7b00 i2c data 0x7b60
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4420 ); // i2cPagedRead  coef read 4420
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4424 ); // i2cPagedRead  coef write 4424
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4428 ); // i2cPagedRead  coef write 4428
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4432 ); // i2cPagedRead  coef write 4432
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4436 ); // i2cPagedRead  coef read 4436
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7b00, 0x00000000, 4440 ); // i2cPagedRead  coef write 4440
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4444 ); // i2cPagedRead  coef read 4444
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4448 ); // i2cPagedRead  coef read 4448
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007b60, 4452 ); // i2cPagedRead  coef read 4452
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4456 ); // i2cPagedRead  coef read 4456
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4460 ); // i2cPagedRead  coef write 4460
//      snd_hda i2cPagedRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4276);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4277);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7900 i2c data 0x79e0
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b79, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4467 ); // i2cPagedRead  coef read 4467
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4471 ); // i2cPagedRead  coef write 4471
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4475 ); // i2cPagedRead  coef write 4475
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4479 ); // i2cPagedRead  coef write 4479
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4483 ); // i2cPagedRead  coef read 4483
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7900, 0x00000000, 4487 ); // i2cPagedRead  coef write 4487
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4491 ); // i2cPagedRead  coef read 4491
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4495 ); // i2cPagedRead  coef read 4495
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x000079e0, 4499 ); // i2cPagedRead  coef read 4499
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4503 ); // i2cPagedRead  coef read 4503
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4507 ); // i2cPagedRead  coef write 4507
//      snd_hda i2cPagedRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4276);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4277);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x79a0 i2c data 0x00a0
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b79, 0x00a0, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4514 ); // i2cPagedWrite  coef read 4514
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4518 ); // i2cPagedWrite  coef write 4518
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4522 ); // i2cPagedWrite  coef write 4522
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4526 ); // i2cPagedWrite  coef write 4526
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4530 ); // i2cPagedWrite  coef read 4530
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4534 ); // i2cPagedWrite  coef read 4534
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x79a0, 0x00000000, 4538 ); // i2cPagedWrite  coef write 4538
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4542 ); // i2cPagedWrite  coef read 4542
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4546 ); // i2cPagedWrite  coef read 4546
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4550 ); // i2cPagedWrite  coef read 4550
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4554 ); // i2cPagedWrite  coef write 4554
//      snd_hda i2cPagedWrite end

	// weird - multiple power down/ups
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4603 ); // i2cPagedRead  coef read 4603
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4607 ); // i2cPagedRead  coef write 4607
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4611 ); // i2cPagedRead  coef write 4611
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4615 ); // i2cPagedRead  coef write 4615
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4619 ); // i2cPagedRead  coef read 4619
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 4623 ); // i2cPagedRead  coef write 4623
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4627 ); // i2cPagedRead  coef read 4627
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4631 ); // i2cPagedRead  coef read 4631
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 4635 ); // i2cPagedRead  coef read 4635
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4639 ); // i2cPagedRead  coef read 4639
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4643 ); // i2cPagedRead  coef write 4643
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_jack_nids(struct hda_codec *codec)
{
        int retval;

        int retgain1;
        int retgain2;


        // so this is clearly setting up for audio

        // this works on nids 0x22, 0x23, and 0x44, 0x45

        // these I think are the line in/headphone socket nids

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // so first seems to be the channels through node 0x22

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031);
//      snd_hda:     stream format 34 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4663);
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 4666);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4669);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);

        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4670);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // so the following is being done with node 0x22 powered down!!

//      snd_hda: # AppleHDAWidgetCS8409::setConnectionSelect: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x00000013, 4671 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef read 4671
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0009, 0x0033, 0x00000000, 4675 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef write 4675
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CONNECT_SEL, 0x00000000);

        retgain1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 4680);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7);
//      snd_hda:     amp gain/mute 34 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 4682);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7);
//      snd_hda:     amp gain/mute 34 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 4684);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7);
//      snd_hda:     amp gain/mute 34 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 4686);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7);
//      snd_hda:     amp gain/mute 34 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input


        // this is working on node 0x44

        retgain1 = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 4688);
//      snd_hda:     amp gain/mute 68 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 68 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006000);
//      snd_hda:     amp gain/mute 68 0x6000 mute 0 gain 0x0 0 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 4690);
//      snd_hda:     amp gain/mute 68 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 68 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005000);
//      snd_hda:     amp gain/mute 68 0x5000 mute 0 gain 0x0 0 index 0x00 left 0 right 1 output 0 input 1  right  input


        // I think this is for node 0x44

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 4692 ); //   coef read 4692
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00000000, 4696 ); //   coef write 4696

        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 4700);
        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020);
//      snd_hda:     68 ['AC_PINCTL_IN_EN']


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


	// and redo the stream format???
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031);
//      snd_hda:     stream format 34 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

	 // followed by channels for node 0x23

        retgain1 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 4710);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7);
//      snd_hda:     amp gain/mute 35 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 4712);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7);
//      snd_hda:     amp gain/mute 35 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 4714);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7);
//      snd_hda:     amp gain/mute 35 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 4716);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7);
//      snd_hda:     amp gain/mute 35 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 4718);
//      snd_hda:     amp gain/mute 69 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 69 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006000);
//      snd_hda:     amp gain/mute 69 0x6000 mute 0 gain 0x0 0 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 4720);
//      snd_hda:     amp gain/mute 69 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 69 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005000);
//      snd_hda:     amp gain/mute 69 0x5000 mute 0 gain 0x0 0 index 0x00 left 0 right 1 output 0 input 1  right  input

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4722);
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 4725);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4728);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);

        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 35 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]


        // and a sneaky node 0x45 here

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000001, 4731 ); //   coef read 4731
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00000000, 4735 ); //   coef write 4735

        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 4739);
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     69 []


        // more node 0x22, 0x23 setups
        // this does seem to repeat the above
        // except the gain is slightly different

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 4742);
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4743);
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 4746);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4749);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0x00000033, 4751 ); // coef write mask 4751
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0xundef, 0x00000033, 4751 ); // coef write mask 4751


        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 4757);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4758);
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 4761);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4764);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0x00000033, 4766 ); // coef write mask 4766
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0xundef, 0x00000033, 4766 ); // coef write mask 4766


        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4772);
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 4775);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4778);
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4780);
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 4783);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4786);
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retgain1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 4796);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3);
//      snd_hda:     amp gain/mute 34 0x60b3 mute 1 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 4798);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3);
//      snd_hda:     amp gain/mute 34 0x50b3 mute 1 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 4800);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3);
//      snd_hda:     amp gain/mute 35 0x60b3 mute 1 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 4802);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3);
//      snd_hda:     amp gain/mute 35 0x50b3 mute 1 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 4805);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 4807);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 4809);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 35 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 4811);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 35 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_TDM(struct hda_codec *codec)
{
        int retval;

        // so this seems to be where we see the same code as in unmute and volup
        // - note that code structure is similar but detail differences exist
        // eg 0x083f below is 0x08ff in the unmute/volup stage

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // why is this here??
        // this sets the input nid 0x02 (but not 0x03)

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]
        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]


        // so apple seems to convert all input audio to 4 channel, 44.1 kHz, 24 bits per channel with higher level processing
        // (as seen from node 0x2, 0x3 setups)
        // the digital data is streamed over the PCI bus to the 8409 HDA where its converted to a digital TDM stream over
        // the interal i2c bus to the amplifiers
        // the following seems to be setting up the TDM conversion by coef writes to the vendor node

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 4823 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4823
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 4827 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4827
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008000, 4831 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4831
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 4835 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4835
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008000, 4839 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4839
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 4843 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4843
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4847 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4847
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 4851 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4851
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x0000083f, 4855 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4855
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x083f, 0x00000000, 4859 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4859
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4863 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4863

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x0000801f, 4867 ); // coef write mask 4867
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x0000801f, 4867 ); // coef write mask 4867
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0000, 0x00000000, 4873 ); // coef write mask 4873
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0000, 0xundef, 0x00000000, 4873 ); // coef write mask 4873
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 4879 ); // coef write mask 4879
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 4879 ); // coef write mask 4879
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000080, 4885 ); // coef write mask 4885
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000080, 4885 ); // coef write mask 4885


        // this seems to be setup for node 0x02 chain - which seems to use node 0x24 and amps 0x64 and 0x62

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 4891 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4891
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0020, 0x00000000, 4895 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4895

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 4899 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4899

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 4904 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 4904
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 4908 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 4908
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 4912 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 4912

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 4915

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000020, 4920 ); // coef write mask 4920
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000020, 4920 ); // coef write mask 4920
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000000, 4926 ); // coef write mask 4926
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000000, 4926 ); // coef write mask 4926
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x0000083f, 4932 ); // coef write mask 4932
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x0000083f, 4932 ); // coef write mask 4932


        // this enables node 0x24 output

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 4939);
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']


        // and redo the amplifier setup

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4943 ); // i2cWrite  coef read 4943
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4947 ); // i2cWrite  coef write 4947
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 4951 ); // i2cWrite  coef write 4951
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 4955 ); // i2cWrite  coef write 4955
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4959 ); // i2cWrite  coef read 4959
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4963 ); // i2cWrite  coef read 4963
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4967 ); // i2cWrite  coef read 4967
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4971 ); // i2cWrite  coef write 4971
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4978 ); // i2cWrite  coef read 4978
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4982 ); // i2cWrite  coef write 4982
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 4986 ); // i2cWrite  coef write 4986
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 4990 ); // i2cWrite  coef write 4990
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4994 ); // i2cWrite  coef read 4994
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4998 ); // i2cWrite  coef read 4998
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5002 ); // i2cWrite  coef read 5002
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5006 ); // i2cWrite  coef write 5006
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1501 i2c data 0x0001   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0015, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5013 ); // i2cWrite  coef read 5013
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5017 ); // i2cWrite  coef write 5017
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5021 ); // i2cWrite  coef write 5021
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1501, 0x00000000, 5025 ); // i2cWrite  coef write 5025
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5029 ); // i2cWrite  coef read 5029
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5033 ); // i2cWrite  coef read 5033
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5037 ); // i2cWrite  coef read 5037
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5041 ); // i2cWrite  coef write 5041
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5048 ); // i2cWrite  coef read 5048
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5052 ); // i2cWrite  coef write 5052
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5056 ); // i2cWrite  coef write 5056
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 5060 ); // i2cWrite  coef write 5060
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5064 ); // i2cWrite  coef read 5064
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5068 ); // i2cWrite  coef read 5068
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5072 ); // i2cWrite  coef read 5072
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5076 ); // i2cWrite  coef write 5076
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1800 i2c data 0x0000   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0018, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5083 ); // i2cWrite  coef read 5083
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5087 ); // i2cWrite  coef write 5087
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5091 ); // i2cWrite  coef write 5091
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1800, 0x00000000, 5095 ); // i2cWrite  coef write 5095
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5099 ); // i2cWrite  coef read 5099
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5103 ); // i2cWrite  coef read 5103
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5107 ); // i2cWrite  coef read 5107
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5111 ); // i2cWrite  coef write 5111
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5118 ); // i2cWrite  coef read 5118
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5122 ); // i2cWrite  coef write 5122
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5126 ); // i2cWrite  coef write 5126
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 5130 ); // i2cWrite  coef write 5130
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5134 ); // i2cWrite  coef read 5134
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5138 ); // i2cWrite  coef read 5138
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5142 ); // i2cWrite  coef read 5142
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5146 ); // i2cWrite  coef write 5146
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5153 ); // i2cWrite  coef read 5153
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5157 ); // i2cWrite  coef write 5157
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5161 ); // i2cWrite  coef write 5161
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 5165 ); // i2cWrite  coef write 5165
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5169 ); // i2cWrite  coef read 5169
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5173 ); // i2cWrite  coef read 5173
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5177 ); // i2cWrite  coef read 5177
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5181 ); // i2cWrite  coef write 5181
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5188 ); // i2cWrite  coef read 5188
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5192 ); // i2cWrite  coef write 5192
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5196 ); // i2cWrite  coef write 5196
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 5200 ); // i2cWrite  coef write 5200
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5204 ); // i2cWrite  coef read 5204
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5208 ); // i2cWrite  coef read 5208
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5212 ); // i2cWrite  coef read 5212
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5216 ); // i2cWrite  coef write 5216
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5223 ); // i2cWrite  coef read 5223
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5227 ); // i2cWrite  coef write 5227
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5231 ); // i2cWrite  coef write 5231
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 5235 ); // i2cWrite  coef write 5235
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5239 ); // i2cWrite  coef read 5239
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5243 ); // i2cWrite  coef read 5243
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5247 ); // i2cWrite  coef read 5247
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5251 ); // i2cWrite  coef write 5251
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5258 ); // i2cWrite  coef read 5258
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5262 ); // i2cWrite  coef write 5262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5266 ); // i2cWrite  coef write 5266
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 5270 ); // i2cWrite  coef write 5270
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5274 ); // i2cWrite  coef read 5274
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5278 ); // i2cWrite  coef read 5278
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5282 ); // i2cWrite  coef read 5282
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5286 ); // i2cWrite  coef write 5286
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5293 ); // i2cWrite  coef read 5293
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5297 ); // i2cWrite  coef write 5297
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5301 ); // i2cWrite  coef write 5301
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 5305 ); // i2cWrite  coef write 5305
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5309 ); // i2cWrite  coef read 5309
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5313 ); // i2cWrite  coef read 5313
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5317 ); // i2cWrite  coef read 5317
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5321 ); // i2cWrite  coef write 5321
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x1100 i2c data 0x1108   reg anal: PCMSampleSetup          : 48kHz
        //cs_8409_vendor_i2cRead(codec, 0x64, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5328 ); // i2cRead  coef read 5328
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5332 ); // i2cRead  coef write 5332
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5336 ); // i2cRead  coef write 5336
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 5340 ); // i2cRead  coef write 5340
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5344 ); // i2cRead  coef read 5344
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5348 ); // i2cRead  coef read 5348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001108, 5352 ); // i2cRead  coef read 5352
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5356 ); // i2cRead  coef read 5356
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5360 ); // i2cRead  coef write 5360
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5367 ); // i2cWrite  coef read 5367
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5371 ); // i2cWrite  coef write 5371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 5375 ); // i2cWrite  coef write 5375
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 5379 ); // i2cWrite  coef write 5379
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5383 ); // i2cWrite  coef read 5383
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5387 ); // i2cWrite  coef read 5387
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5391 ); // i2cWrite  coef read 5391
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5395 ); // i2cWrite  coef write 5395
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5402 ); // i2cWrite  coef read 5402
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5406 ); // i2cWrite  coef write 5406
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5410 ); // i2cWrite  coef write 5410
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 5414 ); // i2cWrite  coef write 5414
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5418 ); // i2cWrite  coef read 5418
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5422 ); // i2cWrite  coef read 5422
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5426 ); // i2cWrite  coef read 5426
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5430 ); // i2cWrite  coef write 5430
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5437 ); // i2cWrite  coef read 5437
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5441 ); // i2cWrite  coef write 5441
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5445 ); // i2cWrite  coef write 5445
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 5449 ); // i2cWrite  coef write 5449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5453 ); // i2cWrite  coef read 5453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5457 ); // i2cWrite  coef read 5457
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5461 ); // i2cWrite  coef read 5461
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5465 ); // i2cWrite  coef write 5465
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1502 i2c data 0x0002   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0015, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5472 ); // i2cWrite  coef read 5472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5476 ); // i2cWrite  coef write 5476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5480 ); // i2cWrite  coef write 5480
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1502, 0x00000000, 5484 ); // i2cWrite  coef write 5484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5488 ); // i2cWrite  coef read 5488
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5492 ); // i2cWrite  coef read 5492
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5496 ); // i2cWrite  coef read 5496
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5500 ); // i2cWrite  coef write 5500
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5507 ); // i2cWrite  coef read 5507
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5511 ); // i2cWrite  coef write 5511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5515 ); // i2cWrite  coef write 5515
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 5519 ); // i2cWrite  coef write 5519
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5523 ); // i2cWrite  coef read 5523
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5527 ); // i2cWrite  coef read 5527
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5531 ); // i2cWrite  coef read 5531
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5535 ); // i2cWrite  coef write 5535
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1801 i2c data 0x0001   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0018, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5542 ); // i2cWrite  coef read 5542
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5546 ); // i2cWrite  coef write 5546
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5550 ); // i2cWrite  coef write 5550
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1801, 0x00000000, 5554 ); // i2cWrite  coef write 5554
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5558 ); // i2cWrite  coef read 5558
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5562 ); // i2cWrite  coef read 5562
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5566 ); // i2cWrite  coef read 5566
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5570 ); // i2cWrite  coef write 5570
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5577 ); // i2cWrite  coef read 5577
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5581 ); // i2cWrite  coef write 5581
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5585 ); // i2cWrite  coef write 5585
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 5589 ); // i2cWrite  coef write 5589
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5593 ); // i2cWrite  coef read 5593
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5597 ); // i2cWrite  coef read 5597
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5601 ); // i2cWrite  coef read 5601
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5605 ); // i2cWrite  coef write 5605
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5612 ); // i2cWrite  coef read 5612
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5616 ); // i2cWrite  coef write 5616
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5620 ); // i2cWrite  coef write 5620
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 5624 ); // i2cWrite  coef write 5624
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5628 ); // i2cWrite  coef read 5628
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5632 ); // i2cWrite  coef read 5632
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5636 ); // i2cWrite  coef read 5636
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5640 ); // i2cWrite  coef write 5640
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5647 ); // i2cWrite  coef read 5647
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5651 ); // i2cWrite  coef write 5651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5655 ); // i2cWrite  coef write 5655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 5659 ); // i2cWrite  coef write 5659
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5663 ); // i2cWrite  coef read 5663
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5667 ); // i2cWrite  coef read 5667
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5671 ); // i2cWrite  coef read 5671
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5675 ); // i2cWrite  coef write 5675
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5682 ); // i2cWrite  coef read 5682
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5686 ); // i2cWrite  coef write 5686
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5690 ); // i2cWrite  coef write 5690
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 5694 ); // i2cWrite  coef write 5694
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5698 ); // i2cWrite  coef read 5698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5702 ); // i2cWrite  coef read 5702
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5706 ); // i2cWrite  coef read 5706
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5710 ); // i2cWrite  coef write 5710
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5717 ); // i2cWrite  coef read 5717
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5721 ); // i2cWrite  coef write 5721
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5725 ); // i2cWrite  coef write 5725
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 5729 ); // i2cWrite  coef write 5729
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5733 ); // i2cWrite  coef read 5733
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5737 ); // i2cWrite  coef read 5737
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5741 ); // i2cWrite  coef read 5741
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5745 ); // i2cWrite  coef write 5745
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5752 ); // i2cWrite  coef read 5752
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5756 ); // i2cWrite  coef write 5756
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5760 ); // i2cWrite  coef write 5760
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 5764 ); // i2cWrite  coef write 5764
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5768 ); // i2cWrite  coef read 5768
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5772 ); // i2cWrite  coef read 5772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5776 ); // i2cWrite  coef read 5776
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5780 ); // i2cWrite  coef write 5780
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x62 i2c            reg 0x1100 i2c data 0x1108   reg anal: PCMSampleSetup          : 48kHz
        //cs_8409_vendor_i2cRead(codec, 0x62, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5787 ); // i2cRead  coef read 5787
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5791 ); // i2cRead  coef write 5791
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5795 ); // i2cRead  coef write 5795
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 5799 ); // i2cRead  coef write 5799
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5803 ); // i2cRead  coef read 5803
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5807 ); // i2cRead  coef read 5807
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001108, 5811 ); // i2cRead  coef read 5811
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5815 ); // i2cRead  coef read 5815
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5819 ); // i2cRead  coef write 5819
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5826 ); // i2cWrite  coef read 5826
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5830 ); // i2cWrite  coef write 5830
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 5834 ); // i2cWrite  coef write 5834
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 5838 ); // i2cWrite  coef write 5838
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5842 ); // i2cWrite  coef read 5842
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5846 ); // i2cWrite  coef read 5846
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5850 ); // i2cWrite  coef read 5850
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5854 ); // i2cWrite  coef write 5854
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 4975);


        // this seems to be setup for node 0x03 chain - which seems to use node 0x25 and amps 0x74 and 0x72

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]
        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000002);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 0)]

        // the following 4 lines are different to that of node 0x02

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008000, 5862 ); //   coef read 5862
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 5866 ); //   coef write 5866
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008000, 5870 ); //   coef read 5870
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 5874 ); //   coef write 5874

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 5878 ); //   coef read 5878

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 5883 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 5883
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 5887 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 5887
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 5891 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 5891

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 5894


        // enable output on node 0x25 

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 5900);
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']


//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5904 ); // i2cWrite  coef read 5904
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5908 ); // i2cWrite  coef write 5908
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 5912 ); // i2cWrite  coef write 5912
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 5916 ); // i2cWrite  coef write 5916
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5920 ); // i2cWrite  coef read 5920
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5924 ); // i2cWrite  coef read 5924
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5928 ); // i2cWrite  coef read 5928
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5932 ); // i2cWrite  coef write 5932
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5939 ); // i2cWrite  coef read 5939
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5943 ); // i2cWrite  coef write 5943
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 5947 ); // i2cWrite  coef write 5947
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 5951 ); // i2cWrite  coef write 5951
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5955 ); // i2cWrite  coef read 5955
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5959 ); // i2cWrite  coef read 5959
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5963 ); // i2cWrite  coef read 5963
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5967 ); // i2cWrite  coef write 5967
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1504 i2c data 0x0004   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0015, 0x0004, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5974 ); // i2cWrite  coef read 5974
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5978 ); // i2cWrite  coef write 5978
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 5982 ); // i2cWrite  coef write 5982
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1504, 0x00000000, 5986 ); // i2cWrite  coef write 5986
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5990 ); // i2cWrite  coef read 5990
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5994 ); // i2cWrite  coef read 5994
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5998 ); // i2cWrite  coef read 5998
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6002 ); // i2cWrite  coef write 6002
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6009 ); // i2cWrite  coef read 6009
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6013 ); // i2cWrite  coef write 6013
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6017 ); // i2cWrite  coef write 6017
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 6021 ); // i2cWrite  coef write 6021
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6025 ); // i2cWrite  coef read 6025
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6029 ); // i2cWrite  coef read 6029
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6033 ); // i2cWrite  coef read 6033
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6037 ); // i2cWrite  coef write 6037
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1802 i2c data 0x0002   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0018, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6044 ); // i2cWrite  coef read 6044
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6048 ); // i2cWrite  coef write 6048
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6052 ); // i2cWrite  coef write 6052
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1802, 0x00000000, 6056 ); // i2cWrite  coef write 6056
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6060 ); // i2cWrite  coef read 6060
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6064 ); // i2cWrite  coef read 6064
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6068 ); // i2cWrite  coef read 6068
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6072 ); // i2cWrite  coef write 6072
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6079 ); // i2cWrite  coef read 6079
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6083 ); // i2cWrite  coef write 6083
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6087 ); // i2cWrite  coef write 6087
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 6091 ); // i2cWrite  coef write 6091
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6095 ); // i2cWrite  coef read 6095
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6099 ); // i2cWrite  coef read 6099
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6103 ); // i2cWrite  coef read 6103
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6107 ); // i2cWrite  coef write 6107
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6114 ); // i2cWrite  coef read 6114
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6118 ); // i2cWrite  coef write 6118
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6122 ); // i2cWrite  coef write 6122
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 6126 ); // i2cWrite  coef write 6126
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6130 ); // i2cWrite  coef read 6130
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6134 ); // i2cWrite  coef read 6134
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6138 ); // i2cWrite  coef read 6138
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6142 ); // i2cWrite  coef write 6142
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6149 ); // i2cWrite  coef read 6149
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6153 ); // i2cWrite  coef write 6153
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6157 ); // i2cWrite  coef write 6157
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 6161 ); // i2cWrite  coef write 6161
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6165 ); // i2cWrite  coef read 6165
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6169 ); // i2cWrite  coef read 6169
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6173 ); // i2cWrite  coef read 6173
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6177 ); // i2cWrite  coef write 6177
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6184 ); // i2cWrite  coef read 6184
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6188 ); // i2cWrite  coef write 6188
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6192 ); // i2cWrite  coef write 6192
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 6196 ); // i2cWrite  coef write 6196
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6200 ); // i2cWrite  coef read 6200
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6204 ); // i2cWrite  coef read 6204
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6208 ); // i2cWrite  coef read 6208
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6212 ); // i2cWrite  coef write 6212
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6219 ); // i2cWrite  coef read 6219
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6223 ); // i2cWrite  coef write 6223
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6227 ); // i2cWrite  coef write 6227
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 6231 ); // i2cWrite  coef write 6231
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6235 ); // i2cWrite  coef read 6235
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6239 ); // i2cWrite  coef read 6239
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6243 ); // i2cWrite  coef read 6243
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6247 ); // i2cWrite  coef write 6247
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6254 ); // i2cWrite  coef read 6254
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6258 ); // i2cWrite  coef write 6258
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6262 ); // i2cWrite  coef write 6262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 6266 ); // i2cWrite  coef write 6266
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6270 ); // i2cWrite  coef read 6270
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6274 ); // i2cWrite  coef read 6274
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6278 ); // i2cWrite  coef read 6278
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6282 ); // i2cWrite  coef write 6282
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x74 i2c            reg 0x1100 i2c data 0x1108   reg anal: PCMSampleSetup          : 48kHz
        //cs_8409_vendor_i2cRead(codec, 0x74, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6289 ); // i2cRead  coef read 6289
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6293 ); // i2cRead  coef write 6293
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6297 ); // i2cRead  coef write 6297
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 6301 ); // i2cRead  coef write 6301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6305 ); // i2cRead  coef read 6305
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6309 ); // i2cRead  coef read 6309
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001108, 6313 ); // i2cRead  coef read 6313
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6317 ); // i2cRead  coef read 6317
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6321 ); // i2cRead  coef write 6321
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6328 ); // i2cWrite  coef read 6328
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6332 ); // i2cWrite  coef write 6332
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 6336 ); // i2cWrite  coef write 6336
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 6340 ); // i2cWrite  coef write 6340
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6344 ); // i2cWrite  coef read 6344
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6348 ); // i2cWrite  coef read 6348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6352 ); // i2cWrite  coef read 6352
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6356 ); // i2cWrite  coef write 6356
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6363 ); // i2cWrite  coef read 6363
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6367 ); // i2cWrite  coef write 6367
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6371 ); // i2cWrite  coef write 6371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 6375 ); // i2cWrite  coef write 6375
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6379 ); // i2cWrite  coef read 6379
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6383 ); // i2cWrite  coef read 6383
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6387 ); // i2cWrite  coef read 6387
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6391 ); // i2cWrite  coef write 6391
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6398 ); // i2cWrite  coef read 6398
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6402 ); // i2cWrite  coef write 6402
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6406 ); // i2cWrite  coef write 6406
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 6410 ); // i2cWrite  coef write 6410
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6414 ); // i2cWrite  coef read 6414
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6418 ); // i2cWrite  coef read 6418
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6422 ); // i2cWrite  coef read 6422
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6426 ); // i2cWrite  coef write 6426
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1508 i2c data 0x0008   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0015, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6433 ); // i2cWrite  coef read 6433
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6437 ); // i2cWrite  coef write 6437
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6441 ); // i2cWrite  coef write 6441
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1508, 0x00000000, 6445 ); // i2cWrite  coef write 6445
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6449 ); // i2cWrite  coef read 6449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6453 ); // i2cWrite  coef read 6453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6457 ); // i2cWrite  coef read 6457
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6461 ); // i2cWrite  coef write 6461
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6468 ); // i2cWrite  coef read 6468
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6472 ); // i2cWrite  coef write 6472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6476 ); // i2cWrite  coef write 6476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 6480 ); // i2cWrite  coef write 6480
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6484 ); // i2cWrite  coef read 6484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6488 ); // i2cWrite  coef read 6488
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6492 ); // i2cWrite  coef read 6492
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6496 ); // i2cWrite  coef write 6496
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1803 i2c data 0x0003   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0018, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6503 ); // i2cWrite  coef read 6503
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6507 ); // i2cWrite  coef write 6507
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6511 ); // i2cWrite  coef write 6511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1803, 0x00000000, 6515 ); // i2cWrite  coef write 6515
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6519 ); // i2cWrite  coef read 6519
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6523 ); // i2cWrite  coef read 6523
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6527 ); // i2cWrite  coef read 6527
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6531 ); // i2cWrite  coef write 6531
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6538 ); // i2cWrite  coef read 6538
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6542 ); // i2cWrite  coef write 6542
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6546 ); // i2cWrite  coef write 6546
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 6550 ); // i2cWrite  coef write 6550
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6554 ); // i2cWrite  coef read 6554
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6558 ); // i2cWrite  coef read 6558
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6562 ); // i2cWrite  coef read 6562
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6566 ); // i2cWrite  coef write 6566
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6573 ); // i2cWrite  coef read 6573
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6577 ); // i2cWrite  coef write 6577
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6581 ); // i2cWrite  coef write 6581
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 6585 ); // i2cWrite  coef write 6585
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6589 ); // i2cWrite  coef read 6589
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6593 ); // i2cWrite  coef read 6593
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6597 ); // i2cWrite  coef read 6597
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6601 ); // i2cWrite  coef write 6601
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6608 ); // i2cWrite  coef read 6608
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6612 ); // i2cWrite  coef write 6612
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6616 ); // i2cWrite  coef write 6616
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 6620 ); // i2cWrite  coef write 6620
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6624 ); // i2cWrite  coef read 6624
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6628 ); // i2cWrite  coef read 6628
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6632 ); // i2cWrite  coef read 6632
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6636 ); // i2cWrite  coef write 6636
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6643 ); // i2cWrite  coef read 6643
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6647 ); // i2cWrite  coef write 6647
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6651 ); // i2cWrite  coef write 6651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 6655 ); // i2cWrite  coef write 6655
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6659 ); // i2cWrite  coef read 6659
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6663 ); // i2cWrite  coef read 6663
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6667 ); // i2cWrite  coef read 6667
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6671 ); // i2cWrite  coef write 6671
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6678 ); // i2cWrite  coef read 6678
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6682 ); // i2cWrite  coef write 6682
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6686 ); // i2cWrite  coef write 6686
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 6690 ); // i2cWrite  coef write 6690
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6694 ); // i2cWrite  coef read 6694
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6698 ); // i2cWrite  coef read 6698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6702 ); // i2cWrite  coef read 6702
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6706 ); // i2cWrite  coef write 6706
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6713 ); // i2cWrite  coef read 6713
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6717 ); // i2cWrite  coef write 6717
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6721 ); // i2cWrite  coef write 6721
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 6725 ); // i2cWrite  coef write 6725
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6729 ); // i2cWrite  coef read 6729
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6733 ); // i2cWrite  coef read 6733
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6737 ); // i2cWrite  coef read 6737
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6741 ); // i2cWrite  coef write 6741
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x72 i2c            reg 0x1100 i2c data 0x1108   reg anal: PCMSampleSetup          : 48kHz
        //cs_8409_vendor_i2cRead(codec, 0x72, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6748 ); // i2cRead  coef read 6748
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6752 ); // i2cRead  coef write 6752
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6756 ); // i2cRead  coef write 6756
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 6760 ); // i2cRead  coef write 6760
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6764 ); // i2cRead  coef read 6764
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6768 ); // i2cRead  coef read 6768
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001108, 6772 ); // i2cRead  coef read 6772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6776 ); // i2cRead  coef read 6776
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6780 ); // i2cRead  coef write 6780
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6787 ); // i2cWrite  coef read 6787
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6791 ); // i2cWrite  coef write 6791
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 6795 ); // i2cWrite  coef write 6795
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 6799 ); // i2cWrite  coef write 6799
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6803 ); // i2cWrite  coef read 6803
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6807 ); // i2cWrite  coef read 6807
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6811 ); // i2cWrite  coef read 6811
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6815 ); // i2cWrite  coef write 6815
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

}

static void sync_converters(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 

        // remove normal channel mapping

        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 6821);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 6823 ); // coef write mask 6823
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 6823 ); // coef write mask 6823


        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000002, 6829);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 6831 ); // coef write mask 6831
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 6831 ); // coef write mask 6831

        // and reset back to normal channel mapping

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000002);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void amps_disable(struct hda_codec *codec)
{
        // - boot code split
        // specific boot only code here

        // this disables the amps


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        // this could be disabling the TDM

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 6848 ); //   coef read 6848
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 6852 ); //   coef write 6852

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 6856 ); //   coef read 6856
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 6860 ); //   coef write 6860

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 6864 ); //   coef read 6864

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 6869 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6869
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 6873 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 6873
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 6877 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6877

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 6880


        // disable amps

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6888 ); // i2cWrite  coef read 6888
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6892 ); // i2cWrite  coef write 6892
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 6896 ); // i2cWrite  coef write 6896
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 6900 ); // i2cWrite  coef write 6900
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6904 ); // i2cWrite  coef read 6904
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6908 ); // i2cWrite  coef read 6908
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6912 ); // i2cWrite  coef read 6912
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6916 ); // i2cWrite  coef write 6916
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);


//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6923 ); // i2cWrite  coef read 6923
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6927 ); // i2cWrite  coef write 6927
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 6931 ); // i2cWrite  coef write 6931
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 6935 ); // i2cWrite  coef write 6935
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6939 ); // i2cWrite  coef read 6939
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6943 ); // i2cWrite  coef read 6943
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6947 ); // i2cWrite  coef read 6947
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6951 ); // i2cWrite  coef write 6951
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6958 ); // i2cWrite  coef read 6958
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6962 ); // i2cWrite  coef write 6962
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 6966 ); // i2cWrite  coef write 6966
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 6970 ); // i2cWrite  coef write 6970
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6974 ); // i2cWrite  coef read 6974
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6978 ); // i2cWrite  coef read 6978
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6982 ); // i2cWrite  coef read 6982
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6986 ); // i2cWrite  coef write 6986
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1501 i2c data 0x0001   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0015, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6993 ); // i2cWrite  coef read 6993
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6997 ); // i2cWrite  coef write 6997
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7001 ); // i2cWrite  coef write 7001
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1501, 0x00000000, 7005 ); // i2cWrite  coef write 7005
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7009 ); // i2cWrite  coef read 7009
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7013 ); // i2cWrite  coef read 7013
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7017 ); // i2cWrite  coef read 7017
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7021 ); // i2cWrite  coef write 7021
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7028 ); // i2cWrite  coef read 7028
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7032 ); // i2cWrite  coef write 7032
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7036 ); // i2cWrite  coef write 7036
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 7040 ); // i2cWrite  coef write 7040
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7044 ); // i2cWrite  coef read 7044
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7048 ); // i2cWrite  coef read 7048
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7052 ); // i2cWrite  coef read 7052
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7056 ); // i2cWrite  coef write 7056
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1800 i2c data 0x0000   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0018, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7063 ); // i2cWrite  coef read 7063
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7067 ); // i2cWrite  coef write 7067
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7071 ); // i2cWrite  coef write 7071
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1800, 0x00000000, 7075 ); // i2cWrite  coef write 7075
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7079 ); // i2cWrite  coef read 7079
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7083 ); // i2cWrite  coef read 7083
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7087 ); // i2cWrite  coef read 7087
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7091 ); // i2cWrite  coef write 7091
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7098 ); // i2cWrite  coef read 7098
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7102 ); // i2cWrite  coef write 7102
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7106 ); // i2cWrite  coef write 7106
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 7110 ); // i2cWrite  coef write 7110
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7114 ); // i2cWrite  coef read 7114
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7118 ); // i2cWrite  coef read 7118
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7122 ); // i2cWrite  coef read 7122
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7126 ); // i2cWrite  coef write 7126
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7133 ); // i2cWrite  coef read 7133
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7137 ); // i2cWrite  coef write 7137
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7141 ); // i2cWrite  coef write 7141
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 7145 ); // i2cWrite  coef write 7145
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7149 ); // i2cWrite  coef read 7149
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7153 ); // i2cWrite  coef read 7153
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7157 ); // i2cWrite  coef read 7157
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7161 ); // i2cWrite  coef write 7161
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7168 ); // i2cWrite  coef read 7168
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7172 ); // i2cWrite  coef write 7172
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7176 ); // i2cWrite  coef write 7176
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 7180 ); // i2cWrite  coef write 7180
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7184 ); // i2cWrite  coef read 7184
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7188 ); // i2cWrite  coef read 7188
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7192 ); // i2cWrite  coef read 7192
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7196 ); // i2cWrite  coef write 7196
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7203 ); // i2cWrite  coef read 7203
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7207 ); // i2cWrite  coef write 7207
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7211 ); // i2cWrite  coef write 7211
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 7215 ); // i2cWrite  coef write 7215
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7219 ); // i2cWrite  coef read 7219
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7223 ); // i2cWrite  coef read 7223
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7227 ); // i2cWrite  coef read 7227
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7231 ); // i2cWrite  coef write 7231
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7238 ); // i2cWrite  coef read 7238
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7242 ); // i2cWrite  coef write 7242
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7246 ); // i2cWrite  coef write 7246
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 7250 ); // i2cWrite  coef write 7250
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7254 ); // i2cWrite  coef read 7254
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7258 ); // i2cWrite  coef read 7258
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7262 ); // i2cWrite  coef read 7262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7266 ); // i2cWrite  coef write 7266
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7273 ); // i2cWrite  coef read 7273
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7277 ); // i2cWrite  coef write 7277
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7281 ); // i2cWrite  coef write 7281
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 7285 ); // i2cWrite  coef write 7285
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7289 ); // i2cWrite  coef read 7289
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7293 ); // i2cWrite  coef read 7293
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7297 ); // i2cWrite  coef read 7297
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7301 ); // i2cWrite  coef write 7301
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x64, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7308 ); // i2cRead  coef read 7308
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7312 ); // i2cRead  coef write 7312
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7316 ); // i2cRead  coef write 7316
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 7320 ); // i2cRead  coef write 7320
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7324 ); // i2cRead  coef read 7324
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7328 ); // i2cRead  coef read 7328
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 7332 ); // i2cRead  coef read 7332
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7336 ); // i2cRead  coef read 7336
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7340 ); // i2cRead  coef write 7340
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7347 ); // i2cWrite  coef read 7347
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7351 ); // i2cWrite  coef write 7351
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 7355 ); // i2cWrite  coef write 7355
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 7359 ); // i2cWrite  coef write 7359
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7363 ); // i2cWrite  coef read 7363
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7367 ); // i2cWrite  coef read 7367
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7371 ); // i2cWrite  coef read 7371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7375 ); // i2cWrite  coef write 7375
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7382 ); // i2cWrite  coef read 7382
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7386 ); // i2cWrite  coef write 7386
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7390 ); // i2cWrite  coef write 7390
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 7394 ); // i2cWrite  coef write 7394
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7398 ); // i2cWrite  coef read 7398
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7402 ); // i2cWrite  coef read 7402
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7406 ); // i2cWrite  coef read 7406
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7410 ); // i2cWrite  coef write 7410
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7417 ); // i2cWrite  coef read 7417
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7421 ); // i2cWrite  coef write 7421
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7425 ); // i2cWrite  coef write 7425
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 7429 ); // i2cWrite  coef write 7429
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7433 ); // i2cWrite  coef read 7433
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7437 ); // i2cWrite  coef read 7437
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7441 ); // i2cWrite  coef read 7441
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7445 ); // i2cWrite  coef write 7445
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7452 ); // i2cWrite  coef read 7452
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7456 ); // i2cWrite  coef write 7456
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7460 ); // i2cWrite  coef write 7460
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 7464 ); // i2cWrite  coef write 7464
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7468 ); // i2cWrite  coef read 7468
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7472 ); // i2cWrite  coef read 7472
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7476 ); // i2cWrite  coef read 7476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7480 ); // i2cWrite  coef write 7480
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1502 i2c data 0x0002   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0015, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7487 ); // i2cWrite  coef read 7487
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7491 ); // i2cWrite  coef write 7491
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7495 ); // i2cWrite  coef write 7495
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1502, 0x00000000, 7499 ); // i2cWrite  coef write 7499
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7503 ); // i2cWrite  coef read 7503
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7507 ); // i2cWrite  coef read 7507
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7511 ); // i2cWrite  coef read 7511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7515 ); // i2cWrite  coef write 7515
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7522 ); // i2cWrite  coef read 7522
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7526 ); // i2cWrite  coef write 7526
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7530 ); // i2cWrite  coef write 7530
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 7534 ); // i2cWrite  coef write 7534
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7538 ); // i2cWrite  coef read 7538
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7542 ); // i2cWrite  coef read 7542
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7546 ); // i2cWrite  coef read 7546
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7550 ); // i2cWrite  coef write 7550
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1801 i2c data 0x0001   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0018, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7557 ); // i2cWrite  coef read 7557
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7561 ); // i2cWrite  coef write 7561
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7565 ); // i2cWrite  coef write 7565
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1801, 0x00000000, 7569 ); // i2cWrite  coef write 7569
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7573 ); // i2cWrite  coef read 7573
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7577 ); // i2cWrite  coef read 7577
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7581 ); // i2cWrite  coef read 7581
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7585 ); // i2cWrite  coef write 7585
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7592 ); // i2cWrite  coef read 7592
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7596 ); // i2cWrite  coef write 7596
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7600 ); // i2cWrite  coef write 7600
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 7604 ); // i2cWrite  coef write 7604
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7608 ); // i2cWrite  coef read 7608
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7612 ); // i2cWrite  coef read 7612
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7616 ); // i2cWrite  coef read 7616
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7620 ); // i2cWrite  coef write 7620
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7627 ); // i2cWrite  coef read 7627
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7631 ); // i2cWrite  coef write 7631
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7635 ); // i2cWrite  coef write 7635
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 7639 ); // i2cWrite  coef write 7639
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7643 ); // i2cWrite  coef read 7643
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7647 ); // i2cWrite  coef read 7647
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7651 ); // i2cWrite  coef read 7651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7655 ); // i2cWrite  coef write 7655
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7662 ); // i2cWrite  coef read 7662
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7666 ); // i2cWrite  coef write 7666
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7670 ); // i2cWrite  coef write 7670
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 7674 ); // i2cWrite  coef write 7674
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7678 ); // i2cWrite  coef read 7678
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7682 ); // i2cWrite  coef read 7682
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7686 ); // i2cWrite  coef read 7686
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7690 ); // i2cWrite  coef write 7690
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7697 ); // i2cWrite  coef read 7697
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7701 ); // i2cWrite  coef write 7701
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7705 ); // i2cWrite  coef write 7705
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 7709 ); // i2cWrite  coef write 7709
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7713 ); // i2cWrite  coef read 7713
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7717 ); // i2cWrite  coef read 7717
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7721 ); // i2cWrite  coef read 7721
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7725 ); // i2cWrite  coef write 7725
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7732 ); // i2cWrite  coef read 7732
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7736 ); // i2cWrite  coef write 7736
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7740 ); // i2cWrite  coef write 7740
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 7744 ); // i2cWrite  coef write 7744
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7748 ); // i2cWrite  coef read 7748
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7752 ); // i2cWrite  coef read 7752
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7756 ); // i2cWrite  coef read 7756
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7760 ); // i2cWrite  coef write 7760
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7767 ); // i2cWrite  coef read 7767
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7771 ); // i2cWrite  coef write 7771
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7775 ); // i2cWrite  coef write 7775
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 7779 ); // i2cWrite  coef write 7779
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7783 ); // i2cWrite  coef read 7783
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7787 ); // i2cWrite  coef read 7787
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7791 ); // i2cWrite  coef read 7791
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7795 ); // i2cWrite  coef write 7795
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x62 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x62, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7802 ); // i2cRead  coef read 7802
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7806 ); // i2cRead  coef write 7806
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7810 ); // i2cRead  coef write 7810
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 7814 ); // i2cRead  coef write 7814
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7818 ); // i2cRead  coef read 7818
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7822 ); // i2cRead  coef read 7822
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 7826 ); // i2cRead  coef read 7826
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7830 ); // i2cRead  coef read 7830
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7834 ); // i2cRead  coef write 7834
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7841 ); // i2cWrite  coef read 7841
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7845 ); // i2cWrite  coef write 7845
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 7849 ); // i2cWrite  coef write 7849
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 7853 ); // i2cWrite  coef write 7853
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7857 ); // i2cWrite  coef read 7857
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7861 ); // i2cWrite  coef read 7861
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7865 ); // i2cWrite  coef read 7865
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7869 ); // i2cWrite  coef write 7869
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);


        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]


        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 5936);


        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 7876 ); //   coef read 7876
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 7880 ); //   coef write 7880
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 7884 ); //   coef read 7884
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 7888 ); //   coef write 7888
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 7892 ); //   coef read 7892

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 7897 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 7897
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 7901 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 7901
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 7905 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 7905

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 7908

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7916 ); // i2cWrite  coef read 7916
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7920 ); // i2cWrite  coef write 7920
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 7924 ); // i2cWrite  coef write 7924
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 7928 ); // i2cWrite  coef write 7928
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7932 ); // i2cWrite  coef read 7932
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7936 ); // i2cWrite  coef read 7936
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7940 ); // i2cWrite  coef read 7940
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7944 ); // i2cWrite  coef write 7944
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7951 ); // i2cWrite  coef read 7951
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7955 ); // i2cWrite  coef write 7955
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 7959 ); // i2cWrite  coef write 7959
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 7963 ); // i2cWrite  coef write 7963
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7967 ); // i2cWrite  coef read 7967
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7971 ); // i2cWrite  coef read 7971
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7975 ); // i2cWrite  coef read 7975
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7979 ); // i2cWrite  coef write 7979
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7986 ); // i2cWrite  coef read 7986
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7990 ); // i2cWrite  coef write 7990
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 7994 ); // i2cWrite  coef write 7994
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 7998 ); // i2cWrite  coef write 7998
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8002 ); // i2cWrite  coef read 8002
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8006 ); // i2cWrite  coef read 8006
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8010 ); // i2cWrite  coef read 8010
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8014 ); // i2cWrite  coef write 8014
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1504 i2c data 0x0004   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0015, 0x0004, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8021 ); // i2cWrite  coef read 8021
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8025 ); // i2cWrite  coef write 8025
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8029 ); // i2cWrite  coef write 8029
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1504, 0x00000000, 8033 ); // i2cWrite  coef write 8033
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8037 ); // i2cWrite  coef read 8037
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8041 ); // i2cWrite  coef read 8041
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8045 ); // i2cWrite  coef read 8045
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8049 ); // i2cWrite  coef write 8049
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8056 ); // i2cWrite  coef read 8056
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8060 ); // i2cWrite  coef write 8060
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8064 ); // i2cWrite  coef write 8064
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 8068 ); // i2cWrite  coef write 8068
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8072 ); // i2cWrite  coef read 8072
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8076 ); // i2cWrite  coef read 8076
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8080 ); // i2cWrite  coef read 8080
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8084 ); // i2cWrite  coef write 8084
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1802 i2c data 0x0002   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0018, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8091 ); // i2cWrite  coef read 8091
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8095 ); // i2cWrite  coef write 8095
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8099 ); // i2cWrite  coef write 8099
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1802, 0x00000000, 8103 ); // i2cWrite  coef write 8103
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8107 ); // i2cWrite  coef read 8107
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8111 ); // i2cWrite  coef read 8111
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8115 ); // i2cWrite  coef read 8115
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8119 ); // i2cWrite  coef write 8119
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8126 ); // i2cWrite  coef read 8126
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8130 ); // i2cWrite  coef write 8130
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8134 ); // i2cWrite  coef write 8134
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 8138 ); // i2cWrite  coef write 8138
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8142 ); // i2cWrite  coef read 8142
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8146 ); // i2cWrite  coef read 8146
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8150 ); // i2cWrite  coef read 8150
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8154 ); // i2cWrite  coef write 8154
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8161 ); // i2cWrite  coef read 8161
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8165 ); // i2cWrite  coef write 8165
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8169 ); // i2cWrite  coef write 8169
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 8173 ); // i2cWrite  coef write 8173
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8177 ); // i2cWrite  coef read 8177
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8181 ); // i2cWrite  coef read 8181
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8185 ); // i2cWrite  coef read 8185
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8189 ); // i2cWrite  coef write 8189
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8196 ); // i2cWrite  coef read 8196
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8200 ); // i2cWrite  coef write 8200
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8204 ); // i2cWrite  coef write 8204
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 8208 ); // i2cWrite  coef write 8208
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8212 ); // i2cWrite  coef read 8212
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8216 ); // i2cWrite  coef read 8216
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8220 ); // i2cWrite  coef read 8220
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8224 ); // i2cWrite  coef write 8224
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8231 ); // i2cWrite  coef read 8231
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8235 ); // i2cWrite  coef write 8235
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8239 ); // i2cWrite  coef write 8239
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 8243 ); // i2cWrite  coef write 8243
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8247 ); // i2cWrite  coef read 8247
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8251 ); // i2cWrite  coef read 8251
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8255 ); // i2cWrite  coef read 8255
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8259 ); // i2cWrite  coef write 8259
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8266 ); // i2cWrite  coef read 8266
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8270 ); // i2cWrite  coef write 8270
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8274 ); // i2cWrite  coef write 8274
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 8278 ); // i2cWrite  coef write 8278
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8282 ); // i2cWrite  coef read 8282
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8286 ); // i2cWrite  coef read 8286
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8290 ); // i2cWrite  coef read 8290
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8294 ); // i2cWrite  coef write 8294
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8301 ); // i2cWrite  coef read 8301
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8305 ); // i2cWrite  coef write 8305
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8309 ); // i2cWrite  coef write 8309
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 8313 ); // i2cWrite  coef write 8313
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8317 ); // i2cWrite  coef read 8317
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8321 ); // i2cWrite  coef read 8321
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8325 ); // i2cWrite  coef read 8325
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8329 ); // i2cWrite  coef write 8329
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x74 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x74, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8336 ); // i2cRead  coef read 8336
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8340 ); // i2cRead  coef write 8340
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8344 ); // i2cRead  coef write 8344
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 8348 ); // i2cRead  coef write 8348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8352 ); // i2cRead  coef read 8352
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8356 ); // i2cRead  coef read 8356
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 8360 ); // i2cRead  coef read 8360
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8364 ); // i2cRead  coef read 8364
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8368 ); // i2cRead  coef write 8368
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8375 ); // i2cWrite  coef read 8375
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8379 ); // i2cWrite  coef write 8379
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 8383 ); // i2cWrite  coef write 8383
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 8387 ); // i2cWrite  coef write 8387
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8391 ); // i2cWrite  coef read 8391
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8395 ); // i2cWrite  coef read 8395
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8399 ); // i2cWrite  coef read 8399
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8403 ); // i2cWrite  coef write 8403
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8410 ); // i2cWrite  coef read 8410
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8414 ); // i2cWrite  coef write 8414
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8418 ); // i2cWrite  coef write 8418
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 8422 ); // i2cWrite  coef write 8422
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8426 ); // i2cWrite  coef read 8426
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8430 ); // i2cWrite  coef read 8430
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8434 ); // i2cWrite  coef read 8434
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8438 ); // i2cWrite  coef write 8438
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8445 ); // i2cWrite  coef read 8445
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8449 ); // i2cWrite  coef write 8449
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8453 ); // i2cWrite  coef write 8453
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 8457 ); // i2cWrite  coef write 8457
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8461 ); // i2cWrite  coef read 8461
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8465 ); // i2cWrite  coef read 8465
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8469 ); // i2cWrite  coef read 8469
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8473 ); // i2cWrite  coef write 8473
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8480 ); // i2cWrite  coef read 8480
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8484 ); // i2cWrite  coef write 8484
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8488 ); // i2cWrite  coef write 8488
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 8492 ); // i2cWrite  coef write 8492
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8496 ); // i2cWrite  coef read 8496
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8500 ); // i2cWrite  coef read 8500
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8504 ); // i2cWrite  coef read 8504
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8508 ); // i2cWrite  coef write 8508
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1508 i2c data 0x0008   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0015, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8515 ); // i2cWrite  coef read 8515
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8519 ); // i2cWrite  coef write 8519
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8523 ); // i2cWrite  coef write 8523
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1508, 0x00000000, 8527 ); // i2cWrite  coef write 8527
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8531 ); // i2cWrite  coef read 8531
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8535 ); // i2cWrite  coef read 8535
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8539 ); // i2cWrite  coef read 8539
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8543 ); // i2cWrite  coef write 8543
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8550 ); // i2cWrite  coef read 8550
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8554 ); // i2cWrite  coef write 8554
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8558 ); // i2cWrite  coef write 8558
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 8562 ); // i2cWrite  coef write 8562
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8566 ); // i2cWrite  coef read 8566
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8570 ); // i2cWrite  coef read 8570
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8574 ); // i2cWrite  coef read 8574
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8578 ); // i2cWrite  coef write 8578
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1803 i2c data 0x0003   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0018, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8585 ); // i2cWrite  coef read 8585
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8589 ); // i2cWrite  coef write 8589
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8593 ); // i2cWrite  coef write 8593
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1803, 0x00000000, 8597 ); // i2cWrite  coef write 8597
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8601 ); // i2cWrite  coef read 8601
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8605 ); // i2cWrite  coef read 8605
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8609 ); // i2cWrite  coef read 8609
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8613 ); // i2cWrite  coef write 8613
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8620 ); // i2cWrite  coef read 8620
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8624 ); // i2cWrite  coef write 8624
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8628 ); // i2cWrite  coef write 8628
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 8632 ); // i2cWrite  coef write 8632
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8636 ); // i2cWrite  coef read 8636
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8640 ); // i2cWrite  coef read 8640
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8644 ); // i2cWrite  coef read 8644
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8648 ); // i2cWrite  coef write 8648
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8655 ); // i2cWrite  coef read 8655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8659 ); // i2cWrite  coef write 8659
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8663 ); // i2cWrite  coef write 8663
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 8667 ); // i2cWrite  coef write 8667
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8671 ); // i2cWrite  coef read 8671
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8675 ); // i2cWrite  coef read 8675
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8679 ); // i2cWrite  coef read 8679
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8683 ); // i2cWrite  coef write 8683
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8690 ); // i2cWrite  coef read 8690
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8694 ); // i2cWrite  coef write 8694
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8698 ); // i2cWrite  coef write 8698
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 8702 ); // i2cWrite  coef write 8702
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8706 ); // i2cWrite  coef read 8706
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8710 ); // i2cWrite  coef read 8710
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8714 ); // i2cWrite  coef read 8714
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8718 ); // i2cWrite  coef write 8718
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8725 ); // i2cWrite  coef read 8725
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8729 ); // i2cWrite  coef write 8729
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8733 ); // i2cWrite  coef write 8733
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 8737 ); // i2cWrite  coef write 8737
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8741 ); // i2cWrite  coef read 8741
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8745 ); // i2cWrite  coef read 8745
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8749 ); // i2cWrite  coef read 8749
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8753 ); // i2cWrite  coef write 8753
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8760 ); // i2cWrite  coef read 8760
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8764 ); // i2cWrite  coef write 8764
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8768 ); // i2cWrite  coef write 8768
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 8772 ); // i2cWrite  coef write 8772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8776 ); // i2cWrite  coef read 8776
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8780 ); // i2cWrite  coef read 8780
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8784 ); // i2cWrite  coef read 8784
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8788 ); // i2cWrite  coef write 8788
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8795 ); // i2cWrite  coef read 8795
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8799 ); // i2cWrite  coef write 8799
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8803 ); // i2cWrite  coef write 8803
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 8807 ); // i2cWrite  coef write 8807
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8811 ); // i2cWrite  coef read 8811
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8815 ); // i2cWrite  coef read 8815
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8819 ); // i2cWrite  coef read 8819
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8823 ); // i2cWrite  coef write 8823
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x72 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x72, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8830 ); // i2cRead  coef read 8830
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8834 ); // i2cRead  coef write 8834
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8838 ); // i2cRead  coef write 8838
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 8842 ); // i2cRead  coef write 8842
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8846 ); // i2cRead  coef read 8846
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8850 ); // i2cRead  coef read 8850
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 8854 ); // i2cRead  coef read 8854
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8858 ); // i2cRead  coef read 8858
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8862 ); // i2cRead  coef write 8862
//      snd_hda i2cRead end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8869 ); // i2cWrite  coef read 8869
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8873 ); // i2cWrite  coef write 8873
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 8877 ); // i2cWrite  coef write 8877
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 8881 ); // i2cWrite  coef write 8881
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8885 ); // i2cWrite  coef read 8885
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8889 ); // i2cWrite  coef read 8889
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8893 ); // i2cWrite  coef read 8893
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8897 ); // i2cWrite  coef write 8897
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

}

static void sync_converters2(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 

        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 8903);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000003, 8905 ); // coef write mask 8905
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000003, 8905 ); // coef write mask 8905


        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 8911);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000003, 8913 ); // coef write mask 8913
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000003, 8913 ); // coef write mask 8913


        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void sync_converters3(struct hda_codec *codec)
{
        int retval;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 

        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 8942);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0x00000003, 8944 ); // coef write mask 8944
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0xundef, 0x00000003, 8944 ); // coef write mask 8944


        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 8950);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000002, 8952 ); // coef write mask 8952
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0xundef, 0x00000002, 8952 ); // coef write mask 8952
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 8958 ); //   coef read 8958
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 8962 ); //   coef read 8962
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 8966 ); // coef write mask 8966
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 8966 ); // coef write mask 8966


        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

}


static void amps_disable2(struct hda_codec *codec)
{
        int retval;

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8976 ); // i2cWrite  coef read 8976
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8980 ); // i2cWrite  coef write 8980
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 8984 ); // i2cWrite  coef write 8984
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 8988 ); // i2cWrite  coef write 8988
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8992 ); // i2cWrite  coef read 8992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8996 ); // i2cWrite  coef read 8996
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 9000 ); // i2cWrite  coef read 9000
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 9004 ); // i2cWrite  coef write 9004
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 9011 ); // i2cWrite  coef read 9011
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 9015 ); // i2cWrite  coef write 9015
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 9019 ); // i2cWrite  coef write 9019
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 9023 ); // i2cWrite  coef write 9023
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9027 ); // i2cWrite  coef read 9027
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9031 ); // i2cWrite  coef read 9031
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 9035 ); // i2cWrite  coef read 9035
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 9039 ); // i2cWrite  coef write 9039
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);


        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        // TDM disable??

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 9045 ); //   coef read 9045
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8800, 0x00000000, 9049 ); //   coef write 9049
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 9053 ); //   coef read 9053
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8820, 0x00000000, 9057 ); //   coef write 9057
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 9061 ); //   coef read 9061
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 9065 ); //   coef read 9065
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 9069 ); //   coef read 9069

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 9074 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 9074
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 9078 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 9078
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 9082 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 9082

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 9085

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);


        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 7948);

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]
        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 2 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 9091);
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     36 []

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 9095 ); // i2cWrite  coef read 9095
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 9099 ); // i2cWrite  coef write 9099
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 9103 ); // i2cWrite  coef write 9103
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 9107 ); // i2cWrite  coef write 9107
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9111 ); // i2cWrite  coef read 9111
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9115 ); // i2cWrite  coef read 9115
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 9119 ); // i2cWrite  coef read 9119
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 9123 ); // i2cWrite  coef write 9123
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 9130 ); // i2cWrite  coef read 9130
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 9134 ); // i2cWrite  coef write 9134
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 9138 ); // i2cWrite  coef write 9138
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 9142 ); // i2cWrite  coef write 9142
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9146 ); // i2cWrite  coef read 9146
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9150 ); // i2cWrite  coef read 9150
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 9154 ); // i2cWrite  coef read 9154
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 9158 ); // i2cWrite  coef write 9158
//      snd_hda i2cWrite end

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);


        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 9164 ); //   coef read 9164
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8840, 0x00000000, 9168 ); //   coef write 9168
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 9172 ); //   coef read 9172
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8860, 0x00000000, 9176 ); //   coef write 9176
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00005401, 9180 ); // coef write mask 9180
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xundef, 0x00005401, 9180 ); // coef write mask 9180
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000220, 9186 ); //   coef read 9186
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 9190 ); //   coef write 9190

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);

}

static void read_coefs2(struct hda_codec *codec)
{

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);

        // lets explicitly check data here
        //snd_hda_coef_sequence(codec, cs8409_init_coef2, "init_coef2");

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 9194 ); //   coef read 9194
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 9198 ); //   coef read 9198
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 9202 ); //   coef read 9202
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 9206 ); //   coef read 9206
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008000, 9210 ); //   coef read 9210
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 9214 ); //   coef read 9214
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008000, 9218 ); //   coef read 9218
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 9222 ); //   coef read 9222
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 9226 ); //   coef read 9226
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 9230 ); //   coef read 9230
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 9234 ); //   coef read 9234
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 9238 ); //   coef read 9238
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 9242 ); //   coef read 9242
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 9246 ); //   coef read 9246
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 9250 ); //   coef read 9250
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 9254 ); //   coef read 9254
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 9258 ); //   coef read 9258
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 9262 ); //   coef read 9262
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 9266 ); //   coef read 9266
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 9270 ); //   coef read 9270
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 9274 ); //   coef read 9274
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 9278 ); //   coef read 9278
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 9282 ); //   coef read 9282
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 9286 ); //   coef read 9286
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 9290 ); //   coef read 9290
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 9294 ); //   coef read 9294
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 9298 ); //   coef read 9298
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 9302 ); //   coef read 9302
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 9306 ); //   coef read 9306
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 9310 ); //   coef read 9310
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 9314 ); //   coef read 9314
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 9318 ); //   coef read 9318
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 9322 ); //   coef read 9322
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 9326 ); //   coef read 9326
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 9330 ); //   coef read 9330
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 9334 ); //   coef read 9334
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 9338 ); //   coef read 9338
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 9342 ); //   coef read 9342
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 9346 ); //   coef read 9346
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 9350 ); //   coef read 9350
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 9354 ); //   coef read 9354
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 9358 ); //   coef read 9358
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 9362 ); //   coef read 9362
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 9366 ); //   coef read 9366
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 9370 ); //   coef read 9370
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 9374 ); //   coef read 9374
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 9378 ); //   coef read 9378
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 9382 ); //   coef read 9382
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 9386 ); //   coef read 9386
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 9390 ); //   coef read 9390
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 9394 ); //   coef read 9394
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 9398 ); //   coef read 9398
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 9402 ); //   coef read 9402
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 9406 ); //   coef read 9406
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 9410 ); //   coef read 9410
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 9414 ); //   coef read 9414
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 9418 ); //   coef read 9418
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 9422 ); //   coef read 9422
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 9426 ); //   coef read 9426
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 9430 ); //   coef read 9430
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 9434 ); //   coef read 9434
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 9438 ); //   coef read 9438
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 9442 ); //   coef read 9442

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);

        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 9447 ); //   coef write 9447

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);

        //retval = snd_hda_codec_read_check(codec, core->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9127);
}

static void setup_amps2(struct hda_codec *codec)
{
        int retval;

	// there is a GET_POWER STATE here suggesting it would turn on power except its already on
        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9446);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 3 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 9456);
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     37 []

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9465);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9467);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9469);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 35 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9471);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 35 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9480);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9482);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9484);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 35 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9486);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 35 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_gpio2(struct hda_codec *codec)
{
        int retval;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

	// this could well be a set power state to AC_PWRST_D0 for these nodes - except they are already powered
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9525);
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9526);

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000027, 9529);
//      snd_hda:     gpio data 1 0x27
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000027, 9530);
//      snd_hda:     gpio data 1 0x27
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000027, 9531);
//      snd_hda:     gpio data 1 0x27

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
}

static void setup_mic3(struct hda_codec *codec)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 9546 ); // i2cPagedRead  coef read 9546
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 9550 ); // i2cPagedRead  coef write 9550
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 9554 ); // i2cPagedRead  coef write 9554
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 9558 ); // i2cPagedRead  coef write 9558
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9562 ); // i2cPagedRead  coef read 9562
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 9566 ); // i2cPagedRead  coef write 9566
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9570 ); // i2cPagedRead  coef read 9570
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9574 ); // i2cPagedRead  coef read 9574
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 9578 ); // i2cPagedRead  coef read 9578
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 9582 ); // i2cPagedRead  coef read 9582
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 9586 ); // i2cPagedRead  coef write 9586
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
}

static void setup_mic_vol3(struct hda_codec *codec)
{
        int retval;

        // nodes 0x44, 0x45 which are connected to 0x22, 0x23 are labelled as mic inputs

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9598);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9600);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9602);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 35 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9604);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 35 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_mic_vol4(struct hda_codec *codec)
{
        int retval;

        // nodes 0x44, 0x45 which are connected to 0x22, 0x23 are labelled as mic inputs

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9613);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9615);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9617);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 35 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9619);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 35 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
}

static void setup_mic4(struct hda_codec *codec)
{
        int retval;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 9663 ); // i2cPagedRead  coef read 9663
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 9667 ); // i2cPagedRead  coef write 9667
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 9671 ); // i2cPagedRead  coef write 9671
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 9675 ); // i2cPagedRead  coef write 9675
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9679 ); // i2cPagedRead  coef read 9679
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 9683 ); // i2cPagedRead  coef write 9683
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9687 ); // i2cPagedRead  coef read 9687
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9691 ); // i2cPagedRead  coef read 9691
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 9695 ); // i2cPagedRead  coef read 9695
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 9699 ); // i2cPagedRead  coef read 9699
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 9703 ); // i2cPagedRead  coef write 9703
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 9714 ); // i2cPagedRead  coef read 9714
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 9718 ); // i2cPagedRead  coef write 9718
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 9722 ); // i2cPagedRead  coef write 9722
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 9726 ); // i2cPagedRead  coef write 9726
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9730 ); // i2cPagedRead  coef read 9730
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 9734 ); // i2cPagedRead  coef write 9734
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9738 ); // i2cPagedRead  coef read 9738
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 9742 ); // i2cPagedRead  coef read 9742
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 9746 ); // i2cPagedRead  coef read 9746
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 9750 ); // i2cPagedRead  coef read 9750
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 9754 ); // i2cPagedRead  coef write 9754
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
}

static void setup_mic_vol5(struct hda_codec *codec)
{
        int retval;

        int retgain1;
        int retgain2;

        // nodes 0x44, 0x45 which are connected to 0x22, 0x23 are labelled as mic inputs

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9767);
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9768);

        // so this is wierd - set node 0x22 stream format to 44.1 kHz, 24 bits
        // followed by setting gain of node 0x23 and 0x45
        // then set node 0x23 to 48 kHz, 8 bits??


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031);
//      snd_hda:     stream format 34 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]


        retgain1 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9777);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006027);
//      snd_hda:     amp gain/mute 35 0x6027 mute 0 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9779);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005027);
//      snd_hda:     amp gain/mute 35 0x5027 mute 0 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000027, 9781);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0027 mute 0 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7);
//      snd_hda:     amp gain/mute 35 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000027, 9783);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x0027 mute 0 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7);
//      snd_hda:     amp gain/mute 35 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 9785);
//      snd_hda:     amp gain/mute 69 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 69 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006000);
//      snd_hda:     amp gain/mute 69 0x6000 mute 0 gain 0x0 0 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 9787);
//      snd_hda:     amp gain/mute 69 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 69 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005000);
//      snd_hda:     amp gain/mute 69 0x5000 mute 0 gain 0x0 0 index 0x00 left 0 right 1 output 0 input 1  right  input

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9789);

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 9790);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_mic_vol6(struct hda_codec *codec)
{
        int retval;

        int retgain1;
        int retgain2;


        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9789);
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 9792);
	hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

 
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9795);
	hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);

        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 35 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]


        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000001, 9798 ); //   coef read 9798
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00000000, 9802 ); //   coef write 9802


        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 9806);
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     69 []


        // nodes 0x44, 0x45 which are connected to 0x22, 0x23 are labelled as mic inputs

        // disable node 0x22 and 0x23 by setting stream id to 0

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 9809);
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9810);
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 9813);
	hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9816);
	hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0x00000033, 9818 ); // coef write mask 9818
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0xundef, 0x00000033, 9818 ); // coef write mask 9818


        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 9824);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9825);
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 9828);
	hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9831);
	hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);



        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0x00000033, 9833 ); // coef write mask 9833
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0xundef, 0x00000033, 9833 ); // coef write mask 9833


        // nodes 0x44, 0x45 which are connected to 0x22, 0x23 are labelled as mic inputs

        // disable node 0x22 and 0x23 by setting stream id to 0
        // followed by gain setting

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9839);
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 9842);
	hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9845);
	hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);


        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9847);
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 9850);
	hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 9853);
	hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_mic_vol7(struct hda_codec *codec)
{
        int retval;

        int retgain1;
        int retgain2;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        retgain1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 9862);
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033);
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 9864);
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033);
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retgain1 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 9866);
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3);
//      snd_hda:     amp gain/mute 35 0x60b3 mute 1 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retgain2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 9868);
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3);
//      snd_hda:     amp gain/mute 35 0x50b3 mute 1 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //retval/snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void cs_8409_unmute(struct hda_codec *codec)
{
	int retval;

	int retwake;

        int retconv;

        int retpower1;
        int retpower2;

	int ret_power;

	printk("snd_hda_intel: command nid cs_8409_unmute");

	// this initial bit is specific to unmute


        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

	// this is the mike

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x0038
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 22 ); // i2cPagedRead  coef read 22
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 26 ); // i2cPagedRead  coef write 26
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 30 ); // i2cPagedRead  coef write 30
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 34 ); // i2cPagedRead  coef write 34
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 38 ); // i2cPagedRead  coef read 38
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 42 ); // i2cPagedRead  coef write 42
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 46 ); // i2cPagedRead  coef read 46
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 50 ); // i2cPagedRead  coef read 50
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 54 ); // i2cPagedRead  coef read 54
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 58 ); // i2cPagedRead  coef read 58
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 62 ); // i2cPagedRead  coef write 62
//      snd_hda i2cPagedRead end


        // so from this point on unmute and volup are identical

	// these are the amps

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 71 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 71
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 75 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 75
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 79 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 79
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 83 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 83
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 87 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 87
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 91 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 91
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 95 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 95
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 99 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 99
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 103 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 103
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 107 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 107
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 111 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 111

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x00008000, 115 ); // coef write mask 115
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x00008000, 115 ); // coef write mask 115
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 121 ); // coef write mask 121
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 121 ); // coef write mask 121
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 127 ); // coef write mask 127
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 127 ); // coef write mask 127
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000280, 133 ); // coef write mask 133

//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000280, 133 ); // coef write mask 133
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 139 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 139
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 143 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 143
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 147 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 147

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 152 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 152
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 156 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 156
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 160 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 160

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 163

        // boot code has this here
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 168 ); // coef write mask 168
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 168 ); // coef write mask 168
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 174 ); // coef write mask 174
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 174 ); // coef write mask 174
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x000008ff, 180 ); // coef write mask 180
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x000008ff, 180 ); // coef write mask 180

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 187);

        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 191 ); // i2cWrite  coef read 191
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 195 ); // i2cWrite  coef write 195
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 199 ); // i2cWrite  coef write 199
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 203 ); // i2cWrite  coef write 203
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 207 ); // i2cWrite  coef read 207
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 211 ); // i2cWrite  coef read 211
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 215 ); // i2cWrite  coef read 215
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 219 ); // i2cWrite  coef write 219
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 226 ); // i2cWrite  coef read 226
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 230 ); // i2cWrite  coef write 230
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 234 ); // i2cWrite  coef write 234
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 238 ); // i2cWrite  coef write 238
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 242 ); // i2cWrite  coef read 242
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 246 ); // i2cWrite  coef read 246
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 250 ); // i2cWrite  coef read 250
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 254 ); // i2cWrite  coef write 254
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1501 i2c data 0x0001   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0015, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 261 ); // i2cWrite  coef read 261
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 265 ); // i2cWrite  coef write 265
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 269 ); // i2cWrite  coef write 269
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1501, 0x00000000, 273 ); // i2cWrite  coef write 273
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 277 ); // i2cWrite  coef read 277
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 281 ); // i2cWrite  coef read 281
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 285 ); // i2cWrite  coef read 285
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 289 ); // i2cWrite  coef write 289
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 296 ); // i2cWrite  coef read 296
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 300 ); // i2cWrite  coef write 300
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 304 ); // i2cWrite  coef write 304
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 308 ); // i2cWrite  coef write 308
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 312 ); // i2cWrite  coef read 312
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 316 ); // i2cWrite  coef read 316
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 320 ); // i2cWrite  coef read 320
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 324 ); // i2cWrite  coef write 324
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1800 i2c data 0x0000   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0018, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 331 ); // i2cWrite  coef read 331
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 335 ); // i2cWrite  coef write 335
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 339 ); // i2cWrite  coef write 339
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1800, 0x00000000, 343 ); // i2cWrite  coef write 343
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 347 ); // i2cWrite  coef read 347
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 351 ); // i2cWrite  coef read 351
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 355 ); // i2cWrite  coef read 355
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 359 ); // i2cWrite  coef write 359
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 366 ); // i2cWrite  coef read 366
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 370 ); // i2cWrite  coef write 370
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 374 ); // i2cWrite  coef write 374
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 378 ); // i2cWrite  coef write 378
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 382 ); // i2cWrite  coef read 382
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 386 ); // i2cWrite  coef read 386
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 390 ); // i2cWrite  coef read 390
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 394 ); // i2cWrite  coef write 394
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 401 ); // i2cWrite  coef read 401
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 405 ); // i2cWrite  coef write 405
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 409 ); // i2cWrite  coef write 409
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 413 ); // i2cWrite  coef write 413
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 417 ); // i2cWrite  coef read 417
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 421 ); // i2cWrite  coef read 421
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 425 ); // i2cWrite  coef read 425
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 429 ); // i2cWrite  coef write 429
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 436 ); // i2cWrite  coef read 436
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 440 ); // i2cWrite  coef write 440
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 444 ); // i2cWrite  coef write 444
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 448 ); // i2cWrite  coef write 448
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 452 ); // i2cWrite  coef read 452
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 456 ); // i2cWrite  coef read 456
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 460 ); // i2cWrite  coef read 460
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 464 ); // i2cWrite  coef write 464
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 471 ); // i2cWrite  coef read 471
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 475 ); // i2cWrite  coef write 475
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 479 ); // i2cWrite  coef write 479
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 483 ); // i2cWrite  coef write 483
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 487 ); // i2cWrite  coef read 487
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 491 ); // i2cWrite  coef read 491
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 495 ); // i2cWrite  coef read 495
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 499 ); // i2cWrite  coef write 499
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 506 ); // i2cWrite  coef read 506
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 510 ); // i2cWrite  coef write 510
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 514 ); // i2cWrite  coef write 514
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 518 ); // i2cWrite  coef write 518
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 522 ); // i2cWrite  coef read 522
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 526 ); // i2cWrite  coef read 526
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 530 ); // i2cWrite  coef read 530
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 534 ); // i2cWrite  coef write 534
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 541 ); // i2cWrite  coef read 541
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 545 ); // i2cWrite  coef write 545
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 549 ); // i2cWrite  coef write 549
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 553 ); // i2cWrite  coef write 553
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 557 ); // i2cWrite  coef read 557
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 561 ); // i2cWrite  coef read 561
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 565 ); // i2cWrite  coef read 565
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 569 ); // i2cWrite  coef write 569
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x64, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 576 ); // i2cRead  coef read 576
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 580 ); // i2cRead  coef write 580
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 584 ); // i2cRead  coef write 584
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 588 ); // i2cRead  coef write 588
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 592 ); // i2cRead  coef read 592
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 596 ); // i2cRead  coef read 596
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 600 ); // i2cRead  coef read 600
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 604 ); // i2cRead  coef read 604
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 608 ); // i2cRead  coef write 608
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 615 ); // i2cWrite  coef read 615
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 619 ); // i2cWrite  coef write 619
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 623 ); // i2cWrite  coef write 623
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 627 ); // i2cWrite  coef write 627
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 631 ); // i2cWrite  coef read 631
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 635 ); // i2cWrite  coef read 635
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 639 ); // i2cWrite  coef read 639
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 643 ); // i2cWrite  coef write 643
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 650 ); // i2cWrite  coef read 650
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 654 ); // i2cWrite  coef write 654
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 658 ); // i2cWrite  coef write 658
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 662 ); // i2cWrite  coef write 662
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 666 ); // i2cWrite  coef read 666
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 670 ); // i2cWrite  coef read 670
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 674 ); // i2cWrite  coef read 674
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 678 ); // i2cWrite  coef write 678
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 685 ); // i2cWrite  coef read 685
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 689 ); // i2cWrite  coef write 689
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 693 ); // i2cWrite  coef write 693
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 697 ); // i2cWrite  coef write 697
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 701 ); // i2cWrite  coef read 701
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 705 ); // i2cWrite  coef read 705
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 709 ); // i2cWrite  coef read 709
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 713 ); // i2cWrite  coef write 713
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 720 ); // i2cWrite  coef read 720
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 724 ); // i2cWrite  coef write 724
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 728 ); // i2cWrite  coef write 728
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 732 ); // i2cWrite  coef write 732
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 736 ); // i2cWrite  coef read 736
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 740 ); // i2cWrite  coef read 740
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 744 ); // i2cWrite  coef read 744
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 748 ); // i2cWrite  coef write 748
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1502 i2c data 0x0002   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0015, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 755 ); // i2cWrite  coef read 755
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 759 ); // i2cWrite  coef write 759
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 763 ); // i2cWrite  coef write 763
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1502, 0x00000000, 767 ); // i2cWrite  coef write 767
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 771 ); // i2cWrite  coef read 771
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 775 ); // i2cWrite  coef read 775
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 779 ); // i2cWrite  coef read 779
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 783 ); // i2cWrite  coef write 783
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 790 ); // i2cWrite  coef read 790
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 794 ); // i2cWrite  coef write 794
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 798 ); // i2cWrite  coef write 798
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 802 ); // i2cWrite  coef write 802
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 806 ); // i2cWrite  coef read 806
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 810 ); // i2cWrite  coef read 810
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 814 ); // i2cWrite  coef read 814
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 818 ); // i2cWrite  coef write 818
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1801 i2c data 0x0001   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0018, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 825 ); // i2cWrite  coef read 825
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 829 ); // i2cWrite  coef write 829
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 833 ); // i2cWrite  coef write 833
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1801, 0x00000000, 837 ); // i2cWrite  coef write 837
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 841 ); // i2cWrite  coef read 841
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 845 ); // i2cWrite  coef read 845
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 849 ); // i2cWrite  coef read 849
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 853 ); // i2cWrite  coef write 853
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 860 ); // i2cWrite  coef read 860
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 864 ); // i2cWrite  coef write 864
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 868 ); // i2cWrite  coef write 868
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 872 ); // i2cWrite  coef write 872
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 876 ); // i2cWrite  coef read 876
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 880 ); // i2cWrite  coef read 880
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 884 ); // i2cWrite  coef read 884
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 888 ); // i2cWrite  coef write 888
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 895 ); // i2cWrite  coef read 895
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 899 ); // i2cWrite  coef write 899
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 903 ); // i2cWrite  coef write 903
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 907 ); // i2cWrite  coef write 907
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 911 ); // i2cWrite  coef read 911
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 915 ); // i2cWrite  coef read 915
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 919 ); // i2cWrite  coef read 919
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 923 ); // i2cWrite  coef write 923
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 930 ); // i2cWrite  coef read 930
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 934 ); // i2cWrite  coef write 934
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 938 ); // i2cWrite  coef write 938
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 942 ); // i2cWrite  coef write 942
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 946 ); // i2cWrite  coef read 946
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 950 ); // i2cWrite  coef read 950
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 954 ); // i2cWrite  coef read 954
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 958 ); // i2cWrite  coef write 958
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 965 ); // i2cWrite  coef read 965
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 969 ); // i2cWrite  coef write 969
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 973 ); // i2cWrite  coef write 973
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 977 ); // i2cWrite  coef write 977
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 981 ); // i2cWrite  coef read 981
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 985 ); // i2cWrite  coef read 985
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 989 ); // i2cWrite  coef read 989
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 993 ); // i2cWrite  coef write 993
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1000 ); // i2cWrite  coef read 1000
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1004 ); // i2cWrite  coef write 1004
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1008 ); // i2cWrite  coef write 1008
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 1012 ); // i2cWrite  coef write 1012
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1016 ); // i2cWrite  coef read 1016
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1020 ); // i2cWrite  coef read 1020
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1024 ); // i2cWrite  coef read 1024
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1028 ); // i2cWrite  coef write 1028
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1035 ); // i2cWrite  coef read 1035
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1039 ); // i2cWrite  coef write 1039
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1043 ); // i2cWrite  coef write 1043
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 1047 ); // i2cWrite  coef write 1047
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1051 ); // i2cWrite  coef read 1051
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1055 ); // i2cWrite  coef read 1055
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1059 ); // i2cWrite  coef read 1059
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1063 ); // i2cWrite  coef write 1063
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x62 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x62, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1070 ); // i2cRead  coef read 1070
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1074 ); // i2cRead  coef write 1074
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1078 ); // i2cRead  coef write 1078
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 1082 ); // i2cRead  coef write 1082
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1086 ); // i2cRead  coef read 1086
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1090 ); // i2cRead  coef read 1090
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 1094 ); // i2cRead  coef read 1094
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1098 ); // i2cRead  coef read 1098
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1102 ); // i2cRead  coef write 1102
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1109 ); // i2cWrite  coef read 1109
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1113 ); // i2cWrite  coef write 1113
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1117 ); // i2cWrite  coef write 1117
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 1121 ); // i2cWrite  coef write 1121
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1125 ); // i2cWrite  coef read 1125
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1129 ); // i2cWrite  coef read 1129
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1133 ); // i2cWrite  coef read 1133
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1137 ); // i2cWrite  coef write 1137
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1144 ); // i2cWrite  coef read 1144
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1148 ); // i2cWrite  coef write 1148
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1152 ); // i2cWrite  coef write 1152
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 1156 ); // i2cWrite  coef write 1156
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1160 ); // i2cWrite  coef read 1160
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1164 ); // i2cWrite  coef read 1164
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1168 ); // i2cWrite  coef read 1168
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1172 ); // i2cWrite  coef write 1172
//      snd_hda i2cWrite end

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 1180 ); //   coef read 1180
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 1184 ); //   coef write 1184
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 1188 ); //   coef read 1188
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 1192 ); //   coef write 1192
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 1196 ); //   coef read 1196

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 1201 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1201
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 1205 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 1205
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 1209 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1209

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 1212

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 1218);
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1222 ); // i2cWrite  coef read 1222
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1226 ); // i2cWrite  coef write 1226
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1230 ); // i2cWrite  coef write 1230
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 1234 ); // i2cWrite  coef write 1234
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1238 ); // i2cWrite  coef read 1238
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1242 ); // i2cWrite  coef read 1242
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1246 ); // i2cWrite  coef read 1246
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1250 ); // i2cWrite  coef write 1250
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1257 ); // i2cWrite  coef read 1257
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1261 ); // i2cWrite  coef write 1261
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1265 ); // i2cWrite  coef write 1265
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 1269 ); // i2cWrite  coef write 1269
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1273 ); // i2cWrite  coef read 1273
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1277 ); // i2cWrite  coef read 1277
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1281 ); // i2cWrite  coef read 1281
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1285 ); // i2cWrite  coef write 1285
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1504 i2c data 0x0004   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0015, 0x0004, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1292 ); // i2cWrite  coef read 1292
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1296 ); // i2cWrite  coef write 1296
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1300 ); // i2cWrite  coef write 1300
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1504, 0x00000000, 1304 ); // i2cWrite  coef write 1304
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1308 ); // i2cWrite  coef read 1308
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1312 ); // i2cWrite  coef read 1312
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1316 ); // i2cWrite  coef read 1316
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1320 ); // i2cWrite  coef write 1320
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1327 ); // i2cWrite  coef read 1327
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1331 ); // i2cWrite  coef write 1331
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1335 ); // i2cWrite  coef write 1335
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 1339 ); // i2cWrite  coef write 1339
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1343 ); // i2cWrite  coef read 1343
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1347 ); // i2cWrite  coef read 1347
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1351 ); // i2cWrite  coef read 1351
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1355 ); // i2cWrite  coef write 1355
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1802 i2c data 0x0002   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0018, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1362 ); // i2cWrite  coef read 1362
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1366 ); // i2cWrite  coef write 1366
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1370 ); // i2cWrite  coef write 1370
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1802, 0x00000000, 1374 ); // i2cWrite  coef write 1374
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1378 ); // i2cWrite  coef read 1378
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1382 ); // i2cWrite  coef read 1382
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1386 ); // i2cWrite  coef read 1386
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1390 ); // i2cWrite  coef write 1390
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1397 ); // i2cWrite  coef read 1397
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1401 ); // i2cWrite  coef write 1401
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1405 ); // i2cWrite  coef write 1405
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 1409 ); // i2cWrite  coef write 1409
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1413 ); // i2cWrite  coef read 1413
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1417 ); // i2cWrite  coef read 1417
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1421 ); // i2cWrite  coef read 1421
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1425 ); // i2cWrite  coef write 1425
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1432 ); // i2cWrite  coef read 1432
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1436 ); // i2cWrite  coef write 1436
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1440 ); // i2cWrite  coef write 1440
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 1444 ); // i2cWrite  coef write 1444
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1448 ); // i2cWrite  coef read 1448
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1452 ); // i2cWrite  coef read 1452
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1456 ); // i2cWrite  coef read 1456
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1460 ); // i2cWrite  coef write 1460
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1467 ); // i2cWrite  coef read 1467
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1471 ); // i2cWrite  coef write 1471
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1475 ); // i2cWrite  coef write 1475
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 1479 ); // i2cWrite  coef write 1479
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1483 ); // i2cWrite  coef read 1483
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1487 ); // i2cWrite  coef read 1487
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1491 ); // i2cWrite  coef read 1491
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1495 ); // i2cWrite  coef write 1495
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1502 ); // i2cWrite  coef read 1502
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1506 ); // i2cWrite  coef write 1506
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1510 ); // i2cWrite  coef write 1510
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 1514 ); // i2cWrite  coef write 1514
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1518 ); // i2cWrite  coef read 1518
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1522 ); // i2cWrite  coef read 1522
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1526 ); // i2cWrite  coef read 1526
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1530 ); // i2cWrite  coef write 1530
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1537 ); // i2cWrite  coef read 1537
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1541 ); // i2cWrite  coef write 1541
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1545 ); // i2cWrite  coef write 1545
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 1549 ); // i2cWrite  coef write 1549
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1553 ); // i2cWrite  coef read 1553
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1557 ); // i2cWrite  coef read 1557
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1561 ); // i2cWrite  coef read 1561
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1565 ); // i2cWrite  coef write 1565
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1572 ); // i2cWrite  coef read 1572
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1576 ); // i2cWrite  coef write 1576
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1580 ); // i2cWrite  coef write 1580
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 1584 ); // i2cWrite  coef write 1584
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1588 ); // i2cWrite  coef read 1588
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1592 ); // i2cWrite  coef read 1592
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1596 ); // i2cWrite  coef read 1596
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1600 ); // i2cWrite  coef write 1600
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x74 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x74, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1607 ); // i2cRead  coef read 1607
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1611 ); // i2cRead  coef write 1611
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1615 ); // i2cRead  coef write 1615
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 1619 ); // i2cRead  coef write 1619
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1623 ); // i2cRead  coef read 1623
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1627 ); // i2cRead  coef read 1627
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 1631 ); // i2cRead  coef read 1631
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1635 ); // i2cRead  coef read 1635
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1639 ); // i2cRead  coef write 1639
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1646 ); // i2cWrite  coef read 1646
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1650 ); // i2cWrite  coef write 1650
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1654 ); // i2cWrite  coef write 1654
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 1658 ); // i2cWrite  coef write 1658
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1662 ); // i2cWrite  coef read 1662
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1666 ); // i2cWrite  coef read 1666
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1670 ); // i2cWrite  coef read 1670
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1674 ); // i2cWrite  coef write 1674
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1681 ); // i2cWrite  coef read 1681
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1685 ); // i2cWrite  coef write 1685
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1689 ); // i2cWrite  coef write 1689
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 1693 ); // i2cWrite  coef write 1693
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1697 ); // i2cWrite  coef read 1697
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1701 ); // i2cWrite  coef read 1701
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1705 ); // i2cWrite  coef read 1705
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1709 ); // i2cWrite  coef write 1709
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1716 ); // i2cWrite  coef read 1716
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1720 ); // i2cWrite  coef write 1720
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1724 ); // i2cWrite  coef write 1724
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 1728 ); // i2cWrite  coef write 1728
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1732 ); // i2cWrite  coef read 1732
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1736 ); // i2cWrite  coef read 1736
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1740 ); // i2cWrite  coef read 1740
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1744 ); // i2cWrite  coef write 1744
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1751 ); // i2cWrite  coef read 1751
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1755 ); // i2cWrite  coef write 1755
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1759 ); // i2cWrite  coef write 1759
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 1763 ); // i2cWrite  coef write 1763
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1767 ); // i2cWrite  coef read 1767
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1771 ); // i2cWrite  coef read 1771
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1775 ); // i2cWrite  coef read 1775
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1779 ); // i2cWrite  coef write 1779
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1508 i2c data 0x0008   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0015, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1786 ); // i2cWrite  coef read 1786
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1790 ); // i2cWrite  coef write 1790
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1794 ); // i2cWrite  coef write 1794
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1508, 0x00000000, 1798 ); // i2cWrite  coef write 1798
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1802 ); // i2cWrite  coef read 1802
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1806 ); // i2cWrite  coef read 1806
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1810 ); // i2cWrite  coef read 1810
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1814 ); // i2cWrite  coef write 1814
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1821 ); // i2cWrite  coef read 1821
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1825 ); // i2cWrite  coef write 1825
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1829 ); // i2cWrite  coef write 1829
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 1833 ); // i2cWrite  coef write 1833
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1837 ); // i2cWrite  coef read 1837
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1841 ); // i2cWrite  coef read 1841
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1845 ); // i2cWrite  coef read 1845
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1849 ); // i2cWrite  coef write 1849
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1803 i2c data 0x0003   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0018, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1856 ); // i2cWrite  coef read 1856
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1860 ); // i2cWrite  coef write 1860
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1864 ); // i2cWrite  coef write 1864
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1803, 0x00000000, 1868 ); // i2cWrite  coef write 1868
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1872 ); // i2cWrite  coef read 1872
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1876 ); // i2cWrite  coef read 1876
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1880 ); // i2cWrite  coef read 1880
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1884 ); // i2cWrite  coef write 1884
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1891 ); // i2cWrite  coef read 1891
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1895 ); // i2cWrite  coef write 1895
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1899 ); // i2cWrite  coef write 1899
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 1903 ); // i2cWrite  coef write 1903
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1907 ); // i2cWrite  coef read 1907
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1911 ); // i2cWrite  coef read 1911
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1915 ); // i2cWrite  coef read 1915
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1919 ); // i2cWrite  coef write 1919
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1926 ); // i2cWrite  coef read 1926
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1930 ); // i2cWrite  coef write 1930
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1934 ); // i2cWrite  coef write 1934
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 1938 ); // i2cWrite  coef write 1938
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1942 ); // i2cWrite  coef read 1942
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1946 ); // i2cWrite  coef read 1946
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1950 ); // i2cWrite  coef read 1950
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1954 ); // i2cWrite  coef write 1954
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1961 ); // i2cWrite  coef read 1961
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1965 ); // i2cWrite  coef write 1965
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1969 ); // i2cWrite  coef write 1969
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 1973 ); // i2cWrite  coef write 1973
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1977 ); // i2cWrite  coef read 1977
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1981 ); // i2cWrite  coef read 1981
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1985 ); // i2cWrite  coef read 1985
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1989 ); // i2cWrite  coef write 1989
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1996 ); // i2cWrite  coef read 1996
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2000 ); // i2cWrite  coef write 2000
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2004 ); // i2cWrite  coef write 2004
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 2008 ); // i2cWrite  coef write 2008
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2012 ); // i2cWrite  coef read 2012
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2016 ); // i2cWrite  coef read 2016
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2020 ); // i2cWrite  coef read 2020
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2024 ); // i2cWrite  coef write 2024
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2031 ); // i2cWrite  coef read 2031
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2035 ); // i2cWrite  coef write 2035
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2039 ); // i2cWrite  coef write 2039
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 2043 ); // i2cWrite  coef write 2043
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2047 ); // i2cWrite  coef read 2047
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2051 ); // i2cWrite  coef read 2051
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2055 ); // i2cWrite  coef read 2055
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2059 ); // i2cWrite  coef write 2059
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2066 ); // i2cWrite  coef read 2066
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2070 ); // i2cWrite  coef write 2070
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2074 ); // i2cWrite  coef write 2074
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 2078 ); // i2cWrite  coef write 2078
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2082 ); // i2cWrite  coef read 2082
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2086 ); // i2cWrite  coef read 2086
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2090 ); // i2cWrite  coef read 2090
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2094 ); // i2cWrite  coef write 2094
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x72 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x72, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2101 ); // i2cRead  coef read 2101
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2105 ); // i2cRead  coef write 2105
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2109 ); // i2cRead  coef write 2109
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 2113 ); // i2cRead  coef write 2113
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2117 ); // i2cRead  coef read 2117
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2121 ); // i2cRead  coef read 2121
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 2125 ); // i2cRead  coef read 2125
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2129 ); // i2cRead  coef read 2129
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2133 ); // i2cRead  coef write 2133
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2140 ); // i2cWrite  coef read 2140
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2144 ); // i2cWrite  coef write 2144
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2148 ); // i2cWrite  coef write 2148
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 2152 ); // i2cWrite  coef write 2152
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2156 ); // i2cWrite  coef read 2156
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2160 ); // i2cWrite  coef read 2160
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2164 ); // i2cWrite  coef read 2164
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2168 ); // i2cWrite  coef write 2168
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2175 ); // i2cWrite  coef read 2175
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2179 ); // i2cWrite  coef write 2179
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2183 ); // i2cWrite  coef write 2183
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 2187 ); // i2cWrite  coef write 2187
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2191 ); // i2cWrite  coef read 2191
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2195 ); // i2cWrite  coef read 2195
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2199 ); // i2cWrite  coef read 2199
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2203 ); // i2cWrite  coef write 2203
//      snd_hda i2cWrite end

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 2209);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 2211 ); // coef write mask 2211
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 2211 ); // coef write mask 2211

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 2217);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 2219 ); // coef write mask 2219
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 2219 ); // coef write mask 2219

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]
        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        // additional power status not in boot code
        retpower1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2232);
        retpower2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2233);


        // there is additional code in the boot stage

        // following is common code for boot and unmute etc

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 2240);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0x00000003, 2242 ); // coef write mask 2242
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0xundef, 0x00000003, 2242 ); // coef write mask 2242

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 2248);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000002, 2250 ); // coef write mask 2250
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0xundef, 0x00000002, 2250 ); // coef write mask 2250
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 2256 ); //   coef read 2256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 2260 ); //   coef read 2260
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 2264 ); // coef write mask 2264
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 2264 ); // coef write mask 2264

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2274 ); // i2cWrite  coef read 2274
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2278 ); // i2cWrite  coef write 2278
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 2282 ); // i2cWrite  coef write 2282
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2286 ); // i2cWrite  coef write 2286
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2290 ); // i2cWrite  coef read 2290
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2294 ); // i2cWrite  coef read 2294
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2298 ); // i2cWrite  coef read 2298
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2302 ); // i2cWrite  coef write 2302
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2309 ); // i2cWrite  coef read 2309
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2313 ); // i2cWrite  coef write 2313
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 2317 ); // i2cWrite  coef write 2317
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2321 ); // i2cWrite  coef write 2321
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2325 ); // i2cWrite  coef read 2325
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2329 ); // i2cWrite  coef read 2329
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2333 ); // i2cWrite  coef read 2333
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2337 ); // i2cWrite  coef write 2337
//      snd_hda i2cWrite end

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 2343 ); //   coef read 2343
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8800, 0x00000000, 2347 ); //   coef write 2347
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 2351 ); //   coef read 2351
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8820, 0x00000000, 2355 ); //   coef write 2355
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 2359 ); //   coef read 2359
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 2363 ); //   coef read 2363
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 2367 ); //   coef read 2367

        // boot code addition
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 2372 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 2372
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 2376 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 2376
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 2380 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 2380

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 2383

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 2 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 2389);

        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     36 []

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2393 ); // i2cWrite  coef read 2393
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2397 ); // i2cWrite  coef write 2397
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 2401 ); // i2cWrite  coef write 2401
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2405 ); // i2cWrite  coef write 2405
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2409 ); // i2cWrite  coef read 2409
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2413 ); // i2cWrite  coef read 2413
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2417 ); // i2cWrite  coef read 2417
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2421 ); // i2cWrite  coef write 2421
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2428 ); // i2cWrite  coef read 2428
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2432 ); // i2cWrite  coef write 2432
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2436 ); // i2cWrite  coef write 2436
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2440 ); // i2cWrite  coef write 2440
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2444 ); // i2cWrite  coef read 2444
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2448 ); // i2cWrite  coef read 2448
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2452 ); // i2cWrite  coef read 2452
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2456 ); // i2cWrite  coef write 2456
//      snd_hda i2cWrite end

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 2462 ); //   coef read 2462
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8840, 0x00000000, 2466 ); //   coef write 2466
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 2470 ); //   coef read 2470
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8860, 0x00000000, 2474 ); //   coef write 2474
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00005401, 2478 ); // coef write mask 2478
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xundef, 0x00005401, 2478 ); // coef write mask 2478
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000220, 2484 ); //   coef read 2484
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 2488 ); //   coef write 2488


        // the following duplicates the boot sequence in cs8409_init_coef2

        //snd_hda_coef_sequence(codec, cs8409_init_coef2, "init_coef2");

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 2492 ); //   coef read 2492
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 2496 ); //   coef read 2496
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 2500 ); //   coef read 2500
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 2504 ); //   coef read 2504
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008000, 2508 ); //   coef read 2508
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 2512 ); //   coef read 2512
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008000, 2516 ); //   coef read 2516
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 2520 ); //   coef read 2520
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 2524 ); //   coef read 2524
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 2528 ); //   coef read 2528
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 2532 ); //   coef read 2532
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 2536 ); //   coef read 2536
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 2540 ); //   coef read 2540
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 2544 ); //   coef read 2544
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 2548 ); //   coef read 2548
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 2552 ); //   coef read 2552
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 2556 ); //   coef read 2556
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 2560 ); //   coef read 2560
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 2564 ); //   coef read 2564
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 2568 ); //   coef read 2568
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 2572 ); //   coef read 2572
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 2576 ); //   coef read 2576
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 2580 ); //   coef read 2580
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 2584 ); //   coef read 2584
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 2588 ); //   coef read 2588
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 2592 ); //   coef read 2592
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 2596 ); //   coef read 2596
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 2600 ); //   coef read 2600
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 2604 ); //   coef read 2604
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 2608 ); //   coef read 2608
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 2612 ); //   coef read 2612
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 2616 ); //   coef read 2616
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 2620 ); //   coef read 2620
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 2624 ); //   coef read 2624
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 2628 ); //   coef read 2628
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 2632 ); //   coef read 2632
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 2636 ); //   coef read 2636
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 2640 ); //   coef read 2640
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 2644 ); //   coef read 2644
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 2648 ); //   coef read 2648
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 2652 ); //   coef read 2652
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 2656 ); //   coef read 2656
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 2660 ); //   coef read 2660
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 2664 ); //   coef read 2664
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 2668 ); //   coef read 2668
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 2672 ); //   coef read 2672
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 2676 ); //   coef read 2676
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 2680 ); //   coef read 2680
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 2684 ); //   coef read 2684
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 2688 ); //   coef read 2688
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 2692 ); //   coef read 2692
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 2696 ); //   coef read 2696
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 2700 ); //   coef read 2700
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 2704 ); //   coef read 2704
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 2708 ); //   coef read 2708
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 2712 ); //   coef read 2712
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 2716 ); //   coef read 2716
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 2720 ); //   coef read 2720
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 2724 ); //   coef read 2724
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 2728 ); //   coef read 2728
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 2732 ); //   coef read 2732
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 2736 ); //   coef read 2736
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 2740 ); //   coef read 2740
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 2745 ); //   coef write 2745

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 3 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 2754);

        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     37 []

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2761 ); // i2cWrite  coef read 2761
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2765 ); // i2cWrite  coef write 2765
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 2769 ); // i2cWrite  coef write 2769
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2773 ); // i2cWrite  coef write 2773
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2777 ); // i2cWrite  coef read 2777
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2781 ); // i2cWrite  coef read 2781
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2785 ); // i2cWrite  coef read 2785
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2789 ); // i2cWrite  coef write 2789
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2796 ); // i2cWrite  coef read 2796
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2800 ); // i2cWrite  coef write 2800
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 2804 ); // i2cWrite  coef write 2804
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2808 ); // i2cWrite  coef write 2808
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2812 ); // i2cWrite  coef read 2812
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2816 ); // i2cWrite  coef read 2816
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2820 ); // i2cWrite  coef read 2820
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2824 ); // i2cWrite  coef write 2824
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2838 ); // i2cWrite  coef read 2838
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2842 ); // i2cWrite  coef write 2842
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 2846 ); // i2cWrite  coef write 2846
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2850 ); // i2cWrite  coef write 2850
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2854 ); // i2cWrite  coef read 2854
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2858 ); // i2cWrite  coef read 2858
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2862 ); // i2cWrite  coef read 2862
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2866 ); // i2cWrite  coef write 2866
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2877 ); // i2cWrite  coef read 2877
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2881 ); // i2cWrite  coef write 2881
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2885 ); // i2cWrite  coef write 2885
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2889 ); // i2cWrite  coef write 2889
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2893 ); // i2cWrite  coef read 2893
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2897 ); // i2cWrite  coef read 2897
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2901 ); // i2cWrite  coef read 2901
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2905 ); // i2cWrite  coef write 2905
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        retpower1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2912);
        retpower2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2913);

        printk("snd_hda_intel: command nid end cs_8409_unmute");

}


static void cs_8409_volup(struct hda_codec *codec)
{
	int retval;

	int retwake;

        int retconv;

        int retpower1;
        int retpower2;

	printk("snd_hda_intel: command nid cs_8409_volup");

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 37 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 37
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 41 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 41
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 45 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 45
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 49 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 49
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 53 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 53
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 57 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 57
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 61 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 61
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 65 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 65
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 69 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 69
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 73 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 73
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 77 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 77

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x00008000, 81 ); // coef write mask 81
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x00008000, 81 ); // coef write mask 81
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 87 ); // coef write mask 87
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 87 ); // coef write mask 87
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 93 ); // coef write mask 93
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 93 ); // coef write mask 93
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000280, 99 ); // coef write mask 99

//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000280, 99 ); // coef write mask 99
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 105 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 105
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 109 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 109
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 113 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 113

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 118 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 118
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 122 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 122
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 126 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 126

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 129

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 134 ); // coef write mask 134
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 134 ); // coef write mask 134
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 140 ); // coef write mask 140
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 140 ); // coef write mask 140
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x000008ff, 146 ); // coef write mask 146
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x000008ff, 146 ); // coef write mask 146

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 153);

        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 157 ); // i2cWrite  coef read 157
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 161 ); // i2cWrite  coef write 161
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 165 ); // i2cWrite  coef write 165
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 169 ); // i2cWrite  coef write 169
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 173 ); // i2cWrite  coef read 173
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 177 ); // i2cWrite  coef read 177
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 181 ); // i2cWrite  coef read 181
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 185 ); // i2cWrite  coef write 185
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 192 ); // i2cWrite  coef read 192
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 196 ); // i2cWrite  coef write 196
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 200 ); // i2cWrite  coef write 200
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 204 ); // i2cWrite  coef write 204
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 208 ); // i2cWrite  coef read 208
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 212 ); // i2cWrite  coef read 212
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 216 ); // i2cWrite  coef read 216
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 220 ); // i2cWrite  coef write 220
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1501 i2c data 0x0001   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0015, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 227 ); // i2cWrite  coef read 227
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 231 ); // i2cWrite  coef write 231
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 235 ); // i2cWrite  coef write 235
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1501, 0x00000000, 239 ); // i2cWrite  coef write 239
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 243 ); // i2cWrite  coef read 243
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 247 ); // i2cWrite  coef read 247
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 251 ); // i2cWrite  coef read 251
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 255 ); // i2cWrite  coef write 255
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 262 ); // i2cWrite  coef read 262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 266 ); // i2cWrite  coef write 266
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 270 ); // i2cWrite  coef write 270
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 274 ); // i2cWrite  coef write 274
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 278 ); // i2cWrite  coef read 278
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 282 ); // i2cWrite  coef read 282
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 286 ); // i2cWrite  coef read 286
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 290 ); // i2cWrite  coef write 290
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1800 i2c data 0x0000   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0018, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 297 ); // i2cWrite  coef read 297
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 301 ); // i2cWrite  coef write 301
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 305 ); // i2cWrite  coef write 305
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1800, 0x00000000, 309 ); // i2cWrite  coef write 309
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 313 ); // i2cWrite  coef read 313
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 317 ); // i2cWrite  coef read 317
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 321 ); // i2cWrite  coef read 321
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 325 ); // i2cWrite  coef write 325
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 332 ); // i2cWrite  coef read 332
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 336 ); // i2cWrite  coef write 336
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 340 ); // i2cWrite  coef write 340
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 344 ); // i2cWrite  coef write 344
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 348 ); // i2cWrite  coef read 348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 352 ); // i2cWrite  coef read 352
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 356 ); // i2cWrite  coef read 356
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 360 ); // i2cWrite  coef write 360
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 367 ); // i2cWrite  coef read 367
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 371 ); // i2cWrite  coef write 371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 375 ); // i2cWrite  coef write 375
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 379 ); // i2cWrite  coef write 379
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 383 ); // i2cWrite  coef read 383
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 387 ); // i2cWrite  coef read 387
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 391 ); // i2cWrite  coef read 391
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 395 ); // i2cWrite  coef write 395
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 402 ); // i2cWrite  coef read 402
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 406 ); // i2cWrite  coef write 406
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 410 ); // i2cWrite  coef write 410
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 414 ); // i2cWrite  coef write 414
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 418 ); // i2cWrite  coef read 418
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 422 ); // i2cWrite  coef read 422
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 426 ); // i2cWrite  coef read 426
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 430 ); // i2cWrite  coef write 430
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 437 ); // i2cWrite  coef read 437
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 441 ); // i2cWrite  coef write 441
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 445 ); // i2cWrite  coef write 445
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 449 ); // i2cWrite  coef write 449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 453 ); // i2cWrite  coef read 453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 457 ); // i2cWrite  coef read 457
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 461 ); // i2cWrite  coef read 461
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 465 ); // i2cWrite  coef write 465
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 472 ); // i2cWrite  coef read 472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 476 ); // i2cWrite  coef write 476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 480 ); // i2cWrite  coef write 480
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 484 ); // i2cWrite  coef write 484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 488 ); // i2cWrite  coef read 488
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 492 ); // i2cWrite  coef read 492
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 496 ); // i2cWrite  coef read 496
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 500 ); // i2cWrite  coef write 500
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 507 ); // i2cWrite  coef read 507
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 511 ); // i2cWrite  coef write 511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 515 ); // i2cWrite  coef write 515
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 519 ); // i2cWrite  coef write 519
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 523 ); // i2cWrite  coef read 523
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 527 ); // i2cWrite  coef read 527
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 531 ); // i2cWrite  coef read 531
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 535 ); // i2cWrite  coef write 535
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x64, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 542 ); // i2cRead  coef read 542
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 546 ); // i2cRead  coef write 546
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 550 ); // i2cRead  coef write 550
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 554 ); // i2cRead  coef write 554
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 558 ); // i2cRead  coef read 558
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 562 ); // i2cRead  coef read 562
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 566 ); // i2cRead  coef read 566
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 570 ); // i2cRead  coef read 570
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 574 ); // i2cRead  coef write 574
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 581 ); // i2cWrite  coef read 581
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 585 ); // i2cWrite  coef write 585
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 589 ); // i2cWrite  coef write 589
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 593 ); // i2cWrite  coef write 593
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 597 ); // i2cWrite  coef read 597
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 601 ); // i2cWrite  coef read 601
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 605 ); // i2cWrite  coef read 605
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 609 ); // i2cWrite  coef write 609
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 616 ); // i2cWrite  coef read 616
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 620 ); // i2cWrite  coef write 620
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 624 ); // i2cWrite  coef write 624
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 628 ); // i2cWrite  coef write 628
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 632 ); // i2cWrite  coef read 632
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 636 ); // i2cWrite  coef read 636
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 640 ); // i2cWrite  coef read 640
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 644 ); // i2cWrite  coef write 644
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 651 ); // i2cWrite  coef read 651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 655 ); // i2cWrite  coef write 655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 659 ); // i2cWrite  coef write 659
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 663 ); // i2cWrite  coef write 663
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 667 ); // i2cWrite  coef read 667
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 671 ); // i2cWrite  coef read 671
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 675 ); // i2cWrite  coef read 675
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 679 ); // i2cWrite  coef write 679
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 686 ); // i2cWrite  coef read 686
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 690 ); // i2cWrite  coef write 690
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 694 ); // i2cWrite  coef write 694
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 698 ); // i2cWrite  coef write 698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 702 ); // i2cWrite  coef read 702
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 706 ); // i2cWrite  coef read 706
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 710 ); // i2cWrite  coef read 710
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 714 ); // i2cWrite  coef write 714
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1502 i2c data 0x0002   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0015, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 721 ); // i2cWrite  coef read 721
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 725 ); // i2cWrite  coef write 725
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 729 ); // i2cWrite  coef write 729
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1502, 0x00000000, 733 ); // i2cWrite  coef write 733
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 737 ); // i2cWrite  coef read 737
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 741 ); // i2cWrite  coef read 741
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 745 ); // i2cWrite  coef read 745
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 749 ); // i2cWrite  coef write 749
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 756 ); // i2cWrite  coef read 756
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 760 ); // i2cWrite  coef write 760
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 764 ); // i2cWrite  coef write 764
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 768 ); // i2cWrite  coef write 768
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 772 ); // i2cWrite  coef read 772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 776 ); // i2cWrite  coef read 776
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 780 ); // i2cWrite  coef read 780
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 784 ); // i2cWrite  coef write 784
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1801 i2c data 0x0001   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0018, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 791 ); // i2cWrite  coef read 791
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 795 ); // i2cWrite  coef write 795
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 799 ); // i2cWrite  coef write 799
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1801, 0x00000000, 803 ); // i2cWrite  coef write 803
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 807 ); // i2cWrite  coef read 807
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 811 ); // i2cWrite  coef read 811
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 815 ); // i2cWrite  coef read 815
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 819 ); // i2cWrite  coef write 819
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 826 ); // i2cWrite  coef read 826
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 830 ); // i2cWrite  coef write 830
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 834 ); // i2cWrite  coef write 834
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 838 ); // i2cWrite  coef write 838
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 842 ); // i2cWrite  coef read 842
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 846 ); // i2cWrite  coef read 846
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 850 ); // i2cWrite  coef read 850
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 854 ); // i2cWrite  coef write 854
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 861 ); // i2cWrite  coef read 861
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 865 ); // i2cWrite  coef write 865
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 869 ); // i2cWrite  coef write 869
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 873 ); // i2cWrite  coef write 873
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 877 ); // i2cWrite  coef read 877
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 881 ); // i2cWrite  coef read 881
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 885 ); // i2cWrite  coef read 885
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 889 ); // i2cWrite  coef write 889
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 896 ); // i2cWrite  coef read 896
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 900 ); // i2cWrite  coef write 900
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 904 ); // i2cWrite  coef write 904
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 908 ); // i2cWrite  coef write 908
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 912 ); // i2cWrite  coef read 912
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 916 ); // i2cWrite  coef read 916
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 920 ); // i2cWrite  coef read 920
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 924 ); // i2cWrite  coef write 924
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 931 ); // i2cWrite  coef read 931
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 935 ); // i2cWrite  coef write 935
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 939 ); // i2cWrite  coef write 939
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 943 ); // i2cWrite  coef write 943
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 947 ); // i2cWrite  coef read 947
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 951 ); // i2cWrite  coef read 951
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 955 ); // i2cWrite  coef read 955
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 959 ); // i2cWrite  coef write 959
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 966 ); // i2cWrite  coef read 966
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 970 ); // i2cWrite  coef write 970
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 974 ); // i2cWrite  coef write 974
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 978 ); // i2cWrite  coef write 978
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 982 ); // i2cWrite  coef read 982
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 986 ); // i2cWrite  coef read 986
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 990 ); // i2cWrite  coef read 990
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 994 ); // i2cWrite  coef write 994
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1001 ); // i2cWrite  coef read 1001
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1005 ); // i2cWrite  coef write 1005
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1009 ); // i2cWrite  coef write 1009
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 1013 ); // i2cWrite  coef write 1013
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1017 ); // i2cWrite  coef read 1017
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1021 ); // i2cWrite  coef read 1021
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1025 ); // i2cWrite  coef read 1025
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1029 ); // i2cWrite  coef write 1029
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x62 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x62, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1036 ); // i2cRead  coef read 1036
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1040 ); // i2cRead  coef write 1040
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1044 ); // i2cRead  coef write 1044
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 1048 ); // i2cRead  coef write 1048
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1052 ); // i2cRead  coef read 1052
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1056 ); // i2cRead  coef read 1056
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 1060 ); // i2cRead  coef read 1060
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1064 ); // i2cRead  coef read 1064
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1068 ); // i2cRead  coef write 1068
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1075 ); // i2cWrite  coef read 1075
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1079 ); // i2cWrite  coef write 1079
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1083 ); // i2cWrite  coef write 1083
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 1087 ); // i2cWrite  coef write 1087
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1091 ); // i2cWrite  coef read 1091
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1095 ); // i2cWrite  coef read 1095
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1099 ); // i2cWrite  coef read 1099
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1103 ); // i2cWrite  coef write 1103
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1110 ); // i2cWrite  coef read 1110
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1114 ); // i2cWrite  coef write 1114
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1118 ); // i2cWrite  coef write 1118
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 1122 ); // i2cWrite  coef write 1122
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1126 ); // i2cWrite  coef read 1126
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1130 ); // i2cWrite  coef read 1130
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1134 ); // i2cWrite  coef read 1134
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1138 ); // i2cWrite  coef write 1138
//      snd_hda i2cWrite end

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 1146 ); //   coef read 1146
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 1150 ); //   coef write 1150
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 1154 ); //   coef read 1154
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 1158 ); //   coef write 1158
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 1162 ); //   coef read 1162

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 1167 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1167
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 1171 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 1171
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 1175 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1175

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 1178

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 1184);

        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1188 ); // i2cWrite  coef read 1188
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1192 ); // i2cWrite  coef write 1192
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1196 ); // i2cWrite  coef write 1196
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 1200 ); // i2cWrite  coef write 1200
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1204 ); // i2cWrite  coef read 1204
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1208 ); // i2cWrite  coef read 1208
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1212 ); // i2cWrite  coef read 1212
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1216 ); // i2cWrite  coef write 1216
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1223 ); // i2cWrite  coef read 1223
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1227 ); // i2cWrite  coef write 1227
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1231 ); // i2cWrite  coef write 1231
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 1235 ); // i2cWrite  coef write 1235
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1239 ); // i2cWrite  coef read 1239
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1243 ); // i2cWrite  coef read 1243
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1247 ); // i2cWrite  coef read 1247
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1251 ); // i2cWrite  coef write 1251
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1504 i2c data 0x0004   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0015, 0x0004, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1258 ); // i2cWrite  coef read 1258
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1262 ); // i2cWrite  coef write 1262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1266 ); // i2cWrite  coef write 1266
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1504, 0x00000000, 1270 ); // i2cWrite  coef write 1270
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1274 ); // i2cWrite  coef read 1274
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1278 ); // i2cWrite  coef read 1278
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1282 ); // i2cWrite  coef read 1282
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1286 ); // i2cWrite  coef write 1286
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1293 ); // i2cWrite  coef read 1293
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1297 ); // i2cWrite  coef write 1297
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1301 ); // i2cWrite  coef write 1301
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 1305 ); // i2cWrite  coef write 1305
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1309 ); // i2cWrite  coef read 1309
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1313 ); // i2cWrite  coef read 1313
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1317 ); // i2cWrite  coef read 1317
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1321 ); // i2cWrite  coef write 1321
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1802 i2c data 0x0002   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0018, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1328 ); // i2cWrite  coef read 1328
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1332 ); // i2cWrite  coef write 1332
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1336 ); // i2cWrite  coef write 1336
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1802, 0x00000000, 1340 ); // i2cWrite  coef write 1340
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1344 ); // i2cWrite  coef read 1344
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1348 ); // i2cWrite  coef read 1348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1352 ); // i2cWrite  coef read 1352
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1356 ); // i2cWrite  coef write 1356
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1363 ); // i2cWrite  coef read 1363
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1367 ); // i2cWrite  coef write 1367
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1371 ); // i2cWrite  coef write 1371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 1375 ); // i2cWrite  coef write 1375
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1379 ); // i2cWrite  coef read 1379
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1383 ); // i2cWrite  coef read 1383
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1387 ); // i2cWrite  coef read 1387
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1391 ); // i2cWrite  coef write 1391
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1398 ); // i2cWrite  coef read 1398
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1402 ); // i2cWrite  coef write 1402
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1406 ); // i2cWrite  coef write 1406
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 1410 ); // i2cWrite  coef write 1410
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1414 ); // i2cWrite  coef read 1414
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1418 ); // i2cWrite  coef read 1418
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1422 ); // i2cWrite  coef read 1422
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1426 ); // i2cWrite  coef write 1426
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1433 ); // i2cWrite  coef read 1433
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1437 ); // i2cWrite  coef write 1437
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1441 ); // i2cWrite  coef write 1441
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 1445 ); // i2cWrite  coef write 1445
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1449 ); // i2cWrite  coef read 1449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1453 ); // i2cWrite  coef read 1453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1457 ); // i2cWrite  coef read 1457
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1461 ); // i2cWrite  coef write 1461
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1468 ); // i2cWrite  coef read 1468
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1472 ); // i2cWrite  coef write 1472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1476 ); // i2cWrite  coef write 1476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 1480 ); // i2cWrite  coef write 1480
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1484 ); // i2cWrite  coef read 1484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1488 ); // i2cWrite  coef read 1488
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1492 ); // i2cWrite  coef read 1492
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1496 ); // i2cWrite  coef write 1496
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1503 ); // i2cWrite  coef read 1503
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1507 ); // i2cWrite  coef write 1507
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1511 ); // i2cWrite  coef write 1511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 1515 ); // i2cWrite  coef write 1515
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1519 ); // i2cWrite  coef read 1519
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1523 ); // i2cWrite  coef read 1523
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1527 ); // i2cWrite  coef read 1527
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1531 ); // i2cWrite  coef write 1531
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1538 ); // i2cWrite  coef read 1538
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1542 ); // i2cWrite  coef write 1542
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1546 ); // i2cWrite  coef write 1546
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 1550 ); // i2cWrite  coef write 1550
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1554 ); // i2cWrite  coef read 1554
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1558 ); // i2cWrite  coef read 1558
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1562 ); // i2cWrite  coef read 1562
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1566 ); // i2cWrite  coef write 1566
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x74 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x74, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1573 ); // i2cRead  coef read 1573
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1577 ); // i2cRead  coef write 1577
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1581 ); // i2cRead  coef write 1581
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 1585 ); // i2cRead  coef write 1585
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1589 ); // i2cRead  coef read 1589
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1593 ); // i2cRead  coef read 1593
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 1597 ); // i2cRead  coef read 1597
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1601 ); // i2cRead  coef read 1601
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1605 ); // i2cRead  coef write 1605
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1612 ); // i2cWrite  coef read 1612
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1616 ); // i2cWrite  coef write 1616
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1620 ); // i2cWrite  coef write 1620
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 1624 ); // i2cWrite  coef write 1624
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1628 ); // i2cWrite  coef read 1628
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1632 ); // i2cWrite  coef read 1632
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1636 ); // i2cWrite  coef read 1636
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1640 ); // i2cWrite  coef write 1640
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1647 ); // i2cWrite  coef read 1647
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1651 ); // i2cWrite  coef write 1651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1655 ); // i2cWrite  coef write 1655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 1659 ); // i2cWrite  coef write 1659
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1663 ); // i2cWrite  coef read 1663
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1667 ); // i2cWrite  coef read 1667
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1671 ); // i2cWrite  coef read 1671
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1675 ); // i2cWrite  coef write 1675
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1682 ); // i2cWrite  coef read 1682
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1686 ); // i2cWrite  coef write 1686
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1690 ); // i2cWrite  coef write 1690
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 1694 ); // i2cWrite  coef write 1694
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1698 ); // i2cWrite  coef read 1698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1702 ); // i2cWrite  coef read 1702
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1706 ); // i2cWrite  coef read 1706
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1710 ); // i2cWrite  coef write 1710
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1717 ); // i2cWrite  coef read 1717
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1721 ); // i2cWrite  coef write 1721
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1725 ); // i2cWrite  coef write 1725
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 1729 ); // i2cWrite  coef write 1729
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1733 ); // i2cWrite  coef read 1733
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1737 ); // i2cWrite  coef read 1737
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1741 ); // i2cWrite  coef read 1741
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1745 ); // i2cWrite  coef write 1745
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1508 i2c data 0x0008   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0015, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1752 ); // i2cWrite  coef read 1752
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1756 ); // i2cWrite  coef write 1756
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1760 ); // i2cWrite  coef write 1760
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1508, 0x00000000, 1764 ); // i2cWrite  coef write 1764
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1768 ); // i2cWrite  coef read 1768
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1772 ); // i2cWrite  coef read 1772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1776 ); // i2cWrite  coef read 1776
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1780 ); // i2cWrite  coef write 1780
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1787 ); // i2cWrite  coef read 1787
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1791 ); // i2cWrite  coef write 1791
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1795 ); // i2cWrite  coef write 1795
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 1799 ); // i2cWrite  coef write 1799
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1803 ); // i2cWrite  coef read 1803
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1807 ); // i2cWrite  coef read 1807
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1811 ); // i2cWrite  coef read 1811
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1815 ); // i2cWrite  coef write 1815
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1803 i2c data 0x0003   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0018, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1822 ); // i2cWrite  coef read 1822
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1826 ); // i2cWrite  coef write 1826
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1830 ); // i2cWrite  coef write 1830
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1803, 0x00000000, 1834 ); // i2cWrite  coef write 1834
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1838 ); // i2cWrite  coef read 1838
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1842 ); // i2cWrite  coef read 1842
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1846 ); // i2cWrite  coef read 1846
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1850 ); // i2cWrite  coef write 1850
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1857 ); // i2cWrite  coef read 1857
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1861 ); // i2cWrite  coef write 1861
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1865 ); // i2cWrite  coef write 1865
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 1869 ); // i2cWrite  coef write 1869
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1873 ); // i2cWrite  coef read 1873
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1877 ); // i2cWrite  coef read 1877
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1881 ); // i2cWrite  coef read 1881
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1885 ); // i2cWrite  coef write 1885
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1892 ); // i2cWrite  coef read 1892
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1896 ); // i2cWrite  coef write 1896
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1900 ); // i2cWrite  coef write 1900
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 1904 ); // i2cWrite  coef write 1904
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1908 ); // i2cWrite  coef read 1908
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1912 ); // i2cWrite  coef read 1912
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1916 ); // i2cWrite  coef read 1916
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1920 ); // i2cWrite  coef write 1920
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1927 ); // i2cWrite  coef read 1927
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1931 ); // i2cWrite  coef write 1931
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1935 ); // i2cWrite  coef write 1935
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 1939 ); // i2cWrite  coef write 1939
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1943 ); // i2cWrite  coef read 1943
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1947 ); // i2cWrite  coef read 1947
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1951 ); // i2cWrite  coef read 1951
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1955 ); // i2cWrite  coef write 1955
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1962 ); // i2cWrite  coef read 1962
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1966 ); // i2cWrite  coef write 1966
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1970 ); // i2cWrite  coef write 1970
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 1974 ); // i2cWrite  coef write 1974
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1978 ); // i2cWrite  coef read 1978
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1982 ); // i2cWrite  coef read 1982
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1986 ); // i2cWrite  coef read 1986
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1990 ); // i2cWrite  coef write 1990
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1997 ); // i2cWrite  coef read 1997
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2001 ); // i2cWrite  coef write 2001
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2005 ); // i2cWrite  coef write 2005
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 2009 ); // i2cWrite  coef write 2009
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2013 ); // i2cWrite  coef read 2013
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2017 ); // i2cWrite  coef read 2017
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2021 ); // i2cWrite  coef read 2021
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2025 ); // i2cWrite  coef write 2025
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2032 ); // i2cWrite  coef read 2032
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2036 ); // i2cWrite  coef write 2036
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2040 ); // i2cWrite  coef write 2040
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 2044 ); // i2cWrite  coef write 2044
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2048 ); // i2cWrite  coef read 2048
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2052 ); // i2cWrite  coef read 2052
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2056 ); // i2cWrite  coef read 2056
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2060 ); // i2cWrite  coef write 2060
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x72 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x72, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2067 ); // i2cRead  coef read 2067
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2071 ); // i2cRead  coef write 2071
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2075 ); // i2cRead  coef write 2075
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 2079 ); // i2cRead  coef write 2079
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2083 ); // i2cRead  coef read 2083
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2087 ); // i2cRead  coef read 2087
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 2091 ); // i2cRead  coef read 2091
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2095 ); // i2cRead  coef read 2095
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2099 ); // i2cRead  coef write 2099
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2106 ); // i2cWrite  coef read 2106
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2110 ); // i2cWrite  coef write 2110
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2114 ); // i2cWrite  coef write 2114
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 2118 ); // i2cWrite  coef write 2118
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2122 ); // i2cWrite  coef read 2122
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2126 ); // i2cWrite  coef read 2126
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2130 ); // i2cWrite  coef read 2130
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2134 ); // i2cWrite  coef write 2134
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2141 ); // i2cWrite  coef read 2141
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2145 ); // i2cWrite  coef write 2145
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2149 ); // i2cWrite  coef write 2149
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 2153 ); // i2cWrite  coef write 2153
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2157 ); // i2cWrite  coef read 2157
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2161 ); // i2cWrite  coef read 2161
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2165 ); // i2cWrite  coef read 2165
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2169 ); // i2cWrite  coef write 2169
//      snd_hda i2cWrite end

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 2175);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 2177 ); // coef write mask 2177
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 2177 ); // coef write mask 2177

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 2183);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 2185 ); // coef write mask 2185
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 2185 ); // coef write mask 2185

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        retpower1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2198);
        retpower2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2199);


        // so up to this point volup and play are the same - only some power state differences at beginning
        // the following is unique to volup
        // the primary purpose of the following seems to be to disable the amps

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 2206);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0x00000003, 2208 ); // coef write mask 2208
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0xundef, 0x00000003, 2208 ); // coef write mask 2208

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 2214);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000002, 2216 ); // coef write mask 2216
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0xundef, 0x00000002, 2216 ); // coef write mask 2216
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 2222 ); //   coef read 2222
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 2226 ); //   coef read 2226
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 2230 ); // coef write mask 2230
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 2230 ); // coef write mask 2230

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2240 ); // i2cWrite  coef read 2240
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2244 ); // i2cWrite  coef write 2244
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 2248 ); // i2cWrite  coef write 2248
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2252 ); // i2cWrite  coef write 2252
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2256 ); // i2cWrite  coef read 2256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2260 ); // i2cWrite  coef read 2260
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2264 ); // i2cWrite  coef read 2264
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2268 ); // i2cWrite  coef write 2268
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2275 ); // i2cWrite  coef read 2275
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2279 ); // i2cWrite  coef write 2279
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 2283 ); // i2cWrite  coef write 2283
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2287 ); // i2cWrite  coef write 2287
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2291 ); // i2cWrite  coef read 2291
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2295 ); // i2cWrite  coef read 2295
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2299 ); // i2cWrite  coef read 2299
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2303 ); // i2cWrite  coef write 2303
//      snd_hda i2cWrite end

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 2309 ); //   coef read 2309
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8800, 0x00000000, 2313 ); //   coef write 2313
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 2317 ); //   coef read 2317
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8820, 0x00000000, 2321 ); //   coef write 2321
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 2325 ); //   coef read 2325
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 2329 ); //   coef read 2329
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 2333 ); //   coef read 2333

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 2338 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 2338
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 2342 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 2342
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 2346 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 2346

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 2349

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 2 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 2355);

        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     36 []

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2359 ); // i2cWrite  coef read 2359
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2363 ); // i2cWrite  coef write 2363
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 2367 ); // i2cWrite  coef write 2367
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2371 ); // i2cWrite  coef write 2371
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2375 ); // i2cWrite  coef read 2375
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2379 ); // i2cWrite  coef read 2379
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2383 ); // i2cWrite  coef read 2383
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2387 ); // i2cWrite  coef write 2387
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2394 ); // i2cWrite  coef read 2394
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2398 ); // i2cWrite  coef write 2398
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2402 ); // i2cWrite  coef write 2402
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2406 ); // i2cWrite  coef write 2406
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2410 ); // i2cWrite  coef read 2410
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2414 ); // i2cWrite  coef read 2414
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2418 ); // i2cWrite  coef read 2418
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2422 ); // i2cWrite  coef write 2422
//      snd_hda i2cWrite end

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 2428 ); //   coef read 2428
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8840, 0x00000000, 2432 ); //   coef write 2432
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 2436 ); //   coef read 2436
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8860, 0x00000000, 2440 ); //   coef write 2440
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00005401, 2444 ); // coef write mask 2444
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xundef, 0x00005401, 2444 ); // coef write mask 2444
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000220, 2450 ); //   coef read 2450
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 2454 ); //   coef write 2454

	// this code duplicates code in boot and unmute

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 2458 ); //   coef read 2458
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 2462 ); //   coef read 2462
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 2466 ); //   coef read 2466
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 2470 ); //   coef read 2470
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008000, 2474 ); //   coef read 2474
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 2478 ); //   coef read 2478
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008000, 2482 ); //   coef read 2482
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 2486 ); //   coef read 2486
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 2490 ); //   coef read 2490
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 2494 ); //   coef read 2494
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 2498 ); //   coef read 2498
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 2502 ); //   coef read 2502
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 2506 ); //   coef read 2506
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 2510 ); //   coef read 2510
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 2514 ); //   coef read 2514
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 2518 ); //   coef read 2518
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 2522 ); //   coef read 2522
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 2526 ); //   coef read 2526
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 2530 ); //   coef read 2530
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 2534 ); //   coef read 2534
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 2538 ); //   coef read 2538
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 2542 ); //   coef read 2542
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 2546 ); //   coef read 2546
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 2550 ); //   coef read 2550
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 2554 ); //   coef read 2554
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 2558 ); //   coef read 2558
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 2562 ); //   coef read 2562
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 2566 ); //   coef read 2566
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 2570 ); //   coef read 2570
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 2574 ); //   coef read 2574
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 2578 ); //   coef read 2578
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 2582 ); //   coef read 2582
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 2586 ); //   coef read 2586
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 2590 ); //   coef read 2590
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 2594 ); //   coef read 2594
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 2598 ); //   coef read 2598
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 2602 ); //   coef read 2602
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 2606 ); //   coef read 2606
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 2610 ); //   coef read 2610
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 2614 ); //   coef read 2614
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 2618 ); //   coef read 2618
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 2622 ); //   coef read 2622
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 2626 ); //   coef read 2626
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 2630 ); //   coef read 2630
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 2634 ); //   coef read 2634
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 2638 ); //   coef read 2638
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 2642 ); //   coef read 2642
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 2646 ); //   coef read 2646
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 2650 ); //   coef read 2650
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 2654 ); //   coef read 2654
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 2658 ); //   coef read 2658
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 2662 ); //   coef read 2662
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 2666 ); //   coef read 2666
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 2670 ); //   coef read 2670
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 2674 ); //   coef read 2674
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 2678 ); //   coef read 2678
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 2682 ); //   coef read 2682
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 2686 ); //   coef read 2686
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 2690 ); //   coef read 2690
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 2694 ); //   coef read 2694
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 2698 ); //   coef read 2698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 2702 ); //   coef read 2702
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 2706 ); //   coef read 2706
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 2711 ); //   coef write 2711

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000);
//      snd_hda:     stream format 3 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 2720);

        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);
//      snd_hda:     37 []

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2727 ); // i2cWrite  coef read 2727
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2731 ); // i2cWrite  coef write 2731
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 2735 ); // i2cWrite  coef write 2735
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2739 ); // i2cWrite  coef write 2739
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2743 ); // i2cWrite  coef read 2743
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2747 ); // i2cWrite  coef read 2747
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2751 ); // i2cWrite  coef read 2751
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2755 ); // i2cWrite  coef write 2755
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2762 ); // i2cWrite  coef read 2762
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2766 ); // i2cWrite  coef write 2766
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 2770 ); // i2cWrite  coef write 2770
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2774 ); // i2cWrite  coef write 2774
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2778 ); // i2cWrite  coef read 2778
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2782 ); // i2cWrite  coef read 2782
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2786 ); // i2cWrite  coef read 2786
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2790 ); // i2cWrite  coef write 2790
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2804 ); // i2cWrite  coef read 2804
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2808 ); // i2cWrite  coef write 2808
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 2812 ); // i2cWrite  coef write 2812
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2816 ); // i2cWrite  coef write 2816
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2820 ); // i2cWrite  coef read 2820
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2824 ); // i2cWrite  coef read 2824
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2828 ); // i2cWrite  coef read 2828
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2832 ); // i2cWrite  coef write 2832
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2843 ); // i2cWrite  coef read 2843
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2847 ); // i2cWrite  coef write 2847
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2851 ); // i2cWrite  coef write 2851
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5000, 0x00000000, 2855 ); // i2cWrite  coef write 2855
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2859 ); // i2cWrite  coef read 2859
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2863 ); // i2cWrite  coef read 2863
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2867 ); // i2cWrite  coef read 2867
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2871 ); // i2cWrite  coef write 2871
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2878);
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2879);

        printk("snd_hda_intel: command nid end cs_8409_volup");

}

static void play_node0x02_format(struct hda_codec *codec);
static void play_tdm_setup(struct hda_codec *codec);
static void play_tdm_rate_set(struct hda_codec *codec);
static void play_0x24_pin_set(struct hda_codec *codec);
static void play_amps_enable_6462(struct hda_codec *codec);
static void play_node0x03_format(struct hda_codec *codec);
static void play_tdm_enable(struct hda_codec *codec);
static void play_0x25_pin_set(struct hda_codec *codec);
static void play_amps_enable_7472(struct hda_codec *codec);
static void play_sync_converters(struct hda_codec *codec);


static void cs_8409_play(struct hda_codec *codec)
{
        int retpower1;
        int retpower2;

        int retconv;

        int retval;

	printk("snd_hda_intel: command nid cs_8409_play");


        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        play_node0x02_format(codec);

        play_tdm_setup(codec);

        play_tdm_rate_set(codec);

        play_0x24_pin_set(codec);

        play_amps_enable_6462(codec);

        play_node0x03_format(codec);

        play_tdm_enable(codec);

        play_0x25_pin_set(codec);

        play_amps_enable_7472(codec);

        play_sync_converters(codec);


        printk("snd_hda_intel: command nid end cs_8409_play");
}


static void play_node0x02_format(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]
}

static void play_tdm_setup(struct hda_codec *codec)
{
        int retval;

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 16 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 16
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 20 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 20
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 24 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 24
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 28 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 28
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 32 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 32
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 36 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 36
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 40 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 40
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 44 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 44
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 48 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 48
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 52 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 52
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 56 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 56

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x00008000, 60 ); // coef write mask 60
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 66 ); // coef write mask 66
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 72 ); // coef write mask 72
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000280, 78 ); // coef write mask 78

//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x00008000, 60 ); // coef write mask 60
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 66 ); // coef write mask 66
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 72 ); // coef write mask 72
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000280, 78 ); // coef write mask 78

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 84 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 84
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 88 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 88
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 92 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 92

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 97 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 97
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 101 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 101
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 105 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 105

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 108
}

static void play_tdm_rate_set(struct hda_codec *codec)
{
        int retval;

        // Im assuming this is setting the TDM rate because of the use of vendor commands

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 113 ); // coef write mask 113
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 119 ); // coef write mask 119
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x000008ff, 125 ); // coef write mask 125

//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 113 ); // coef write mask 113
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 119 ); // coef write mask 119
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x000008ff, 125 ); // coef write mask 125
}

static void play_0x24_pin_set(struct hda_codec *codec)
{
        int retval;

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 132);

        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

}

static void play_amps_enable_6462(struct hda_codec *codec)
{
        int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 136 ); // i2cWrite  coef read 136
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 140 ); // i2cWrite  coef write 140
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 144 ); // i2cWrite  coef write 144
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 148 ); // i2cWrite  coef write 148
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 152 ); // i2cWrite  coef read 152
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 156 ); // i2cWrite  coef read 156
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 160 ); // i2cWrite  coef read 160
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 164 ); // i2cWrite  coef write 164
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 171 ); // i2cWrite  coef read 171
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 175 ); // i2cWrite  coef write 175
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 179 ); // i2cWrite  coef write 179
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 183 ); // i2cWrite  coef write 183
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 187 ); // i2cWrite  coef read 187
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 191 ); // i2cWrite  coef read 191
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 195 ); // i2cWrite  coef read 195
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 199 ); // i2cWrite  coef write 199
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1501 i2c data 0x0001   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0015, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 206 ); // i2cWrite  coef read 206
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 210 ); // i2cWrite  coef write 210
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 214 ); // i2cWrite  coef write 214
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1501, 0x00000000, 218 ); // i2cWrite  coef write 218
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 222 ); // i2cWrite  coef read 222
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 226 ); // i2cWrite  coef read 226
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 230 ); // i2cWrite  coef read 230
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 234 ); // i2cWrite  coef write 234
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 241 ); // i2cWrite  coef read 241
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 245 ); // i2cWrite  coef write 245
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 249 ); // i2cWrite  coef write 249
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 253 ); // i2cWrite  coef write 253
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 257 ); // i2cWrite  coef read 257
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 261 ); // i2cWrite  coef read 261
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 265 ); // i2cWrite  coef read 265
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 269 ); // i2cWrite  coef write 269
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1800 i2c data 0x0000   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0018, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 276 ); // i2cWrite  coef read 276
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 280 ); // i2cWrite  coef write 280
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 284 ); // i2cWrite  coef write 284
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1800, 0x00000000, 288 ); // i2cWrite  coef write 288
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 292 ); // i2cWrite  coef read 292
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 296 ); // i2cWrite  coef read 296
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 300 ); // i2cWrite  coef read 300
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 304 ); // i2cWrite  coef write 304
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 311 ); // i2cWrite  coef read 311
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 315 ); // i2cWrite  coef write 315
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 319 ); // i2cWrite  coef write 319
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 323 ); // i2cWrite  coef write 323
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 327 ); // i2cWrite  coef read 327
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 331 ); // i2cWrite  coef read 331
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 335 ); // i2cWrite  coef read 335
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 339 ); // i2cWrite  coef write 339
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 346 ); // i2cWrite  coef read 346
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 350 ); // i2cWrite  coef write 350
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 354 ); // i2cWrite  coef write 354
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 358 ); // i2cWrite  coef write 358
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 362 ); // i2cWrite  coef read 362
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 366 ); // i2cWrite  coef read 366
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 370 ); // i2cWrite  coef read 370
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 374 ); // i2cWrite  coef write 374
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 381 ); // i2cWrite  coef read 381
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 385 ); // i2cWrite  coef write 385
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 389 ); // i2cWrite  coef write 389
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 393 ); // i2cWrite  coef write 393
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 397 ); // i2cWrite  coef read 397
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 401 ); // i2cWrite  coef read 401
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 405 ); // i2cWrite  coef read 405
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 409 ); // i2cWrite  coef write 409
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 416 ); // i2cWrite  coef read 416
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 420 ); // i2cWrite  coef write 420
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 424 ); // i2cWrite  coef write 424
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 428 ); // i2cWrite  coef write 428
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 432 ); // i2cWrite  coef read 432
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 436 ); // i2cWrite  coef read 436
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 440 ); // i2cWrite  coef read 440
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 444 ); // i2cWrite  coef write 444
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 451 ); // i2cWrite  coef read 451
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 455 ); // i2cWrite  coef write 455
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 459 ); // i2cWrite  coef write 459
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 463 ); // i2cWrite  coef write 463
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 467 ); // i2cWrite  coef read 467
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 471 ); // i2cWrite  coef read 471
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 475 ); // i2cWrite  coef read 475
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 479 ); // i2cWrite  coef write 479
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 486 ); // i2cWrite  coef read 486
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 490 ); // i2cWrite  coef write 490
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 494 ); // i2cWrite  coef write 494
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 498 ); // i2cWrite  coef write 498
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 502 ); // i2cWrite  coef read 502
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 506 ); // i2cWrite  coef read 506
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 510 ); // i2cWrite  coef read 510
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 514 ); // i2cWrite  coef write 514
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x64, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 521 ); // i2cRead  coef read 521
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 525 ); // i2cRead  coef write 525
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 529 ); // i2cRead  coef write 529
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 533 ); // i2cRead  coef write 533
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 537 ); // i2cRead  coef read 537
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 541 ); // i2cRead  coef read 541
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 545 ); // i2cRead  coef read 545
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 549 ); // i2cRead  coef read 549
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 553 ); // i2cRead  coef write 553
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 560 ); // i2cWrite  coef read 560
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 564 ); // i2cWrite  coef write 564
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 568 ); // i2cWrite  coef write 568
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 572 ); // i2cWrite  coef write 572
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 576 ); // i2cWrite  coef read 576
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 580 ); // i2cWrite  coef read 580
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 584 ); // i2cWrite  coef read 584
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 588 ); // i2cWrite  coef write 588
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x64, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 595 ); // i2cWrite  coef read 595
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 599 ); // i2cWrite  coef write 599
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0064, 0x00000000, 603 ); // i2cWrite  coef write 603
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 607 ); // i2cWrite  coef write 607
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 611 ); // i2cWrite  coef read 611
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 615 ); // i2cWrite  coef read 615
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 619 ); // i2cWrite  coef read 619
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 623 ); // i2cWrite  coef write 623
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 630 ); // i2cWrite  coef read 630
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 634 ); // i2cWrite  coef write 634
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 638 ); // i2cWrite  coef write 638
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 642 ); // i2cWrite  coef write 642
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 646 ); // i2cWrite  coef read 646
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 650 ); // i2cWrite  coef read 650
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 654 ); // i2cWrite  coef read 654
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 658 ); // i2cWrite  coef write 658
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 665 ); // i2cWrite  coef read 665
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 669 ); // i2cWrite  coef write 669
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 673 ); // i2cWrite  coef write 673
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 677 ); // i2cWrite  coef write 677
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 681 ); // i2cWrite  coef read 681
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 685 ); // i2cWrite  coef read 685
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 689 ); // i2cWrite  coef read 689
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 693 ); // i2cWrite  coef write 693
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1502 i2c data 0x0002   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0015, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 700 ); // i2cWrite  coef read 700
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 704 ); // i2cWrite  coef write 704
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 708 ); // i2cWrite  coef write 708
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1502, 0x00000000, 712 ); // i2cWrite  coef write 712
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 716 ); // i2cWrite  coef read 716
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 720 ); // i2cWrite  coef read 720
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 724 ); // i2cWrite  coef read 724
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 728 ); // i2cWrite  coef write 728
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 735 ); // i2cWrite  coef read 735
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 739 ); // i2cWrite  coef write 739
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 743 ); // i2cWrite  coef write 743
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 747 ); // i2cWrite  coef write 747
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 751 ); // i2cWrite  coef read 751
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 755 ); // i2cWrite  coef read 755
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 759 ); // i2cWrite  coef read 759
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 763 ); // i2cWrite  coef write 763
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1801 i2c data 0x0001   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0018, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 770 ); // i2cWrite  coef read 770
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 774 ); // i2cWrite  coef write 774
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 778 ); // i2cWrite  coef write 778
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1801, 0x00000000, 782 ); // i2cWrite  coef write 782
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 786 ); // i2cWrite  coef read 786
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 790 ); // i2cWrite  coef read 790
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 794 ); // i2cWrite  coef read 794
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 798 ); // i2cWrite  coef write 798
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 805 ); // i2cWrite  coef read 805
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 809 ); // i2cWrite  coef write 809
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 813 ); // i2cWrite  coef write 813
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 817 ); // i2cWrite  coef write 817
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 821 ); // i2cWrite  coef read 821
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 825 ); // i2cWrite  coef read 825
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 829 ); // i2cWrite  coef read 829
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 833 ); // i2cWrite  coef write 833
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 840 ); // i2cWrite  coef read 840
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 844 ); // i2cWrite  coef write 844
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 848 ); // i2cWrite  coef write 848
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 852 ); // i2cWrite  coef write 852
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 856 ); // i2cWrite  coef read 856
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 860 ); // i2cWrite  coef read 860
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 864 ); // i2cWrite  coef read 864
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 868 ); // i2cWrite  coef write 868
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 875 ); // i2cWrite  coef read 875
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 879 ); // i2cWrite  coef write 879
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 883 ); // i2cWrite  coef write 883
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 887 ); // i2cWrite  coef write 887
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 891 ); // i2cWrite  coef read 891
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 895 ); // i2cWrite  coef read 895
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 899 ); // i2cWrite  coef read 899
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 903 ); // i2cWrite  coef write 903
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 910 ); // i2cWrite  coef read 910
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 914 ); // i2cWrite  coef write 914
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 918 ); // i2cWrite  coef write 918
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 922 ); // i2cWrite  coef write 922
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 926 ); // i2cWrite  coef read 926
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 930 ); // i2cWrite  coef read 930
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 934 ); // i2cWrite  coef read 934
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 938 ); // i2cWrite  coef write 938
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 945 ); // i2cWrite  coef read 945
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 949 ); // i2cWrite  coef write 949
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 953 ); // i2cWrite  coef write 953
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 957 ); // i2cWrite  coef write 957
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 961 ); // i2cWrite  coef read 961
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 965 ); // i2cWrite  coef read 965
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 969 ); // i2cWrite  coef read 969
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 973 ); // i2cWrite  coef write 973
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 980 ); // i2cWrite  coef read 980
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 984 ); // i2cWrite  coef write 984
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 988 ); // i2cWrite  coef write 988
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 992 ); // i2cWrite  coef write 992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 996 ); // i2cWrite  coef read 996
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1000 ); // i2cWrite  coef read 1000
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1004 ); // i2cWrite  coef read 1004
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1008 ); // i2cWrite  coef write 1008
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x62 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x62, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1015 ); // i2cRead  coef read 1015
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1019 ); // i2cRead  coef write 1019
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1023 ); // i2cRead  coef write 1023
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 1027 ); // i2cRead  coef write 1027
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1031 ); // i2cRead  coef read 1031
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1035 ); // i2cRead  coef read 1035
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 1039 ); // i2cRead  coef read 1039
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1043 ); // i2cRead  coef read 1043
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1047 ); // i2cRead  coef write 1047
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1054 ); // i2cWrite  coef read 1054
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1058 ); // i2cWrite  coef write 1058
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1062 ); // i2cWrite  coef write 1062
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 1066 ); // i2cWrite  coef write 1066
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1070 ); // i2cWrite  coef read 1070
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1074 ); // i2cWrite  coef read 1074
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1078 ); // i2cWrite  coef read 1078
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1082 ); // i2cWrite  coef write 1082
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x62, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1089 ); // i2cWrite  coef read 1089
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1093 ); // i2cWrite  coef write 1093
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0062, 0x00000000, 1097 ); // i2cWrite  coef write 1097
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 1101 ); // i2cWrite  coef write 1101
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1105 ); // i2cWrite  coef read 1105
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1109 ); // i2cWrite  coef read 1109
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1113 ); // i2cWrite  coef read 1113
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1117 ); // i2cWrite  coef write 1117
//      snd_hda i2cWrite end

}

static void play_node0x03_format(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033);
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

}

static void play_tdm_enable(struct hda_codec *codec)
{
        int retval;

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 1125 ); //   coef read 1125
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 1129 ); //   coef write 1129
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 1133 ); //   coef read 1133
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 1137 ); //   coef write 1137

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 1141 ); //   coef read 1141

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 1146 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1146
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 1150 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 1150
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 1154 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1154
}

static void play_0x25_pin_set(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 1157

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 1163);

        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040);
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']
}

static void play_amps_enable_7472(struct hda_codec *codec)
{
        int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1167 ); // i2cWrite  coef read 1167
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1171 ); // i2cWrite  coef write 1171
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1175 ); // i2cWrite  coef write 1175
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 1179 ); // i2cWrite  coef write 1179
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1183 ); // i2cWrite  coef read 1183
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1187 ); // i2cWrite  coef read 1187
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1191 ); // i2cWrite  coef read 1191
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1195 ); // i2cWrite  coef write 1195
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1202 ); // i2cWrite  coef read 1202
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1206 ); // i2cWrite  coef write 1206
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1210 ); // i2cWrite  coef write 1210
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 1214 ); // i2cWrite  coef write 1214
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1218 ); // i2cWrite  coef read 1218
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1222 ); // i2cWrite  coef read 1222
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1226 ); // i2cWrite  coef read 1226
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1230 ); // i2cWrite  coef write 1230
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1504 i2c data 0x0004   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0015, 0x0004, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1237 ); // i2cWrite  coef read 1237
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1241 ); // i2cWrite  coef write 1241
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1245 ); // i2cWrite  coef write 1245
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1504, 0x00000000, 1249 ); // i2cWrite  coef write 1249
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1253 ); // i2cWrite  coef read 1253
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1257 ); // i2cWrite  coef read 1257
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1261 ); // i2cWrite  coef read 1261
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1265 ); // i2cWrite  coef write 1265
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1272 ); // i2cWrite  coef read 1272
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1276 ); // i2cWrite  coef write 1276
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1280 ); // i2cWrite  coef write 1280
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 1284 ); // i2cWrite  coef write 1284
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1288 ); // i2cWrite  coef read 1288
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1292 ); // i2cWrite  coef read 1292
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1296 ); // i2cWrite  coef read 1296
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1300 ); // i2cWrite  coef write 1300
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1802 i2c data 0x0002   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0018, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1307 ); // i2cWrite  coef read 1307
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1311 ); // i2cWrite  coef write 1311
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1315 ); // i2cWrite  coef write 1315
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1802, 0x00000000, 1319 ); // i2cWrite  coef write 1319
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1323 ); // i2cWrite  coef read 1323
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1327 ); // i2cWrite  coef read 1327
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1331 ); // i2cWrite  coef read 1331
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1335 ); // i2cWrite  coef write 1335
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1342 ); // i2cWrite  coef read 1342
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1346 ); // i2cWrite  coef write 1346
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1350 ); // i2cWrite  coef write 1350
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 1354 ); // i2cWrite  coef write 1354
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1358 ); // i2cWrite  coef read 1358
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1362 ); // i2cWrite  coef read 1362
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1366 ); // i2cWrite  coef read 1366
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1370 ); // i2cWrite  coef write 1370
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1377 ); // i2cWrite  coef read 1377
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1381 ); // i2cWrite  coef write 1381
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1385 ); // i2cWrite  coef write 1385
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 1389 ); // i2cWrite  coef write 1389
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1393 ); // i2cWrite  coef read 1393
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1397 ); // i2cWrite  coef read 1397
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1401 ); // i2cWrite  coef read 1401
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1405 ); // i2cWrite  coef write 1405
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1412 ); // i2cWrite  coef read 1412
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1416 ); // i2cWrite  coef write 1416
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1420 ); // i2cWrite  coef write 1420
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 1424 ); // i2cWrite  coef write 1424
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1428 ); // i2cWrite  coef read 1428
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1432 ); // i2cWrite  coef read 1432
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1436 ); // i2cWrite  coef read 1436
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1440 ); // i2cWrite  coef write 1440
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1447 ); // i2cWrite  coef read 1447
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1451 ); // i2cWrite  coef write 1451
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1455 ); // i2cWrite  coef write 1455
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 1459 ); // i2cWrite  coef write 1459
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1463 ); // i2cWrite  coef read 1463
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1467 ); // i2cWrite  coef read 1467
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1471 ); // i2cWrite  coef read 1471
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1475 ); // i2cWrite  coef write 1475
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1482 ); // i2cWrite  coef read 1482
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1486 ); // i2cWrite  coef write 1486
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1490 ); // i2cWrite  coef write 1490
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 1494 ); // i2cWrite  coef write 1494
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1498 ); // i2cWrite  coef read 1498
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1502 ); // i2cWrite  coef read 1502
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1506 ); // i2cWrite  coef read 1506
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1510 ); // i2cWrite  coef write 1510
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1517 ); // i2cWrite  coef read 1517
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1521 ); // i2cWrite  coef write 1521
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1525 ); // i2cWrite  coef write 1525
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 1529 ); // i2cWrite  coef write 1529
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1533 ); // i2cWrite  coef read 1533
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1537 ); // i2cWrite  coef read 1537
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1541 ); // i2cWrite  coef read 1541
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1545 ); // i2cWrite  coef write 1545
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x74 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x74, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1552 ); // i2cRead  coef read 1552
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1556 ); // i2cRead  coef write 1556
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1560 ); // i2cRead  coef write 1560
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 1564 ); // i2cRead  coef write 1564
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1568 ); // i2cRead  coef read 1568
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1572 ); // i2cRead  coef read 1572
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 1576 ); // i2cRead  coef read 1576
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1580 ); // i2cRead  coef read 1580
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1584 ); // i2cRead  coef write 1584
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1591 ); // i2cWrite  coef read 1591
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1595 ); // i2cWrite  coef write 1595
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1599 ); // i2cWrite  coef write 1599
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 1603 ); // i2cWrite  coef write 1603
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1607 ); // i2cWrite  coef read 1607
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1611 ); // i2cWrite  coef read 1611
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1615 ); // i2cWrite  coef read 1615
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1619 ); // i2cWrite  coef write 1619
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x74, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1626 ); // i2cWrite  coef read 1626
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1630 ); // i2cWrite  coef write 1630
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0074, 0x00000000, 1634 ); // i2cWrite  coef write 1634
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 1638 ); // i2cWrite  coef write 1638
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1642 ); // i2cWrite  coef read 1642
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1646 ); // i2cWrite  coef read 1646
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1650 ); // i2cWrite  coef read 1650
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1654 ); // i2cWrite  coef write 1654
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0010, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1661 ); // i2cWrite  coef read 1661
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1665 ); // i2cWrite  coef write 1665
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1669 ); // i2cWrite  coef write 1669
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1008, 0x00000000, 1673 ); // i2cWrite  coef write 1673
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1677 ); // i2cWrite  coef read 1677
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1681 ); // i2cWrite  coef read 1681
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1685 ); // i2cWrite  coef read 1685
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1689 ); // i2cWrite  coef write 1689
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0014, 0x00e4, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1696 ); // i2cWrite  coef read 1696
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1700 ); // i2cWrite  coef write 1700
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1704 ); // i2cWrite  coef write 1704
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x14e4, 0x00000000, 1708 ); // i2cWrite  coef write 1708
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1712 ); // i2cWrite  coef read 1712
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1716 ); // i2cWrite  coef read 1716
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1720 ); // i2cWrite  coef read 1720
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1724 ); // i2cWrite  coef write 1724
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1508 i2c data 0x0008   reg anal: PCMRXEnablesA
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0015, 0x0008, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1731 ); // i2cWrite  coef read 1731
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1735 ); // i2cWrite  coef write 1735
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1739 ); // i2cWrite  coef write 1739
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1508, 0x00000000, 1743 ); // i2cWrite  coef write 1743
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1747 ); // i2cWrite  coef read 1747
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1751 ); // i2cWrite  coef read 1751
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1755 ); // i2cWrite  coef read 1755
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1759 ); // i2cWrite  coef write 1759
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0016, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1766 ); // i2cWrite  coef read 1766
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1770 ); // i2cWrite  coef write 1770
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1774 ); // i2cWrite  coef write 1774
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 1778 ); // i2cWrite  coef write 1778
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1782 ); // i2cWrite  coef read 1782
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1786 ); // i2cWrite  coef read 1786
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1790 ); // i2cWrite  coef read 1790
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1794 ); // i2cWrite  coef write 1794
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1803 i2c data 0x0003   reg anal: MonoMixChannelSource
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0018, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1801 ); // i2cWrite  coef read 1801
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1805 ); // i2cWrite  coef write 1805
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1809 ); // i2cWrite  coef write 1809
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1803, 0x00000000, 1813 ); // i2cWrite  coef write 1813
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1817 ); // i2cWrite  coef read 1817
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1821 ); // i2cWrite  coef read 1821
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1825 ); // i2cWrite  coef read 1825
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1829 ); // i2cWrite  coef write 1829
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1900 i2c data 0x0000   reg anal: MonoMixChannelConfig
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0019, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1836 ); // i2cWrite  coef read 1836
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1840 ); // i2cWrite  coef write 1840
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1844 ); // i2cWrite  coef write 1844
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 1848 ); // i2cWrite  coef write 1848
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1852 ); // i2cWrite  coef read 1852
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1856 ); // i2cWrite  coef read 1856
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1860 ); // i2cWrite  coef read 1860
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1864 ); // i2cWrite  coef write 1864
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002d, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1871 ); // i2cWrite  coef read 1871
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1875 ); // i2cWrite  coef write 1875
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1879 ); // i2cWrite  coef write 1879
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 1883 ); // i2cWrite  coef write 1883
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1887 ); // i2cWrite  coef read 1887
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1891 ); // i2cWrite  coef read 1891
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1895 ); // i2cWrite  coef read 1895
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1899 ); // i2cWrite  coef write 1899
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x002e, 0x0005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1906 ); // i2cWrite  coef read 1906
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1910 ); // i2cWrite  coef write 1910
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1914 ); // i2cWrite  coef write 1914
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2e05, 0x00000000, 1918 ); // i2cWrite  coef write 1918
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1922 ); // i2cWrite  coef read 1922
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1926 ); // i2cWrite  coef read 1926
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1930 ); // i2cWrite  coef read 1930
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1934 ); // i2cWrite  coef write 1934
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004a, 0x0021, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1941 ); // i2cWrite  coef read 1941
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1945 ); // i2cWrite  coef write 1945
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1949 ); // i2cWrite  coef write 1949
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4a21, 0x00000000, 1953 ); // i2cWrite  coef write 1953
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1957 ); // i2cWrite  coef read 1957
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1961 ); // i2cWrite  coef read 1961
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1965 ); // i2cWrite  coef read 1965
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1969 ); // i2cWrite  coef write 1969
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x004d, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1976 ); // i2cWrite  coef read 1976
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1980 ); // i2cWrite  coef write 1980
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 1984 ); // i2cWrite  coef write 1984
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x4d07, 0x00000000, 1988 ); // i2cWrite  coef write 1988
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1992 ); // i2cWrite  coef read 1992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1996 ); // i2cWrite  coef read 1996
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2000 ); // i2cWrite  coef read 2000
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2004 ); // i2cWrite  coef write 2004
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0055, 0x0034, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2011 ); // i2cWrite  coef read 2011
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2015 ); // i2cWrite  coef write 2015
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2019 ); // i2cWrite  coef write 2019
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5534, 0x00000000, 2023 ); // i2cWrite  coef write 2023
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2027 ); // i2cWrite  coef read 2027
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2031 ); // i2cWrite  coef read 2031
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2035 ); // i2cWrite  coef read 2035
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2039 ); // i2cWrite  coef write 2039
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x72 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cRead(codec, 0x72, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2046 ); // i2cRead  coef read 2046
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2050 ); // i2cRead  coef write 2050
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2054 ); // i2cRead  coef write 2054
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1100, 0x00000000, 2058 ); // i2cRead  coef write 2058
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2062 ); // i2cRead  coef read 2062
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2066 ); // i2cRead  coef read 2066
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001107, 2070 ); // i2cRead  coef read 2070
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2074 ); // i2cRead  coef read 2074
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2078 ); // i2cRead  coef write 2078
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0011, 0x0007, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2085 ); // i2cWrite  coef read 2085
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2089 ); // i2cWrite  coef write 2089
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2093 ); // i2cWrite  coef write 2093
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1107, 0x00000000, 2097 ); // i2cWrite  coef write 2097
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2101 ); // i2cWrite  coef read 2101
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2105 ); // i2cWrite  coef read 2105
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2109 ); // i2cWrite  coef read 2109
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2113 ); // i2cWrite  coef write 2113
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable
        //cs_8409_vendor_i2cWrite(codec, 0x72, 0x0050, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2120 ); // i2cWrite  coef read 2120
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2124 ); // i2cWrite  coef write 2124
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0072, 0x00000000, 2128 ); // i2cWrite  coef write 2128
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x5001, 0x00000000, 2132 ); // i2cWrite  coef write 2132
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2136 ); // i2cWrite  coef read 2136
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2140 ); // i2cWrite  coef read 2140
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2144 ); // i2cWrite  coef read 2144
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2148 ); // i2cWrite  coef write 2148
//      snd_hda i2cWrite end

}

static void play_sync_converters(struct hda_codec *codec)
{
        int retval;

        int retpower1;
        int retpower2;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 

        // this disables stream on node 0x02 and performs the vendor writes 

        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 2154);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 2156 ); // coef write mask 2156
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 2156 ); // coef write mask 2156


//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 

        // this disables stream on node 0x02 and performs the vendor writes 

        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 2162);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 2164 ); // coef write mask 2164
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 2164 ); // coef write mask 2164


        // this re-enables streams on node 0x02 and 0x03

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010);
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012);
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]


        retpower1 = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2177);
        retpower2 = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2178);

}
