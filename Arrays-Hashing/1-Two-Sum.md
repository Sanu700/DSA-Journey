# 1. Two Sum

## Pattern
HashMap + Lookup

## Approach

1. Create an `unordered_map<int, int>` to store each number and its index.
2. Traverse the array once.
3. For each element, calculate its complement:
   ```cpp
   complement = target - nums[i];
   ```
4. Check if the complement already exists in the map.
   - If it exists, return the stored index and the current index.
5. Otherwise, store the current number and its index in the map.
6. If no pair is found, return an empty vector.

## Time Complexity
O(n)

- Each element is processed once, and HashMap operations take O(1) on average.

## Space Complexity
O(n)

- The HashMap may store all elements in the worst case.

## Interview Note
- Think **"Have I already seen the complement?"**
- Instead of checking every pair (O(n²)), use a HashMap for constant-time lookups.
- Store **number → index** in the map.
- A common mistake is storing the current element before checking for its complement, which can incorrectly pair an element with itself in some variants of the problem.