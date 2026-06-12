class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<pair<long,long>> stack;
        stack.push_back({0,-1});
        long prefix = 0; int n = nums.size();
        long ans = INT_MAX;
        for (int i = 0;i<n;i++) {
            prefix += nums[i];
            while (stack.size() > 0 && stack.back().first > prefix) {
                stack.pop_back();
            }
            long target = prefix - k;
            int id = binarySearch(stack,target);
            if (id != -1 ) {
                ans = min(ans,i - stack[id].second);
            }
            stack.push_back({prefix,i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
    int binarySearch(vector<pair<long,long>>& nums,int target) {
        int l =0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (nums[mid].first <= target) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};