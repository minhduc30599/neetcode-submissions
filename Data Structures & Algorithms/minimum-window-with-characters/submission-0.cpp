class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_map(128, 0);
        int need = 0;

        for (int i = 0; i < t.length(); i++) {
            if (t_map[t[i]] == 0) {
                need++;
            }
            t_map[t[i]]++;
        }

        int left = 0;
        vector<int> s_map(128, 0);
        int have = 0;
        int min_length = INT_MAX;
        int start_index = 0;

        for (int right = 0; right < s.length(); right++) {
            s_map[s[right]]++;

            if (t_map[s[right]] > 0 && s_map[s[right]] == t_map[s[right]]) {
                have++;
            }

            while (need == have) {
                if (min_length > right - left + 1) {
                    start_index = left;
                    min_length = right - left + 1;
                }

                s_map[s[left]]--;

                if (t_map[s[left]] > 0 && s_map[s[left]] < t_map[s[left]]) {
                    have--;
                }
                
                left++;
            }
        }

        return min_length == INT_MAX ? "" : s.substr(start_index, min_length);
    }
};
