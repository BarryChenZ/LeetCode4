class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) sum += i;
        if(sum % 2) return false;
        sort(nums.begin(), nums.end());
        return dfs(nums, nums.size() - 2, nums[nums.size() - 1], sum / 2);
    }
    bool dfs(vector<int>& nums, int i, int acc, int t){
        if(acc == t) return true;
        if(acc > t || i < 0) return false;
        return dfs(nums, i - 1, acc + nums[i], t) || dfs(nums, i - 1, acc, t);
    }
};
