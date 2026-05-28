class Solution {
   public:
    bool isNumber(const std::string& s) {
        if (s.empty()) return false;

        size_t pos;
        try {
            std::stod(s, &pos);  // Chuyển chuỗi thành double
            // Nếu số ký tự chuyển đổi được bằng chính độ dài của chuỗi -> chuỗi hợp lệ
            return pos == s.length();
        } catch (const std::invalid_argument&) {
            // Không có số nào được tìm thấy
            return false;
        } catch (const std::out_of_range&) {
            // Số quá lớn hoặc quá nhỏ
            return false;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int result;

        for (string a : tokens) {
            if (isNumber(a)) {
                st.push(a);
            } else {
                if (a == "+") {
                    int b = stoi(st.top());
                    st.pop();
                    int a = stoi(st.top());
                    st.pop();
                    result = a + b;
                    st.push(to_string(result));
                } else if (a == "-") {
                    int b = stoi(st.top());
                    st.pop();
                    int a = stoi(st.top());
                    st.pop();
                    result = a - b;
                    st.push(to_string(result));
                } else if (a == "*") {
                    int b = stoi(st.top());
                    st.pop();
                    int a = stoi(st.top());
                    st.pop();
                    result = a * b;
                    st.push(to_string(result));
                } else if (a == "/") {
                    int b = stoi(st.top());
                    st.pop();
                    int a = stoi(st.top());
                    st.pop();
                    result = a / b;
                    st.push(to_string(result));
                }
            }
        }

        return stoi(st.top());
    }
};
