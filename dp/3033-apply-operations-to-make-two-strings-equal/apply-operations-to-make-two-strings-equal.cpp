class Solution {
public:

    const int INF = 1e9;

    int dp[505][2];

    int solve(int i,
              bool pending,
              string &s1,
              string &s2,
              int x) {

        int n = s1.size();

        // finished traversal
        if (i == n) {

            // no pending mismatch left
            if (!pending) return 0;

            return INF;
        }

        if (dp[i][pending] != -1)
            return dp[i][pending];

        int ans = INF;

        // current chars already equal
        if (s1[i] == s2[i]) {

            ans = solve(i + 1,
                        pending,
                        s1,
                        s2,
                        x);
        }
        else {

            // mismatch exists

            // OPTION 1:
            // use adjacent operation
            // flips i and i+1
            if (i + 1 < n) {

                s1[i] = (s1[i] == '0') ? '1' : '0';
                s1[i + 1] = (s1[i + 1] == '0') ? '1' : '0';

                ans = min(ans,
                          1 + solve(i + 1,
                                    pending,
                                    s1,
                                    s2,
                                    x));

                // backtrack
                s1[i] = (s1[i] == '0') ? '1' : '0';
                s1[i + 1] = (s1[i + 1] == '0') ? '1' : '0';
            }

            // OPTION 2:
            // use global operation pairing

            if (pending) {

                // close previous pending mismatch
                ans = min(ans,
                          x + solve(i + 1,
                                    false,
                                    s1,
                                    s2,
                                    x));
            }
            else {

                // start pending mismatch
                ans = min(ans,
                          solve(i + 1,
                                true,
                                s1,
                                s2,
                                x));
            }
        }

        return dp[i][pending] = ans;
    }

    int minOperations(string s1,
                      string s2,
                      int x) {

        int mismatch = 0;

        for (int i = 0; i < s1.size(); i++) {

            if (s1[i] != s2[i])
                mismatch++;
        }

        // impossible
        if (mismatch % 2)
            return -1;

        memset(dp, -1, sizeof(dp));

        return solve(0,
                     false,
                     s1,
                     s2,
                     x);
    }
};