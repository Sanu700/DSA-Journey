# 424. Longest Repeating Character Replacement

## Pattern
Sliding Window + Frequency Count

## Approach

1. Initialize:
   - `left = 0`
   - `maxFreq = 0`
   - `ans = 0`
   - A frequency array of size `26` to count character occurrences.
2. Expand the window by moving `right`.
3. Increment the frequency of `s[right]`.
4. Update `maxFreq` with the highest frequency seen so far.
5. If the number of replacements needed,
   - `(window size - maxFreq)`,
   exceeds `k`, shrink the window:
   - Decrement the frequency of `s[left]`.
   - Move `left` forward.
6. Update the maximum window size after ensuring the window is valid.
7. Return the maximum length.

## Key Observation

For a window to be valid:

```text
(window size) - (frequency of the most common character) <= k
```

The remaining characters can all be replaced to match the most frequent character.

## Time Complexity

O(n)

- Each character enters and leaves the window at most once.

## Space Complexity

O(1)

- Frequency array of size `26`.

## Interview Note

- Think **"Expand the window while it's valid. If it becomes invalid, shrink it until it's valid again."**
- Keep track of the **maximum frequency** in the window.
- **Do not recompute `maxFreq` while shrinking.** It can remain stale and the algorithm is still correct, which keeps the solution linear.
- The condition to remember is:

```text
(window size - maxFreq) > k
```

If this is true, shrink the window.