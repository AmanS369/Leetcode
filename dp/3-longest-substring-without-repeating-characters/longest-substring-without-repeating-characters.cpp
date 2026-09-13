class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans =0;
        while(j<n){
            char c = s[j];
            mp[c]+=1;
            if(mp[c]>1){
                while(mp[c] > 1 && i<=j){
                    mp[s[i]]-=1;
                    i++;
                }
            }
            ans = max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};