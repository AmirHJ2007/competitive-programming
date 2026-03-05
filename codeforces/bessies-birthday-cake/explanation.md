# Bessie's Birthday Cake (Hard)

We are given a polygon with n vertices and x chosen vertices.
We can add up to y extra vertices.

Goal: maximize the number of triangles formed by non-intersecting diagonals.

## Key Idea

Sort the chosen vertices and consider gaps between them
in the circular order.

Each gap of size g contributes floor(g/2) possible triangles.

Odd gaps allow one extra triangle if we spend vertices.

We greedily fill the smallest odd gaps first using the
available y vertices.

## Complexity

O(x log x)
