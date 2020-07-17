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
