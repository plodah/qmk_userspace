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
#Dictionaries
declare -a usesmalldict=(
    "keychron/q1v1/iso_encoder/keymaps/plodah"
    "keychron/q1v1/iso_encoder/keymaps/plodahc"
)
declare -a uselargedict=(
    "keychron/v6/iso_encoder/keymaps/plodah"
    "sofle/keymaps/plodah"
)
#        dictionary.txt exists   &&   (  dictionary.h does not exist      ||  (dictionary.h exists && dictionary.txt is newer than dictionary.h)  )
if [[ -e $plodir/dict-large.txt  && ( ! -e $plodir/autocorrect_data_l.h || (-e $plodir/autocorrect_data_l.h && $plodir/dict-large.txt -nt $plodir/autocorrect_data_l.h ) ) ]]; then
  qmk generate-autocorrect-data -o $plodir/autocorrect_data_l.h $plodir/dict-large.txt
fi
if [[ -e $plodir/dict-medium.txt && ( ! -e $plodir/autocorrect_data.h   || (-e $plodir/autocorrect_data.h   && $plodir/dict-medium.txt -nt $plodir/autocorrect_data.h  ) ) ]]; then
  qmk generate-autocorrect-data -o $plodir/autocorrect_data.h $plodir/dict-medium.txt
fi
if [[ -e $plodir/dict-small.txt  && ( ! -e $plodir/autocorrect_data_s.h || (-e $plodir/autocorrect_data_s.h && $plodir/dict-small.txt -nt $plodir/autocorrect_data_s.h ) ) ]]; then
  qmk generate-autocorrect-data -o $plodir/autocorrect_data_s.h $plodir/dict-small.txt
fi

for i in "${usesmalldict[@]}"
do
  cp $plodir/autocorrect_data_s.h $usrdir/keyboards/$i/autocorrect_data.h
done
for i in "${uselargedict[@]}"
do
  cp $plodir/autocorrect_data_l.h $usrdir/keyboards/$i/autocorrect_data.h
done
#rm $plodir/autocorrect_data_l.h $plodir/*.bak

#compilationdb
declare -a compilationdbs=(
    "-km plodahc -kb keebio/iris/keymaps/plodah"
    "-km plodahc -kb keychron/v2/iso_encoder"
    "-km plodah -kb ymdk/yd60mq/keymaps/plodah_jpn"
    "-km plodah -kb ploopyco/trackball_thumb"
    "-km plodah -kb ploopyco/madromys"
)

if [ "$1" == "clean" ]
  then
    echo "$(date +%H:%M:%S) CLEAN"
    rm $qmkdir/*.uf2 $qmkdir/*.bin $qmkdir/*.hex $usrdir/*.uf2 $usrdir/*.bin $usrdir/*.hex $usrdir/compile_commands.json
    #asd=`find keyboards -iname plodah* | sed 's,^[^/]*/,,'`
    for j in "${compilationdbs[@]}"
    do
        qmk generate-compiation-database $j
    done
    #qmk generate-compilation-database -km plodahc -kb keychron/v2/iso_encoder
    #qmk generate-compilation-database -km plodah -kb keychron/v2/iso_encoder
    #qmk generate-compilation-database -km plodah -kb ploopyco/trackball_thumb
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
