# 143. Reorder List

## Pattern

Fast & Slow Pointers + Reverse Linked List + Two Pointer Merge

## Intuition

The list needs to be reordered by taking nodes alternately from the front and back:

1 → 2 → 3 → 4 → 5

becomes:

1 → 5 → 2 → 4 → 3

The easiest way is to break the problem into 3 familiar linked-list patterns:

Find the middle → Reverse second half → Merge alternately

## Approach

1. Use slow and fast pointers to find the middle of the linked list.

   slow → 1 step

   fast → 2 steps

2. Split the list into two halves.

   First half:

   1 → 2 → 3

   Second half:

   4 → 5

3. Reverse the second half.

   5 → 4

4. Merge the two halves alternately:

   1 → 5 → 2 → 4 → 3

5. During merging, save the next pointers of both lists before changing any links.

## Time Complexity

O(n)

- Finding the middle takes O(n).
- Reversing the second half takes O(n).
- Merging takes O(n).

## Space Complexity

O(1)

- Only a constant number of pointers are used.
- No extra array or list is created.

## Interview Note

- Think **"Middle → Reverse → Merge."**
- Reuse the Fast & Slow Pointer pattern to find the middle.
- Reuse the Reverse Linked List pattern for the second half.
- For merging, alternate nodes from the first and reversed second half.
- Always save the next pointers before modifying links.

## Mental Model

Original:

   1 → 2 → 3 → 4 → 5

        ↓

Find middle:

   1 → 2 → 3 | 4 → 5

        ↓

Reverse second half:

   1 → 2 → 3 | 5 → 4

        ↓

Merge alternately:

   1 → 5 → 2 → 4 → 3

## Key Idea

**Find middle → Split → Reverse second half → Alternate merge.**

This problem is basically a combination of three linked-list patterns you already know.