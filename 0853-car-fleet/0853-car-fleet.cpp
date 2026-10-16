class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, double>> pq;
        for(int i=0;i<position.size();i++){
            double t= double(target-position[i])/speed[i];
            pq.push({position[i],t});
        }
        int c=0;
        double first=pq.top().second;
        while(!pq.empty()){
            // auto it = pq.top();
            pq.pop();
            if(pq.empty()){
                c++;
                continue;
            }
            while (!pq.empty() && pq.top().second <= first){
                pq.pop();
            }
            first =pq.top().second;
            c++;
    }
    return c;
}};