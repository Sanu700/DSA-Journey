# 167. Two Sum II - Input Array Is Sorted

## Pattern
Two Pointers

## Approach

1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`
2. Calculate the sum of `numbers[left] + numbers[right]`.
3. If the sum equals the target, return the 1-based indices.
4. If the sum is smaller than the target, move the left pointer (`left++`) to increase the sum.
5. If the sum is greater than the target, move the right pointer (`right--`) to decrease the sum.
6. Repeat until the pair is found.

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Note
- This approach works **only because the array is sorted**.
- Think:
  - `sum < target` → Move `left` right to increase the sum.
  - `sum > target` → Move `right` left to decrease the sum.
- Common mistake: Using this approach on an **unsorted** array. For an unsorted array, use a **HashMap** instead.