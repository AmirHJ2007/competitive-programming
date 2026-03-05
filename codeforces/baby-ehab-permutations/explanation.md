# Baby Ehab Plays with Permutations

Problem from Codeforces.

## Problem
Given n cubes labeled from 1 to n, Baby Ehab performs exactly j swap operations.
In each operation he swaps two cubes.

For each j from 1 to k we must count how many different permutations can appear.

## Idea

Each operation is a swap (transposition).  
After j swaps, at most 2j elements can be affected.

We use dynamic programming where:

dp[i][j] = number of permutations of size i reachable using j swaps.

Then we extend these permutations to size n by counting ways to choose the affected elements.

## Complexity

Time: O(k²)  
Memory: O(k²)

## Implementation

See `solution.cpp`.
