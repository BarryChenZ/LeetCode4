class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(count > res) res = count;
                count = 0;
            }
            else{
                count++;
            }
        }
        return (count > res)? count : res;
    }
};
