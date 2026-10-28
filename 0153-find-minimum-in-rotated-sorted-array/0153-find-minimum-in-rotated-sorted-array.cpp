class Solution {
public:
    int findMin(vector<int>& nums) {
     int minimum = *min_element(nums.begin(),nums.end());
     return minimum;   
    }
};