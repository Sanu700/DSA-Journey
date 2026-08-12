# 100. Same Tree

## Pattern
Tree + DFS / Recursion

## Approach

1. If both nodes are `nullptr`, return `true`.
2. If only one node is `nullptr`, return `false`.
3. If their values are different, return `false`.
4. Recursively compare:
   - Left subtree of both trees.
   - Right subtree of both trees.
5. Return `true` only if both subtrees are the same.

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- Compare **both value and structure**.
- Traverse both trees simultaneously.
- Think:
  ```text
  Both null → Same
  One null → Different
  Values different → Different
  Otherwise → Check left + right
  ```
- Common mistake: Only comparing node values and ignoring the tree structure.
```