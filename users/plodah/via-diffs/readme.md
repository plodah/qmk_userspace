## create a diff between branches
```sh
git diff main via_plodah_uk --output ../qmk_userspace/users/plodah/via-diffs/viaapp2.diff
```

## update via-app
```sh
destname="via_plodah_uk"
destname="via_plodah_uk-$(date +%Y-%m-%d)"

git fetch upstream
git fetch origin

git checkout main
git pull --rebase upstream main
git push

git checkout -b $destname main
#or git checkout $destname
git apply ../qmk_userspace/users/plodah/via-diffs/viaapp.diff
git push --set-upstream origin $destname
```
