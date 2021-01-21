all:
	gcc -Wall --pedantic src/*.c -o bin/gauss -ggdb

test: all
	bin/gauss dane/A dane/b
test2: all
	bin/gauss dane/A2 dane/b2
test3: all
	bin/gauss dane/A3 dane/b3
test4: all
	bin/gauss dane/A4 dane/b4
