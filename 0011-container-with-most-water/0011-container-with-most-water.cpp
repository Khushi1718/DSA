class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 ;
        int r = height.size()-1;
        int ans = 0 ; 
        while(l<r){
            int currwater = (r-l) * min(height[r],height[l]);
            ans = max(ans,currwater);
            if(height[r]>height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};