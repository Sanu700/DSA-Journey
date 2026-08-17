# 695. Max Area of Island

## Pattern
Grid + DFS + Connected Components

## Approach

1. Traverse every cell in the grid.
2. When an unvisited land cell (`1`) is found, start DFS.
3. In DFS:
   - Stop if the cell is outside the grid or is water (`0`).
   - Mark the current cell as visited by changing it to `0`.
   - Return:
     ```cpp
     1 + area of all 4 connected directions
     ```
4. Store the returned area:
   ```cpp
   int area = dfs(grid, i, j);
   ```
5. Update the maximum:
   ```cpp
   maxArea = max(maxArea, area);
   ```
6. Return `maxArea`.

## Time Complexity
O(m × n)

- Every cell is visited at most once.

## Space Complexity
O(m × n)

- Worst-case recursion stack when the entire grid is one connected island.

## Interview Note
- Same pattern as **Number of Islands**, but the DFS returns the size of the connected component.
- Think:
  ```text
  Number of Islands → DFS + count components

  Max Area of Island → DFS + return component size
  ```
- Mark visited cells:
  ```cpp
  grid[r][c] = 0;
  ```
- Common C++ mistake:
  ```cpp
  grid[r][c] == 0;  // comparison ❌
  grid[r][c] = 0;   // assignment ✅
  ```