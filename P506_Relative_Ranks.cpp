class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++) m[nums[i]] = i;
        
        vector<string> ans(nums.size(), "");
        int cnt = 1;
        for(map<int,int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++, cnt++){
            if(cnt == 1){
                ans[it->second] = "Gold Medal";
            }
            else if(cnt == 2){
                ans[it->second] = "Silver Medal";
            }
            else if(cnt == 3){
                ans[it->second] = "Bronze Medal";
            }
            else ans[it->second] = to_string(cnt);
        }
        return ans;
    }
};
