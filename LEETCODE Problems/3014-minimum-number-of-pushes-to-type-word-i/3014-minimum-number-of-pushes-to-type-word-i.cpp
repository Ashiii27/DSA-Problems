class Solution {
public:
    int minimumPushes(string A) {
        if(A.size()<8) {
            return A.size();
        }
        else if(A.size() >=8 && A.size()<16){
            return 8+(A.size()%8)*2;
        }
        else if(A.size() >= 16 && A.size()<24){
            return 24+(A.size()%8)*3;
        }
        else
            return 48+(A.size()%8)*4;
    }
};