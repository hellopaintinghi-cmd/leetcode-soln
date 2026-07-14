class Solution {
public:
    struct Robot {
        int pos;
        int health;
        char dir;
        int idx;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& health, string directions) {
        int n = positions.size();
        vector<Robot> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], health[i], directions[i], i});
        }

        sort(robots.begin(), robots.end(),
             [](const Robot &a, const Robot &b) {
                 return a.pos < b.pos;
             });
        stack<int> st;

        for(int i = 0;i < n;i++){
            if(robots[i].dir == 'R'){
                st.push(i);
            }else{
                while(!st.empty() && robots[i].health > 0){
                    int j = st.top();

                    if(robots[j].health < robots[i].health){
                        robots[i].health--;
                        robots[j].health = 0;
                        st.pop();
                    }else if(robots[j].health == robots[i].health){
                        robots[i].health = 0;
                        robots[j].health = 0;
                        st.pop();
                        break;
                    }else{
                        robots[j].health--;
                        robots[i].health = 0;
                        break;
                    }
                }
            }
        }

        vector<pair<int, int>> result;
        for(auto &r : robots){
            if(r.health > 0){
                result.push_back({r.idx, r.health});
            }
        }

        sort(result.begin(), result.end());
        vector<int> ans;
        for (auto &p : result)
            ans.push_back(p.second);

        return ans;
    }
};