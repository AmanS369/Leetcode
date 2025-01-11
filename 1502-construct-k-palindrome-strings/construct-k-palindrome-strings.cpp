class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()< k) return false;
        int oddCount =0;
   
        unordered_map<char,int>mp;
        for(auto i : s){
            mp[i]++;
        }
        for(auto [key,value]:mp){
            if(value%2!=0) oddCount++;
            
        }
return oddCount <= k;
        
    }
};