TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

.PHONY: whodunnit testwhodunnit

copy:
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o copy copy.c -lcs50 -lm

whodunnit:
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o whodunnit whodunnit.c -lcs50 -lm

testwhodunnit: whodunnit
	./whodunnit clue.bmp verdict.bmp && open verdict.bmp
