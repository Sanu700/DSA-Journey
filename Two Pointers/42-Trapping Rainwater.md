# 42. Trapping Rain Water

## Pattern
Two Pointers

## Approach

1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`
2. Maintain two running maximums:
   - `leftMax`
   - `rightMax`
3. While `left < right`:
   - Update `leftMax` and `rightMax`.
   - If `leftMax < rightMax`:
     - Water trapped at `left` = `leftMax - height[left]`.
     - Add it to the answer and move `left++`.
   - Otherwise:
     - Water trapped at `right` = `rightMax - height[right]`.
     - Add it to the answer and move `right--`.
4. Return the total trapped water.

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Note
- Water trapped at an index depends on the **smaller of the tallest walls** on its left and right.
- Maintain `leftMax` and `rightMax` while moving two pointers inward.
- Process the side with the **smaller boundary**, because its trapped water is already determined.
- Common mistakes:
  - Forgetting to update `leftMax`/`rightMax` before calculating water.
  - Using `height[left]`/`height[right]` instead of the running maximums.
  - Forgetting to move the pointer after processing a side.