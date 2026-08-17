# 124. Binary Tree Maximum Path Sum

## Pattern
Tree + DFS / Recursion + Global Maximum

## Approach

1. Use DFS to calculate the maximum path contribution from each subtree.
2. If `root == nullptr`, return `0`.
3. Recursively calculate the left and right contributions.
4. Ignore negative contributions:
   ```cpp
   left = max(0, left);
   right = max(0, right);
   ```
5. A path passing through the current node can use **both sides**:
   ```cpp
   ans = max(ans, root->val + left + right);
   ```
6. When returning to the parent, we can only take **one side**:
   ```cpp
   return root->val + max(left, right);
   ```
7. Call `dfs(root)` and return the global `ans`.

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- **Update answer:** `left + root + right`
- **Return to parent:** `root + max(left, right)`
- We cannot return both left and right to the parent because that would create a branching path.
- Ignore negative subtree contributions using:
  ```cpp
  max(0, contribution)
  ```
- Very similar to **Diameter of Binary Tree**, but instead of heights, we use path sums.
- Common mistake: Forgetting to call `dfs(root)` before returning `ans`.