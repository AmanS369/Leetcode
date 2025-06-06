class Solution {
public:
        int n = 0;
        int m = 0;
            int ans =0;

    int rangePalindrome(string s,string t){

        vector<int>maxT(m,0);
        vector<int>maxS(n,0);

        vector<vector<bool>>dpS(n,vector<bool>(n,false));
        vector<vector<bool>>dpT(m,vector<bool>(m,false));

        for(int i = n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                dpS[i][j] = (j-i==0) || (j==i+1 && (s[i]==s[j])) || (dpS[i+1][j-1] && (s[i]==s[j]));
                if(dpS[i][j]){
                    maxS[i] = max(maxS[i],j-i+1);
                    ans = max(ans,j-i+1);
                }
            }
        }


        for(int i = m-1;i>=0;i--){
            for(int j=i;j<m;j++){
                dpT[i][j] = (j==i) || (j==i+1 && (t[i]==t[j])) || (dpT[i+1][j-1] && (t[i]==t[j]));
                if(dpT[i][j]){
                    maxT[j] = max(maxT[j],j-i+1);
                    ans = max(ans,j-i+1);
                }
            }
        }


        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    if(i>0 && j< m - 1){
                        dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 2 ) ;
                    }else dp[i][j] = 2;
                    int extra =0;
                    if(i+1< n) extra = max(extra,maxS[i+1]);
                    if(j-1 >=0 ) extra = max(extra,maxT[j-1]);
                     ans = max( ans , dp[i][j] + extra);
                    
                }
            }
        }
        return ans;

    }


 
    int longestPalindrome(string s, string t) {
         n = s.size();
        m = t.size();
        return rangePalindrome(s,t);
    }
};