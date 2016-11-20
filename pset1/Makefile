TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

all: mario mariotest greedy greedytest
.PHONY: mario greedy

mario:
	cc mario.c -lcs50 -o mario

mariotest: mario
	$(TESTRUNNER) 2015.fall.pset1.mario mario.c

greedy:
	cc greedy.c -lcs50 -o greedy

greedytest: greedy
	$(TESTRUNNER) 2015.fall.pset1.greedy greedy.c
