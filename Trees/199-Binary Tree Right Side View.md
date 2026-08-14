# 199. Binary Tree Right Side View

## Pattern
Tree + BFS / Queue

## Approach

1. If `root == nullptr`, return an empty vector.
2. Use a queue for level-order traversal.
3. At the beginning of each level, store:
   ```cpp
   int size = q.size();
   ```
4. Process exactly `size` nodes.
5. The **last node processed in each level** is visible from the right side:
   ```cpp
   if(i == size - 1)
       ans.push_back(node->val);
   ```
6. Push the left and right children into the queue.
7. Return the answer.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Interview Note
- Think **"Level Order BFS + last node of every level."**
- The right subtree does not necessarily determine the answer.
- Visibility is determined **level by level**, not by subtree height.
- Common mistake: Using `q.size()` directly in the `for` loop while adding children. Store it first:
  ```cpp
  int size = q.size();
  ```