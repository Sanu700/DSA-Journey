# 198. House Robber

## Pattern
1D Dynamic Programming

## Approach
1. Let `dp[i]` be the maximum money that can be robbed from the first `i` houses.
2. For each house, choose one of two actions:
   - Skip the current house: `dp[i - 1]`
   - Rob the current house: `nums[i - 1] + dp[i - 2]`
3. Take the better option:
   ```cpp
   dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
   ```
4. Use only the previous two states to optimize space.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Interview Note
- The main idea is to model the decision at each house as **skip or rob**.
- The adjacent-house restriction is what creates the DP recurrence.
- A common mistake is forgetting the `i - 2` state when deciding to rob the current house.
