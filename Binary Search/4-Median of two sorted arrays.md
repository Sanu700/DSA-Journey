# 4. Median of Two Sorted Arrays

## Pattern
Binary Search + Partition

## Approach

1. Always binary search on the **smaller array**.
2. Create a partition in `nums1`:
   ```cpp
   partitionA = ...
   ```
3. Calculate the corresponding partition in `nums2` so that the left side contains half of all elements:
   ```cpp
   partitionB = (m + n + 1) / 2 - partitionA;
   ```
4. Get the four boundary values:
   - `leftA`
   - `rightA`
   - `leftB`
   - `rightB`
5. Check if the partition is correct:
   ```cpp
   leftA <= rightB && leftB <= rightA
   ```
6. If the partition is correct:
   - Odd total length:
     ```cpp
     max(leftA, leftB)
     ```
   - Even total length:
     ```cpp
     (max(leftA,leftB) + min(rightA,rightB)) / 2.0
     ```
7. If `leftA > rightB`, we took too many elements from `nums1`:
   ```cpp
   right = partitionA - 1;
   ```
8. Otherwise, we need more elements from `nums1`:
   ```cpp
   left = partitionA + 1;
   ```

## Time Complexity
O(log(min(m,n)))

## Space Complexity
O(1)

## Interview Note
- **Don't merge the arrays** — that takes O(m+n).
- Think **"Find the correct partition."**
- The left side must contain half of all elements.
- For a valid partition:
  ```text
  leftA <= rightB
  leftB <= rightA
  ```
- The median comes from the elements directly around the partition.
- Use `INT_MIN` and `INT_MAX` when a partition is at the beginning or end of an array.