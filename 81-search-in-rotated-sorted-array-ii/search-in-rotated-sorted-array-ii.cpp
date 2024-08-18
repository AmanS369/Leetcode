class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(target == arr[mid]) return true;
            //left
            if( arr[left] < arr[mid] ){

                if(target <= arr[mid] && target >= arr[left]){
                    right= mid-1;
                }else left = mid+1;

            }else if( arr[left] > arr[mid] ) {

                if(target >= arr[mid] && target <= arr[right]){
                    left = mid+1;
                }else right = mid-1;
            
            }else{
                left++;
            }
        }
        return false;
    }
};