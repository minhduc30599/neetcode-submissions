class TimeMap {
   private:
    unordered_map<string, vector<int>> result_map;
    unordered_map<string, string> value_map;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (result_map.find(key) == result_map.end()) {
            result_map.insert({key, {timestamp}});
        } else {
            result_map[key].push_back(timestamp);
        }

        value_map.insert({key + to_string(timestamp), value});
    }

    string get(string key, int timestamp) {
        if (result_map.find(key) != result_map.end()) {
            vector<int> val = result_map[key];
            int left = 0;
            int right = val.size() - 1;
            string result = "";
            int largest_num = 0;

            while (left <= right) {
                int middle = left + (right - left) / 2;

                if (result_map[key][middle] == timestamp) {
                    return value_map[key + to_string(timestamp)];
                } else if (result_map[key][middle] > timestamp) {
                    right = middle - 1;
                } else {
                    result = value_map[key + to_string(result_map[key][middle])];
                    left = middle + 1;
                }
            }

            return result;
        }

        return "";
    }
};
