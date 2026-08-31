# 55. Jump Game

## Pattern

Greedy

## Approach

1. Keep track of:

   maxReach = farthest index we can reach so far

2. Start with:

   maxReach = 0

3. Traverse the array from left to right.

4. For every index `i`, first check whether it is reachable:

   if(i > maxReach)

   then we cannot reach this index, so return `false`.

5. If the index is reachable, use the jump available at this index to extend our reach:

   maxReach = max(maxReach, i + nums[i])

6. If:

   maxReach >= nums.size() - 1

   we can reach the last index, so return `true`.

7. If we finish the loop without getting stuck, return `true`.

## Code

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(i > maxReach)
                return false;

            maxReach = max(maxReach, i + nums[i]);

            if(maxReach >= nums.size() - 1)
                return true;
        }

        return true;
    }
};

## Time Complexity

O(n)

- We traverse the array once.

## Space Complexity

O(1)

- We only maintain `maxReach`.

## Interview Note

- Think **"What is the farthest position I can reach so far?"**
- At every reachable index, try to extend `maxReach`.

   maxReach = max(maxReach, i + nums[i])

- If:

   i > maxReach

   then the current index is unreachable, so return `false`.

- We don't care about the exact sequence of jumps.
- We only care about the **farthest reachable position**.

## Example

nums = [2,3,1,1,4]

   i = 0 → maxReach = 2

   i = 1 → maxReach = 4

   maxReach >= last index

   → true

## Key Idea

Current reachable range

        ↓

Can this index extend my range?

        ↓

Update maxReach

        ↓

If an index is beyond maxReach → impossible