class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, n = nums.size(), ans = INT_MAX, sum = 0;
        for (int i = 0;i<n;i++) {
            sum += nums[i];
            while (sum >=target) {
                ans = min(ans,i-left+1);
                sum -= nums[left]; left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};