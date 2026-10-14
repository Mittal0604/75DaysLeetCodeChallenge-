class Solution {
public:
    int dominantIndex(vector<int>& nums) {
     int largest = *max_element(nums.begin(),nums.end());
     int count = 0;
     for(int i = 0; i < nums.size(); i++){
        if(nums[i] != largest && nums[i] * 2 <= largest) count++; 
     }
     //int ans = -1;
     if(count == nums.size()-1) {
        for(int i = 0; i < nums.size(); i++){
            if(largest == nums[i]) return i;
        }
     }
     return -1;   
    }
};