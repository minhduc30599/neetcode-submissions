class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        bool is_included_i = false;
                        int index_i;
                        bool is_included_j = false;
                        int index_j;
                        bool is_included_k = false;
                        int index_k;

                        for (int l = 0; l < results.size(); l++) {
                            for (int n = 0; n < results[l].size(); n++) {
                                if (results[l][n] == nums[i]) {
                                    is_included_i = true;
                                    index_i = n;
                                    break;
                                }
                            }

                            for (int n = 0; n < results[l].size(); n++) {
                                if (results[l][n] == nums[j] && n != index_i) {
                                    is_included_j = true;
                                    index_j = n;
                                    break;
                                }
                            }

                            for (int n = 0; n < results[l].size(); n++) {
                                if (results[l][n] == nums[k] && n != index_i && n != index_j) {
                                    is_included_k = true;
                                    index_k = n;
                                    break;
                                }
                            }

                            if (is_included_i && is_included_j && is_included_k) {
                                break;
                            } else {
                                is_included_i = false;
                                index_i = 0;
                                is_included_j = false;
                                index_j = 0;
                                is_included_k = false;
                                index_k = 0;
                            }
                        }

                        if (!is_included_i && !is_included_j && !is_included_k) {
                            results.push_back({nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
        }

        return results;
    }
};
