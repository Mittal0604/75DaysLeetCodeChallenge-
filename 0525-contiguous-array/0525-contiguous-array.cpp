class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),inc=0,ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x==1) inc++;
            else inc--;
            if(mp.count(inc)){
                ans=max(ans,i-mp[inc]);
            }
            if(!mp.count(inc)){
                mp[inc]=i;
            }
        }
        return ans;
    }
};