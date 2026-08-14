# 102. Binary Tree Level Order Traversal

## Pattern
Tree + BFS / Queue

## Approach

1. If `root == nullptr`, return an empty vector.
2. Create a queue and push the root.
3. While the queue is not empty:
   - Store the current queue size:
     ```cpp
     int size = q.size();
     ```
   - Create a vector for the current level.
   - Process exactly `size` nodes.
   - Add each node's value to the current level.
   - Push its left and right children into the queue.
4. Add the current level to the answer.
5. Return the result.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Interview Note
- Whenever you see **"level order"**, think **BFS + Queue**.
- The key trick is:
  ```cpp
  int size = q.size();
  while(size--) {
      // process one level
  }
  ```
- `size` ensures that only nodes belonging to the current level are processed.
- Common mistake: Forgetting to create a separate `vector<int> level` for every level.