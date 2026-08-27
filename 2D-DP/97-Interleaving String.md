# 97. Interleaving String

## Pattern

2D Dynamic Programming

## Approach

1. Create a `dp` array where:

   dp[i][j] = true if the first i characters of s1 and first j characters of s2 can form the first i+j characters of s3

2. First check the lengths:

   if(s1.size() + s2.size() != s3.size())
       return false;

3. Initialize:

   dp[0][0] = true

   No characters taken from either string means we can form an empty prefix of `s3`.

4. Traverse all possible values of `i` and `j`.

5. At `(i, j)`, the character of `s3` we need to match is:

   s3[i + j - 1]

   because we have already used `i` characters from `s1` and `j` characters from `s2`.

6. If the current character from `s1` matches:

   s1[i - 1] == s3[i + j - 1]

   then we can come from the state where we used one fewer character from `s1`:

   dp[i][j] = dp[i][j] || dp[i - 1][j]

7. If the current character from `s2` matches:

   s2[j - 1] == s3[i + j - 1]

   then we can come from the state where we used one fewer character from `s2`:

   dp[i][j] = dp[i][j] || dp[i][j - 1]

8. Return:

   dp[m][n]

## Time Complexity

O(m × n)

- We check every possible combination of characters from `s1` and `s2`.

## Space Complexity

O(m × n)

- The 2D DP table stores a state for every `(i, j)` pair.

## Interview Note

- Think **"Can I form s3 by taking the next character from s1 OR s2?"**
- At every state `(i, j)`, there are only two possible choices:
  - Take the next character from `s1`
  - Take the next character from `s2`
- The important index is:

   s3[i + j - 1]

- If `s1` matches `s3` → come from TOP:

   dp[i - 1][j]

- If `s2` matches `s3` → come from LEFT:

   dp[i][j - 1]

- Key transition:

   dp[i][j] = dp[i][j] || dp[i-1][j]

   OR

   dp[i][j] = dp[i][j] || dp[i][j-1]

- The main idea is **2D DP where the two dimensions represent how many characters we have consumed from s1 and s2**.