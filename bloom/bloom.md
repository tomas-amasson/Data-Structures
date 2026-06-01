## BLOOM FILTER

Applied in data structures to turn the search to O(1).

### STRUCTURE

Fb = Array of m bits + Set of K hash functions [hj(x)]

### BASIC FUNCTION

calculates h1(x), h2(x), ... , hk(x)
B[hi(x)] = 1, i starts from 1 to k

[May cause false postitives]

### FALSE POSITIVE PROBABILITY


Probability (1 - 1/m)^k of not being altered = e^(-k/m)
for all bits = e^(-k*n/m)

Probability that one bit is 1, after n insertions is
1 - e^(-k*n/m)

Probability of false positive = (1 - e^(kn/m))^k

ln E(m, n) = -m/n * ln²2
m* = n ln(E(m, n))/ ln²2
