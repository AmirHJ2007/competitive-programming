# The Number of Pairs

Given integers c, d, x we count pairs (a,b) such that:

c * lcm(a,b) - d * gcd(a,b) = x

## Key Idea

Let g = gcd(a,b), and write:

a = g*u
b = g*v

where gcd(u,v) = 1.

Then:

c * g * u * v - d * g = x  
g(cuv - d) = x

Let k = x/g + d.

If k % c == 0 then uv = k/c.

Number of coprime pairs (u,v) with uv = m equals:

2^(number of distinct prime factors of m).

## Complexity

Precomputation: O(N log log N)  
Per test case: O(sqrt(x))
