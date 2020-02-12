class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size(), -1);
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++){
            m[intervals[i][0]] = i;
        }
        for(int i = 0; i < intervals.size(); i++){
            int temp = intervals[i][1];
            auto ptr = m.lower_bound(temp);
            if(ptr != m.end()) ans[i] = ptr->second;
        }
        return ans;
    }
};
