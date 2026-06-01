# HASH METHODS

## Division

h(K) = k % m

### Problems

m can't be powers of 2, since it breaks the equal probabilities within the hash.

### Good Structure

m is better if is a prime number, greate than any key.


## Multiplication
A is a number between 0 and 1.

h(K) = floor(m([kA] % 1))

### Problems

A can't be a number with a low number of decimals.

### Good Structure

if A has a lot of decimals.

## Universal

### Problems

Rehashing is expensive

### Good Structure

- Choose a prime number: p (p is greater than any key)
- Define the following sets: Zp and Zp*
- Define the hash function: Hab(k) =  ((aK + b) % p) % m

|H| = p(p - 1)

#### How to resolve

- Choose a Hab(k)
- Use it until it's is not spaced anymore
- To check that, use: if the Sum from i = 0 to m - 1(ni²) <= 2n, the spacing is good
- Choose a new hash function and rehash
