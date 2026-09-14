class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); i++){
            if(isupper(word[i]) && islower(word[0])) return false;
            if(i > 1 && isupper(word[i]) != isupper(word[1])) return false;
        }
        return true;
    }
};