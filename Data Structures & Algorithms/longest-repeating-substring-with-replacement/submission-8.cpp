class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int curr_max = 0;
        int result = 0;
        unordered_map<char, int> char_map;

        for (int right = 0; right < s.length(); right++) {
            int window_size = right - left + 1;
            char_map[s[right]]++;

            if (char_map.find(s[right]) == char_map.end()) {
                if (1 > curr_max) {
                    curr_max = 1;
                }
            } else {
                if (char_map[s[right]] > curr_max) {
                    curr_max = char_map[s[right]];
                }

                if (window_size - curr_max > k) {
                        char_map[s[left]]--;
                        left += 1;
                }
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
