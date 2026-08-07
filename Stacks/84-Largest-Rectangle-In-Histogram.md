# 84. Largest Rectangle in Histogram

## Pattern

Monotonic Increasing Stack

## Approach

1. Maintain a stack of **indices** with increasing heights.
2. Traverse the histogram:
   - If the current height is greater than or equal to the stack top, push its index.
   - Otherwise, pop until the stack becomes increasing.
3. For every popped bar:
   - Height = `heights[popped]`
   - Right boundary = current index.
   - Left boundary = stack top after popping (or `-1` if empty).
   - Compute width and update the maximum area.
4. After traversal, pop all remaining bars using `n` as the right boundary.

## Key Observation

- Every bar is treated as the **smallest height** of a rectangle.
- The stack helps find the **first smaller element on both sides**.
- When a smaller bar is encountered, the popped bar's maximum rectangle is determined.

## Time Complexity

- **O(n)**
  - Every index is pushed and popped at most once.

## Space Complexity

- **O(n)**
  - Stack stores indices.

## Interview Note

- Store **indices**, not heights.
- Keep the stack **monotonically increasing**.
- On popping:
  ```cpp
  height = heights[popped];
  left = st.empty() ? -1 : st.top();
  right = currentIndex;
  width = right - left - 1;
  area = height * width;
  ```
- After the loop, process the remaining stack with `right = n`.
