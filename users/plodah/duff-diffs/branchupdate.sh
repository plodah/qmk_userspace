#! sh

workdir=/tmp/qmktest
diffdir=/repo/qmkstuff/qmk_userspace/users/plodah/firmware-diffs

mkdir ${workdir}
git clone -o upstream ssh://git@github.com/qmk/qmk_firmware ${workdir}
cd ${workdir}

#git remote add upstream ssh://git@github.com/qmk/qmk_firmware
git remote add plodahforg ssh://git@git.lan:222/plodah/qmk_firmware
git remote add plodahgthb ssh://git@github.com/plodah/qmk_firmware

#master develop xap

function update-sourcebranch(){
    srcr=$1; srcb=$2;

    cb=`git branch --show-current`
    if [[ ${cb} != ${srcb} ]]; then
        echo "> git checkout ${srcb}"
        git checkout ${srcb}
    else
        echo "NO checkout"
    fi

    echo "> git pull --rebase ${srcr} ${srcb}"
    git reset --hard ${srcr}/${srcb}
    git clean -fd
    git pull --rebase ${srcr} ${srcb}
}

function patch-branch(){
    diff=$1;

    for d in ${diff}/*.diff; do
        diffname=`echo "$d" | awk -F/ '{print $NF}' | awk -F. '{print $1}'`
        msg="apply diff '$diffname'"
        echo "--- $msg ---"
        git apply $d
        sleep 3
        git add .
        git commit --all --message "$msg"
    done
}

function copy-branch(){
    srcr=$1; srcb=$2; dstr=$3; dstb=$4; diff=$5;
    echo "=== copy-branch $1 $2 $3 $4 ==="

    if [[ -z $dstb ]]; then
        echo "SAME DEST as src ${srcb}"
        dstb=${srcb}
    fi

    update-sourcebranch $srcr $srcb
    git checkout -b $dstb $srcb

    if [[ -n $diff ]]; then
        echo "patch it"
        patch-branch $diff
    else
        echo "no patches"
    fi
    echo "> git push --force ${dstr} ${dstb}"
    git push --force ${dstr} ${dstb}
}

copy-branch upstream master plodahforg
copy-branch upstream master plodahgthb
copy-branch upstream develop plodahforg
copy-branch upstream develop plodahgthb
copy-branch upstream xap plodahforg
copy-branch upstream xap plodahgthb

copy-branch plodahforg master plodahforg mybuilds ${diffdir}
copy-branch plodahgthb master plodahgthb mybuilds ${diffdir}
