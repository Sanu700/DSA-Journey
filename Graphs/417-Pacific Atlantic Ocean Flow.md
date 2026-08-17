# 417. Pacific Atlantic Water Flow

## Pattern
Grid + Reverse DFS + Two Visited Grids

## Approach

1. Water normally flows from a **higher/equal height to a lower/equal height**.
2. Instead of starting DFS from every cell and checking whether it can reach an ocean, reverse the process.
3. Start DFS from the ocean boundaries and find all cells that can reach each ocean.

### Pacific Ocean

Start DFS from:
- Top row
- Left column

Store reachable cells in:
```cpp
pacific[r][c] = true;
```

### Atlantic Ocean

Start DFS from:
- Bottom row
- Right column

Store reachable cells in:
```cpp
atlantic[r][c] = true;
```

4. During reverse DFS, move to a neighbour only if:
   ```cpp
   heights[nr][nc] >= heights[r][c]
   ```
   because water could originally flow from that higher neighbour to the current cell.

5. Finally, if a cell is reachable from **both oceans**, add it to the answer:
   ```cpp
   if(pacific[r][c] && atlantic[r][c])
       ans.push_back({r,c});
   ```

## Time Complexity
O(m × n)

- Each cell is visited at most once for each ocean.

## Space Complexity
O(m × n)

- Two visited grids.
- Recursion stack can also be O(m × n) in the worst case.

## Interview Note
- The main trick is **reverse the direction of traversal**.
- Instead of asking:
  ```text
  Can this cell reach the ocean?
  ```
  ask:
  ```text
  Can the ocean reach this cell in reverse?
  ```
- Normal flow:
  ```text
  High → Low
  ```
- Reverse DFS:
  ```text
  Low → High
  ```
- Remember:
  ```text
  Pacific  → Top + Left
  Atlantic → Bottom + Right
  ```
- Answer = **intersection of cells reachable from both oceans**.