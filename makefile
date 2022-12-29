fibcalc: fibcalc.o BigInt.o
	gcc -static -o fibcalc fibcalc.o BigInt.o -lm
fibcalc.o: fibcalc.c BigInt.h
	gcc -c -g fibcalc.c
BigInt.o: BigInt.c BigInt.h
	gcc -c -g BigInt.c
