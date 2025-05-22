all: clean arcfour example 

example: example.o
	gcc arcfour.o example.o -o example -Wall -Wextra -Werror -O2 
	./example

example.o: src/example.c
	gcc -c -O2 -Wall -Wextra -Werror src/example.c

arcfour: arcfour.o
	gcc arcfour.o -o arcfour.so -O2 -Wall -Wextra -Werror -fPIC -shared -ldl -D_GNU_SOURCE

arcfour.o: src/arcfour.c
	gcc -c -O2 -Wall -Wextra -Werror src/arcfour.c

clean:
	rm -f *.o *.so example
