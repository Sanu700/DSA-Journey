# 312. Burst Balloons

## Pattern

Interval Dynamic Programming

## Approach

1. Add `1` to both ends of the array.

   This gives us fixed boundary balloons:

   [1, nums..., 1]

2. Create a 2D `dp` array where:

   dp[l][r] = maximum coins obtainable by bursting all balloons from l to r

3. The important trick is to think about the balloon that is burst LAST.

   Instead of asking:

   "Which balloon should I burst first?"

   ask:

   "Which balloon should I burst last?"

4. Suppose `k` is the last balloon burst in interval `[l, r]`.

   By then, every balloon between `l` and `r` has already disappeared.

   Therefore, the neighbors of `k` are fixed:

   a[l-1] and a[r+1]

5. Coins gained from bursting `k` last:

   a[l-1] * a[k] * a[r+1]

6. Everything before bursting `k` splits into two independent intervals:

   Left:

   dp[l][k-1]

   Right:

   dp[k+1][r]

7. Therefore:

   dp[l][r] = max(
       dp[l][r],
       dp[l][k-1] + dp[k+1][r]
       + a[l-1] * a[k] * a[r+1]
   )

8. We process smaller intervals first so that the required left and right DP states are already calculated.

9. Return:

   dp[1][n]

## Time Complexity

O(n³)

- There are O(n²) intervals.
- For every interval, we try every possible last balloon `k`.

## Space Complexity

O(n²)

- The 2D DP table stores the answer for every interval.

## Interview Note

- Think **"Which balloon should be burst LAST?"**
- Choosing the last balloon makes its neighbors fixed.
- The interval then splits into:

   LEFT INTERVAL + LAST BALLOON + RIGHT INTERVAL

- Key transition:

   dp[l][r] = max(
       dp[l][k-1]
       + dp[k+1][r]
       + a[l-1] * a[k] * a[r+1]
   )

- Add virtual `1`s at both ends to handle boundary balloons easily.
- This is **Interval DP**, not sliding window.
- General interval DP pattern:

   choose a `k` inside `[l,r]`

   ↓

   solve left interval

   +

   solve right interval

   +

   cost of choosing `k`

- The biggest trick is changing the perspective from **FIRST** to **LAST**.