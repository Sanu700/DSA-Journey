# 286. Walls and Gates / Islands and Treasure

## Pattern
Grid + Multi-Source BFS

## Approach

1. Traverse the entire grid.
2. Put **all treasure cells (`0`)** into the queue initially.
3. Start BFS from all treasures simultaneously.
4. For each cell, check its 4 neighbours:
   - Up
   - Down
   - Left
   - Right
5. Only process unvisited empty cells (`INT_MAX`).
6. Set the neighbour's distance:
   ```cpp
   grid[nr][nc] = grid[r][c] + 1;
   ```
7. Push the neighbour into the queue.
8. Continue until the queue is empty.

## Time Complexity
O(m × n)

- Every cell is visited at most once.

## Space Complexity
O(m × n)

- Queue can contain O(m × n) cells in the worst case.

## Interview Note
- This is a **Multi-Source BFS** problem.
- `0` → treasure / starting point.
- `-1` → wall / blocked cell.
- `INT_MAX` → empty land whose distance needs to be found.
- Put **all sources into the queue before starting BFS**.
- BFS guarantees that the first distance assigned to a cell is its shortest distance to the nearest treasure.

## Pattern Recognition
```text
Shortest distance
+
Grid
+
Multiple starting points
        ↓
Multi-Source BFS
```