# 347. Top K Frequent Elements

## Pattern
Frequency Counting + Bucket Sort

## Approach

1. Create an `unordered_map<int, int>` to store the frequency of each number.
2. Create a bucket array of size `n + 1`, where the index represents the frequency.
3. Traverse the frequency map and place each number into its corresponding bucket.
4. Traverse the buckets from highest frequency to lowest.
5. Add the numbers from each bucket to the answer until `k` elements are collected.
6. Return the answer.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Interview Note
- The **bucket index represents the frequency**, not the number.
- Each bucket stores all numbers having that frequency.
- Whenever you see **"Top K Frequent"**, think:
  - **HashMap** → Count frequencies.
  - **Bucket Sort** (Optimal) or **Heap** (Alternative) → Retrieve the top `k` elements.
- A common mistake is pushing the bucket index (`i`) into the answer instead of the numbers stored inside `bucket[i]`.
```