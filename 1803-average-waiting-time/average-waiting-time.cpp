class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int prevWait = -1;
        double avgSum =0;
        for(int i=0;i<customers.size();i++){
            if(prevWait!=-1 && prevWait > customers[i][0]  ){
                prevWait = prevWait +  customers[i][1];
                
            }else{
                prevWait = customers[i][1] + customers[i][0];
                
            }
           
            avgSum += prevWait - customers[i][0] ;
        }
        return (double)(avgSum/customers.size());
    }
};