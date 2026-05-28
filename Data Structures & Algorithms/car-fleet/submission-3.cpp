class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result = 0;
        int n = position.size();
        stack<double> st;
        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = { position[i], speed[i] };
        }

        sort(vec.rbegin(), vec.rend());

        for (int i = 0; i < n; i++) {
            double time = (double)(target - vec[i].first) / vec[i].second;

            if (st.empty() || !st.empty() && st.top() < time) {
                result++;
                st.push(time);
            }
        }

        return result;
    }
};
