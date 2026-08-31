# 846. Hand of Straights

## Pattern

Greedy + Sorting / Ordered Map

## Approach

1. First check whether the number of cards can be divided into groups of `groupSize`:

   if(hand.size() % groupSize != 0)
       return false;

2. Store the frequency of every card in an ordered `map`.

   freq[card] = number of times the card is available

3. The smallest remaining card must be the start of a group.

   start = freq.begin()->first

4. Starting from `start`, we need exactly `groupSize` consecutive cards:

   start
   start + 1
   start + 2
   ...
   start + groupSize - 1

5. If any required card has frequency `0`, return `false`.

6. Use one copy of every required card.

   freq[card]--;

7. If a card's frequency becomes `0`, remove it from the map.

8. Continue until all cards have been used.

9. If all cards can be grouped successfully, return `true`.

## Time Complexity

O(n log n)

- Each card is inserted into the ordered map.
- We repeatedly access the smallest remaining card.
- Map operations take O(log n).

## Space Complexity

O(n)

- The frequency map can contain up to `n` distinct cards.

## Interview Note

- First check:

   hand.size() % groupSize != 0 → impossible

- The key greedy idea is:

   **"The smallest remaining card MUST start a group."**

- Why?

   There is no smaller unused card that could come before it.

- Once we choose the smallest card, we are forced to find:

   start, start+1, ..., start+groupSize-1

- If any card is missing → return `false`.

- Use a frequency map because duplicates are allowed.

## Mental Model

Smallest remaining card

        ↓

Must start a group

        ↓

Need consecutive cards

        ↓

start, start+1, start+2, ...

        ↓

Missing card?

   YES → false

   NO → consume group

        ↓

Repeat

## Key Idea

**Smallest remaining card → forced group start**

**Divisibility → necessary check**

**Consecutive cards → actual greedy constraint**