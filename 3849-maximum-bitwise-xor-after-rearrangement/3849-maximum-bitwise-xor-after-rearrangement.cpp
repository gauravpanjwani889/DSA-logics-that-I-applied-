class Solution {
public:
    string maximumXor(string s, string t) {
        int a=0,b=0;
        for(char c:t){
            if(c=='0'){
                a++; //zeros
            }
            else{
                b++; //ones
            }
        }

        for(char &c:s){
            if(c=='0'){
                if(b>0){
                    c='1';
                    b--;
                }
                else{
                    a--;
                }

            }
            else{
                if(a>0){
                    c='1';
                    a--;
                }
                else{
                    c='0';
                    b--;

                }
            }
        }
        return s;
        
    }
};