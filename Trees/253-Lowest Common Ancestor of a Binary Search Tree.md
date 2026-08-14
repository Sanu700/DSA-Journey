# 236. Lowest Common Ancestor of a Binary Tree

## Pattern
Tree + DFS / Recursion

## Approach

1. If `root == nullptr`, return `nullptr`.
2. If `root` is `p` or `q`, return `root`.
3. Recursively search for `p` and `q` in:
   - Left subtree
   - Right subtree
4. If both `left` and `right` return a node:
   - `p` and `q` are in different subtrees.
   - Current `root` is the LCA.
5. If only `left` returns a node, return `left`.
6. If only `right` returns a node, return `right`.
7. If neither returns a node, return `nullptr`.

## Time Complexity
O(n)

## Space Complexity
O(h)

- `h` = height of the tree due to recursion stack.

## Interview Note
- `p` and `q` are already given — we need to find their lowest common ancestor.
- The key condition is:
  ```cpp
  if(left && right)
      return root;
  ```
- If both sides find something, the current node is where the paths to `p` and `q` meet.
- Common mistake: Checking `left` or `right` before checking `left && right`.
- Think:
  ```text
  Both sides found → current node is LCA
  Left only        → return left
  Right only       → return right
  Neither          → nullptr
  ```