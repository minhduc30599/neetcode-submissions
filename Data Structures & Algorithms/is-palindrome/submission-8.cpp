#include <string>

using namespace std;

// Mẹo 3: Tắt đồng bộ I/O trước khi hàm main() của hệ thống chạy
static const int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    // Mẹo 1: Đổi 'string s' thành 'const string& s' để triệt tiêu việc copy dữ liệu
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Mẹo 2: Tự kiểm tra ASCII thay vì dùng isalnum để bỏ qua overhead của C++ Locale
            while (left < right && !isAlphanumeric(s[left])) left++;
            while (left < right && !isAlphanumeric(s[right])) right--;

            if (left < right) {
                // Tự ép kiểu tolower bằng thao tác bit (chữ hoa và chữ thường cách nhau 32, tức là bit thứ 5)
                // Hoặc đơn giản là dùng ASCII math
                if (toLowerCase(s[left]) != toLowerCase(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }

private:
    // Hàm inline giúp code lồng thẳng vào vòng lặp, không tốn thời gian nhảy (jump) con trỏ hàm
    inline bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z') || 
               (c >= 'a' && c <= 'z') || 
               (c >= '0' && c <= '9');
    }

    inline char toLowerCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + 32; // Khoảng cách giữa 'A' (65) và 'a' (97) là 32
        }
        return c;
    }
};