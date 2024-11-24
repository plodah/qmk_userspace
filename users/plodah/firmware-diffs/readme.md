# How to DIFF
because I will probably forget.

## Create Diff
    git diff master sourcebranch > /path/to/diff.txt

## Apply Diff
    git checkout -b new-branch
    git apply /path/to/diff.txt
