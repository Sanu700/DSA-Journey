# 110. Balanced Binary Tree

## Pattern
Tree + DFS / Recursion

## Approach

1. Create a `height()` helper function.
2. If `root == nullptr`, return `0`.
3. Recursively calculate:
   ```cpp
   left = height(root->left);
   right = height(root->right);
   ```
4. If either subtree is already unbalanced (`-1`), return `-1`.
5. Check the current node:
   ```cpp
   if(abs(left - right) > 1)
       return -1;
   ```
6. If balanced, return its height:
   ```cpp
   return 1 + max(left, right);
   ```
7. In `isBalanced()`, check:
   ```cpp
   return height(root) != -1;
   ```

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- A tree is balanced if **at every node**:
  ```text
  |leftHeight - rightHeight| <= 1
  ```
- Use `-1` to indicate that a subtree is already unbalanced.
- This avoids repeatedly calculating heights and gives O(n) time.
- Common mistake:
  ```cpp
  abs(left - right) < 1
  ```
  is wrong. The tree is unbalanced when:
  ```cpp
  abs(left - right) > 1
  ```