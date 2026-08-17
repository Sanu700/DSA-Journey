# 297. Serialize and Deserialize Binary Tree

## Pattern
Tree + DFS / Recursion

## Approach

### Serialize

1. Use **preorder DFS**:
   ```text
   Root → Left → Right
   ```
2. Store each node's value.
3. Store `#` for `nullptr`.
4. Separate values using commas.

Example:
```text
1,2,#,#,3,4,#,#,5,#,#
```

### Deserialize

1. Split the string into tokens.
2. Maintain an `index` pointing to the current token.
3. If the token is `#`, return `nullptr`.
4. Otherwise create a node using the token.
5. Recursively build:
   - Left subtree
   - Right subtree
6. Increment `index` as each token is consumed.

## Time Complexity
O(n)

## Space Complexity
O(n)

## Interview Note
- **Preorder + null markers** uniquely identifies the tree.
- `#` is essential to preserve the tree structure.
- Use `int& index` so all recursive calls share and update the same position.
- Think:
  ```text
  Serialize:
  Tree → Preorder + "#"

  Deserialize:
  Preorder + "#" → Tree
  ```
- Common mistake: Not storing `nullptr` markers, which can make different tree structures produce the same serialization.