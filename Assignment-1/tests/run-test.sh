#!/bin/bash

# Set base directories based on the current script's location
script_dir="$(cd "$(dirname "$0")" && pwd)"
project_root="$(cd "$script_dir/.." && pwd)"

# Paths to the necessary files
FUNCTIONS_FILE="${project_root}/run.sh"
SHUNIT2_PATH="${project_root}/../external-libraries/shunit2/shunit2"

# Debugging: Print current directory and paths
echo "Current directory: $(pwd)"
echo "Script directory: $script_dir"
echo "Project root: $project_root"
echo "Functions file path: $FUNCTIONS_FILE"
echo "shunit2 path: $SHUNIT2_PATH"

# Source the functions file
if [ -f "$FUNCTIONS_FILE" ]; then
    . "$FUNCTIONS_FILE"
    echo "Functions file sourced."
else
    echo "Functions file not found!"
    exit 1
fi

# Test setup
setUp() {
    echo "Setting up test environment"
    TEST_DIR=$(mktemp -d)
    cd "$TEST_DIR"
}

# Test teardown
tearDown() {
    echo "Tearing down test environment"
    cd ..
    rm -rf "$TEST_DIR"
}

# Test functions
testCheckBuild() {
    echo "Running testCheckBuild"
    mkdir build
    checkBuild
    assertFalse "Directory build should not exist" "[ -d build ]"
}

testMakeBuild() {
    echo "Running testMakeBuild"
    makeBuild
    assertTrue "CMake build should produce a Makefile" "[ -f Makefile ]"
    cd ..
    assertTrue "Directory build should exist" "[ -d build ]"
}

testRunBuild() {
    echo "Running testRunBuild"
    main
    assertTrue "main/runBuild should execute without error" "[ $? -eq 0 ]"
}

cd ..

# Source shunit2 and run tests
if [ -f "$SHUNIT2_PATH" ]; then
    . "$SHUNIT2_PATH"
    echo "shunit2 library sourced."
else
    echo "shunit2 library not found!"
    exit 1
fi

rm -rf ${script_dir}/build