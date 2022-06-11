#!/bin/sh

echo "-----Exercise 11 tests-----"

# Compile
echo "Compiling Exercise 11...."
g++ -std=c++11 ejercicio_11/ejercicio11.cpp -o ejercicio_11/compiled/ejercicio11
echo "Exercise 11 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 11 tests...."

ejercicio_11/compiled/ejercicio11 < ejercicio_11/tests/lab10e1.in.txt > ejercicio_11/outputs/lab10e1.out.txt
difference=$($file_compare_tool ejercicio_11/outputs/lab10e1.out.txt ejercicio_11/tests/lab10e1.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 11 Tests passed successfully"
exit 0
