# snd_hda_macbookpro

Compiling and installing driver:
-------------

**fedora package install**
```
dnf install wget make gcc kernel-devel
```
**ubuntu package install**  
```
apt install wget make gcc linux-headers-generic
```
**build driver**  
```
git clone https://github.com/leifliddy/macbook12-audio-driver.git  
cd macbook12-audio-driver/
./install.cirrus.driver.sh
reboot
```
