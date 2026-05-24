class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) {
            return false;
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            char char_left = tolower(s[left]);
            char char_right = tolower(s[right]);

            if (!isalnum(char_left)) {
                left++;
            } else if (!isalnum(char_right)) {
                right--;
            } else {
                if (char_left != char_right) {
                    return false;   
                }
                left++;
                right--;
            }
        }

        return true;
    }
};
