startdir=`pwd`
echo "$(date +%H:%M:%S) START"
if [[ `grep WSL2 /proc/version` ]]; then
  echo "$(date +%H:%M:%S) This is WSL"
  wsl="true"
  qmkdir="/home/michael/plodah_qmk_firmware"
  usrdir="/home/michael/plodah_qmk_userspace"
  gdrdir="/mnt/d/Google Drive/Keebs/Firmware"
else
  echo "$(date +%H:%M:%S) This is _NOT_ WSL"
  qmkdir="/d/Repo/qmk_firmware"
  usrdir="/d/Repo/qmk_userspace"
  gdrdir="/d/Google Drive/Keebs/Firmware"
fi
subdir=compiled-$(date +%Y-w%W)
plodir="$usrdir/users/plodah"

cd $qmkdir
qmk generate-autocorrect-data -o $plodir/autocorrect_data.h $plodir/dictionary.txt
rm $plodir/*.bak

if [ "$1" == "clean" ] || [ "$wsl" == "true" ]
  then
    echo "$(date +%H:%M:%S) CLEAN"
    rm $qmkdir/*.uf2 $qmkdir/*.bin $qmkdir/*.hex $usrdir/*.uf2 $usrdir/*.bin $usrdir/*.hex
    qmk clean
    qmk userspace-doctor
    qmk userspace-list
    echo "$(date +%H:%M:%S) COMPILE"
    qmk userspace-compile
  else
    if [ "$1" == "nowt" ]
      then
        echo "nowt"
      else
        echo "$(date +%H:%M:%S) NO CLEAN"
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

if [ -d "$gdrdir/$subdir" ]
  then rm "$gdrdir/$subdir/*" -rf
  else mkdir "$gdrdir/$subdir"
fi
cp -r "$qmkdir/$subdir" "$gdrdir/"

cd $startdir
echo "$(date +%H:%M:%S) FIN"
