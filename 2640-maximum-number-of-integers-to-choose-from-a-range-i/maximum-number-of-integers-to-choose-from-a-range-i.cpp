class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st;
        for(auto i:banned)st.insert(i);
        long long sum =0;
        int i=1;
        int cnt=0;
        while(sum < maxSum && i<=n){
            if(st.count(i)==0){
                if(sum+i <= maxSum) {
                    sum+=i;cnt++;
                    cout<<i<<" ";
                 }
            }
            i++;
            
        }
        return cnt;
    }
};