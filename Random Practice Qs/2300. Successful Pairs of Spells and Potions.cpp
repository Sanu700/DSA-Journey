class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
      
        
        sort(potions.begin(),potions.end());
        vector<int> pair(spells.size());
        for(int i=0;i<spells.size();i++){
        int l = 0;
        int r = n;
        
        while(l<r){
            int mid = l+(r-l)/2;
            if((long long) spells[i] * potions[mid] >= success){
                r = mid;}
                else{
                l = mid+1;
                }
                pair[i] = n-l;
            }
        }
    
        return pair;
    }
};


 
