class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_vector(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            s1_vector[s1[i] - 'a']++;
        }

        int left = 0;
        vector<int> s2_vector(26, 0);

        for (int right = 0; right < s2.length(); right++) {
            int length = right - left + 1;
            s2_vector[s2[right] - 'a']++;

            if (length < s1.length()) {
                continue;
            } else if (length > s1.length()) {
                s2_vector[s2[left] - 'a']--;
                left++;
            }
    
            if (s1_vector == s2_vector) {
                return true;
            }
        }

        return false;
    }
};
