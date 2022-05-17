#!/bin/sh

echo "-----Exercise 1 tests-----"

# Compile
echo "Compiling Exercise 1...."
g++ -std=c++11 ejercicio_1/ejercicio1.cpp -o ejercicio_1/compiled/ejercicio1
echo "Exercise 1 compiled successfully"

# Detect os for file compare tool
file_compare_tool=""
if [ "$1" = "nomatch" ]
then
    # Windows
    echo "Using fc"
    file_compare_tool="fc /w"
else
    # Unix
    echo "Using diff"
    file_compare_tool="diff --ignore-space-change"
fi

# Run all tests
echo "Running Exercise 1 tests...."

ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/0.in.txt > ejercicio_1/outputs/0.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/0.out.txt ejercicio_1/tests/0.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/01.in.txt > ejercicio_1/outputs/01.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/01.out.txt ejercicio_1/tests/01.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/02.in.txt > ejercicio_1/outputs/02.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/02.out.txt ejercicio_1/tests/02.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/10.in.txt > ejercicio_1/outputs/10.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/10.out.txt ejercicio_1/tests/10.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/100.in.txt > ejercicio_1/outputs/100.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/100.out.txt ejercicio_1/tests/100.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi


ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/1000.in.txt > ejercicio_1/outputs/1000.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/1000.out.txt ejercicio_1/tests/1000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/10000.in.txt > ejercicio_1/outputs/10000.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/10000.out.txt ejercicio_1/tests/10000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi

ejercicio_1/compiled/ejercicio1 < ejercicio_1/tests/1000000.in.txt > ejercicio_1/outputs/1000000.out.txt
difference=$($file_compare_tool ejercicio_1/outputs/1000000.out.txt ejercicio_1/tests/1000000.out.txt)
echo $difference

if [ "$difference" != "" ]
then
    exit 1
fi


echo "Exercise 1 Tests passed successfully"
exit 0
