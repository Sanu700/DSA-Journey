# 153. Find Minimum in Rotated Sorted Array

## Pattern
Binary Search

## Approach

1. Initialize `left = 0` and `right = n - 1`.
2. Find the middle:
   ```cpp
   mid = left + (right - left) / 2;
   ```
3. Compare `nums[mid]` with `nums[right]`.
4. If `nums[mid] > nums[right]`:
   - Minimum is on the **right**.
   - `left = mid + 1`
5. Otherwise:
   - Minimum is at `mid` or on the **left**.
   - `right = mid`
6. Continue until `left == right`.
7. Return `nums[left]`.

## Time Complexity
O(log n)

## Space Complexity
O(1)

## Interview Note
- Don't sort the array — that makes it `O(n log n)`.
- Think **"Which half contains the minimum?"**
- If `nums[mid] > nums[right]` → minimum is in the right half.
- Otherwise → minimum is in the left half or at `mid`.