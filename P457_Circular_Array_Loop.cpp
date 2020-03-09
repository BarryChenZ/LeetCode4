class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        while(start < n){
            while(start < n && nums[start] == 1001) start++;
            if(start == n) return false;
            
            int direction = nums[start];
            int cur = start;
            int next;
            while(nums[cur] <= 1000){
                next = ((cur + nums[cur]) % n + n) % n;
                if(cur == next){
                    nums[cur] = 1001;
                    break;
                }
                if(nums[next] > 1001) return true;
                
                nums[cur] += 3000;
                if(nums[next] == 1001 || nums[next] * direction < 0){
                    break;
                }
                cur = next;
            }
            for(int i = start; i != next;){
                int tmp = nums[i];
                nums[i] = 1001;
                i = ((tmp - 3000 + i) % n + n) % n;
            }
        }
        return false;
    }
};
