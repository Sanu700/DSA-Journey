# 981. Time Based Key-Value Store

## Pattern
HashMap + Binary Search

## Approach

1. Create a HashMap:
   ```cpp
   key → vector of (timestamp, value)
   ```
2. In `set()`:
   - Store `{timestamp, value}` for the given key.
   - Timestamps for the same key are already in increasing order.
3. In `get()`:
   - Find the vector for the given key.
   - Binary search for the **largest timestamp <= target timestamp**.
4. If `v[mid].first <= timestamp`:
   - This is a valid answer.
   - Store its value.
   - Search right for a potentially later valid timestamp.
5. Otherwise:
   - Timestamp is too large.
   - Search left.
6. Return the stored answer, or `""` if no valid timestamp exists.

## Time Complexity
- `set()` → O(1)
- `get()` → O(log n)

## Space Complexity
O(n)

## Interview Note
- Think:
  ```text
  key
   ↓
  sorted vector of (timestamp, value)
   ↓
  Binary Search
   ↓
  rightmost timestamp <= target
  ```
- This is a **"rightmost valid element"** Binary Search pattern.
- Don't search for `timestamp == target`; the required timestamp may not exist.
- Common mistake: Declaring the HashMap inside the constructor. It must be a **class member** so both `set()` and `get()` can access it.