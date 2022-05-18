#!/bin/sh

echo "-----Exercise 7 tests-----"

# Compile
echo "Compiling Exercise 7...."
g++ -std=c++11 ejercicio_7/ejercicio7.cpp -o ejercicio_7/compiled/ejercicio7
echo "Exercise 7 compiled successfully"

file_compare_tool="diff --ignore-space-change"

# Run all tests
echo "Running Exercise 7 tests...."

ejercicio_7/compiled/ejercicio7 < ejercicio_7/tests/msp1.in.txt > ejercicio_7/outputs/msp1.out.txt
difference=$($file_compare_tool ejercicio_7/outputs/msp1.out.txt ejercicio_7/tests/msp1.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_7/compiled/ejercicio7 < ejercicio_7/tests/msp2.in.txt > ejercicio_7/outputs/msp2.out.txt
difference=$($file_compare_tool ejercicio_7/outputs/msp2.out.txt ejercicio_7/tests/msp2.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_7/compiled/ejercicio7 < ejercicio_7/tests/msp3.in.txt > ejercicio_7/outputs/msp3.out.txt
difference=$($file_compare_tool ejercicio_7/outputs/msp3.out.txt ejercicio_7/tests/msp3.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_7/compiled/ejercicio7 < ejercicio_7/tests/msp4.in.txt > ejercicio_7/outputs/msp4.out.txt
difference=$($file_compare_tool ejercicio_7/outputs/msp4.out.txt ejercicio_7/tests/msp4.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi


echo "Exercise 7 Tests passed successfully"
exit 0
