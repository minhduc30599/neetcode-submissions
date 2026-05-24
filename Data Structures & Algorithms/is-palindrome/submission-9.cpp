class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Bước nhanh qua các ký tự không hợp lệ bên trái
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Bước nhanh qua các ký tự không hợp lệ bên phải
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Chỉ gọi tolower khi chắc chắn cả 2 đều là chữ/số
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }

        return true;
    }
};