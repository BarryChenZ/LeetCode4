class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() <= 1) return ans;
        unordered_map<int,int> m; 
        
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 0;
            }
            m[nums[i]]++;
        }
        for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second > 1) ans.push_back(it->first);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};
