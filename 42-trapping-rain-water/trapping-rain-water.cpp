class Solution {
public:
    int trap(vector<int>& h) {
        int n =h.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        for(int i=0;i<n;i++){
            if(i==0)left[i] = h[i];
            else left[i] = max(h[i],left[i-1]);
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1)right[i] = h[i];
            else right[i] = max(h[i],right[i+1]);
        }

        int water=0;
        for(int i=1;i<n-1;i++){
            if(left[i] > h[i] && right[i]>h[i]) water = water + min(right[i],left[i])-h[i];
        }
        return water;

    }
};