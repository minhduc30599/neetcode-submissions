class Solution {
public:
    bool isPalindrome(string s) {
        string text;
        char left;
        char right;

        for (char t : s) {
            if (isalnum(t)) {
                text += t;
            }
        }

        for (int i = 0; i < text.length(); i++) {
            left = tolower(text[i]);
            right = tolower(text[text.length() - i - 1]);

            if (left != right) {
                return false;
            }
        }

        return true;
    }
};
