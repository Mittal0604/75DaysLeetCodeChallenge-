class Solution {
public:
    int arraySign(vector<int>& nums) {
       int product=1;
       for(int i=0;i<nums.size();i++){
        if(product*nums[i]>0){
            product=1;
        }
        else if(product*nums[i]<0){
            product=-1;
        }
        else{
            product=0;
        }
       }
       int ans=signFunc(product);
       return ans;
    }
    int signFunc(int p){
        int result;
        if(p>0) result=1;
        else if(p<0) result=-1;
        else result=0;
        return result;
    }
};