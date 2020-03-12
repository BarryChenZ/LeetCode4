class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n % 2 != 0) return count(nums, nums[(n-1)/2]);
        else{
            return min(count(nums, nums[n/2-1]),count(nums, nums[n/2]));
        }
    }
    int count(vector<int>& nums, int num){
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++){
            tmp += abs(nums[i] - num);  
        }
        return tmp;
    }
};
