class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count =0;
        for(int i=0;i<flowerbed.size();i++){
            int left = (i == 0) ? 0 : flowerbed[i-1];
            int right = (i == flowerbed.size()-1) ? 0 : flowerbed[i+1];
            if(flowerbed[i] == 0 && left == 0 && right == 0 ){
                  
                 flowerbed[i] = 1;
                 count++;
            }
            
        }
        return count >= n;
    }
};