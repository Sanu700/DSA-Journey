# 207. Course Schedule

## Pattern
Directed Graph + Cycle Detection

## Approach
1. Build an adjacency list for each course dependency.
2. Run DFS on every node with three states:
   - unvisited
   - visiting
   - visited
3. If we see a node already in the current recursion stack, a cycle exists.
4. If any cycle is found, return `false`; otherwise return `true`.

## Time Complexity
O(V + E)

## Space Complexity
O(V + E)

## Interview Note
- Course scheduling is just a directed graph cycle check.
- A cycle means the prerequisites cannot be completed in order.
- Use a recursion stack or topological sort to detect that cycle.
