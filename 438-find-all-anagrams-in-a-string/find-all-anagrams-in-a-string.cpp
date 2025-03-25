class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return {};  

        unordered_map<char, int> og, window;
        vector<int> ans;

        
        for (char c : p) og[c]++;

        int left = 0, right = 0, required = og.size(), formed = 0;

        while (right < n) {
            char ch = s[right];
            window[ch]++;

            
            if (og.find(ch) != og.end() && window[ch] == og[ch])
                formed++;

          
            while (right - left + 1 > m) {
                char leftChar = s[left];
                if (og.find(leftChar) != og.end() && window[leftChar] == og[leftChar])
                    formed--;  
                window[leftChar]--;
                left++;
            }

           
            if (formed == required) ans.push_back(left);

            right++;  
        }

        return ans;
    }
};
