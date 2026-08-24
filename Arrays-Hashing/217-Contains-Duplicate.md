# 217. Contains Duplicate

## Pattern
HashSet

## Approach
1. Create a hash set to store values seen so far.
2. Traverse the array.
3. If the current value already exists in the set, return `true`.
4. Otherwise, insert it and continue.
5. If the loop finishes, return `false`.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Interview Note
- The key check is: **have I already seen this number?**
- A set gives constant-time lookup and insertion on average.
- This is cleaner than using a map for this particular problem.
