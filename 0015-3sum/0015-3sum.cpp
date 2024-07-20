class Solution {
public:
    vector<vector<int>> ans;

    void twoPointer(vector<int>& nums, int l, int r, int ele, int target) {
        while (l < r) {
            if (nums[l] + nums[r] == target) {
                ans.push_back({ele, nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            } else if (nums[l] + nums[r] < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        ans.clear(); // Clear ans to handle multiple calls
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) { // nums.size() - 2 to avoid out of bounds
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            twoPointer(nums, i + 1, nums.size() - 1, nums[i], 0 - nums[i]);
        }
        return ans;
    }
};
