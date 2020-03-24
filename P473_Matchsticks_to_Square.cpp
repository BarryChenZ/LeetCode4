class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4) return false;
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, 0, 0, 0, sum / 4);
    }
    
    bool dfs(vector<int>& nums, int sum, int status, int sides, int target){
        int n = nums.size();
        if(status == (1 << n) - 1) return sides == 4; //使用完最後一個
        
        for(int i = 0; i < n; i++){
            if(status & (1 << i)) continue;
            int sum_ = sum;
            int sides_ = sides;
            if(sum + nums[i] > target) return false;
            if(sum + nums[i] == target){
                sum_ = 0;
                sides_++;
            }
            else{
                sum_ += nums[i];
            }
            if(dfs(nums, sum_, status | (1 << i), sides_, target)) return true;
        }
        return false;
    }
};
