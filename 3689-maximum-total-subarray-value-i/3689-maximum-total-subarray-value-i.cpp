class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int maxi=0;
       // long long ans=0;
        for(int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        return (long long)k*(maxi-mini);
    }
};