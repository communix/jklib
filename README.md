# JK C Library
The JK library has the common library code for PC and Embeded C programming.

## libjk.a build process in windows MinGW environments.
Follow the below steps to build the libjk.a
you can change it to your own environment (Like as Linux) changing the cmake -G option.
```
$ cd ./src/build
$ cmake -G "MinGW Makefiles" CMakeLists.txt
$ make
```

## Install a libjk.a library.
After make, you can install the library and header file to the release directory.
```
$ cd ./src/build
$ make install
[100%] Built target jk
Install the project...
-- Install configuration: "Debug"
-- Installing: C:/Users/jayki/Documents/projects/source/jklib/src/build/../../release/libjk.a
-- Up-to-date: C:/Users/jayki/Documents/projects/source/jklib/src/build/../../release/libjk.h
```

## libjk.a unit test
The unit_test.exe is built when you build the libjk.a library.
you can execute the unit_test.exe to run a unit test.
```
$ cd ./src/unit_test/
$ ./unit_test.exe
jklib_unit_test.c:26:test_integer_type_size:PASS

-----------------------
1 Tests 0 Failures 0 Ignored
OK
```
