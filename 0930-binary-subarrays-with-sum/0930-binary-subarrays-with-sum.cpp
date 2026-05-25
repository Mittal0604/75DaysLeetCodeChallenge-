class Solution {
public:
        int find(vector<int>& nums, int goal){
            int n=nums.size();
        int count=0,left=0,right=0;
        int sum=0;
        while(right<n){
            sum+=nums[right];
            while(left<=right && sum > goal){
                sum-=nums[left]; 
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
        }
         int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find(nums, goal) - find(nums, goal - 1);
    }
};