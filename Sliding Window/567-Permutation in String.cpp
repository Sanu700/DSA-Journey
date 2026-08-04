class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int l = 0;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
        }
        for(int r=0;r<s2.size();r++){
             freq2[s2[r]-'a']++;
             if((r-l+1)>k){
                freq2[s2[l]-'a']--;
                l++;
                

             }
             if(r-l+1 == k){
                 if(freq1== freq2)
                 return true;
             }
        }
       
        return false;
    }
};