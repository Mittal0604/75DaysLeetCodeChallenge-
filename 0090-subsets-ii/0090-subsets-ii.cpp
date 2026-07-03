class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubset(0,nums,ans,ds);
        return ans;
    }
   void findSubset(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        ans.push_back(ds);
        for(int i=ind; i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubset(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
};