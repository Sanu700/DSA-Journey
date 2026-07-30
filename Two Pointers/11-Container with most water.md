# 11. Container With Most Water

## Pattern
Two Pointers

## Approach

1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`
2. Calculate the current area:
   ```cpp
   area = (right - left) * min(height[left], height[right]);
   ```
3. Update the maximum area.
4. Move the pointer with the **smaller height**:
   - If `height[left] < height[right]`, move `left++`.
   - Otherwise, move `right--`.
5. Repeat until `left >= right`.

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Note
- Think **"Width × Minimum Height"**.
- The shorter wall limits the container's height.
- Always move the pointer pointing to the **shorter wall**, since moving the taller wall only decreases the width without increasing the limiting height.
- Common mistake: Moving the taller pointer instead of the shorter one.