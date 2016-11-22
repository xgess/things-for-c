TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

fifteen: fifteen.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o fifteen fifteen.c -lcs50 -lm

clean:
	rm -f *.o a.out core fifteen log.txt

fifteentest: fifteen
	$(TESTRUNNER) 2015.fall.pset3.fifteen fifteen.c

fifteen_win3: fifteen
	./fifteen 3 < ./3x3.txt

fifteen_win4: fifteen
	./fifteen 4 < ./4x4.txt
