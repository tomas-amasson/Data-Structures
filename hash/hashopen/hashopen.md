# OPEN ADDRESSING HASH

Doesn't allow multiple keys in the same slot.

## How to solve

parameterize the hash function: h(K, i)
i = the probe number

### Defining  h(K, i)

- Linear Probing
- Quadratic Probing
- Double Hashing

#### Linear Probing

Uses a auxiliary hash function

h(K, i) = (h'(k) + i) % m

Causes primary cluster, which are long and cause problems to insert and search.

#### Quadractic Probing

Uses non-linear increments

h(K, i) = (h'(K) + c1 * i + c2 * i²) % m

Causes secondary cluster, which is not as bad as the primary one, but reduces performance,
if a key can't find a place with i = 0, it coincides with every other key that had the same problem, but jumping some slots.


#### Double Hashing

h(K, i) = (h1(K) + h2(K) * i) % m

h1(K) = K % m1
h2(K) = 1 + (K % m2)

##### Problems

If the hash table is full:
- If the a >= 0.9, define m3 = c * m1
- Rehash every key with m3 [O(n)]


##### Complexity

###### Case 1. [k does not belong to T]

Defining: 
- a < 1

The number of searches of a key that does not belong to T is at the worst case: 1/(1 - a)

The mean of searches of a key is at the worst case: 1/a * ln(1/[1 - a])

### Colision Probability

#### Birthday Problem
The chance of, in a group of a n people, that at least 2 people have the same birthday day.

- P(Share birthday day)                 = 1/365
- P(!Share birthday day) = 1 - 1/365    = 364/365
- Number of pairs = n!/((n-2)! * 2)     = n(n-1)/2
- P(!Any pair share birhtday day)       = (364/365)^(n(n-1)/2)
- P(Any pair share birthday day)        = 1 - (364/365)^(n(n-1)/2)

For n = 23, P ~= 50%
For n = 57, p ~= 99%

#### Colision Mean
For C = the number of colisions of the i'th key

- 1° key => E[C] = 0
- 2° key => E[C] = 1/m
- 3° key => E[C] = 2/m
...

- i° key => E[C] = (i - 1)/m


E[C] = Sum of all E[Ci]
E[C] ~= m/2


### Perfect Hashing
Is based in 2 levels of Universal Hashing, external and internal hash

- Search = O(1)
- Imutable keys

#### External Hash

For n = m, choose a prime number greater than any key, to be m

h(K) = ((aK + b) mod p) mod m)
[a and b are chosen randomly]

##### Setup External

- For any key calcukate h(K)
- Maintain a counter nj (Number of keys in Sj)
- Verify if the spread is good
- If not, choose new a and b, randomly, and repeat the proccess

- If it's okay, structure the internal hash

##### Setup Internal

- For each Sj, define hj(K) = ((aj * K + bj) mod p) mod mj
[mj = nj²]

- Verify that hj() doesn't allow any colisions
