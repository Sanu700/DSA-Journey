# 130. Surrounded Regions

## Pattern
Grid + DFS + Boundary Traversal

## Approach

1. An `O` can be surrounded only if it **cannot reach the boundary**.
2. Instead of searching for surrounded regions directly:
   - Find all `O`s connected to the boundary.
3. Traverse all four boundaries:
   - Top row
   - Bottom row
   - Left column
   - Right column
4. Whenever a boundary `O` is found, run DFS and mark all connected `O`s as `#`.
   - `#` means the cell is **safe** and must not be converted.
5. Traverse the entire board:
   - Remaining `O` → `X` because it is surrounded.
   - `#` → `O` because it is boundary-connected.

## Time Complexity
O(m × n)

- Every cell is visited at most a constant number of times.

## Space Complexity
O(m × n)

- DFS recursion stack can be O(m × n) in the worst case.

## Interview Note

The key idea is:

```text
Don't find what is surrounded.
Find what is NOT surrounded.
```

### Flow

```text
Boundary O
    ↓
DFS connected O's
    ↓
Mark as #

Remaining O → X
# → O
```

### Important

The board contains capital letter **`O`**, not zero:

```cpp
'O'   // correct
'0'   // wrong
```

Also remember:

```cpp
=    // assignment
==   // comparison
```