class Solution {
public:
    int start=0;
    int ans=1;
    string longestPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            expand(i,i,s,n);
            expand(i,i+1,s,n);
        }
        return s.substr(start,ans);
    }
    void expand(int l,int r,string& s,int n){
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>ans){
                start=l;
                ans=r-l+1;
            }
            l--;
            r++;
        }
    }
};