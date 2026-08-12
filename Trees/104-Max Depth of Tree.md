# 104. Maximum Depth of Binary Tree

## Pattern
Tree + DFS / Recursion

## Approach

1. If `root == nullptr`, return `0`.
2. Recursively find the depth of the left subtree.
3. Recursively find the depth of the right subtree.
4. Current depth is:
   ```cpp
   1 + max(leftDepth, rightDepth)
   ```
5. Return the result.

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- Think **"1 + maximum depth of left and right subtree."**
- Base case: `nullptr → 0`.
- Can also be solved using BFS, where each level increases the depth by `1`.
- DFS is more concise for this problem.