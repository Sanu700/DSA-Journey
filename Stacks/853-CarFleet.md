# 853. Car Fleet

## Pattern

Sorting, Greedy

## Approach

1. Pair each car as `(position, speed)`.
2. Sort cars in **descending order of position**.
3. Compute each car's arrival time:
   ```cpp
   time = (target - position) / speed;
   ```
4. Traverse the sorted cars:
   - If `time > prevFleetTime`, it forms a **new fleet**.
   - Otherwise, it merges with the fleet ahead.
5. Return the fleet count.

## Key Observation

- Cars cannot overtake each other.
- A faster car behind merges into the slower fleet ahead.
- Sorting from **closest to target** lets us compare only arrival times.
- Every increase in arrival time creates a new fleet.

## Time Complexity

- **O(n log n)**
  - Sorting dominates.

## Space Complexity

- **O(n)**
  - For storing `(position, speed)` pairs.

## Interview Note

- Don't simulate car movement.
- Think in terms of **arrival time**.
- Compare only with the fleet ahead after sorting.
- `time > prevFleetTime` → New Fleet.
- `time <= prevFleetTime` → Merge.
