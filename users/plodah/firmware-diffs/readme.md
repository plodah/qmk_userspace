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

## Working with Diffs
```sh
#create a diff
git diff master sourcebranch > /path/to/diff.txt

## apply a Diff
git apply /path/to/diff.txt
```

## Hard reset master branch
```sh
# Reset master to upstream
git checkout master
git pull --rebase upstream master
git reset --hard upstream/master
git push origin master --force
```

## Delete a branch
```sh
# Delete a branch locally and remotely
git checkout master #checkout anything other than the branch to be deleted.
git branch -D naffbranch
git push -d origin naffbranch
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
    if [ -n "$testlocdst" ]; then echo "DESTINATION ALREADY EXISTS LOCALLY: \"$dst\""; fail=true; fi
    if [ -n "$testremdst" ]; then echo "DESTINATION ALREADY EXISTS REMOTE: \"origin/$dst\""; fail=true; fi
    
    if [ -z $fail ]; then
        git checkout $src
        git pull --rebase upstream $src
        git push
        git checkout -b $dst $src
        git push --set-upstream origin $dst

        for d in $diff/*.txt; do
            diffname=`echo "$d" | awk -F/ '{print $NF}' | awk -F. '{print $1}'`
            msg="apply diff '$diffname'"
            echo "--- $msg ---"
            git apply $d
            git commit -am "$msg"
        done

        # git diff $src --stat
        git push
    fi
}

diffpath="../plodah_qmk_userspace/users/plodah/firmware-diffs"
update-branch "develop" "mydevbuilds-$(date +%Y-%m)" $diffpath n
update-branch "master" "mybuilds-$(date +%Y-%m)" $diffpath n
```
