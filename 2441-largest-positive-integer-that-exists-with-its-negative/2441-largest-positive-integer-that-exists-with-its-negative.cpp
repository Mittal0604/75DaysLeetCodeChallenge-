class Solution {
public:
    int findMaxK(vector<int>& nums) {
      sort(nums.begin(), nums.end());
    //   if(nums[0] > -1 || nums[nums.size()-1] < 0) return -1;
      int left = 0, right = nums.size() - 1, ans = -1;
      while(left < right){
        if(nums[left] > -1) break;
        if(abs(nums[left]) == nums[right]){
            ans = nums[right];
            break;
        }
        else if(abs(nums[left]) < nums[right]) right--;
        else left++;
      }
      return ans;  
    }
};