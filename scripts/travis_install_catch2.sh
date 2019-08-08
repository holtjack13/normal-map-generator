#!/bin/sh

# A script for installing Catch2 from source on travis build machine instance

# Clone Catch2 GitHub repository
git clone https://github.com/catchorg/Catch2.git

# Enter Catch2 directory, build and install
cd Catch2
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build/ --target install
