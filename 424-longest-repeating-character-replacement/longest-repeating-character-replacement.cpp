class Solution {
public:
    unordered_map<int,int>mp;
    int maxCnt(){
        int cnt=0;
        for(auto [ key,value]:mp){
            cnt = max(cnt,value);
        }
        return cnt;
    }
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int n = s.size();
        int mx = 0;
        
        while(j<n){
            mp[s[j]]+=1;
            int cnt = maxCnt();
            if( cnt + k >= j-i+1 ){
               mx = max(mx,j-i+1);
               
            }else{
                mp[s[i]]-=1;
                i++;
            }
            j++;
        }
        // int cnt = maxCnt();

        //  if( cnt + k >= j-i+1 ){
        //        mx = max(mx,j-i);
        //     }
        return mx;
    }
};