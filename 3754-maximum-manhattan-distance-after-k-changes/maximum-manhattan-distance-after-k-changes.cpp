
class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        for (char hor : {'E', 'W'}) {
            for (char ver : {'N', 'S'}) {
               int rem = k;
               int X=0;
               int Y=0;
               for(auto ch : s){
                 if( ch == 'W' || ch=='E'){
                    if(ch != hor && rem){
                        ch = hor;
                        rem-=1;
                    }
                 }else if(ch == 'N' || ch=='S' ){
                     if(ch != ver && rem){
                        ch = ver;
                        rem-=1;
                    }
                 }

                 if(ch=='E') X+=1;
                 else if(ch=='W') X-=1;
                 else if(ch=='N')Y+=1;
                 else if(ch=='S')Y-=1;

                 ans = max(ans,abs(X)+abs(Y));
               }
            }
        }
        return ans;
    }
};