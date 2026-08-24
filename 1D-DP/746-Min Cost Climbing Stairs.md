# 746. Min Cost Climbing Stairs

## Pattern
1D Dynamic Programming

## Approach
1. To reach step `i`, we can come from `i - 1` or `i - 2`.
2. Compute the minimum cost to reach each step:
   ```cpp
   dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
   ```
3. The answer is the minimum cost to reach the last or second-last step.
4. Use previous two states to reduce space to `O(1)`.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Interview Note
- This is similar to climbing stairs, but instead of counting ways, we minimize cost.
- The recurrence is based on the minimum accumulated cost to each step.
- Avoid greedily picking the cheaper immediate step; the DP state matters.
