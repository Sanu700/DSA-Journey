# 239. Sliding Window Maximum

## Pattern
Fixed Sliding Window + Monotonic Deque

## Approach

1. Create a deque to store **indices** of useful elements.
2. Traverse the array.
3. Remove indices from the front that are outside the current window.
4. Remove indices from the back while their corresponding values are smaller than the current value.
5. Push the current index into the deque.
6. Once the first window is formed (`i >= k - 1`), the front of the deque contains the maximum element for the current window.
7. Store `nums[dq.front()]` in the answer.

## Time Complexity
O(n)

- Every index is inserted and removed from the deque at most once.

## Space Complexity
O(k)

- The deque stores at most `k` indices.

## Interview Note
- This is a **fixed-size sliding window** problem.
- The deque is maintained in **decreasing order of values**.
- Store **indices**, not values, so expired elements can be removed efficiently.
- The **front** of the deque always represents the maximum element in the current window.
- Common mistakes:
  - Storing values instead of indices.
  - Forgetting to remove indices that fall outside the window.
  - Forgetting to remove smaller elements from the back before inserting the current element.