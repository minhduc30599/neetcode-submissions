class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int left = prices[0];
        int right = prices[0];
        int result = right - left;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < left) {
                left = prices[i];
                right = prices[i];
            }

            if (i + 1 < prices.size() && prices[i + 1] > right) {
                right = prices[i + 1];
            }

            if (right - left > result) {
                result = right - left;
            }
        }
        return result;
    }
};
