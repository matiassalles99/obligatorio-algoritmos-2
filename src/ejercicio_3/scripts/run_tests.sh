#!/bin/sh

echo "-----Exercise 3 tests-----"

# Compile
echo "Compiling Exercise 3...."
g++ -std=c++11 ejercicio_3/ejercicio3.cpp -o ejercicio_3/compiled/ejercicio3
echo "Exercise 3 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 3 tests...."

ejercicio_3/compiled/ejercicio3 < ejercicio_3/tests/0.in.txt > ejercicio_3/outputs/0.out.txt
difference=$($file_compare_tool ejercicio_3/outputs/0.out.txt ejercicio_3/tests/0.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_3/compiled/ejercicio3 < ejercicio_3/tests/10.in.txt > ejercicio_3/outputs/10.out.txt
difference=$($file_compare_tool ejercicio_3/outputs/10.out.txt ejercicio_3/tests/10.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_3/compiled/ejercicio3 < ejercicio_3/tests/100.in.txt > ejercicio_3/outputs/100.out.txt
difference=$($file_compare_tool ejercicio_3/outputs/100.out.txt ejercicio_3/tests/100.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_3/compiled/ejercicio3 < ejercicio_3/tests/1000.in.txt > ejercicio_3/outputs/1000.out.txt
difference=$($file_compare_tool ejercicio_3/outputs/1000.out.txt ejercicio_3/tests/1000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_3/compiled/ejercicio3 < ejercicio_3/tests/100000.in.txt > ejercicio_3/outputs/100000.out.txt
difference=$($file_compare_tool ejercicio_3/outputs/100000.out.txt ejercicio_3/tests/100000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_3/compiled/ejercicio3 < ejercicio_3/tests/1000000.in.txt > ejercicio_3/outputs/1000000.out.txt
difference=$($file_compare_tool ejercicio_3/outputs/1000000.out.txt ejercicio_3/tests/1000000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 3 Tests passed successfully"
exit 0
