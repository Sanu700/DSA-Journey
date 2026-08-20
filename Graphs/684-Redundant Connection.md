# 684. Redundant Connection

## Pattern
Undirected Graph + DFS + Cycle Detection

## Intuition

We are given edges that were originally part of a tree, but one extra edge was added.

That extra edge creates a cycle.

For every edge `[u, v]`:

1. Check whether `u` and `v` are already connected.
2. If they are already connected, adding `[u,v]` creates a cycle.
3. Therefore `[u,v]` is the redundant edge.
4. Otherwise, add the edge to the graph.

---

## Example

Edges:

```text
[1,2]
[2,3]
[3,4]
[1,4]
```

Process:

```text
[1,2] → not connected → add

[2,3] → not connected → add

[3,4] → not connected → add
```

Graph:

```text
1 — 2 — 3 — 4
```

Now:

```text
[1,4]
```

DFS from `1` can already reach `4`.

Therefore:

```text
1 → 2 → 3 → 4
```

Adding `[1,4]` creates:

```text
1 → 2 → 3 → 4
↑             ↓
└─────────────┘
```

So answer:

```text
[1,4]
```

---

## DFS

The DFS checks whether `target` is reachable from `node`.

```cpp
bool dfs(int node, int target,
         vector<vector<int>>& adj,
         vector<bool>& visited) {

    if(node == target)
        return true;

    visited[node] = true;

    for(int nei : adj[node]) {

        if(!visited[nei]) {

            if(dfs(nei, target, adj, visited))
                return true;
        }
    }

    return false;
}
```

---

## Main Algorithm

```text
For every edge [u,v]:

       DFS(u → v)
           ↓
    Are they connected?
       ↙          ↘
     YES           NO
      ↓             ↓
   cycle          add edge
      ↓
 return [u,v]
```

### Important

Do **not** build the entire graph first.

Process edges incrementally:

```text
edge 1 → check → add
edge 2 → check → add
edge 3 → check → add
...
```

Otherwise you won't know which edge was responsible for creating the cycle.

---

## Complexity

Let `E` be the number of edges.

For every edge, we may perform a DFS:

```text
O(E × (V + E))
```

With this problem's constraints, this is acceptable.

Space:

```text
O(V + E)
```

for the graph, visited array, and recursion stack.

---

## Pattern Recognition

```text
Adding an edge
      ↓
Are the two endpoints already connected?
      ↓
YES → Adding edge creates cycle
      ↓
Redundant Connection
```

### Key Idea

> **Before adding an edge, check whether its two endpoints are already connected.**