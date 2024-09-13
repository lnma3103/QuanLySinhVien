if [ -d "build" ]; then
  echo "Directory build already exists"
else
  echo "Directory build does not exist. Creating build directory..."
  mkdir build
fi

cmake -B build -G "Unix Makefiles"
cmake --build build