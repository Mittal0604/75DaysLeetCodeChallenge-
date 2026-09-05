class Solution {
public:
    string reverseWords(string s) {
        int x = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i == s.size()-1) reverse(s.begin()+x,s.begin()+i+1);
            else if(s[i] == ' ') {
                reverse(s.begin()+x,s.begin()+i);
                x = i+1;
            }
        }
        return s;
    }
};