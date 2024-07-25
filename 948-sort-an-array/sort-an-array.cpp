class Solution {
public:
    void merge(int s, int mid, int e, vector<int>& arr) {
        int i = s;
        int j = mid + 1;
        int k = 0;
        vector<int> tempArr(e - s + 1); 
        
        while (i <= mid && j <= e) {
            if (arr[i] <= arr[j]) {
                tempArr[k++] = arr[i++];
            } else {
                tempArr[k++] = arr[j++];
            }
        }
        
      
        while (i <= mid) {
            tempArr[k++] = arr[i++];
        }
        
    
        while (j <= e) {
            tempArr[k++] = arr[j++];
        }
        
      
        for (int k = 0; k < tempArr.size(); ++k) {
            arr[s + k] = tempArr[k];
        }
    }

    void mergeSort(int s, int e, vector<int>& nums) {
        if (s >= e) return;
        int mid = s + (e - s) / 2;
        mergeSort(s, mid, nums);
        mergeSort(mid + 1, e, nums);
        merge(s, mid, e, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};
