test: hash_map_test.o hash_map.o error.o linked_value.o value.o
	gcc -o $@ $^

hash_map_test.o: hash_map_test.c
	gcc -o $@ -c $^

hash_map.o: hash_map.c
	gcc -o $@ -c $^

error.o: ../errors/error.c
	gcc -o $@ -c $^

linked_value.o: ../linked_value/linked_value.c
	gcc -o $@ -c $^

value.o: ../value/value.c
	gcc -o $@ -c $^

clean:
	rm -f *.o test
