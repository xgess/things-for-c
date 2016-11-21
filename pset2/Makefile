TESTRUNNER=docker run -v $(shell pwd):/src -it --rm xgess/cs50 check50

all: initials initialstest caesar caesartest vigenere vigeneretest
.PHONY: initials caesar vigenere

initials:
	cc initials.c -lcs50 -o initials

initialstest: initials
	$(TESTRUNNER) 2015.fall.pset2.initials initials.c

caesar:
	cc caesar.c -lcs50 -o caesar

caesartest: caesar
	$(TESTRUNNER) 2015.fall.pset2.caesar caesar.c

vigenere:
	cc vigenere.c -lcs50 -o vigenere

vigeneretest: vigenere
	$(TESTRUNNER) 2015.fall.pset2.vigenere vigenere.c
