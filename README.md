# Data Structures in C

This repository contemplates implementations form the most common data structures and algorithms in computer science. I am using the C programming language to implement those structures since it is a language free from abstractions.

## Build the project

I am using the premake5 tool to create the build systems for different operating systems. In the case of a GNU/Linux environment it will create a Makefile to compile in debug mode with the following commands:

```shell
$ premake5 gmake
$ make
```

So far there are no script to run the tests automatically, but you can run then with:

```shell
$ bin/Debug/dsc-tests
```
