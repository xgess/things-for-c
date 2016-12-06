TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

.PHONY: recover

clean:
	rm -f *.jpg

recover: clean
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o recover recover.c -lcs50 -lm

run: recover
	./recover && open *.jpg

test: recover
	$(TESTRUNNER) 2015.fall.pset4.recover recover.c	

