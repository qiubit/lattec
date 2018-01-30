#!/bin/bash

for filename in bad/*.lat; do
  echo $filename
  ../latc_llvm $filename
  echo $?
done
