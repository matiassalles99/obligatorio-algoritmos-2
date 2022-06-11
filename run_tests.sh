echo "Running all tests..."

./ejercicio_1/scripts/run_tests.sh
if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 1"
    exit 1
fi

./ejercicio_2/scripts/run_tests.sh
if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 2"
    exit 1
fi

./ejercicio_3/scripts/run_tests.sh
if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 3"
    exit 1
fi

./ejercicio_4/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 4"
    exit 1
fi

./ejercicio_5/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 5"
    exit 1
fi

./ejercicio_6/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 6"
    exit 1
fi

./ejercicio_7/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 7"
    exit 1
fi

# Falta el 8 porque esta fallando

./ejercicio_9/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 9"
    exit 1
fi

./ejercicio_10/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 10"
    exit 1
fi

./ejercicio_11/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 11"
    exit 1
fi

echo "All tests passed :)"