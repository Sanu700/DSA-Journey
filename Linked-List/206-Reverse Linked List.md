# 206. Reverse Linked List

## Pattern

Linked List + Pointer Manipulation

## Intuition

We need to reverse the direction of every link in the linked list.

Think:

prev ← curr → next

At every node, reverse the link so that:

curr → prev

Then move both pointers forward.

## Approach

1. Maintain two pointers:

   prev = previous node

   curr = current node

2. Initially:

   prev = null

   curr = head

3. At every node, first save the next node.

   This is important because we are about to change the current node's `next` pointer.

4. Reverse the current link:

   current → previous

5. Move forward:

   prev → current

   curr → next

6. Continue until `curr` becomes null.

7. At the end, `prev` is the new head of the reversed linked list.

## Time Complexity

O(n)

- Every node is visited exactly once.

## Space Complexity

O(1)

- Only a constant number of pointers are used.

## Interview Note

- Think **"Save → Reverse → Move."**
- Always save the next node BEFORE reversing the current pointer.
- The three important pointers are:

   `prev` → node behind current

   `curr` → node currently being processed

   `next` → saved next node

- At the end:

   `prev` = new head

## Mental Model

Original:

   A → B → C → null

After reversing:

   null ← A ← B ← C

   C becomes the new head.

## Key Idea

**Save the next node → reverse the pointer → move forward.**