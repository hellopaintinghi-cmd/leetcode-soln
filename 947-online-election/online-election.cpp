class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leaders;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;

        unordered_map<int, int> votes;
        int leader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.size(); i++) {
            votes[persons[i]]++;

            if (votes[persons[i]] >= maxVotes) {
                leader = persons[i];
                maxVotes = votes[persons[i]];
            }

            leaders.push_back(leader);
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */