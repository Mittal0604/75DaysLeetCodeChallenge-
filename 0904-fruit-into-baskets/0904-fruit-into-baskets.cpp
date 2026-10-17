class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size(), first = nums[0], maxi = 0, i = 0,l = 0;
        while (i<n && nums[i] == first) i++;
        if (i == n) return n;
        int second = nums[i];
        int firstO = i-1;
        int secondO = i;
        maxi = i+1;
        i++;
        while (i<n) {
            if (nums[i] == first || nums[i] == second) {
                if (nums[i] == first) firstO = i;
                else secondO = i;
                maxi = max(i-l+1,maxi);
                i++;
                continue;
            }
            l = min(firstO,secondO)+1;
            first = nums[l];
            firstO = i-1;
            secondO = i;
            second = nums[i];

            maxi = max(i-l+1,maxi);
            i++;
        }
        return maxi;
    }
};