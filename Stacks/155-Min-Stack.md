# 155. Min Stack

## Pattern

Stack

## Approach

1. Initialize two stacks:
   - `st` to store all elements.
   - `minSt` to store the minimum element at each level.
2. For `push(val)`:
   - Push `val` into `st`.
   - If `minSt` is empty, push `val`.
   - Otherwise, push `min(val, minSt.top())` into `minSt`.
3. For `pop()`:
   - Pop the top element from both `st` and `minSt`.
4. For `top()`:
   - Return `st.top()`.
5. For `getMin()`:
   - Return `minSt.top()`.

## Key Observation

- The minimum element changes when elements are popped.
- A second stack stores the minimum value corresponding to every element in the main stack.
- Thus, the current minimum is always available in **O(1)** using `minSt.top()`.

## Time Complexity

- **O(1)**

  - Each operation (`push`, `pop`, `top`, `getMin`) takes constant time.

## Space Complexity

- **O(n)**

  - In the worst case, the auxiliary stack stores one minimum value for every element in the main stack.

## Interview Note

- Use an auxiliary stack whenever you need to maintain the minimum element efficiently.
- On every `push`, update the current minimum.
- On every `pop`, remove the corresponding minimum as well.
- This guarantees **O(1)** time for `push`, `pop`, `top`, and `getMin()`.
