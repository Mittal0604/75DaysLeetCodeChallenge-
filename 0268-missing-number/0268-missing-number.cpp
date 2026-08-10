class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            if(s.find(i)==s.end()){
                ans=i;
            }
        }
        return ans;
    }
};