class Solution {
public:
    int compress(vector<char>& chars) {
       int l = 0;
       int r = 0;
       while(r < chars.size()){
        char current = chars[r];
        int count = 0;
        while(r < chars.size() && chars[r] == current){
            r++;
            count++;
        }
        chars[l++] = current;

        if(count>1){
            string cnt = to_string(count);
         for(char c : cnt){
            chars[l++] = c;
        }
        }

       
       } 
       return l;
    }
};