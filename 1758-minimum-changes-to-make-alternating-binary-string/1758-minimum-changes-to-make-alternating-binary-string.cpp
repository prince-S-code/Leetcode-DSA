class Solution {
public:
    int minOperations(string s) {
        int count1=0,count0=0;
        for(int i=0;i<s.size();i++){
            // assumption that string start from 0
            if(i%2==0){ //for even indexes 
                if(s[i]=='0'){
                    count1++;
                }
                else{
                    count0++;
                }
            }
            else{ // for odd indxes
                if(s[i]=='1'){
                    count1++;
                }else {
                    count0++;
                }
            }
        }
        return min(count1,count0);
    }
};