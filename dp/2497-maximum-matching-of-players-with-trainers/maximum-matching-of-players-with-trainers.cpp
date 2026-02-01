class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end(),greater<int>());
        sort(t.begin(),t.end(),greater<int>());

        int i=0;
        int j=0;
        int ans =0;
        while(i< p.size() && j<t.size()){
            if(t[j] >= p[i]){
               
                ans+=1;
                j++;
               
            }
            i++;
        }
        return ans;
    }
};