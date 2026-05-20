class Solution {
public:
  int n;
    vector<int> dp;

    bool isValid(vector<int>& freq) {
        int val = 0;

        for (int x : freq) {
            if (x == 0) continue;

            if (val == 0)
                val = x;
            else if (val != x)
                return false;
        }

        return true;
    }

    int solve(int i,string &s){
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        vector<int> freq(26, 0);

        int ans = 1e9;
        for (int j = i; j < n; j++) {

            freq[s[j] - 'a']++;

            // check if current substring s[i..j] is valid
            if (isValid(freq)) {
                ans = min(ans, 1 + solve(j + 1, s));
            }
        }

        return dp[i] = ans;

    }


    int minimumSubstringsInPartition(string s) {
        n = s.size();

        dp.resize(n, -1);

        return solve(0, s); 
    }
};