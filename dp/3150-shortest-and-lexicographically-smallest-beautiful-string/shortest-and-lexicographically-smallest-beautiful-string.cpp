class Solution {
public:
    string comp(string a, string b) {
        if (a.empty()) return b;
        if (b.length() < a.length()) {
            return b;
        }
        if (b.length() == a.length() && b < a) {
            return b;
        }

        return a;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int curr = 0;

        string ans = "";

        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                curr++;
            }
            while (curr > k) {
                if (s[i] == '1') {
                    curr--;
                }
                i++;
            }

            // Exactly k ones
            if (curr == k) {
                while (i <= j && s[i] == '0') {
                    i++;
                }
                string candidate = s.substr(i, j - i + 1);
                ans = comp(ans, candidate);
            }
        }

        return ans;
    }
};