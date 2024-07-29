class Solution {
public:
static bool cmp(const pair<char,int>&a , pair<char,int>&b){
    return a.second > b.second;
}
    string frequencySort(string s) {
        vector<pair<char,int>>vec;
        map<char,int>mp;
        for(char c :s){
            mp[c]+=1;
        }
        for(auto [key,value]:mp){
            vec.push_back({key,value});
        }
        sort(vec.begin(),vec.end(),cmp);
          
        string ans="";
        for(auto i:vec){
            
            while(i.second--){
                ans+=i.first;
            }
        }
        return ans;
    }
};