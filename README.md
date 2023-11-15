# Data Structures in C

This repository contemplates implementations form the most common data structures and algorithms in computer science. I am using the C programming language to implement those structures since it is a language free from abstractions.

## Build the project

I am using the premake5 tool to create the build systems for different operating systems. In the case of a GNU/Linux environment it will create a Makefile to compile in debug mode with the following commands:

```shell
$ tools/premake/premake5 gmake
$ make
```

So far there are no script to run the tests automatically, but you can run then with:

```shell
$ tools/tests.sh
```

To remove all make files and clean bin and obj folders run:

```shell
$ tools/clean.sh
```

It's possible to install the library after it is built:

```shell
$ tools/install.sh
```