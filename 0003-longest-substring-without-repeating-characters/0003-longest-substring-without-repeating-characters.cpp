class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int maxi = 0, l = 0;
        for (int i = 0;i<n;i++) {
            char c = s[i];
            while (set.count(c)) {
                set.erase(s[l]);
                l++;
            }
            maxi = max(maxi,i-l+1);
            set.insert(c);
        } 
        maxi = max(maxi,n-l);
        return maxi; 
    }
};