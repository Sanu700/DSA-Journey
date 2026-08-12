# 543. Diameter of Binary Tree

## Pattern
Tree + DFS / Recursion

## Approach

1. Create a recursive `height()` function.
2. If `root == nullptr`, return `0`.
3. Recursively calculate:
   ```cpp
   left = height(root->left);
   right = height(root->right);
   ```
4. Diameter passing through the current node:
   ```cpp
   left + right
   ```
5. Update the global maximum:
   ```cpp
   ans = max(ans, left + right);
   ```
6. Return the height of the current node to its parent:
   ```cpp
   1 + max(left, right)
   ```

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- **Diameter through current node = `leftHeight + rightHeight`**
- **Height returned to parent = `1 + max(leftHeight, rightHeight)`**
- Important: Don't return `left + right`; return the height.
- Diameter is measured in **number of edges**.
- Common pattern: **Calculate something recursively, update global answer, then return a different value to the parent.**