class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;
        for( int x : nums){
            freq[x]++;
        }
        for(auto it : freq){
            if(it.second == 2){
                ans.push_back(it.first);
            }  
        }
        for(int i = 1; i <= nums.size(); i++){
            if(freq.find(i) == freq.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};