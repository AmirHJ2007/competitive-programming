# Xor-tree

We are given a tree with initial values and desired values.

Operation on node x flips values of nodes at even distance from x.

## Key Idea

Traverse the tree using DFS.

Keep track of flip operations affecting nodes at even and odd depths.

When visiting a node, determine its current value after applying
previous flips.

If it differs from the target value, perform an operation on that node.

## Complexity

O(n)
