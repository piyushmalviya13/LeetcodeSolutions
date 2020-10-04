class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        int ans = 1;
        int end = intervals[0][1];
        int beg = intervals[0][0];
        for(int i = 1;i<n;i++) {
            if(intervals[i][1] <= end && intervals[i][0] >= beg) {
                continue;
            }
            else if(intervals[i][1] >= end && intervals[i][0] <= beg) {
                 beg = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                beg = intervals[i][0];
                end = intervals[i][1];
                ans++;
            }
            
        }
        
        return ans;
    }
};
