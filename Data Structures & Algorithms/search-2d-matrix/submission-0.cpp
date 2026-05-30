class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            int left = 0;
            int right = matrix[i].size() - 1;

            while (left <= right) {
                int middle = left + (right - left) / 2;

                if (target == matrix[i][middle]) {
                    return true;
                } else if (target > matrix[i][middle]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        
        return false;
    }
};
