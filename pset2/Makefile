TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

all: initials initialstest caesar caesartest
.PHONY: initials caesar

initials:
	cc initials.c -lcs50 -o initials

initialstest: initials
	$(TESTRUNNER) 2015.fall.pset2.initials initials.c

caesar:
	cc caesar.c -lcs50 -o caesar

caesartest: caesar
	$(TESTRUNNER) 2015.fall.pset2.caesar caesar.c
