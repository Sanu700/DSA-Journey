# 98. Validate Binary Search Tree

## Pattern
Tree + DFS + Valid Range

## Approach

1. Use DFS and maintain a valid range `(minVal, maxVal)` for every node.
2. If `root == nullptr`, return `true`.
3. Check if the current value is outside its valid range:
   ```cpp
   if(root->val <= minVal || root->val >= maxVal)
       return false;
   ```
4. For the left subtree:
   ```cpp
   dfs(root->left, minVal, root->val)
   ```
   - Every value must be smaller than the current node.
5. For the right subtree:
   ```cpp
   dfs(root->right, root->val, maxVal)
   ```
   - Every value must be greater than the current node.
6. If all nodes satisfy their ranges, return `true`.

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- Don't only compare a node with its immediate parent.
- Every node must satisfy constraints from **all its ancestors**.
- Think:
  ```text
  Root → (-∞, +∞)

  Left  → (minVal, root->val)
  Right → (root->val, maxVal)
  ```
- Use `long` for the range to safely handle `INT_MIN` and `INT_MAX`.