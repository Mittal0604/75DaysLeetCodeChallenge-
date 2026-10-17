class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> frq(256,-1);
        int n = s.size();
        int maxi = 0, l = 0, ans = 0;
        for (int i = 0;i<n;i++) {
            char c = s[i];
            if(frq[c] >= l) {
                l = frq[c] + 1;
            }
            frq[c] = i;
            maxi = i-l+1;
            ans = max(ans,maxi);
        } 
        return ans; 
    }
};