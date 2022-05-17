#!/bin/sh

echo "-----Exercise 4 tests-----"

# Compile
echo "Compiling Exercise 4...."
g++ -std=c++11 ejercicio_4/ejercicio4.cpp -o ejercicio_4/compiled/ejercicio4
echo "Exercise 4 compiled successfully"

# Run all tests
echo "Running Exercise 4 tests...."

ejercicio_4/compiled/ejercicio4 < ejercicio_4/tests/10.in.txt > ejercicio_4/outputs/10.out.txt
difference=$(diff --ignore-space-change ejercicio_4/outputs/10.out.txt ejercicio_4/tests/10.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_4/compiled/ejercicio4 < ejercicio_4/tests/100.in.txt > ejercicio_4/outputs/100.out.txt
difference=$(diff --ignore-space-change ejercicio_4/outputs/100.out.txt ejercicio_4/tests/100.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_4/compiled/ejercicio4 < ejercicio_4/tests/1000.in.txt > ejercicio_4/outputs/1000.out.txt
difference=$(diff --ignore-space-change ejercicio_4/outputs/1000.out.txt ejercicio_4/tests/1000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_4/compiled/ejercicio4 < ejercicio_4/tests/10000.in.txt > ejercicio_4/outputs/10000.out.txt
difference=$(diff --ignore-space-change ejercicio_4/outputs/10000.out.txt ejercicio_4/tests/10000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_4/compiled/ejercicio4 < ejercicio_4/tests/100000.in.txt > ejercicio_4/outputs/100000.out.txt
difference=$(diff --ignore-space-change ejercicio_4/outputs/100000.out.txt ejercicio_4/tests/100000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi



echo "Exercise 4 Tests passed successfully"
exit 0
