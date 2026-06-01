class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0;
        int right = nums1.size();
        int m = nums1.size();
        int n = nums2.size();

        while (left <= right) {
            int part_a = left + (right - left) / 2;
            int part_b = (m + n + 1) / 2 - part_a;

            int max_left_a = part_a == 0 ? INT_MIN : nums1[part_a - 1];
            int min_right_a = m - part_a == 0 ? INT_MAX : nums1[part_a];
            int max_left_b = part_b == 0 ? INT_MIN : nums2[part_b - 1];
            int min_right_b = n - part_b == 0 ? INT_MAX : nums2[part_b];

            if (max_left_a <= min_right_b && max_left_b <= min_right_a) {
                if ((m + n) % 2 == 0) {
                    return static_cast<double>(max(max_left_a, max_left_b) + min(min_right_a, min_right_b)) / 2.0;
                } else {
                    return max(max_left_a, max_left_b);
                }
            } else if (max_left_a > min_right_b) {
                right = part_a - 1;
            } else {
                left = part_a + 1;
            }
        }

        return 0.0;
    }
};
