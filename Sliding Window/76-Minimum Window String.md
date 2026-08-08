# 704. Binary Search

## Pattern

Binary Search

## Approach

1. Initialize `left = 0` and `right = n - 1`.
2. Calculate:
   ```cpp
   mid = left + (right - left) / 2;
   ```
3. If `nums[mid] == target`, return `mid`.
4. If `nums[mid] > target`, search the left half.
5. Otherwise, search the right half.
6. Return `-1` if the target is not found.

## Key Observation

- Binary Search works on a **sorted array**.
- Each comparison eliminates half of the search space.
- Therefore, the search takes **O(log n)** time. :contentReference[oaicite:0]{index=0}

## Time Complexity

- **O(log n)**

## Space Complexity

- **O(1)**

## Interview Note

- Use:
  ```cpp
  mid = left + (right - left) / 2;
  ```
  to avoid integer overflow.
- Standard template:
  ```cpp
  while(left <= right)
  ```
- `nums[mid] > target` → `right = mid - 1`
- `nums[mid] < target` → `left = mid + 1`