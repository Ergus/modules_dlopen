## Readme

This is a test code to show how to implement a modular dynamic program. 

The modules are compiles as dynamic libraries and loaded at runtime
with dlopen.

Inside the modules there are simple functions that act as
constructors,, destructor and initializer. 

In the initializer function there is a call to a function exposed in
the caller program to be used by the modules. This is useful to
populate functions and variables containers in the main program with
pointers to functions and variables defined in the module.

It is very important the compilations options used in the Makefile to
create the dynamic objects and to expose the caller program objects to
the modules opened with dlopen.

## Build

Just run `make` and `make test`.
