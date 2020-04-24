class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        stack<int> s;
        vector<int> ans(size, -1);
        for(int i = 0; i < size * 2; i++){
            int num = nums[i % size]; 
            while(!s.empty() && nums[s.top()] < num){
                ans[s.top()] = num;
                s.pop();
            }
            if(i < size) s.push(i);
        }
        return ans;
    }
};
