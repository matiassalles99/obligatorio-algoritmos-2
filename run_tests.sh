echo "Running all tests..."

./ejercicio_1/scripts/run_tests.sh
if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 1"
    exit 1
fi


./ejercicio_4/scripts/run_tests.sh

if [ $? -ne 0 ]; then
    echo "Error running tests for exercise 4"
    exit 1
fi
