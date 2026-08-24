# 152. Maximum Product Subarray

## Pattern

1D Dynamic Programming + Kadane's Algorithm

## Approach

1. Maintain two variables:
   - `maxProd` → maximum product ending at the current index.
   - `minProd` → minimum product ending at the current index.

2. We need both because a negative number can turn the minimum product into the maximum product.

3. Initialize both with the first element:

   ```cpp
   maxProd = nums[0];
   minProd = nums[0];
   ```

4. Traverse the array from index `1`.

5. For every element, calculate the new maximum and minimum:

   ```cpp
   int currMax = max({
       nums[i],
       nums[i] * maxProd,
       nums[i] * minProd
   });

   int currMin = min({
       nums[i],
       nums[i] * maxProd,
       nums[i] * minProd
   });
   ```

6. Update:

   ```cpp
   maxProd = currMax;
   minProd = currMin;
   ```

7. Keep track of the global maximum product.

## Time Complexity

O(n)

- Traverse the array once.

## Space Complexity

O(1)

- Only a few variables are used.

## Interview Note

- Think: **"What is the maximum and minimum product ending at this position?"**
- We need the minimum because:

  ```text
  negative × negative = positive
  ```

- A negative number can swap the role of `maxProd` and `minProd`.
- Zero breaks the current product and allows a new subarray to start.
- Key transition:

  ```cpp
  currMax = max(nums[i], nums[i] * maxProd, nums[i] * minProd);

  currMin = min(nums[i], nums[i] * maxProd, nums[i] * minProd);
  ```