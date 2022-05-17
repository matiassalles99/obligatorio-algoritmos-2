echo "Running all tests..."

./ejercicio_1/scripts/run_tests.sh
if [ $? -ne 0 ]; then
    echo "Error running tests for ejercicio_1"
    exit 1
fi

