bin/a.out: src/main.o src/gauss.o
	$(CC) $^

gauss.o: src/gauss.c src/gauss.h