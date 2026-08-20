# 213. House Robber II

## Pattern
1D Dynamic Programming + Circular Array

## Intuition

House Robber I works normally when houses are in a line.

Here, houses are arranged in a **circle**.

Therefore:

```text
House 0 ↔ House n-1
```

are also adjacent.

So we cannot rob both the first and last house.

---

## Key Trick

Break the circular problem into **2 linear problems**.

### Case 1 — Don't rob the first house

Consider:

```text
[1 ... n-1]
```

### Case 2 — Don't rob the last house

Consider:

```text
[0 ... n-2]
```

Then take the maximum:

```cpp
max(case1, case2)
```

---

## Why Two Cases?

Every valid solution must satisfy one of these:

```text
Can't rob both first and last
          ↓
 ┌────────┴────────┐
 ↓                 ↓
Skip first       Skip last
 ↓                 ↓
[1...n-1]         [0...n-2]
```

Now each case is just **House Robber I**.

---

## House Robber DP

For a linear range:

```text
At every house:

1. Skip it
   → previous maximum

2. Rob it
   → current money + maximum from 2 houses back
```

Therefore:

```cpp
curr = max(
    prev1,
    nums[i] + prev2
);
```

where:

```text
prev1 = best answer up to previous house
prev2 = best answer up to 2 houses before
```

---

## Code

```cpp
class Solution {
public:

    int robRange(vector<int>& nums, int start, int end) {

        int prev2 = 0;
        int prev1 = 0;

        for(int i = start; i <= end; i++) {

            int curr = max(
                prev1,
                nums[i] + prev2
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        // Don't rob first house
        int case1 = robRange(nums, 1, n-1);

        // Don't rob last house
        int case2 = robRange(nums, 0, n-2);

        return max(case1, case2);
    }
};
```

---

## Example

```text
nums = [2, 3, 2]
```

### Case 1: Skip first

```text
[3, 2]
```

Best:

```text
3
```

### Case 2: Skip last

```text
[2, 3]
```

Best:

```text
3
```

Answer:

```text
3
```

We cannot take:

```text
2 + 2
```

because the first and last houses are adjacent.

---

## Complexity

There are two passes over the array.

### Time

```text
O(n)
```

### Space

Using two variables:

```text
O(1)
```

---

## Pattern Recognition

```text
House Robber I
→ Linear houses
→ Normal 1D DP

House Robber II
→ Circular houses
→ Break into 2 linear ranges
→ Apply House Robber I
→ Take max
```

### Key Idea

> **Circular House Robber = max(rob houses `0...n-2`, rob houses `1...n-1`).**