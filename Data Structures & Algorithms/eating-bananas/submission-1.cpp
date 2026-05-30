class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        int result = 0;

        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > right) {
                right = piles[i];
            }
        }

        while (left <= right) {
            int middle = left + (right - left) / 2;
            int nums = 0;

            for (int i = 0; i < piles.size(); i++) {
                double n = static_cast<double>(piles[i]) / static_cast<double>(middle);

                if (n < 1) {
                    nums++;
                } else {
                    double m = ceil(n);
                    nums += static_cast<int>(m);
                }
            }

            if (nums > h) {
                left = middle + 1;
            } else {
                result = middle;
                right = middle - 1;
            }
        }

        return result;
    }
};
