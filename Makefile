bin/a.out: src/main.o src/gauss.o
	$(CC) $^
	cc src/main.c src/gauss.h src/gauss.c
gauss.o: src/gauss.c src/gauss.h
	cc -c src/gauss.c src/gauss.h