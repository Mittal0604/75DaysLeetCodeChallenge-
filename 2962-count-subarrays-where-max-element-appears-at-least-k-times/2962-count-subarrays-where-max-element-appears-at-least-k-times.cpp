class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        for(int x:nums) maxi=max(maxi,x);
        int n=nums.size();
        int l=0,count=0;  long long ans=0;
        for(int r=0;r<n;r++){
            if(nums[r]==maxi){
                count++;
                while(count>=k){
                    ans+=(n-r);
                    if(nums[l]==maxi) count--;
                    l++;
                }
            }
        }
        return ans;
    }
};