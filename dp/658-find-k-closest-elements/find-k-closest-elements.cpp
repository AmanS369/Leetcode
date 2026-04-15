class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>ans;
        pair<int,int>pos;
        pos ={0,arr[0]};
        for(int i=0;i<n;i++){
            if(abs(pos.second-x) > abs(x-arr[i])){
                pos = {i,arr[i]};
            }
        }

        int i= pos.first;
        int j=pos.first;
        ans.push_back(arr[i]);
        i--;
        j++;
        
        k--;
        while(k > 0){
    

            if(i>=0 && j<n){
                if(abs(x-arr[i]) > abs(x-arr[j])){
                 ans.push_back(arr[j]);
                  j++;
                }else{
                    ans.push_back(arr[i]);
                    i--;
                }
            }else{
                if(i>=0){
                  ans.push_back(arr[i]);
                  i--;
                }

                else if(j<n){
                    ans.push_back(arr[j]);
                    j++;
                }
            }
            k--;
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};