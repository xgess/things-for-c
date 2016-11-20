TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

all: mario mariotest
.PHONY: all mario mariotest

mario:
	cc mario.c -lcs50 -o mario

mariotest: mario
	$(TESTRUNNER) 2015.fall.pset1.mario mario.c
