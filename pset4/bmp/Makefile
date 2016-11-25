TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

.PHONY: whodunnit testwhodunnit resize

copy:
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o copy copy.c -lcs50 -lm

whodunnit:
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o whodunnit whodunnit.c -lcs50 -lm

testwhodunnit: whodunnit
	./whodunnit clue.bmp verdict.bmp && open verdict.bmp

resize:
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o resize resize.c -lcs50 -lm

resizetest: resize
	$(TESTRUNNER) 2015.fall.pset4.resize bmp.h resize.c

testresize: resize
	./resize 4 smiley.bmp test.bmp && open test.bmp

