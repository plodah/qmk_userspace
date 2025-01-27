# How to git
Because I will forget.

## Basics
```sh
#create new branch from current or specific branch
git checkout -b new-branch
git checkout -b new-branch source-branch

#Add files to commit then commit with message
git add .
git commit m "Commit Message"

#Commit all files that have been modified
git commit -am "Commit Message"

```
## Manage Remotes
```sh
# list remotes. Ideal result listed.
> git remote -v
origin      https://github.com/plodah/qmk_firmware.git (fetch)
origin      https://github.com/plodah/qmk_firmware.git (push)
upstream    https://github.com/qmk/qmk_firmware.git (fetch)
upstream    https://github.com/qmk/qmk_firmware.git (push)

# To add upstream
git remote add upstream https://github.com/qmk/qmk_firmware.git

# Other things to work with remotes remotes
git remote remove badremote
git remote rename usptream upstream
```

## Basic reset master
```sh
checkout origin/master
git pull upstream master 
git push
```
## Hard reset master branch
```sh
# Reset master to upstream
git checkout origin/master
git pull --rebase upstream master
git reset --hard upstream/master
git push origin master --force
```
## Update working branch
```sh
git checkout workingbranch
git pull --rebase origin master
git push
```
## Working with Diffs
```sh
#create a diff
git diff master sourcebranch --output /path/to/diff.txt

## apply a Diff
git apply /path/to/diff.txt
```

## Delete a branch
```sh
# Delete a branch locally and remotely
git checkout master #checkout anything other than the branch to be deleted.
git branch -D naffbranch # Local
git push -d origin naffbranch # Remote
```

## Update Everything
```sh
#!/bin/bash
update-branch() {
    src=$1; dst=$2; diff=$3; del=$4 fail="";
    
    testlocsrc=`git branch --list $src`
    testremsrc=`git branch --remote --list origin/$src`
    testlocdst=`git branch --list $dst`
    testremdst=`git branch --remote --list origin/$dst`
    
    if [ -z "$testlocsrc" ]; then echo "LOCAL BRANCH \"$src\" DOES NOT EXIST"; fail=true; fi
    if [ -z "$testremsrc" ]; then echo "REMOTE BRANCH \"$src\" DOES NOT EXIST"; fail=true; fi
    
    if [ -n "$testlocdst" ]; then echo "DESTINATION ALREADY EXISTS LOCALLY: \"$dst\""
      if [ -z $fail ] && [ "DEL" == $del ]; then git checkout $src; git branch -D $dst
      else fail=true; fi
    fi
    if [ -n "$testremdst" ]; then echo "DESTINATION ALREADY EXISTS REMOTE: \"origin/$dst\""
      if [ -z $fail ] && [ "DEL" == $del ]; then git push -d origin $dst
      else fail=true; fi
    fi
    
    if [ -z $fail ]; then
        git checkout $src
        git pull --rebase upstream $src
        git push
        git checkout -b $dst $src
        git push --set-upstream origin $dst

        for d in $diff/*.diff; do
            diffname=`echo "$d" | awk -F/ '{print $NF}' | awk -F. '{print $1}'`
            msg="apply diff '$diffname'"
            echo "--- $msg ---"
            git apply $d
            git add .
            git commit --all --message "$msg"
        done

        # git diff $src --stat
        git push
    fi
}

diffpath="../plodah_qmk_userspace/users/plodah/firmware-diffs"
update-branch "develop" "mydevbuilds-$(date +%Y-%m)" $diffpath n
update-branch "master" "mybuilds-$(date +%Y-%m)" $diffpath n
```
