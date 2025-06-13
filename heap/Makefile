test: heap_test.o heap.o error.o value.o
	gcc -o $@ $^

heap_test.o: heap_test.c
	gcc -o $@ -c $^

heap.o: heap.c
	gcc -o $@ -c $^

error.o: ../errors/error.c
	gcc -o $@ -c $^

value.o: ../value/value.c
	gcc -o $@ -c $^

clean:
	rm -f *.o test
