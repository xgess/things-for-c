# cs50
big thanks to Yung Hwa Kwon <yung.kwon@damncarousel.com> github.com/nowk

Docker image for cs50 C environment and tools `check50` and `style50`.

## Build

    docker build --rm -t cs50 .

## Usage

*Using /sample*

__check50:__

    docker run -v $(pwd)/sample:/src -it --rm cs50 check50 2014.fall.pset1.hello hello.c

__style50:__

    docker run -v $(pwd)/sample:/src -it --rm cs50 style50 hello.c

or check out how it's being done in the makefile
