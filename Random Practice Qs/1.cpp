

class Solution {
public:
    int longestValidSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> first(k,-1);
        vector<int> last(k,-1);
        vector<int> got;
        first[0] = 0;

        long long sum = 0;
        int best = 0;

        for(int i=0;i<n;i++){
            int val = nums[i] % k;
            if(val < 0) val += k;

            int dbl = (2LL * val) % k;
            if(last[dbl] == -1){
                got.push_back(dbl);
            }
            last[dbl] = i;

            sum += nums[i];
            int cur = sum % k;
            if(cur < 0) cur += k;

            if(first[cur] != -1){
                best = max(best, i - first[cur] + 1);
            }

            for(int j=0;j<(int)got.size();j++){
                int d = got[j];
                int need = cur - d;
                if(need < 0) need += k;

                if(first[need] != -1 && last[d] >= first[need]){
                    best = max(best, i - first[need] + 1);
                }
            }

            if(first[cur] == -1){
                first[cur] = i+1;
            }
        }

        return best;
    }
};
