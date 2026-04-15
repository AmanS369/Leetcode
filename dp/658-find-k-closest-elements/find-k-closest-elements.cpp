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
        int t=k;
        k--;
        while(k > 0){
    

            if(i>=0 && j<n){
                if(abs(x-arr[i]) > abs(x-arr[j])){
              
                  j++;
                }else{
                  
                    i--;
                }
            }else{
                if(i>=0){
                  i--;
                }

                else if(j<n){
                    j++;
                }
            }
            k--;
        }

    return vector<int>(arr.begin() + i + 1, arr.begin() + i + 1 + t );

    }


    
};


// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int left = 0, right = arr.size() - k;

//         while (left < right) {
//             int mid = left + (right - left) / 2;

//             if (x - arr[mid] > arr[mid + k] - x) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }

//         return vector<int>(arr.begin() + left, arr.begin() + left + k);
//     }
// };