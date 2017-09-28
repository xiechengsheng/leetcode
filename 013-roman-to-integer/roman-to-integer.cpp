// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.


class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]=='I') sum+=1*(sum>=5?-1:1);
            else if(s[i]=='V') sum+=5;
            else if(s[i]=='X') sum+=10*(sum>=50?-1:1);
            else if(s[i]=='L') sum+=50;
            else if(s[i]=='C') sum+=100*(sum>=500?-1:1);
            else if(s[i]=='D') sum+=500;  
            else if(s[i]=='M') sum+=1000*(sum>=5000?-1:1);
        }
        return sum;
    }
};
