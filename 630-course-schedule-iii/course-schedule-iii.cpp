class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<int> pq;

        int currTime = 0;

        for(auto &c : courses){
            int duration = c[0];
            int lastDay = c[1];

            currTime += duration;
            pq.push(duration);

            if(currTime > lastDay){
                currTime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};