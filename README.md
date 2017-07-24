Hachi
=====

*"Hachi is a wordcount using a C djb2 Hashtable"*

## Hash Function

As shown in severals performance graphs, in terms of throughput at not-too-small data sizes (larger than 10-20 bytes), xxHash64 is the king.

Nevertheless, [djb2](http://www.cse.yorku.ca/~oz/hash.html) is choosen as:

* Non-cryptographic hash function
* Quick implementattion for lack of time
* Fastest one if < 10 bytes (FNV hash function competitor with a bit less of collisions)
* It beats most usable algorithms as string hash function by adjusting the factor of three.

I assume that djb2 is not the fastest one for wordcounting and it produces too much collisions for my taste.

## TODO

- [x] Hashtable implementation
- [x] Hash function
- [ ] Wordcount app encapsulation
