class Solution {
public:
    bool isPalindrome(string s) {
        string text;
        char left;
        char right;
        regex pattern("[a-zA-Z0-9]");

        for (char t : s) {
            if (!isspace(t) && regex_search(string(1, t), pattern)) {
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
