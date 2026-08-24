# 300. Longest Increasing Subsequence

## Pattern

1D Dynamic Programming

## Approach

1. Create a `dp` array where:

   dp[i] = length of the longest increasing subsequence ending at index i

2. Initialize every value to `1` because every element itself is an increasing subsequence.

3. For every element `i`, check all previous elements `j`.

4. If:

   nums[j] < nums[i]

   then `nums[i]` can be added after the increasing subsequence ending at `j`.

5. Update:

   dp[i] = max(dp[i], dp[j] + 1)

6. The answer is the maximum value in the `dp` array.

## Code

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

## Time Complexity

O(n²)

- For every element, we check all previous elements.

## Space Complexity

O(n)

- The `dp` array stores the LIS length ending at every index.

## Interview Note

- Think: "What is the longest increasing subsequence that can end at this element?"
- Only consider previous elements smaller than the current element.
- Key transition:

  dp[i] = max(dp[i], dp[j] + 1)

  when:

  nums[j] < nums[i]

- Every element starts with a subsequence length of `1`.
- There is also an O(n log n) binary-search solution, but the DP version is the important one to understand first.