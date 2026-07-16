class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int count=0, left=0, maxim=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            count++;
            while(count>k){
                if(nums[left]==0) count--;
                left++;
            }
        }
        maxim=max(maxim,(i-left+1));
      }
      return maxim;  
    }
};