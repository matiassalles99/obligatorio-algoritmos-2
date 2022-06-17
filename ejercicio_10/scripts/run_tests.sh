#!/bin/sh

echo "-----Exercise 10 tests-----"

# Compile
echo "Compiling Exercise 10...."
g++ -std=c++11 ejercicio_10/ejercicio10.cpp -o ejercicio_10/compiled/ejercicio10
echo "Exercise 10 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 10 tests...."

ejercicio_10/compiled/ejercicio10 < ejercicio_10/tests/suma10e1.in.txt > ejercicio_10/outputs/suma10e1.out.txt
difference=$($file_compare_tool ejercicio_10/outputs/suma10e1.out.txt ejercicio_10/tests/suma10e1.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_10/compiled/ejercicio10 < ejercicio_10/tests/suma10e2.in.txt > ejercicio_10/outputs/suma10e2.out.txt
difference=$($file_compare_tool ejercicio_10/outputs/suma10e2.out.txt ejercicio_10/tests/suma10e2.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_10/compiled/ejercicio10 < ejercicio_10/tests/suma10e3.in.txt > ejercicio_10/outputs/suma10e3.out.txt
difference=$($file_compare_tool ejercicio_10/outputs/suma10e3.out.txt ejercicio_10/tests/suma10e3.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 10 Tests passed successfully"
exit 0
