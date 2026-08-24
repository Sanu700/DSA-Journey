# 424. Longest Repeating Character Replacement

## Pattern
Sliding Window + Frequency Counting

## Approach
1. Maintain a window with `left` and `right` pointers.
2. Count the frequency of characters inside the current window.
3. Track the maximum frequency seen so far in the window.
4. If the window length minus the maximum frequency is greater than `k`, shrink the window from the left.
5. Update the answer with the current valid window size.

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Note
- The condition for a valid window is:
  ```cpp
  (windowSize - maxFreq) <= k
  ```
- The key is to keep only the frequency count and the maximum frequency.
- This is a standard sliding-window optimization problem.
