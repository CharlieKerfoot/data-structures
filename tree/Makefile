test: tree_test.o tree.o error.o value.o
	gcc -o $@ $^

tree_test.o: tree_test.c
	gcc -o $@ -c $^

tree.o: tree.c
	gcc -o $@ -c $^

error.o: ../errors/error.c
	gcc -o $@ -c $^

value.o: ../value/value.c
	gcc -o $@ -c $^

clean:
	rm -f *.o test
