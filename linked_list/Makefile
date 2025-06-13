test: linked_list_test.o linked_list.o error.o linked_value.o value.o
	gcc -o $@ $^

linked_list_test.o: linked_list_test.c
	gcc -o $@ -c $^

linked_list.o: linked_list.c
	gcc -o $@ -c $^

error.o: ../errors/error.c
	gcc -o $@ -c $^

linked_value.o: ../linked_value/linked_value.c
	gcc -o $@ -c $^

value.o: ../value/value.c
	gcc -o $@ -c $^

clean:
	rm -f *.o test
