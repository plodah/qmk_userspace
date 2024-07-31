#!/bin/bash
startdir=`pwd`
echo "$(date +%H:%M:%S) START"
if [[ `grep -e "WSL2" /proc/version` ]]; then
  echo "$(date +%H:%M:%S) This is WSL"
  qmkenv="wsl"
  qmkdir="$HOME/repo/plodah_qmk_firmware"
  usrdir="$HOME/repo/plodah_qmk_userspace"
  fwsdir="/mnt/d/Google Drive/Keebs/Firmware"
elif [[ `grep -e "Debian" /proc/version` ]]; then
  echo "$(date +%H:%M:%S) This is Debian"
  qmkenv="deb"
  qmkdir="$HOME/Repo/plodah_qmk_firmware"
  usrdir="$HOME/Repo/plodah_qmk_userspace"
  fwsdir="$HOME/Documents/kbfirmware"
else
  echo "$(date +%H:%M:%S) This is probably MSYS"
  qmkdir="/d/Repo/qmk_firmware"
  usrdir="/d/Repo/qmk_userspace"
  fwsdir="/d/Google Drive/Keebs/Firmware"
fi
subdir=compiled-$(date +%Y-w%W)
plodir="$usrdir/users/plodah"

cd $qmkdir
qmk generate-autocorrect-data -o $plodir/autocorrect_data.h $plodir/dictionary.txt
rm $plodir/*.bak

if [ "$1" == "clean" ]
  then
    echo "$(date +%H:%M:%S) CLEAN"
    rm $qmkdir/*.uf2 $qmkdir/*.bin $qmkdir/*.hex $usrdir/*.uf2 $usrdir/*.bin $usrdir/*.hex
    qmk userspace-doctor
    qmk userspace-list
    echo "$(date +%H:%M:%S) COMPILE"
    qmk userspace-compile -c
  else
    if [ "$1" == "nowt" ]
      then
        echo "nowt"
      else
        echo "$(date +%H:%M:%S) NO CLEAN"
        qmk userspace-doctor
        qmk userspace-list
        echo "$(date +%H:%M:%S) COMPILE"
        qmk userspace-compile
    fi
fi

echo "$(date +%H:%M:%S) COPY FILES" AS $subdir

if [ ! -d "$qmkdir/$subdir" ]
  then mkdir "$qmkdir/$subdir"
fi
cp *.uf2 *.bin *.hex "$qmkdir/$subdir/"

if [ -d "$usrdir/$subdir" ]
  then rm "$usrdir/$subdir/*" -rf
  else mkdir "$usrdir/$subdir"
fi
cp -r "$qmkdir/$subdir" "$usrdir/"

if [ -d "$fwsdir/$subdir" ]
  then rm "$fwsdir/$subdir/*" -rf
  else mkdir "$fwsdir/$subdir"
fi
cp -r "$qmkdir/$subdir" "$fwsdir/"

cd $startdir
echo "$(date +%H:%M:%S) FIN"
