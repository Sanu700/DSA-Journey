# 226. Invert Binary Tree

## Pattern
Tree + DFS / Recursion

## Approach

1. If the current node is `nullptr`, return `nullptr`.
2. Recursively invert the left subtree.
3. Recursively invert the right subtree.
4. Swap the left and right children.
5. Return the current node.

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- Think **"invert every node by swapping its children."**
- The same logic works with DFS or BFS.
- Common mistake: Forgetting to return the current node after swapping.
- For a balanced tree, recursion space is O(log n); for a skewed tree, O(n).