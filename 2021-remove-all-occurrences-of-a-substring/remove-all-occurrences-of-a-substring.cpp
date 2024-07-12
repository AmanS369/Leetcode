class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        for(int i=0;i<s.size();i++){
            // cout<<ans<<endl;
            ans+=s[i];
            if(ans.size() >= part.size()){
                int size = ans.size();
                
                if(ans.substr(size - part.size(),part.size()) == part  ){
                   ans = ans.substr(0,size - part.size());         
                }



            }

              cout<<ans<<" "<<i<<endl;
        }

        return ans;
    }
};