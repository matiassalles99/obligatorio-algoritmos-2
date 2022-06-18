#!/bin/sh

echo "-----Exercise 9 tests-----"

# Compile
echo "Compiling Exercise 9...."
g++ -std=c++11 ejercicio_9/ejercicio9.cpp -o ejercicio_9/compiled/ejercicio9
echo "Exercise 9 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 9 tests...."

ejercicio_9/compiled/ejercicio9 < ejercicio_9/tests/coef10e1.in.txt > ejercicio_9/outputs/coef10e1.out.txt
difference=$($file_compare_tool ejercicio_9/outputs/coef10e1.out.txt ejercicio_9/tests/coef10e1.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_9/compiled/ejercicio9 < ejercicio_9/tests/coef10e2.in.txt > ejercicio_9/outputs/coef10e2.out.txt
difference=$($file_compare_tool ejercicio_9/outputs/coef10e2.out.txt ejercicio_9/tests/coef10e2.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_9/compiled/ejercicio9 < ejercicio_9/tests/coef10e3.in.txt > ejercicio_9/outputs/coef10e3.out.txt
difference=$($file_compare_tool ejercicio_9/outputs/coef10e3.out.txt ejercicio_9/tests/coef10e3.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 9 Tests passed successfully"
exit 0
