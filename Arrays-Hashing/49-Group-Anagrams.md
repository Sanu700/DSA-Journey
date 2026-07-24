# 49. Group Anagrams

## Pattern
HashMap + Grouping (Signature Key)

## Approach

1. Create an `unordered_map<string, vector<string>>`.
2. For each string, create a copy (`key`).
3. Sort the copied string to generate a unique signature.
4. Store the original string in the map using the sorted string as the key.
5. Traverse the map and push each grouped vector into the answer.
6. Return the final `vector<vector<string>>`.

## Time Complexity
O(n × k log k)

- `n` = number of strings
- `k` = average length of each string

## Space Complexity
O(n × k)

## Interview Note
If the strings contain only lowercase English letters (`a-z`), an optimal solution uses a **26-character frequency array** as the key instead of sorting each string, reducing the time complexity to **O(n × k)**.