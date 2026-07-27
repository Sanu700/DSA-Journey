# 125. Valid Palindrome

## Pattern
Two Pointers

## Approach

1. Initialize two pointers: `left = 0` and `right = n - 1`.
2. Move the left pointer forward until it points to an alphanumeric character.
3. Move the right pointer backward until it points to an alphanumeric character.
4. Compare the lowercase versions of both characters using `tolower()`.
5. If they are different, return `false`.
6. Otherwise, move both pointers inward.
7. If the entire string is traversed without mismatches, return `true`.

## Time Complexity
O(n)

## Space Complexity
O(1)

## Interview Note
- Think **"Compare from both ends."**
- Use `isalnum()` to skip spaces and special characters.
- Use `tolower()` to make the comparison case-insensitive.
- Common mistake: Forgetting to `continue` after skipping a non-alphanumeric character, which leads to comparing invalid characters.