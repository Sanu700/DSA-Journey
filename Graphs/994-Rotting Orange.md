# 994. Rotting Oranges

## Pattern
Grid + Multi-Source BFS + Level/Time Tracking

## Approach

1. Traverse the entire grid.
2. Put all initially rotten oranges (`2`) into the queue.
3. Count the number of fresh oranges (`1`).
4. Start multi-source BFS.
5. Process the queue **level by level**:
   - One BFS level represents **1 minute**.
6. For every rotten orange, check its 4 neighbours.
7. If a neighbour is fresh:
   - Make it rotten:
     ```cpp
     grid[nr][nc] = 2;
     ```
   - Decrease the fresh count:
     ```cpp
     fresh--;
     ```
   - Add it to the queue.
8. After processing one complete level, increment `time`.
9. At the end:
   - If `fresh == 0`, return `time`.
   - Otherwise, return `-1`.

## Time Complexity
O(m × n)

- Every cell is processed at most once.

## Space Complexity
O(m × n)

- Queue can contain O(m × n) cells.

## Interview Note
- This is **Multi-Source BFS** because all initially rotten oranges are starting points.
- The key trick:
  ```text
  One BFS level = One minute
  ```
- Keep track of `fresh` oranges to detect whether all oranges can eventually rot.
- If fresh oranges remain after BFS, they are unreachable:
  ```cpp
  return -1;
  ```

## Pattern Recognition

```text
Multiple starting points
        +
Grid
        +
Shortest time / distance
        ↓
Multi-Source BFS
```

- **Islands & Treasure** → BFS levels represent distance.
- **Rotting Oranges** → BFS levels represent time.