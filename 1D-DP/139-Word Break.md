# 139. Word Break

## Pattern

1D Dynamic Programming + HashSet

## Approach

1. Create a `dp` array where:

   dp[i] = true if the first i characters can be formed using dictionary words

2. Store all dictionary words in an `unordered_set` for fast lookup.

3. Set:

   dp[0] = true

4. Traverse every position `i` from 1 to n.

5. For every `i`, try every previous position `j`.

6. If `dp[j]` is true and `s[j...i-1]` is present in the dictionary:

   if(dp[j] && words.count(s.substr(j, i - j))) {
       dp[i] = true;
       break;
   }

7. Return:

   dp[n]

## Time Complexity

O(n² × k)

- We check all pairs of positions.
- Creating a substring can take O(k), where k is the substring length.

## Space Complexity

O(n + m)

- dp array uses O(n) space.
- HashSet stores m dictionary words.

## Interview Note

- Think: "Can I reach position i from some previous valid position j?"
- If dp[j] is true and the substring from j to i-1 is a dictionary word, then dp[i] is true.
- Similar to Climbing Stairs, except the jump size is the length of a valid word.
- Key transition:

  dp[i] = dp[i] || (dp[j] && words.count(s.substr(j, i - j)));

- dp[0] = true is the important base case.