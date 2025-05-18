#!/usr/bin/env bash

# run in the project directory
for entry in *; do
    if [ -d "$entry" ] && [[ $entry == m* ]]; then
        src_code="$PWD/"$entry"/"$entry".cpp"
        (cd bin && g++ -o "$entry" "$src_code")
    fi
done