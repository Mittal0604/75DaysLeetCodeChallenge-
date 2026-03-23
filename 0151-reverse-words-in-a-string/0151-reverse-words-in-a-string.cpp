class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int i = 0, n = s.size();
        int l = 0; // index to place characters

        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            if (l != 0) s[l++] = ' ';

            int j = i;

            // find word
            while (j < n && s[j] != ' ') j++;

            // reverse word
            reverse(s.begin() + i, s.begin() + j);

            // copy word
            while (i < j) {
                s[l++] = s[i++];
            }
        }
         s.resize(l);
        return s;
    }
};