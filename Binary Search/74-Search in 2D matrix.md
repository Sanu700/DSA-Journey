# 74. Search a 2D Matrix

## Pattern

Binary Search

## Approach

1. Treat the entire matrix as a **sorted 1D array**.
2. Set:
   ```cpp
   left = 0;
   right = m * n - 1;
   ```
3. Calculate `mid`.
4. Convert `mid` into matrix coordinates:
   ```cpp
   row = mid / n;
   col = mid % n;
   ```
5. Compare `matrix[row][col]` with `target` and perform normal binary search.

## Key Observation

- Every row is sorted.
- The first element of each row is greater than the last element of the previous row.
- Therefore, the entire matrix behaves like one sorted array.
- `mid / n` gives the row and `mid % n` gives the column.

## Time Complexity

- **O(log(m × n))**

## Space Complexity

- **O(1)**

## Interview Note

Remember the conversion:

```cpp
row = mid / n;
col = mid % n;
```

Think:

```text
2D Matrix → Flatten mentally → Normal Binary Search
```
```