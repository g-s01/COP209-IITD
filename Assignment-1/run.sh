parent_dir=$(dirname "$(pwd)")

checkBuild() {
    if [ -d "build" ]; then
        rm -r build
    fi
}

makeBuild() {
    mkdir build
    cd build
    cmake $parent_dir
    cmake --build .
}

runBuild() {
    ./Assignment1
}

main() {
    checkBuild
    makeBuild
    runBuild
}

main