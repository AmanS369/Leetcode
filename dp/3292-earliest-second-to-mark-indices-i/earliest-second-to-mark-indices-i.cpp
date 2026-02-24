class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, int idx){
        unordered_map<int, int> lastIndex;
        for(int i=0;i<idx;i++){
            lastIndex[changeIndices[i]] = i;
        }

        // calcualte the last second (limi) of every index in the changeIndices
        // and before that just calculate how much second u have to decrese
        // for ex. if idx == 1 is 2 in the nums , then it requires atleast 2 second after it can be marked , so the last position in the changeIndices of 1 should be atleast greater than 3 

        // if last positon of 1 is less than the second require to make it zero then decrease it 
        //eevery time u come to a positon which is not equal to that indices jut increaemtn your seocn
        if(lastIndex.size()!=nums.size()) return false;
        int cnt=0;
        for(int i=0;i<idx;i++){
            if(i == lastIndex[changeIndices[i]]){
                if(cnt < nums[changeIndices[i] -1]) return false;
                else cnt = cnt - nums[changeIndices[i] -1]; // sinc 1- indexing
            }
            else cnt ++;
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        int l=0,r = m+1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(isPossible(nums,changeIndices,mid)){
                r = mid;
            }else l = mid+1;
        }
        return r == m +1 ? -1:r;
    }
};