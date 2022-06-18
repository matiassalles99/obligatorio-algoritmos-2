#!/bin/sh

echo "-----Exercise 2 tests-----"

# Compile
echo "Compiling Exercise 2...."
g++ -std=c++11 ejercicio_2/ejercicio2.cpp -o ejercicio_2/compiled/ejercicio2
echo "Exercise 2 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 2 tests...."

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/0.in.txt > ejercicio_2/outputs/0.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/0.out.txt ejercicio_2/tests/0.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/01.in.txt > ejercicio_2/outputs/01.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/01.out.txt ejercicio_2/tests/01.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/1.in.txt > ejercicio_2/outputs/1.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/1.out.txt ejercicio_2/tests/1.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/5.in.txt > ejercicio_2/outputs/5.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/5.out.txt ejercicio_2/tests/5.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/10.in.txt > ejercicio_2/outputs/10.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/10.out.txt ejercicio_2/tests/10.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/100.in.txt > ejercicio_2/outputs/100.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/100.out.txt ejercicio_2/tests/100.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/1000.in.txt > ejercicio_2/outputs/1000.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/1000.out.txt ejercicio_2/tests/1000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/10000.in.txt > ejercicio_2/outputs/10000.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/10000.out.txt ejercicio_2/tests/10000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_2/compiled/ejercicio2 < ejercicio_2/tests/1000000.in.txt > ejercicio_2/outputs/1000000.out.txt
difference=$($file_compare_tool ejercicio_2/outputs/1000000.out.txt ejercicio_2/tests/1000000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

echo "Exercise 2 Tests passed successfully"
exit 0
