#!/bin/sh

echo "-----Exercise 8 tests-----"

# Compile
echo "Compiling Exercise 8...."
g++ -std=c++11 ejercicio_8/ejercicio8.cpp -o ejercicio_8/compiled/ejercicio8
echo "Exercise 8 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 8 tests...."

ejercicio_8/compiled/ejercicio8 < ejercicio_8/tests/10.in.txt > ejercicio_8/outputs/10.out.txt
difference=$($file_compare_tool ejercicio_8/outputs/10.out.txt ejercicio_8/tests/10.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_8/compiled/ejercicio8 < ejercicio_8/tests/100.in.txt > ejercicio_8/outputs/100.out.txt
difference=$($file_compare_tool ejercicio_8/outputs/100.out.txt ejercicio_8/tests/100.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_8/compiled/ejercicio8 < ejercicio_8/tests/1000.in.txt > ejercicio_8/outputs/1000.out.txt
difference=$($file_compare_tool ejercicio_8/outputs/1000.out.txt ejercicio_8/tests/1000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_8/compiled/ejercicio8 < ejercicio_8/tests/10000.in.txt > ejercicio_8/outputs/10000.out.txt
difference=$($file_compare_tool ejercicio_8/outputs/10000.out.txt ejercicio_8/tests/10000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_8/compiled/ejercicio8 < ejercicio_8/tests/100000.in.txt > ejercicio_8/outputs/100000.out.txt
difference=$($file_compare_tool ejercicio_8/outputs/100000.out.txt ejercicio_8/tests/100000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 8 Tests passed successfully"
exit 0
