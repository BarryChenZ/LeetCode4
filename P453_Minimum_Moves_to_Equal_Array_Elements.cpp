class Solution {
public:
    int minMoves(vector<int>& nums) {
        multiset<int> s;
        int mini = *min_element(nums.begin(),nums.end());
        int ans = 0;
        for(int u : nums)
            ans += u - mini;
        return ans;
    }
};
