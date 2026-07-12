class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0 ) return{};
        vector<pair<int,int>> vec;
        
        for(int i=0;i<n;i++)
            vec.push_back({arr[i],i});

        sort(vec.begin(),vec.end());
        vector<int> ans(n);
        int rank=1;
        ans[vec[0].second]=1;
        for(int i=1;i<n;i++){
        if(vec[i].first!=vec[i-1].first)
        rank++;

        ans[vec[i].second]=rank;
        }
        return ans;
    }
};