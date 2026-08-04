# 567. Permutation in String

## Pattern

Sliding Window + Frequency Count

## Approach

1. Let the window size be `k = s1.length()`.
2. Create two frequency arrays of size `26`:
   - `freq1` → stores character frequencies of `s1`.
   - `freq2` → stores character frequencies of the current window in `s2`.
3. Fill `freq1` using the characters of `s1`.
4. Traverse `s2` using a sliding window.
5. For each new character:
   - Increment its frequency in `freq2`.
6. If the window size becomes greater than `k`:
   - Decrement the frequency of the leftmost character.
   - Move the `left` pointer forward.
7. Whenever the window size equals `k`:
   - Compare `freq1` and `freq2`.
   - If they are equal, return `true`.
8. If no matching window is found, return `false`.

## Key Observation

Two strings are permutations of each other **if and only if** their character frequencies are identical.

Since there are only **26 lowercase English letters**, comparing two frequency arrays takes **O(26) = O(1)** time.

## Time Complexity

- **O(n)**
  - Sliding window traverses `s2` once.
  - Comparing frequency arrays is constant time (`26` elements).

## Space Complexity

- **O(1)**
  - Two frequency arrays of fixed size `26`.

## Interview Note

- The window size is **fixed** to `s1.length()`.
- Use a **frequency array**, not an `unordered_set`, because permutations depend on **character counts**, not just the presence of characters.
- The sliding window pattern is:
  - Expand the window.
  - Shrink if its size exceeds `k`.
  - Compare frequencies when the window size is exactly `k`.
```