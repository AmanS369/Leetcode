class Solution {
public:
    string makeFancyString(string s) {
        char prev = '\0';   
        string ans = "";
        int cnt = 1;

        for (auto str : s) {
            if (ans.size() > 0 && prev == str && cnt == 2) 
                continue;  

            else if (ans.size() > 0 && prev == str && cnt == 1) {
                ans += str; 
                cnt += 1;
            } 

            else if (ans.size() == 0 || str != prev) {
                cnt = 1;     
                prev = str;
                ans += str; 
            }
        }

        return ans;
    }
};
