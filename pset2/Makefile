TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

all: initials initialstest
.PHONY: initials

initials:
	cc initials.c -lcs50 -o initials

initialstest: initials
	$(TESTRUNNER) 2015.fall.pset2.initials initials.c
