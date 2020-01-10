class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Sort array
	sort(nums.begin(), nums.end());

	// Remove any duplicates
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	// If there are less than 3 elements remaining, return the highest value
	if (nums.size() < 3)
		return *max_element(nums.begin(), nums.end());
	else
		return nums[nums.size() - 3];
    }
};
