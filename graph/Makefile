test: graph_test.o graph.o error.o
	gcc -o $@ $^

graph_test.o: graph_test.c
	gcc -o $@ -c $^

graph.o: graph.c
	gcc -o $@ -c $^

error.o: ../errors/error.c
	gcc -o $@ -c $^

clean:
	rm -f *.o test
