#!/bin/sh

# A script for installing OpenCV from source on travis build machine instance

# Install OpenCV dependencies
sudo apt-get install -y build-essential libgtk2.0-dev pkg-config libavcodec-dev \
                        libavformat-dev libswscale-dev

# Clone OpenCV GitHub repository
git clone https://github.com/opencv/opencv.git

# Enter OpenCV directory, make build directory for CMake files
cd opencv
mkdir build
cd build

# Build project and install to machine
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local  \
         -DBUILD_DOCS=OFF -DBUILD_EXAMPLES=OFF -DBUILD_opencv_apps=OFF  \
         -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF -DBUILD_JAVA=OFF

make -j4
sudo make install

