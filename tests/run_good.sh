#!/bin/bash

for filename in good/*.lat; do
    echo $filename
    ../latc_llvm $filename
    if [ $? -ne 0 ]
        then
            echo "Compile $filename ERROR!"
            exit 1
    fi
done

for filename in good/*.bc; do
    OUT=$(basename $filename)
    OUTFILE=${OUT%%.*}\.myout
    echo "RUNNING $filename"
    /home/students/inf/PUBLIC/MRJP/llvm39/bin/lli $filename >$OUTFILE
done

for filename in *.myout; do
    IN=good/${filename%%.*}\.output
    echo $IN
    diff $IN $filename
    echo "Diff ok"
done

rm *.myout
