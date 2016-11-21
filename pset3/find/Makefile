TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

all: find generate

find: find.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core find generate

findtest: find
	$(TESTRUNNER) 2015.fall.pset3.find helpers.c
