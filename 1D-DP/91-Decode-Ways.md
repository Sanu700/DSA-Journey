# 91. Decode Ways

## Pattern

1D Dynamic Programming

## Intuition

At every position, we can decode either:

```text
1 digit
```

or:

```text
2 digits
```

But the choice must be valid.

For 1 digit:

```text
1 - 9
```

For 2 digits:

```text
10 - 26
```

Therefore, if the choices are valid:

```text
dp[i] = dp[i-1] + dp[i-2]
```

This is similar to the **Climbing Stairs** pattern, but here we have validity conditions.

---

## Base Cases

```text
dp[0] = 1
```

There is one way to decode an empty string, which helps build the DP.

For the first character:

```text
dp[1] = 1
```

if it is not `0`.

---

## Approach

Create:

```cpp
vector<int> dp(n + 1, 0);
```

Initialize:

```cpp
dp[0] = 1;
```

For every position:

### 1. Take one digit

If:

```cpp
s[i-1] != '0'
```

then:

```cpp
dp[i] += dp[i-1];
```

### 2. Take two digits

If the two digits form a number between `10` and `26`:

```cpp
if(s[i-2] == '1' ||
   (s[i-2] == '2' && s[i-1] <= '6'))
```

then:

```cpp
dp[i] += dp[i-2];
```

---

## Code

```cpp
class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {

            // Take 1 digit
            if(s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            // Take 2 digits
            if(i >= 2 &&
               (s[i-2] == '1' ||
               (s[i-2] == '2' && s[i-1] <= '6'))) {

                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};
```

---

## Example

For:

```text
s = "226"
```

Ways:

```text
2 2 6
22 6
2 26
```

Therefore:

```text
dp[1] = 1
dp[2] = 2
dp[3] = 3
```

Answer:

```text
3
```

---

## Space Optimized

We only need the previous two values.

```cpp
int prev2 = 1;
int prev1 = 0;

for(int i = 1; i <= n; i++) {

    int curr = 0;

    if(s[i-1] != '0') {
        curr += prev1;
    }

    if(i >= 2 &&
       (s[i-2] == '1' ||
       (s[i-2] == '2' && s[i-1] <= '6'))) {

        curr += prev2;
    }

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

Can take 1 digit → dp[i-1]

Can take 2 digits → dp[i-2]

     ↓

Add only valid choices

     ↓

1D DP
```

### Key Idea

> At every position, try decoding 1 digit or 2 digits. Add the number of ways from the previous state only when that decoding is valid.