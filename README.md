### Google Test GTest/GMock on Ubuntu using CMake. Tested on Ubuntu 20.04.

#### Install CMake:

```console
$ sudo apt-get install cmake
```

#### Install GTest:

1. Install gtest development package. This package only install source files and you have to compile the code yourself to create the necessary library files.

```console
$ sudo apt-get install libgtest-dev
```

2. Go to the location of the source files (should be located at /usr/src/gtest)

```console
$ cd /usr/src/gtest
```

3. Run CMake to configure the project and generate a native build system. Then compile/link the project:

```console
$ sudo cmake CMakeLists.txt
```

```console
$ sudo make
```
 
4. Find and copy the files **libgtest.a** and **libgtest_main.a** to your /usr/lib folder (You can also do a symlink). These files in my case were at "/lib/x86_64-linux-gnu" folder. Therefore:


```console
$ sudo cp ./lib/x86_64-linux-gnu/libgtest*.a /usr/lib
```

#### Install GMock (all steps are similar to GTest)

```console
$ sudo apt-get install libgmock-dev
```

```console
$ cd /usr/src/gmock
```

```console
$ sudo cmake CMakeLists.txt
```

```console
$ sudo make
```

Files **libgmock.a** and **libgmock_main.a**
```console
$ sudo cp ./lib/x86_64-linux-gnu/libgmock*.a /usr/lib
```

### Test

Clone this repository

```console
$ git clone 
```

#### Test GTest
Inside of the folder **gtest_example**:
```console
$ mkdir build && cd build 
```

```console
$ cmake .. 
```

```console
$ make 
```

Run the tests:
```console
$ ./runTests
```

#### Test GMock
Inside of the folder **gmock_example**:
```console
$ mkdir build && cd build 
```

```console
$ cmake .. 
```

```console
$ make 
```

Run the tests:
```console
$ ./runTests
```

#### References

This tutorial is based on the following sources:

[Getting started with Google Test (GTest) on Ubuntu](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/)

[Google C++ Testing, GTest, GMock Framework](https://www.youtube.com/watch?v=nbFXI9SDfbk&list=PL_dsdStdDXbo-zApdWB5XiF2aWpsqzV55)

For using GMock library I had to use this file to unable cmake to find the Gmock packages:
[FindGMock.cmake](https://github.com/cucumber/cucumber-cpp/blob/main/cmake/modules/FindGMock.cmake)

