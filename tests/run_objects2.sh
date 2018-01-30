#!/bin/bash

for filename in extensions/objects2/*.lat; do
    echo $filename
    ../latc_llvm $filename
    if [ $? -ne 0 ]
        then
            echo "Compile $filename ERROR!"
            exit 1
    fi
done

for filename in extensions/objects2/*.bc; do
    OUT=$(basename $filename)
    OUTFILE=${OUT%%.*}\.myout
    echo "RUNNING $filename"
    lli $filename >$OUTFILE
done

for filename in *.myout; do
    IN=extensions/objects2/${filename%%.*}\.output
    echo $IN
    diff $IN $filename
    echo "Diff ok"
done

rm *.myout
