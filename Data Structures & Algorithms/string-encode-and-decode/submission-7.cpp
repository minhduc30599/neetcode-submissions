class Solution {
   public:
    string encode(vector<string>& strs) {
        string code = "";
        for (int i = 0; i < strs.size(); i++) {
            code += strs[i] + to_string(strs[i].length()) + "#";
        }

        return code;
    }

    vector<string> decode(string s) {
        vector<string> results;
        string character = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                character += s[i];
            } else {
                if (isdigit(s[i - 1])) {
                    string text(1, s[i - 1]);
                    int num_index = i - 1;
                    int line = 1;
                    bool is_stop = false;
                    while (isdigit(s[num_index]) && !is_stop) {
                        if (character.length() - line == stoi(text)) {
                            character.erase(character.length() - line);
                            results.push_back(character);
                            character = "";
                            is_stop = true;
                        } else {
                            num_index--;
                            line++;
                            text = s[num_index] + text;
                        }
                    }
                } else {
                    character += s[i];
                }
            }
        }

        return results;
    }
};
