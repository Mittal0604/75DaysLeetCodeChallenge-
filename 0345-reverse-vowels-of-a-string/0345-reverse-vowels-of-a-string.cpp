class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
    
        while (left < right) {
            if (!isVowel(s[left])) {
                left++;
        } 
            else if (!isVowel(s[right])) {
                right--;
        } 
            else {
                swap(s[left], s[right]);
                left++;
                right--;
        }
    }
    return s;
    }
    bool isVowel(char c) {
    return c == 'a' || c == 'A' || c == 'e' || c == 'E' || 
           c == 'i' || c == 'I' || c == 'o' || c == 'O' || 
           c == 'u' || c == 'U';
}
};