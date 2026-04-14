class Solution {
public:
   int longestBalanced(string s) {
int n=s.size();
int ones=0,zeros=0;
for(char i:s){
if(i=='1')ones++;
else zeros++;
}

    vector<int> ps(n+1,0);  
    for(int i=0;i<n;i++){  
        if(s[i]=='1')ps[i+1]=ps[i]+1;  
        else ps[i+1]=ps[i]-1;              
    }  
    unordered_map<int,vector<int>> mp;  
    for(int i=0;i<=n;i++){  
        mp[ps[i]].push_back(i);  
    }  
    int ans=0;  
    for(int j=1;j<=n;j++){  
        int p=ps[j];  
        if(mp.find(p)!=mp.end() &&mp[p][0]<j){  
            ans=max(ans,j-mp[p][0]);  
        }  
        if(mp.find(p-2)!=mp.end()){  
            vector<int>& v=mp[p-2];  
            auto a=lower_bound(v.begin(),v.end(),j-2*zeros);  
            if(a!=v.end()&&*a<j){  
                ans=max(ans,j-*a);  
            }  
        }  
        if(mp.find(p+2)!=mp.end()){  
            vector<int>& v=mp[p+2];  
            auto a=lower_bound(v.begin(),v.end(),j-2*ones);  
            if(a!=v.end()&&*a<j){  
                ans=max(ans,j-*a);  
            }  
        }  
    }  
    return ans;  
      
}
};