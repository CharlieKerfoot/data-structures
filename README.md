### Overview

The most fundamental data structures implemented in C. Each folder contains the main c file, a header file, tests, a Makefile, and a README providing a brief overview of the data structures, its use cases, and additional references.

These libraries are meant primarily for educational purposes, so I would reccommend implementing them yourself in C, rather than simply forking the repo or copying the folders into your project. Look at a reference like [Wikipedia](https://en.wikipedia.org/wiki/Data_structure) or one of the reference I included and build out the concept by hand.

Most of the references I used are from the CMU class [Introduction to Data Structures](https://www.andrew.cmu.edu/course/15-121/). They were simply some of the first I came across when looking for references sources. If you know of higher quality ones, reach out and let me know.

I take a lot of design liberties, but the general premise is the same regardless. I choose to use a generic Value type which contains a name and integer data to display that each of the structures can hold whatever type of data that you need. I also choose certian types of data structures, but the difference between a general tree or a binary search tree really isn't too important.

## List

| Data Structure | Description |
|----------------|-------------|
| Graph          | A collection of vertices connected by edges |
| Hash Map       | An unordered array with O(n) lookup |
| Heap           | A tree with strict min-first or max-first ordering |
| Linked List    | A sequential collection of items |
| Queue          | A sequence of items adhering to the First-In-First-Out (FIFO) principle |
| Stack          | A sequence of items adhering to the Last-In-First-Out (LIFO) principle |
| Tree           | A series of nodes connected vertically as branches |

## Tests

In any folder, run

```
make
```
and then

```
./test
```

The output should be "All Tests Passed".

## License

Feel free to use these libraries in any projects. They are primarily for educational purposes.
