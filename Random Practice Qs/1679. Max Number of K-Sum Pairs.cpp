class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int x : nums){
            int needed = k-x;
            if(mp[needed]>0){
                count++;
                mp[needed]--;

            }
            else{
                mp[x]++;
            }
        }
        return count;
    }
};

