class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> product(nums.size());
        int n = nums.size();
        prefix[0] = 1;
        suffix[n-1] = 1;

        for(int i = 1;i<n;i++){

            prefix[i]  = prefix[i-1] * nums[i-1]; 
        
        }
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i = 0;i<n;i++){
            product[i] = suffix[i] * prefix[i];
        }

        return product; 
    }
};


