test: queue_test.o queue.o error.o linked_value.o value.o
	gcc -o $@ $^

queue_test.o: queue_test.c
	gcc -o $@ -c $^

queue.o: queue.c
	gcc -o $@ -c $^

error.o: ../errors/error.c
	gcc -o $@ -c $^

linked_value.o: ../linked_value/linked_value.c
	gcc -o $@ -c $^

value.o: ../value/value.c
	gcc -o $@ -c $^

clean:
	rm -f *.o test
