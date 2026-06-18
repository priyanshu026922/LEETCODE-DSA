1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double val1=6.0*minutes;
5        double val2=(hour%12)*30.0;
6
7        double val3=(double)minutes/2.0;
8
9
10        double x=abs(val1-val2-val3);
11
12        return min(360.0-x,x);
13
14    }
15};