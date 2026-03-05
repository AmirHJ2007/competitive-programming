# Iahub and Permutations (Codeforces)

## Problem
Some elements of a permutation are replaced with -1.  
The original permutation had no fixed points (a[i] ≠ i).  
Count how many valid original permutations exist.

## Approach
Let:
- `t` = number of missing values that are not “dangerous”
- `k` = number of positions where putting the same index value would create a fixed point

We use DP to count valid assignments while avoiding fixed points, then multiply by `t!`.

## Complexity
Time: O(n^2)  
Memory: O(n^2)

## Files
- `solution.cpp`
