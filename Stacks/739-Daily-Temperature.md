# 739. Daily Temperatures

## Pattern

Monotonic Stack

## Approach

1. Initialize:
   - A result array `ans` of size `n` with all values as `0`.
   - A stack to store **indices** of temperatures.
2. Traverse the temperature array from left to right.
3. While the stack is not empty and the current temperature is greater than the temperature at the index on the top of the stack:
   - Pop the top index.
   - The current day is the next warmer day for that index.
   - Store the difference in days: `ans[index] = i - index`.
4. Push the current index onto the stack.
5. After the traversal, any indices left in the stack have no warmer day ahead, so their answer remains `0`.

## Key Observation

- We need to find the **next greater temperature** for every day.
- A **monotonic decreasing stack** keeps temperatures in decreasing order.
- The stack stores **indices**, not temperatures, so we can:
  - Compare temperatures using the indices.
  - Calculate the number of days between them.

## Time Complexity

- **O(n)**
  - Each index is pushed and popped at most once.

## Space Complexity

- **O(n)**
  - In the worst case, all indices are stored in the stack.

## Interview Note

- Use a **monotonic decreasing stack** whenever you need to find the **next greater element**.
- Store **indices** instead of values.
- When a greater temperature is found:
  - Pop all smaller temperatures.
  - Update their answer with the distance to the current index.
- Any indices remaining in the stack do not have a warmer day ahead, so their answer is `0`.