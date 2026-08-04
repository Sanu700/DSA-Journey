# 76. Minimum Window Substring

## Pattern
Sliding Window + HashMap

## Approach

1. Create a frequency map (`need`) for all characters in `t`.
2. Maintain another frequency map (`window`) for the current window in `s`.
3. Initialize:
   - `left = 0`
   - `have = 0`
   - `needCount = need.size()`
4. Expand the window by moving `right` and update the `window` frequency.
5. Whenever a character's required frequency is satisfied, increment `have`.
6. While `have == needCount` (window is valid):
   - Update the minimum window if the current one is smaller.
   - Remove the leftmost character from the window.
   - If removing it makes the window invalid, decrement `have`.
   - Move `left++`.
7. Return the smallest valid substring found.

## Time Complexity
O(n)

- Each character is added to and removed from the window at most once.

## Space Complexity
O(k)

- `k` = number of distinct characters (or O(1) for a fixed character set like ASCII).

## Interview Note
- Think **"Expand until the window becomes valid, then shrink while it remains valid."**
- Maintain two frequency maps:
  - `need` → required frequencies.
  - `window` → current window frequencies.
- Instead of comparing the two maps every time, maintain:
  - `have` = number of satisfied characters.
  - `needCount` = total distinct required characters.
- Common mistakes:
  - Comparing entire frequency maps each iteration.
  - Forgetting to decrement `have` when the window becomes invalid after shrinking.
  - Updating the answer only after shrinking instead of before removing the left character.