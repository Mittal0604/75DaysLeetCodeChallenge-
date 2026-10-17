class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, mini = INT_MAX, total = 0, i = 0;
        k = n-k;
        while (i<k) sum+= nums[i], total += nums[i],i++;
        mini = sum;
        while (i<n) {
            sum = sum + nums[i] - nums[i-k];
            mini = min(mini,sum);
            total += nums[i];
            i++;
        }
        // cout << mini <<  " " << total;
        return total - mini;
    }
};