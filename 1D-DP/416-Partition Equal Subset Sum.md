# 416. Partition Equal Subset Sum

## Pattern

1D Dynamic Programming + 0/1 Knapsack

## Approach

1. Calculate the total sum of all elements.

2. If the total sum is odd, it cannot be divided into two equal subsets.

   sum % 2 != 0 → false

3. If the sum is even, each subset must have:

   target = sum / 2

4. Create a DP array where:

   dp[j] = true if we can form sum j using the elements seen so far

5. Initialize:

   dp[0] = true

   We can always form sum 0 by choosing nothing.

6. For every number, update the DP array backwards:

   dp[j] = dp[j] || dp[j - num]

7. Traverse backwards so that each number is used at most once.

8. Return:

   dp[target]

## Time Complexity

O(n × target)

- For every number, we check every possible sum up to target.

## Space Complexity

O(target)

- The 1D DP array stores whether each sum can be formed.

## Interview Note

- Think: "Can I select some numbers whose sum is exactly half of the total?"
- This converts the problem into a **0/1 Knapsack** problem.
- Each number can be used only once.
- The most important trick is iterating backwards:

   for(int j = target; j >= num; j--)

- Forward iteration could use the same number multiple times.
- Key transition:

   dp[j] = dp[j] || dp[j - num];

- If `sum` is odd, immediately return `false`.