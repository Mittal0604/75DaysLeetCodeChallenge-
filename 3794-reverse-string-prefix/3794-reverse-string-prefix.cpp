class Solution {
public:
    string reversePrefix(string s, int k) {
        int l = 0,r = k-1;
        while(l<r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;r--;
        }
        return s;
    }
};