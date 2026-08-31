# 134. Gas Station

## Pattern

Greedy

## Approach

1. At every station, calculate the net gas gained or lost:

   diff = gas[i] - cost[i]

2. Maintain two variables:

   tank = gas remaining while trying the current starting station

   total = total gas available across the entire circuit

3. For every station:

   tank += gas[i] - cost[i]

   total += gas[i] - cost[i]

4. If:

   tank < 0

   then the current starting station cannot reach station `i + 1`.

5. More importantly, none of the stations between the current `start` and `i` can be a valid starting point.

   Therefore:

   start = i + 1

   tank = 0

6. After checking every station, if:

   total < 0

   then the total gas is less than the total cost, so completing the circuit is impossible:

   return -1

7. Otherwise, `start` is the valid starting station.

## Time Complexity

O(n)

- We traverse the stations once.

## Space Complexity

O(1)

- We only use `total`, `tank`, and `start`.

## Interview Note

- Think **"If I run out of gas at station i, where should I restart?"**
- If `tank < 0`, the current start is impossible.
- The key greedy observation is:

   If starting from `start` cannot reach `i + 1`,
   then every station between `start` and `i` also cannot be a valid start.

- Therefore we can safely skip the entire failed segment:

   start = i + 1

- There are TWO separate conditions:

   1. `tank < 0` → current starting point fails → move `start`

   2. `total < 0` → entire circuit is impossible → return `-1`

- Key equations:

   diff = gas[i] - cost[i]

   tank += diff

   total += diff

## Mental Model

Start at `start`

        ↓

Keep adding `gas[i] - cost[i]`

        ↓

tank < 0?

        ↓ YES

Current start and everything before i
cannot be a valid start

        ↓

start = i + 1
tank = 0

        ↓

At the end:

total < 0 → -1

total >= 0 → start

## Key Idea

**Local failure → move the starting point**

**Global gas shortage → impossible**