# 207. Course Schedule

## Pattern
Directed Graph + DFS + Cycle Detection

## Intuition

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

If there is a cycle:

```text
0 → 1 → 2 → 0
```

then the courses have a circular dependency and **cannot all be completed**.

So the problem becomes:

> **Does the directed graph contain a cycle?**

---

## DFS Cycle Detection

Use two arrays:

```cpp
visited
path
```

### `visited[node]`

Means:

> Have we completely processed this node before?

### `path[node]`

Means:

> Is this node currently present in my DFS recursion path?

---

## Important Logic

```cpp
if(path[node])
    return true;
```

If we encounter a node that is already in the current DFS path:

```text
A → B → C
    ↑   ↓
    └───┘
```

we found a cycle.

### After finishing DFS

```cpp
path[node] = false;
```

because we're no longer exploring that node.

---

## Algorithm

1. Build adjacency list:
   ```cpp
   adj[prerequisite].push_back(course);
   ```

2. Run DFS from every unvisited course.

3. During DFS:
   - If `path[node] == true` → cycle → return `true`.
   - Otherwise mark:
     ```cpp
     visited[node] = true;
     path[node] = true;
     ```

4. DFS all neighbours.

5. After processing:
   ```cpp
   path[node] = false;
   ```

6. If any cycle exists:
   ```cpp
   return false;
   ```

7. Otherwise:
   ```cpp
   return true;
   ```

---

## Core DFS

```cpp
bool dfs(int node,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         vector<bool>& path) {

    if(path[node])
        return true;

    if(visited[node])
        return false;

    visited[node] = true;
    path[node] = true;

    for(int nei : adj[node]) {
        if(dfs(nei, adj, visited, path))
            return true;
    }

    path[node] = false;

    return false;
}
```

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

for the adjacency list, visited arrays, and recursion stack.

---

## Pattern Recognition

```text
Course dependencies
        ↓
Directed Graph
        ↓
Circular dependency?
        ↓
Cycle Detection
        ↓
DFS + visited + current path
```

### Important Difference

For **undirected graph cycle detection**, we usually track the **parent**.

For **Course Schedule (directed graph)**, we track the **current DFS path**.

```text
Undirected → parent
Directed   → path / recursion stack
```