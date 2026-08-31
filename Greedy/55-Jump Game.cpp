class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0];


        for(int i=1;i<nums.size();i++){
            if(i > maxReach) return false;

            maxReach = max(nums[i]+i ,maxReach);

            if(maxReach >= nums.size()-1) return true;
        }
        return true;
    }
};


