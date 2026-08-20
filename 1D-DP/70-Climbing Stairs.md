# 70. Climbing Stairs

## Pattern
1D Dynamic Programming

## Intuition

At every step, you can climb either:

```text
1 step
```

or

```text
2 steps
```

To reach step `n`, you must have come from:

```text
n - 1
```

or

```text
n - 2
```

Therefore:

```text
dp[n] = dp[n-1] + dp[n-2]
```

This is essentially the Fibonacci pattern.

---

## Base Cases

```text
dp[1] = 1
```

There is only one way:

```text
1
```

For 2 steps:

```text
dp[2] = 2
```

Ways:

```text
1 + 1
2
```

---

## Approach

Create:

```cpp
vector<int> dp(n + 1);
```

Initialize:

```cpp
dp[1] = 1;
dp[2] = 2;
```

Then:

```cpp
for(int i = 3; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
}
```

Return:

```cpp
dp[n]
```

---

## Example

For `n = 5`:

```text
dp[1] = 1
dp[2] = 2
dp[3] = 3
dp[4] = 5
dp[5] = 8
```

Answer:

```text
8
```

---

## Space Optimized

We only need the previous two values.

```cpp
int prev2 = 1;
int prev1 = 2;

for(int i = 3; i <= n; i++) {

    int curr = prev1 + prev2;

    prev2 = prev1;
    prev1 = curr;
}

return prev1;
```

### Complexity

**Time:**

```text
O(n)
```

**Space:**

```text
O(1)
```

---

## Pattern Recognition

```text
Current state
     ↓
depends on previous 2 states
     ↓
dp[i] = dp[i-1] + dp[i-2]
     ↓
1D DP
```

### Key Idea

> To reach step `i`, the last move must have come from either `i-1` or `i-2`.