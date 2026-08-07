class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;          // stores indices
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {

                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        // Process remaining bars
        while(!st.empty()) {

            int height = heights[st.top()];
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = n - left - 1;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
