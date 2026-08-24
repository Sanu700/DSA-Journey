# 213. House Robber II

## Pattern
1D Dynamic Programming + Circular Array

## Approach
1. A circular arrangement means the first and last house are adjacent.
2. Break the problem into two linear cases:
   - Skip the first house: `robRange(nums, 1, n - 1)`
   - Skip the last house: `robRange(nums, 0, n - 2)`
3. Run the standard House Robber DP on each range.
4. Return the maximum of the two results.

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Note
- The circular constraint is the key trick here.
- Always reduce the circular problem to two linear cases.
- If the first and last house are adjacent, they cannot both be robbed.
