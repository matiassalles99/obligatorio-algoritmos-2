#!/bin/sh

echo "-----Exercise 5 tests-----"

# Compile
echo "Compiling Exercise 5...."
g++ -std=c++11 ejercicio_5/ejercicio5.cpp -o ejercicio_5/compiled/ejercicio5
echo "Exercise 5 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 5 tests...."

ejercicio_5/compiled/ejercicio5 < ejercicio_5/tests/5.in.txt > ejercicio_5/outputs/5.out.txt
difference=$($file_compare_tool ejercicio_5/outputs/5.out.txt ejercicio_5/tests/5.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_5/compiled/ejercicio5 < ejercicio_5/tests/8.in.txt > ejercicio_5/outputs/8.out.txt
difference=$($file_compare_tool ejercicio_5/outputs/8.out.txt ejercicio_5/tests/8.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_5/compiled/ejercicio5 < ejercicio_5/tests/10.in.txt > ejercicio_5/outputs/10.out.txt
difference=$($file_compare_tool ejercicio_5/outputs/10.out.txt ejercicio_5/tests/10.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_5/compiled/ejercicio5 < ejercicio_5/tests/100.in.txt > ejercicio_5/outputs/100.out.txt
difference=$($file_compare_tool ejercicio_5/outputs/100.out.txt ejercicio_5/tests/100.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_5/compiled/ejercicio5 < ejercicio_5/tests/1000.in.txt > ejercicio_5/outputs/1000.out.txt
difference=$($file_compare_tool ejercicio_5/outputs/1000.out.txt ejercicio_5/tests/1000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 5 Tests passed successfully"
exit 0
