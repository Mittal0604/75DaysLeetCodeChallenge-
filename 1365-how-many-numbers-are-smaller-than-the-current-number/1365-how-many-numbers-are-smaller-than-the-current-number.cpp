class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int> ans;
       int  i = 0;
       while(i < nums.size()){
        int count = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] < nums[i] && j != i) count++;
        }
        ans.push_back(count);
        i++;
       }
       return ans; 
    }
};