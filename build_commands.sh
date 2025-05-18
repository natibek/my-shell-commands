#!/usr/bin/env bash

if [ $# -ne 0 ]; then
    entries=$@
else
    entries=*
fi

# run in the project directory
for entry in $entries; do
    if [ -d "$entry" ] && [[ $entry == m* ]]; then
        src_code="$PWD/"$entry"/"$entry".cpp"
        (cd bin && g++ -o "$entry" "$src_code" && echo $entry built)
    fi
done