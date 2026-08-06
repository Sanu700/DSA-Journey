# 20. Valid Parentheses

## Pattern

Stack

## Approach

1. Initialize an empty stack.
2. Traverse each character in the string.
3. If the character is an opening bracket (`(`, `{`, `[`):
   - Push it onto the stack.
4. Otherwise, it is a closing bracket:
   - If the stack is empty, return `false`.
   - Pop the top element from the stack.
   - Check if it matches the corresponding opening bracket.
   - If it doesn't match, return `false`.
5. After processing all characters:
   - If the stack is empty, all brackets are matched.
   - Otherwise, return `false`.

## Key Observation

- Every closing bracket must match the **most recent unmatched opening bracket**.
- A **stack (LIFO)** naturally supports this behavior.

## Time Complexity

- **O(n)**
  - Each character is pushed and popped at most once.

## Space Complexity

- **O(n)**
  - In the worst case, all opening brackets are stored in the stack.

## Interview Note

- Use a **stack** whenever you need to match nested structures.
- Push opening brackets.
- On encountering a closing bracket:
  - The stack must not be empty.
  - The top element must be the matching opening bracket.
- Finally, the stack should be empty for the string to be valid.
```