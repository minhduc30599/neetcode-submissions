class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = (int)s.length() - 1;
        
        while (left < right) {
            char l = s[left], r = s[right];
            
            // Dùng bitwise để check + convert cùng lúc
            if (!isalnum(l)) { left++; continue; }
            if (!isalnum(r)) { right--; continue; }
            
            // tolower bằng bitwise OR (nhanh hơn function call)
            if ((l | 32) != (r | 32)) return false;
            
            left++; right--;
        }
        return true;
    }
};