#!/bin/bash

echo "Running Garbage Collection Tests..."
gcc -I../include ../tests/test_gc.c ../src/gc.c -o test_gc
./test_gc

echo "Running 'new' Macro Tests..."
gcc -I../include ../tests/test_new.c ../src/gc.c ../src/easyc.c -o test_new
./test_new

echo "All tests passed."