class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int unique;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                unique=nums[i];
            }
            if(nums[i]==unique){
                count++;
            }
            else{
                count--;
            }
            
            } 
             return unique;  
        }
       
    };
