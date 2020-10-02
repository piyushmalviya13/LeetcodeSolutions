class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> dp[target+1];
        vector <int> temp;
        dp[0].push_back(temp);
        
        for(auto j:candidates) {
            for(int i = 0;i<target+1;i++) {
                if(i-j >= 0) {
                    for(auto k:dp[i-j]) {
                        vector <int> temp(k.begin(), k.end());
                        temp.push_back(j);
                        dp[i].push_back(temp);
                    }
                }
            }
        }
        
        return dp[target];
    }
};
