class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int i;
      for(i = nums.size()-2; i >= 0; i--){
        if(nums[i] < nums[i+1]) break;
      }
      if(i == -1){
        reverse(nums.begin(),nums.end());
        return;
      }
      int j = nums.size()-1;
      while(j > i){
        if(nums[j] > nums[i]) break;
        j--;
      }
      swap(nums[i],nums[j]);
      reverse(nums.begin()+i+1,nums.end());  
    }
};