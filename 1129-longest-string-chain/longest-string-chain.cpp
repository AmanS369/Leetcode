class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        int maxLength = 1;

       
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        for (const string &str : words) {
            mp[str] = 1; 

            for (int j = 0; j < str.size(); j++) {
                string preStr = str.substr(0, j) + str.substr(j + 1);
                
                if (mp.find(preStr) != mp.end()) {  
                    mp[str] = max(mp[str], mp[preStr] + 1);
                }
            }

            maxLength = max(maxLength, mp[str]);
        }
        
        return maxLength;
    }
};