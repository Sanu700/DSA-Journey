# 198. House Robber

## Pattern
1D Dynamic Programming

## Intuition

At every house, we have **2 choices**:

```text
1. Don't rob the current house
2. Rob the current house
```

If we rob the current house, we **cannot rob the previous house**.

Therefore:

```text
Don't rob → dp[i-1]

Rob → nums[i-1] + dp[i-2]
```

Take the maximum:

```cpp
dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
```

---

## DP Definition

Let:

```text
dp[i] = maximum money that can be robbed from the first i houses
```

Therefore:

```text
dp[0] = 0
```

No houses → no money.

For the first house:

```text
dp[1] = nums[0]
```

For the first two houses:

```text
dp[2] = max(nums[0], nums[1])
```

We cannot rob both because they are adjacent.

---

## Example

```text
nums = [2, 7, 9, 3, 1]
```

Build DP:

```text
dp[0] = 0
dp[1] = 2
dp[2] = max(2,7) = 7

dp[3] = max(
    dp[2],          // don't rob 9
    9 + dp[1]       // rob 9
)
= max(7,11)
= 11

dp[4] = max(
    11,
    3 + 7
)
= 11

dp[5] = max(
    11,
    1 + 11
)
= 12
```

Answer:

```text
12
```

Rob:

```text
2 + 9 + 1 = 12
```

---

## Code

```cpp
class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for(int i = 3; i <= n; i++) {

            dp[i] = max(
                dp[i-1],            // don't rob current
                nums[i-1] + dp[i-2] // rob current
            );
        }

        return dp[n];
    }
};
```

---

## Space Optimized

Only the previous two states are required.

```cpp
class Solution {
public:

    int rob(vector<int>& nums) {

        int prev2 = 0;
        int prev1 = 0;

        for(int money : nums) {

            int curr = max(
                prev1,
                money + prev2
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
```

---

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
Current house
      ↓
   ┌──┴──┐
   ↓     ↓
 Skip   Rob
   ↓     ↓
dp[i-1] nums[i-1] + dp[i-2]
   └──┬──┘
      ↓
     max
```

### Key Formula

```cpp
dp[i] = max(
    dp[i-1],
    nums[i-1] + dp[i-2]
);
```

### Key Idea

> **If you rob the current house, you must skip the previous one. Otherwise, skip the current house and keep the previous maximum.**