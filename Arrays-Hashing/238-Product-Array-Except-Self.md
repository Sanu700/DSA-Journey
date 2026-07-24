# 238. Product of Array Except Self

## Pattern
Prefix Product + Suffix Product

## Approach

1. Create an answer array initialized with `1`s.
2. Traverse from left to right while maintaining a running **prefix product**.
3. Store the current prefix product in the answer array before updating it.
4. Traverse from right to left while maintaining a running **suffix product**.
5. Multiply each element in the answer array by the current suffix product.
6. Return the answer.

## Time Complexity
O(n)

## Space Complexity
O(1) Extra Space *(excluding the output array)*

## Interview Note
- Think **"Left Product × Right Product"**.
- Instead of creating separate `prefix` and `suffix` arrays, store the prefix products directly in the answer array and use a single variable to maintain the suffix product.
- This achieves the required **O(n)** time and **O(1)** extra space.
- Common mistake: Creating two extra arrays, which increases the space complexity to **O(n)**.