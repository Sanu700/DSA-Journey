# 105. Construct Binary Tree from Preorder and Inorder Traversal

## Pattern
Tree + DFS / Recursion + HashMap

## Approach

1. Preorder traversal is:
   ```text
   Root → Left → Right
   ```
   So the next element in preorder is always the root.

2. Inorder traversal is:
   ```text
   Left → Root → Right
   ```
   Find the root's position in inorder to split the tree.

3. Store each inorder value and its index in a HashMap for O(1) lookup.

4. Create the root using the current `preIndex` and increment it.

5. Recursively build:
   - Left subtree → `left` to `mid - 1`
   - Right subtree → `mid + 1` to `right`

6. Return the constructed root.

## Time Complexity
O(n)

## Space Complexity
O(n)

- HashMap: O(n)
- Recursion stack: O(h)

## Interview Note
- **Preorder tells WHAT the root is.**
- **Inorder tells WHERE to split.**
- Important:
  ```text
  Preorder → Root → Left → Right
  Inorder  → Left → Root → Right
  ```
- Build the **left subtree before the right subtree** because preorder visits left before right.
- Common mistake: Searching for the root in inorder every time, which makes the solution O(n²). Use a HashMap for O(1) lookup.