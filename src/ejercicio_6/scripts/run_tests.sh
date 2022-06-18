#!/bin/sh

echo "-----Exercise 6 tests-----"

# Compile
echo "Compiling Exercise 6...."
g++ -std=c++11 ejercicio_6/ejercicio6.cpp -o ejercicio_6/compiled/ejercicio6
echo "Exercise 6 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 6 tests...."

ejercicio_6/compiled/ejercicio6 < ejercicio_6/tests/3.in.txt > ejercicio_6/outputs/3.out.txt
difference=$($file_compare_tool ejercicio_6/outputs/3.out.txt ejercicio_6/tests/3.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_6/compiled/ejercicio6 < ejercicio_6/tests/7.in.txt > ejercicio_6/outputs/7.out.txt
difference=$($file_compare_tool ejercicio_6/outputs/7.out.txt ejercicio_6/tests/7.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_6/compiled/ejercicio6 < ejercicio_6/tests/10.in.txt > ejercicio_6/outputs/10.out.txt
difference=$($file_compare_tool ejercicio_6/outputs/10.out.txt ejercicio_6/tests/10.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_6/compiled/ejercicio6 < ejercicio_6/tests/100.in.txt > ejercicio_6/outputs/100.out.txt
difference=$($file_compare_tool ejercicio_6/outputs/100.out.txt ejercicio_6/tests/100.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_6/compiled/ejercicio6 < ejercicio_6/tests/1000.in.txt > ejercicio_6/outputs/1000.out.txt
difference=$($file_compare_tool ejercicio_6/outputs/1000.out.txt ejercicio_6/tests/1000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 6 Tests passed successfully"
exit 0
