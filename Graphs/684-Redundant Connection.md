# 684. Redundant Connection

## Pattern
Union Find + Cycle Detection

## Approach
1. Process edges one by one.
2. For each edge `(u, v)`, check whether `u` and `v` are already connected.
3. If they are connected, then adding this edge creates a cycle and it is the redundant edge.
4. Otherwise, union them and continue.
5. Return the first edge that forms a cycle.

## Time Complexity
O(E α(V))

## Space Complexity
O(V)

## Interview Note
- In an undirected graph, a redundant edge is exactly the one that closes a cycle.
- Union Find is ideal because each edge only needs to know whether the endpoints are already connected.
- This is a cleaner approach than repeatedly doing DFS for every edge.
