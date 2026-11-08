class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool exist[26] = {false};
        for(const char ch : sentence) {
            exist[ch - 'a'] = true;
        }
        for(bool ch : exist) {
            if(!ch) return false;
        }
        return true;
    }
};