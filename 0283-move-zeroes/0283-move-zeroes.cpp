class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int l=nums.size();int lastele=0;
      for(int i=0;i<l;i++){
        if(nums[i]!=0){
            swap(nums[lastele],nums[i]);
            lastele++;
        }
    }
    }
};