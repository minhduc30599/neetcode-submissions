class Solution {
   public:
    int trap(vector<int>& height) {
        // int left = 0;
        // int right = left + 1;
        // int results = 0;
        // int temp = 0;
        // bool is_reverse = false;
        // int reverse_target = 0;

        // while (right < height.size()) {
        //     if (height[left] > height[right]) {
        //         temp += height[left] - height[right];
        //         right++;

        //         if (right == height.size() && height[left] > height[right - 1]) {
        //             is_reverse = true;
        //             reverse_target = left;
        //         }
        //     } else if (height[left] <= height[right]) {
        //         results += temp;
        //         temp = 0;
        //         left = right;
        //         right = right + 1;
        //     }
        // }

        // if (is_reverse) {
        //     left = height.size() - 1;
        //     right = left - 1;
        //     temp = 0;

        //     cout << reverse_target << endl;
        //     while (right >= reverse_target) {
        //         if (height[left] > height[right]) {
        //             temp += height[left] - height[right];
        //             right--;
        //         } else if (height[left] <= height[right]) {
        //             cout << temp << endl;
        //             results += temp;
        //             temp = 0;
        //             left = right;
        //             right = right - 1;
        //         }
        //     }
        // }

        // return results;

        int left = 0;
        int right = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        int results = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= max_left) {
                    max_left = height[left];
                } else {
                    results += max_left - height[left];
                }
                left++;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right];
                } else {
                    results += max_right - height[right];
                }
                right--;
            }
        }

        return results;
    }
};
