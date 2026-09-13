class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
     unordered_map<int,int>frq;
     unordered_map<int,int>first;
     unordered_map<int,int>last;
     for(int i = 0; i < nums.size(); i++){
        int c = nums[i];
        frq[c]++;
        if(first.find(c) == first.end()){
            first[c] = i;
        }
        last[c] = i;
     }
     int degree = 0;
     for(auto it : frq){
        degree = max(degree,it.second);
     }
     int ans = nums.size();
     for(auto it : frq) {
        int x = it.first;
        if(frq[x] == degree) {
            int length = last[x] - first[x] + 1;
            ans = min(ans, length);
        }
    }
    return ans;    
    }
};