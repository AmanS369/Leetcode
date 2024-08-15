class Solution {
    public boolean lemonadeChange(int[] bills) {
        int single=0;
        int ten =0;
        int twenty = 0;
        for(int i=0;i<bills.length;i++){
            if(bills[i] == 5){
                single+=1;
            }else if(bills[i] == 10){
                if(single > 0 ){
                    single-=1;
                    ten+=1;
                }else return false;
            }else if(bills[i] == 20){
                if(ten>0 && single >0){
                    ten-=1;
                    single-=1;
                }else if(single >= 3){
                    single-=3;
                }else return false;
            }
        }
        return true;
    }
}