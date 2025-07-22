class Solution {
public:
    
    // int solve(string s){
    //     if(s.length()<1)return 1;
    //     if(s[0]=='0' ) return 0;
    //     if(s[0]!='0' && s.length()==1) return 1;


    //     int ans=0; 
    //     int n =s.length();
    //     ans+= solve(s.substr(1,n-1));
    //     if(s.length()>=2 && stoi(s.substr(0,2))< 27){
    //         ans+= solve(s.substr(2,n-2));
    //     }

    //     return ans;
    
    // }
    // int numDecodings(string s) {
    //     return solve(s);
    // }

    int solve(string s, unordered_map<string, int>& memo) {
        if (s.length() < 1) return 1;
        if (s[0] == '0') return 0;
        if (s[0] != '0' && s.length() == 1) return 1;

        // Check if the result for the current string is already memoized
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        int ans = 0;
        int n = s.length();
        ans += solve(s.substr(1), memo);
        if (s.length() >= 2 && stoi(s.substr(0, 2)) < 27) {
            ans += solve(s.substr(2), memo);
        }



        return memo[s]=ans;
    }

    int numDecodings(string s) {
        unordered_map<string, int> memo;
        return solve(s, memo);
    }

};