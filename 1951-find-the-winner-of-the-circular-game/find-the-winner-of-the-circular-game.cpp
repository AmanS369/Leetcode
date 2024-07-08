class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        int count=1;
        while(!q.empty() ){
            if(q.size()==1) return q.front();
            count ++;
            int round =1;
            while(!q.empty() && round < k){
                  int top = q.front();
                  q.pop();
                  q.push(top);
                  round++;
            }
            q.pop();
        }
      return q.front();
      
    }
};