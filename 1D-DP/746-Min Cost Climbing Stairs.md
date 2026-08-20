# 746. Min Cost Climbing Stairs

## Pattern
1D Dynamic Programming

## Intuition

To reach step `i`, we can come from either:

```text
i - 1
```

or

```text
i - 2
```

We want the **minimum total cost**.

Therefore:

```cpp
dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
```

---

## Important Difference from Climbing Stairs

In **Climbing Stairs**, we were counting the number of ways:

```cpp
dp[i] = dp[i-1] + dp[i-2];
```

Here we're finding the **minimum cost**:

```cpp
dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
```

So the base cases are also different.

---

## Base Cases

```cpp
dp[0] = cost[0];
dp[1] = cost[1];
```

Meaning:

```text
dp[0] = minimum cost to reach stair 0
dp[1] = minimum cost to reach stair 1
```

---

## Example

```text
cost = [10, 15, 20]
```

Initialize:

```text
dp[0] = 10
dp[1] = 15
```

Then:

```text
dp[2] = 20 + min(10,15)
      = 30
```

But the goal is to reach the **top**, which is beyond the last stair.

We can reach the top from either:

```text
last stair
```

or

```text
second-last stair
```

Therefore:

```cpp
answer = min(dp[n-1], dp[n-2]);
```

For this example:

```text
min(30,15) = 15
```

---

## Code

```cpp
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++) {

            dp[i] = cost[i] +
                    min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};
```

---

## Space Optimized

We only need the previous two states:

```cpp
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2; i < n; i++) {

            int curr = cost[i] + min(prev1, prev2);

            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
```

## Complexity

### Time

```text
O(n)
```

### Space

DP array:

```text
O(n)
```

Space optimized:

```text
O(1)
```

---

## Pattern Recognition

```text
Current state
     ↓
Can come from previous 1 or 2 states
     ↓
Choose minimum cost
     ↓
dp[i] = cost[i] + min(dp[i-1], dp[i-2])
```

### Key Idea

> **Don't greedily choose the cheaper immediate step. Store the minimum cost accumulated to reach each step.**