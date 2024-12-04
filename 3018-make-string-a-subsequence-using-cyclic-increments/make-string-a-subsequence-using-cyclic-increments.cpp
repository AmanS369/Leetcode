class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int cnt =0;
        if(str1.size() < str2.size()) return false;
        for(int i=0;i<str1.size();i++){
           if(cnt >= str2.size()) return true;
           else if(str1[i] == str2[cnt]) cnt++;
           else if( str1[i] =='z' && str2[cnt]=='a') cnt++;
           else if(str1[i]+1 == str2[cnt])cnt++;

        }
        if(cnt < str2.size() ) return false;
        return true;
    }
};