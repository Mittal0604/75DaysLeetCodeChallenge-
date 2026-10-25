class Solution {
public:
    vector<int> digits;
    int dp[12][2][12];
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        n = s.size();
        digits.resize(n);
        for(int i = 0; i < n; i++) {
            digits[i] = s[i] - '0';
        }
        int answer = 0;
        for(int cnt = 1; cnt <= n; cnt++) {
            answer += cnt*solve(0,1,cnt);
        }
        return answer;
    }
    int solve(int pos, int tight, int cnt) {
        if (pos == digits.size()) return cnt == 0;
        if (dp[pos][tight][cnt] != -1) return dp[pos][tight][cnt];
        int ans = 0, limit = 9;
        if (tight == 1) limit = digits[pos];
        for (int digit = 0; digit <= limit; digit++) {
            int newCount = cnt;
            if (digit == 1) newCount--;
            if (newCount < 0) continue;
            int newTight = 0;
            if (tight == 1 && digit == limit) newTight = 1;
            ans += solve(pos+1, newTight, newCount);
        }
        return dp[pos][tight][cnt] = ans;
    }
};