# 230. Kth Smallest Element in a BST

## Pattern
BST + Inorder DFS

## Approach

1. Perform an **inorder traversal** of the BST.
2. Inorder traversal gives nodes in sorted order:
   ```text
   Left → Root → Right
   ```
3. Decrease `k` whenever a node is visited.
4. When `k == 0`, the current node is the kth smallest element.
5. Return the stored answer.

## Time Complexity
O(h + k)

- `h` = height of the tree.
- We stop once the kth node is found.

## Space Complexity
O(h)

- Recursion stack.

## Interview Note
- **BST + kth smallest → Inorder traversal.**
- Inorder traversal of a BST gives values in ascending order.
- For kth largest, use **reverse inorder**:
  ```text
  Right → Root → Left
  ```
- No need to store the entire tree in an array or sort it.