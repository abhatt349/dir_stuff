all: dir_things.c
	gcc dir_things.c

clean:
	rm -f *.out
	rm *~
	rm *#

run: all
	./a.out
