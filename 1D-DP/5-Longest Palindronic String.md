# 5. Longest Palindromic Substring

## Pattern
2D DP + Space Optimization

## Approach
1. Let `dp[l][r]` mean whether `s[l..r]` is a palindrome.
2. A substring is a palindrome if:
   ```cpp
   s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])
   ```
3. Compress the table to one dimension to reduce space.
4. Iterate `l` from right to left and `r` from left to right.
5. Keep track of the previous diagonal value using `prev` to restore the needed state.
6. Update the best palindrome length and start index.

## Time Complexity
O(n²)

## Space Complexity
O(n)

## Interview Note
- The important part is preserving the `dp[l + 1][r - 1]` state while compressing to 1D.
- The reverse iteration over `l` is what makes the optimization work.
- This is a classic palindrome DP pattern with a 1D compression trick.
