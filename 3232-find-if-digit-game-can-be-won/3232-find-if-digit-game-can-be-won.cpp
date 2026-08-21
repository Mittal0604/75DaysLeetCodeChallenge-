class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
       int w1=0, w2=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<10){
            w1+=nums[i];
        }
        else w2+=nums[i];
       }
       return w1 != w2 ? true : false; 
    }
};