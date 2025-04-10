class Solution {
public:

   
    int solve(string s, int k) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

       
        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i]] < k) {
                
                int left = solve(s.substr(0, i), k);
                int right = solve(s.substr(i + 1), k);
                return max(left, right);
            }
        }
        return s.length();
    }

    int longestSubstring(string s, int k) {
        return solve(s, k);
    }
};
