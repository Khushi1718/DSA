class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 1 ;
        int even = 2; 
        int summodd=0;
        int sumeven=0;
        for(int i = 0; i <n;i++){
            summodd +=odd;
            sumeven +=even;
            odd+=2;
            even+=2;
        }
        return gcd(summodd,sumeven);
    }
};