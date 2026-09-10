class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool found = false ;
        vector<int> ans;
        int n = digits.size()-1;
        if(digits[n] !=9){
            digits[n]+=1;
            return digits;
        }
        while(n>=0 && digits[n]==9){
            digits[n]=0;
            n--;
        }
        if(n>=0){
            digits[n]+=1;
            return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;

    }
};