class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> str_item(26, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                str_item[strs[i][j] - 'a']++;
            }

            string text = "";
            for (int k = 0; k < str_item.size(); k++) {
                text += to_string(str_item[k]) + '#';
            }
            map[text].push_back(strs[i]);
        }

        vector<vector<string>> results;
        for (auto& [key, value] : map) {
            results.push_back(std::move(value));
        }

        return results;
    }
};
