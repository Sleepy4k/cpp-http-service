#!/bin/bash

# Script to compile and run a C++ program with g++
echo "Compiling C++ program with g++"

# Source file name (change this to your C++ source file)
source_file="./index.cpp"

# Output binary name (change this to your desired output name)
output_binary="./index"

# Compile the C++ program
g++ -std=c++11 "$source_file" -o "$output_binary" -lws2_32

# Check if compilation was successful
if [ $? -eq 0 ]; then
  # Run the compiled binary
  echo "Compilation successful. Running $output_binary..."
  "$output_binary"
else
  echo "Compilation failed."
fi

# Pause to keep the terminal open (optional)
read -p "Press Enter to exit..."