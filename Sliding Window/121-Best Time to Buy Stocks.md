# 121. Best Time to Buy and Sell Stock

## Pattern
Two Pointers

## Approach

1. Initialize two pointers:
   - `left` = buying day
   - `right` = selling day (`left + 1`)
2. Compare the prices:
   - If `prices[left] < prices[right]`, calculate the profit and update the maximum profit.
   - Otherwise, move `left = right` since a cheaper buying day is found.
3. Move `right++` and repeat until the end of the array.
4. Return the maximum profit.

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Note
- Think **"Find the minimum buying price before each selling day."**
- `left` always represents the **best (lowest) buying price seen so far**.
- If a lower price is found, update the buying pointer instead of calculating profit.
- Common mistakes:
  - Updating the buying pointer when prices are equal (not necessary).
  - Selling before buying (ensure `left < right`).
  - Using nested loops, which leads to **O(n²)**.