# 33. Search in Rotated Sorted Array

## Pattern
Binary Search

## Approach

1. Initialize `left = 0` and `right = n - 1`.
2. While `left <= right`:
   - Calculate `mid`.
   - If `nums[mid] == target`, return `mid`.
3. Determine which half is sorted:
   - If `nums[left] <= nums[mid]`, the **left half is sorted**.
   - Otherwise, the **right half is sorted**.
4. If the left half is sorted:
   - Check if `target` lies between `nums[left]` and `nums[mid]`.
   - If yes, search left: `right = mid - 1`.
   - Otherwise, search right: `left = mid + 1`.
5. If the right half is sorted:
   - Check if `target` lies between `nums[mid]` and `nums[right]`.
   - If yes, search right: `left = mid + 1`.
   - Otherwise, search left: `right = mid - 1`.
6. Return `-1` if the target is not found.

## Time Complexity
O(log n)

## Space Complexity
O(1)

## Interview Note
- **At least one half is always sorted.**
- First identify the sorted half.
- Then check whether the target lies inside that sorted range.
- Don't simply use `nums[mid] > target` to decide the direction because the array is rotated.
- Common mistake: Using `while(left < right)` instead of `while(left <= right)`, which can miss the final element.