class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        int start=-1;
        int size=INT_MAX;

        unordered_map<char, int> og;  
        unordered_map<char, int> mp; 

        for (char c : t) og[c]++;  

        int i = 0, j = 0;
        int cnt = og.size();
        string ans = "";

        while (j < n) {
            char ch = s[j];
            mp[ch]++;

            if (og.find(ch) != og.end()) {
                if (mp[ch] == og[ch]) cnt--;
            }

            while (i <= j && cnt == 0) {
                if(size > j-i+1){
                    size = j-i+1;
                    start = i;
                }

                mp[s[i]]--;

                if (og.find(s[i]) != og.end()) {
                    if (mp[s[i]] < og[s[i]]) cnt++;
                }
                i++;
            }
            j++;
        }
        if(start==-1) return "";
        return s.substr(start,size);
    }
};
