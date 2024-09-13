if test -d "build"; then
    echo "Build directory already exists"
else
    mkdir build
fi

cmake -B build -G "Ninja"
cmake --build build