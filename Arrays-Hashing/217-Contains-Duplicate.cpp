/*
Problem: 217. Contains Duplicate

Topic:
Arrays, Hashing

Approach:
Use an unordered_set.
Before inserting every element,
check if it already exists.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> seen;
        for(int x : nums){
            if(seen.count(x)){
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
};
