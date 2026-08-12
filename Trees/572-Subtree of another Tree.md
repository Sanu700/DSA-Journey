# 572. Subtree of Another Tree

## Pattern
Tree + DFS + Recursion

## Approach

1. If `subRoot == nullptr`, return `true`.
2. If `root == nullptr`, return `false`.
3. At every node of `root`, check whether the subtree starting there is the same as `subRoot`.
4. Use the `isSameTree()` helper to compare both trees.
5. If they are the same, return `true`.
6. Otherwise, recursively search:
   - Left subtree
   - Right subtree
7. Return `true` if either subtree contains `subRoot`.

## Time Complexity
O(n × m)

- `n` = nodes in `root`
- `m` = nodes in `subRoot`

## Space Complexity
O(h)

- `h` = height of the tree due to recursion.

## Interview Note
- Think **"DFS through the main tree + Same Tree check at every node."**
- `isSameTree()` from LC 100 can be reused directly.
- Common mistake: Checking `isSameTree()` only once at the root.
- Pattern:
  ```text
  DFS(root)
      ↓
  Same Tree(root, subRoot)?
      ↓
  YES → true
  NO  → search left/right
  ```