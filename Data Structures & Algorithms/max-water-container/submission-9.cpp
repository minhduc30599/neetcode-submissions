class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int results = 0;

        while (left < right) {
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int temp = width * height;
            results = max(results, temp);

            if (heights[left] < heights[right]) {
                left++;
            } else if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
                right--;
            }
        }

        return results;
    }
};
