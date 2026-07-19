class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_id(26, 0);
        vector<bool> seen(26, false);
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            last_id[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (seen[ch - 'a']) continue;
            while (!result.empty() && result.back() > ch && last_id[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            seen[ch - 'a'] = true;
        }
        return result;
    }
};