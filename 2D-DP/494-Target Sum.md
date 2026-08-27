# 494. Target Sum

## Pattern

1D Dynamic Programming + 0/1 Knapsack

## Approach

1. We need to assign either `+` or `-` to every number.

   Let:

   P = sum of numbers assigned `+`

   N = sum of numbers assigned `-`

2. We know:

   P - N = target

   P + N = sum

3. Adding the equations:

   2P = sum + target

   Therefore:

   P = (sum + target) / 2

4. So the problem becomes:

   **"How many subsets have a sum equal to `(sum + target) / 2`?"**

5. If:

   abs(target) > sum

   then it is impossible to reach the target.

6. If:

   (sum + target) % 2 != 0

   then the required subset sum is not an integer, so return `0`.

7. Create a `dp` array where:

   dp[j] = number of subsets that can make sum j

8. Initialize:

   dp[0] = 1

   There is one way to make sum `0`: choose nothing.

9. Traverse every number and update the DP array backwards because every number can be used only once:

   dp[j] += dp[j - num]

10. Return:

   dp[subsetSum]

## Time Complexity

O(n × target)

- `n` is the number of elements.
- We process every possible subset sum up to `subsetSum`.

## Space Complexity

O(target)

- We use a 1D DP array.

## Interview Note

- Think **"Convert + and - into a subset sum problem."**
- The key mathematical transformation is:

   P - N = target

   P + N = sum

   Therefore:

   P = (sum + target) / 2

- Then it becomes a **0/1 Knapsack counting problem**.
- Since every number can be used only once, iterate the sum **backwards**:

   for(int j = subsetSum; j >= num; j--)

- Key transition:

   dp[j] += dp[j - num]

- Important checks:

   abs(target) > sum → impossible

   (sum + target) % 2 != 0 → impossible

- The main trick is recognizing that **Target Sum → Count Subsets with Given Sum**.