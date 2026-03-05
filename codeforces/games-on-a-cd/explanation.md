# Games on a CD

A cyclic string of length n*k is given.
Each game name has length k.

We must reconstruct a valid sequence of n games.

## Key Idea

Treat the CD string as cyclic.

Compute rolling hashes for all substrings of length k.

Compute hashes for all possible game names.

Match substring hashes with game hashes.

Group matches by starting offset modulo k and check
if we can select n distinct games.

Double hashing is used to reduce collision risk.

## Complexity

O(nk log g)
