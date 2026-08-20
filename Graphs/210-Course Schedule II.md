# 210. Course Schedule II

## Pattern
Directed Graph + DFS + Topological Sort + Cycle Detection

## Intuition

We need to return a valid order in which all courses can be completed.

Each prerequisite creates a directed edge:

```text
prerequisite → course
```

For example:

```text
[1, 0]
```

means:

```text
0 → 1
```

So the problem is to find a **topological ordering** of the graph.

---

## Approach

1. Build an adjacency list:
   ```cpp
   adj[p[1]].push_back(p[0]);
   ```

2. Use two arrays:
   ```cpp
   visited
   path
   ```

   - `visited` → node has already been completely processed.
   - `path` → node is currently in the DFS recursion path.

3. During DFS:
   - If `path[node] == true` → cycle detected → return `{}`.
   - If `visited[node] == true` → already processed → skip.

4. Mark:
   ```cpp
   visited[node] = true;
   path[node] = true;
   ```

5. DFS all neighbours.

6. After all neighbours are processed:
   ```cpp
   path[node] = false;
   ans.push_back(node);
   ```

7. Reverse `ans` at the end because DFS produces the reverse topological order:
   ```cpp
   reverse(ans.begin(), ans.end());
   ```

---

## Why Push After DFS?

Example:

```text
0 → 1 → 2
```

DFS goes:

```text
0
 ↓
1
 ↓
2
```

Nodes finish in this order:

```text
2 → 1 → 0
```

So:

```cpp
ans = {2, 1, 0};
```

Reverse it:

```cpp
{0, 1, 2}
```

which is the valid course order.

---

## Cycle Detection

If:

```text
0 → 1 → 2 → 0
```

During DFS we encounter a node that is already in the current path:

```cpp
if(path[node])
    return false;
```

Therefore no valid ordering exists:

```cpp
return {};
```

---

## Complexity

### Time
```text
O(V + E)
```

- `V` = number of courses
- `E` = number of prerequisites

### Space
```text
O(V + E)
```

for the graph, visited arrays, recursion stack, and result.

---

## Core Pattern

```text
Prerequisites
      ↓
Directed Graph
      ↓
Cycle Detection
      ↓
DFS Topological Sort
      ↓
Push node after DFS
      ↓
Reverse answer
      ↓
Course Order
```

## Difference from Course Schedule I

```text
Course Schedule I
→ Detect cycle
→ Return true / false

Course Schedule II
→ Detect cycle
→ Build topological ordering
→ Return course order
```

### Key lines to remember

```cpp
if(path[node])
    return false;       // cycle

path[node] = false;
ans.push_back(node);    // after DFS

reverse(ans.begin(), ans.end());
```