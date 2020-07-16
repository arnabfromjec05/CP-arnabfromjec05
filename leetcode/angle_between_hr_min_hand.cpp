//Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

#include<bits/stdc++.h>
typedef long long int llt;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double hrmov = 0;
        double minmov = 0;
        
        if(hour<12) {
            hrmov = hour*30 + 1.0*(minutes)*0.5;
        }
        else {
            hrmov = 1.0*(minutes)*0.5;
        }
        
        minmov = minutes*6;
        double res1 = max(hrmov,minmov) - min(hrmov,minmov);
        return min(res1,360-res1);
    }
};