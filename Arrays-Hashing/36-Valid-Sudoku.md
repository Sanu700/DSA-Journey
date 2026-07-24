# 36. Valid Sudoku

## Pattern
HashSet + Duplicate Checking

## Approach

1. Create three arrays of `unordered_set<char>`:
   - `rows[9]`
   - `cols[9]`
   - `boxes[9]`
2. Traverse each cell of the board.
3. Ignore empty cells (`'.'`).
4. Compute the box index using:
   ```cpp
   box = (row / 3) * 3 + (col / 3);
   ```
5. If the current number already exists in its corresponding row, column, or box, return `false`.
6. Otherwise, insert the number into all three sets.
7. If the entire board is traversed without duplicates, return `true`.

## Time Complexity
O(1)

- The board size is fixed (`9 × 9 = 81` cells), so the traversal always takes constant time.

## Space Complexity
O(1)

- At most 27 hash sets (`9` rows + `9` columns + `9` boxes), each storing up to `9` digits.

## Interview Note
- This problem is **not about solving Sudoku**—it's only about validating the current board.
- Think **"Duplicate Checking"**:
  - Row → `rows[i]`
  - Column → `cols[j]`
  - Box → `boxes[(i/3) * 3 + (j/3)]`
- A common mistake is forgetting the box index formula:
  ```cpp
  box = (row / 3) * 3 + (col / 3);
  ```
- Whenever a problem has **multiple uniqueness constraints**, think **one HashSet per constraint**.