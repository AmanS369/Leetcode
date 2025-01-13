class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        int ans=0;
        for(auto i : s){
            mp[i]+=1; 
        }
        
        for(auto [key,value]:mp){
            if(value%2==0) ans+=2;
            else ans+=1;
        }
        return ans;
    }
};