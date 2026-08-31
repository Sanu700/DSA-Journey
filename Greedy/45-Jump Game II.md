# 45. Jump Game II

## Pattern

Greedy + BFS / Level-by-Level Traversal

## Approach

1. Keep track of three things:

   jumps = number of jumps taken

   currEnd = farthest index reachable using the current number of jumps

   farthestEnd = farthest index reachable using one additional jump

2. Start with:

   jumps = 0
   currEnd = 0
   farthestEnd = 0

3. Traverse the array up to the second-last index:

   for(int i = 0; i < nums.size() - 1; i++)

   We don't need to jump from the last index.

4. At every index, calculate how far we could reach from there:

   farthestEnd = max(farthestEnd, i + nums[i])

5. When we reach `currEnd`, we have exhausted all positions reachable with the current number of jumps.

   Therefore, we must take another jump:

   jumps++;

   currEnd = farthestEnd;

6. Continue until we can reach the last index.

7. Return:

   jumps

## Code

class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currEnd = 0;
        int farthestEnd = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            farthestEnd = max(farthestEnd, i + nums[i]);

            if(i == currEnd) {

                jumps++;
                currEnd = farthestEnd;
            }
        }

        return jumps;
    }
};

## Time Complexity

O(n)

- We traverse the array once.

## Space Complexity

O(1)

- We only use three variables.

## Interview Note

- Think **"Within my current jump range, how far can my NEXT jump take me?"**
- `currEnd` represents the end of the current reachable range.
- `farthestEnd` represents the best possible end of the next reachable range.
- When `i == currEnd`, we have finished exploring the current jump's range, so we take another jump.

## Mental Model

Current jump:

   [--------- currEnd]

          ↓

Check every position inside this range

          ↓

Find the farthest possible next position

          ↓

   [---------------- farthestEnd]

          ↓

Take another jump

## Key Idea

   farthestEnd = max(farthestEnd, i + nums[i])

   if(i == currEnd) {
       jumps++;
       currEnd = farthestEnd;
   }

- This is similar to **BFS levels**:
  - Current range = current level
  - Farthest range = next level
  - Each level represents one jump.

- Unlike Jump Game I, where we only ask **"Can I reach the end?"**, here we ask **"What is the minimum number of jumps?"**