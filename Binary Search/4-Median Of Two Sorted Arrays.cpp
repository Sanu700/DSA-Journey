class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

       
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int l = 0;
        int r = m;

        while(l <= r) {

            int partitionA = l + (r - l) / 2;

         
            int partitionB = (m + n + 1) / 2 - partitionA;

            int leftA = (partitionA == 0)
                        ? INT_MIN
                        : nums1[partitionA - 1];

            int rightA = (partitionA == m)
                         ? INT_MAX
                         : nums1[partitionA];

            int leftB = (partitionB == 0)
                        ? INT_MIN
                        : nums2[partitionB - 1];

            int rightB = (partitionB == n)
                         ? INT_MAX
                         : nums2[partitionB];

           
            if(leftA <= rightB && leftB <= rightA) {

             
                if((m + n) % 2 == 1)
                    return max(leftA, leftB);

                
                return (max(leftA, leftB) +
                        min(rightA, rightB)) / 2.0;
            }

   
            else if(leftA > rightB) {
                r = partitionA - 1;
            }

            else {
                l = partitionA + 1;
            }
        }

        return 0.0;
    }
};