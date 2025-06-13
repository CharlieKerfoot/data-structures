test: stack_test.o stack.o error.o value.o
	gcc -o $@ $^

stack_test.o: stack_test.c
	gcc -o $@ -c $^

stack.o: stack.c
	gcc -o $@ -c $^

error.o: ../errors/error.c
	gcc -o $@ -c $^

value.o: ../value/value.c
	gcc -o $@ -c $^

clean:
	rm -f *.o test
