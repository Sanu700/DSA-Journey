# 133. Clone Graph

## Pattern
Graph + DFS + HashMap

## Approach

1. Use a HashMap to store:
   ```text
   original node → cloned node
   ```
2. If `node == nullptr`, return `nullptr`.
3. If the node is already present in the map, return its existing clone.
4. Create a new clone:
   ```cpp
   Node* clone = new Node(node->val);
   ```
5. **Store the clone in the map before visiting neighbors.**
6. Traverse all neighbors using DFS and add their clones to the current clone's neighbor list.
7. Return the cloned node.

## Time Complexity
O(V + E)

- `V` = number of vertices.
- `E` = number of edges.

## Space Complexity
O(V)

- HashMap stores every cloned node.
- DFS recursion can also use O(V) space.

## Interview Note
- The HashMap has **two purposes**:
  1. Prevent infinite recursion in cyclic graphs.
  2. Ensure each original node gets exactly **one clone**.
- Important order:
  ```text
  Create clone
      ↓
  Store in map
      ↓
  Clone neighbors
  ```
- Common mistake: Adding the clone to the map **after** processing neighbors. This can cause infinite recursion for cycles.
- Think:
  ```text
  Graph DFS
      +
  original → clone map
  ```