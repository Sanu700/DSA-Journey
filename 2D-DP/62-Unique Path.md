# 62. Unique Paths

## Pattern

2D Dynamic Programming → 1D Space Optimized DP

## Approach

1. Create a `dp` array where:

   dp[c] = number of ways to reach column c in the current row.

2. In the normal 2D DP solution, to reach cell `(r, c)`, we can only come from:

   - Top → `dp[r-1][c]`
   - Left → `dp[r][c-1]`

3. Therefore:

   dp[r][c] = dp[r-1][c] + dp[r][c-1]

4. Since each cell only depends on the top and left cells, we can optimize the 2D DP into a 1D array.

5. Initialize the first row with `1` because there is only one way to reach every cell in the first row.

6. Traverse the remaining rows and update from left to right:

   dp[c] = dp[c] + dp[c-1]

7. Here:

   dp[c] → old value = TOP

   dp[c-1] → already updated value = LEFT

8. Return `dp[n-1]`.

## Time Complexity

O(m × n)

- We visit every cell once.

## Space Complexity

O(n)

- We use a 1D DP array instead of an O(m × n) 2D array.

## Interview Note

- Think **"To reach a cell, I can only come from the top or the left."**
- Normal 2D transition:

   dp[r][c] = dp[r-1][c] + dp[r][c-1]

- After space optimization:

   dp[c] = dp[c] + dp[c-1]

- The important trick is traversing left to right.
- `dp[c]` represents the top value before updating, while `dp[c-1]` represents the already updated left value.
- This is a common pattern for converting **2D DP → 1D DP** when the current state only depends on the previous row and previous column.