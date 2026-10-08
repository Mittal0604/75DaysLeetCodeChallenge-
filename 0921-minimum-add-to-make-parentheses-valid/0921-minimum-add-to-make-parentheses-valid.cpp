class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' && count >= 0) count++;
            else if(s[i] == '(' && count < 0) ans += abs(count), count = 1;
            else if(s[i] == ')') count--;
        }
        return ans + abs(count);
    }
};