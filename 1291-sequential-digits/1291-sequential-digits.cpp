class Solution {
public:
    int findlen(int x){
        int count = 0;
        while(x){
            count++;
            x /= 10;
        }
        return count;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int lenlow = findlen(low);
        int lenhigh = findlen(high);

        for(int len = lenlow; len <= lenhigh; len++){
            for(int start = 1; start + len - 1 <= 9; start++){
                int num = 0;
                for(int d = start; d < start + len; d++){
                    num = num * 10 + d;
                }
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};