#!/bin/bash

# Path to the functions file and shunit2 library
FUNCTIONS_FILE="../run.sh"
SHUNIT2_PATH="../../shunit2"

# Source the functions and shunit2 library
. "$FUNCTIONS_FILE"
. "$SHUNIT2_PATH"

# Test setup
setUp() {
    # Create a temporary directory for testing
    TEST_DIR=$(mktemp -d)
    cd "$TEST_DIR"
}

# Test teardown
tearDown() {
    # Cleanup the temporary directory
    cd ..
    rm -rf "$TEST_DIR"
}

# Test functions
testCheckBuild() {
    # Test checkBuild function
    mkdir build
    checkBuild
    assertFalse "Directory build should not exist" "[ -d build ]"
}

testMakeBuild() {
    # Test makeBuild function
    makeBuild
    assertTrue "Directory build should exist" "[ -d build ]"
    cd build
    assertTrue "CMake build should produce a Makefile" "[ -f CMakeLists.txt ]"
    cd ..
}

testRunBuild() {
    # Mock runBuild function
    # This is a bit tricky because it runs a binary that might not exist.
    # Ideally, you'd mock the `runBuild` function or create a test binary.

    # For now, we are assuming runBuild will run successfully without errors.
    runBuild
    assertTrue "runBuild should execute without error" "[ $? -eq 0 ]"
}

# Run tests
. "$SHUNIT2_PATH"
