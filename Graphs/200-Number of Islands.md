# 200. Number of Islands

## Pattern
Grid + DFS / Connected Components

## Approach

1. Traverse every cell in the grid.
2. When an unvisited land cell (`'1'`) is found:
   - Increment the island count.
   - Start DFS from that cell.
3. In DFS:
   - Stop if the cell is outside the grid.
   - Stop if the cell is water (`'0'`).
   - Mark the current land cell as visited by changing it to `'0'`.
   - Recursively visit all 4 directions:
     ```text
     Up
     Down
     Left
     Right
     ```
4. Continue scanning the grid.
5. Return the total number of islands.

## Time Complexity
O(m × n)

- Every cell is visited at most once.

## Space Complexity
O(m × n)

- Worst case recursion stack for one large connected island.

## Interview Note
- Think **"Connected Components in a Grid."**
- Every time you find an unvisited `'1'`, you've found a **new island**.
- You don't need a separate `visited` matrix:
  ```cpp
  grid[r][c] = '0';
  ```
  can mark cells as visited.
- Common mistake: Counting every `'1'` as an island instead of counting each connected component once.