# Normal Map Generator

[![Build Status](https://travis-ci.org/holtjack13/normal-map-generator.svg?branch=master)](https://travis-ci.org/holtjack13/normal-map-generator)

## Background
As stated on Wikipedia, [normal mapping][1] is:
> a technique used for faking the lighting of bumps and dents - an 
> implementation of bump mapping. It is used to add more details without
> using more polygons.
The artifact produced from this process is a "normal map", a color image storing
the normals of the mapped surface. A surface normal is a vector perpendicular
to a particular point on a surface. These surface normals are used by lighting
algorithms such as the [Lambertian][2] reflectance to calculate the intensity of
light shining on a specific point on a surface.

How can we implement the process of normal mapping? One way to produce a normal
map from an input texture is to use a greyscale version of the texture as a
height map. Because greyscale pixels store a single intensity value, they can
be used to graph a surface, with higher intensities representing higher points
on the surface and vice-versa. By approximating the rate of change of the surface,
we can compute a normal for each surface point. 

## Installing and Building the Program
To install the program you will first need to clone the git repository:
```console
foo@bar:~$ git clone https://github.com/holtjack13/normal-map-generator.git
```
Next, enter the directory and create both a build folder to make 
the program, and a bin folder for the executable:
```console
foo@bar:~$ cd normal-map-generator
foo@bar:~/normal-map-generator$ mkdir build bin
foo@bar:~/normal-map-generator$ cd build
```
From the build folder, run the following command:
```console
foo@bar:~/normal-map-generator/build$ cmake ..
foo@bar:~/normal-map-generator/build$ make 
```
There are some extra flags you may wish to pass to the cmake command:
- `-DCMAKE_BUILD_TYPE` - Determines whether the build is a Debug or Release build. Set to either `Debug` or `Release`
- `DTESTS_ON` - Turns unit tests on, which can be run from build/tests using `ctest`. An tests/bin directory will need to be created to use this feature. Set to either `On` or `Off`.

## Using the program
To run the program, navigate to the bin directory and run the program:
```console
foo@bar:~/normal-map-generator/bin ./nmg-bin <texture-image> <output-image-name>
```
[1]: https://en.wikipedia.org/wiki/Normal_mapping 
[2]: https://en.wikipedia.org/wiki/Lambertian_reflectance
