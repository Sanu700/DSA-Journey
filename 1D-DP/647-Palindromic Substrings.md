# 647. Palindromic Substrings

## Pattern
1D Dynamic Programming

## Approach
1. Use a DP array where `dp[r]` represents whether the current substring ending at `r` is a palindrome.
2. For each left index `l`, check if `s[l] == s[r]` and the inner substring is already valid.
3. The transition is:
   ```cpp
   s[l] == s[r] && (r - l <= 2 || prev)
   ```
4. If valid, increment the palindrome count.
5. Continue until all substrings are checked.

## Time Complexity
O(n²)

## Space Complexity
O(n)

## Interview Note
- This is the counting version of the palindrome DP pattern.
- The state is still “is this substring a palindrome?”
- The key optimization is using the previous diagonal value instead of a full 2D table.
