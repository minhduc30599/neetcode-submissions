class Solution {
   public:
    string encode(vector<string>& strs) {
        string code = "";
        for (int i = 0; i < strs.size(); i++) {
            code += to_string(strs[i].length()) + "#" + strs[i];
        }

        return code;
    }

    vector<string> decode(string s) {
        vector<string> results;
        int i = 0;

        while (i < s.length()) {
            int j = s.find("#", i);
            int length = stoi(s.substr(i, j - i));
            string text = s.substr(j + 1, length);
            results.push_back(text);
            i = j + 1 + length;
        }

        return results;
    }
};