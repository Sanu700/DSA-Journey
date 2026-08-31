# 53. Maximum Subarray

## Pattern

Greedy + 1D DP → Kadane's Algorithm

## Approach

1. Keep track of:

   curr = maximum subarray sum ending at the current index

   ans = maximum subarray sum found so far

2. For every element, we have two choices:

   - Start a new subarray from the current element
   - Extend the previous subarray

3. Therefore:

   curr = max(nums[i], curr + nums[i])

4. If the previous `curr` is negative, adding it to the current element only makes the sum worse.

   So we discard the previous subarray and start fresh.

5. Update the global answer:

   ans = max(ans, curr)

6. Return:

   ans

## Code

int maxSubArray(vector<int>& nums) {

    int curr = nums[0];
    int ans = nums[0];

    for(int i = 1; i < nums.size(); i++) {

        curr = max(nums[i], curr + nums[i]);

        ans = max(ans, curr);
    }

    return ans;
}

## Time Complexity

O(n)

- We traverse the array once.

## Space Complexity

O(1)

- We only maintain `curr` and `ans`.

## Interview Note

- Think **"Should I extend the previous subarray or start fresh?"**
- If the previous sum is negative, discard it because it can only decrease the future sum.
- DP formulation:

   dp[i] = max(nums[i], dp[i-1] + nums[i])

- Since we only need `dp[i-1]`, we optimize it to O(1) space.
- This optimized DP is known as **Kadane's Algorithm**.
- Interview explanation:

   **"At every index, I decide whether to continue the current subarray or start a new one. A negative running sum is harmful, so I discard it."**