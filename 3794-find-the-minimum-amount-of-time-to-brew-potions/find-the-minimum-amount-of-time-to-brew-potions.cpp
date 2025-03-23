class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long>prev(n,0);
        vector<long long>curr(n,0);


        for(int i =0;i<n;i++){
            prev[i] = (i == 0 ? 0 : prev[i-1]) + (long long)skill[i] * mana[0];
        }


        for(int k=1;k<m;k++){
         for(int i =0;i<n;i++){
            curr[i] = (i == 0 ? 0 : curr[i-1]) + (long long)skill[i] * mana[k];
           } 

           long long new_time=0;
           for(int i=0;i<n;i++){
             new_time = max(new_time,prev[i] - (i==0?0:curr[i-1]));
           }

            for(int i=0;i<n;i++){
             prev[i] = curr[i] + new_time;
           }


        }
        return prev[n-1];
    }
};