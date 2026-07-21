# 242. Valid Anagram

## Pattern
Frequency Counting

## Approach

1. If the lengths of both strings are different, return `false`.
2. Create an `unordered_map<char, int>` to store character frequencies.
3. Traverse the first string and increment the frequency of each character.
4. Traverse the second string and decrement the frequency.
5. If any frequency becomes negative, return `false`.
6. If the traversal completes successfully, return `true`.

## Time Complexity
O(n)

## Space Complexity
O(k)

## Interview Note
If the problem guarantees only lowercase English letters, replace the `unordered_map` with an array of size `26` for better performance.