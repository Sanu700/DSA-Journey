# 322. Coin Change

## Pattern

1D Dynamic Programming + Unbounded Knapsack

## Approach

1. Create a `dp` array where:

   ```cpp
   dp[i] = minimum number of coins needed to make amount i
   ```

2. Initialize all values to a large number because initially we assume the amount is impossible.

3. Set:

   ```cpp
   dp[0] = 0;
   ```

   Zero coins are needed to make amount `0`.

4. Traverse every amount from `1` to `amount`.

5. For each amount, try every coin.

6. If the coin can be used:

   ```cpp
   dp[i] = min(dp[i], dp[i - coin] + 1);
   ```

7. If `dp[amount]` is still impossible, return `-1`. Otherwise, return `dp[amount]`.

## Time Complexity

O(amount × n)

- `n` is the number of coins.
- For every amount, we try every coin.

## Space Complexity

O(amount)

- The DP array stores the minimum number of coins for every amount from `0` to `amount`.

## Interview Note

- Think: **"If I take this coin, what is the best answer for the remaining amount?"**
- This is an **unbounded knapsack** problem because each coin can be used unlimited times.
- The key transition is:

  ```cpp
  dp[i] = min(dp[i], dp[i - coin] + 1);
  ```

- `dp[0] = 0` is the important base case.