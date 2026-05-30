class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int result = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = height * width;
                result = max(result, area);
            }
            st.push(i);

            if (i == heights.size() - 1) {
                while (!st.empty()) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i + 1 : i - st.top();
                    int area = height * width;
                    result = max(result, area);
                }
            }
        }

        return result;
    }
};
