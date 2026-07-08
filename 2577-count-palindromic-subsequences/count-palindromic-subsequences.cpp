class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        long long mod = 1e9 + 7;

        //pre[i][a][b] : number of pairs(a, b) strictly before i
        vector<vector<vector<long long>>> pre(n, vector<vector<long long>>(10, vector<long long>(10, 0)));

        //suf[i][a][b] : number of pairs(a, b) strictly after i
        vector<vector<vector<long long>>> suf(n, vector<vector<long long>>(10, vector<long long>(10, 0)));

        vector<long long> count(10, 0);

        vector<vector<long long>> pairs(10, vector<long long>(10, 0));

        for(int i=0;i<n;i++){
            pre[i] = pairs;
            int x = s[i] - '0';

            for(int a=0;a<10;a++){
                pairs[a][x] += count[a];
            }
            count[x]++;
        }

        count.assign(10, 0);
        for (int a = 0; a < 10; a++) {
            fill(pairs[a].begin(), pairs[a].end(), 0);
        }

        for(int i = n-1;i>=0;i--){
            suf[i] = pairs;
            int x = s[i] - '0';
            for (int b = 0; b < 10; b++) {
                pairs[x][b] += count[b];
            }

            count[x]++;
        }

        long long ans = 0;
        for(int mid = 0;mid < n;mid++){
            for(int a=0;a<10;a++){
                for(int b = 0;b<10;b++){
                    ans += pre[mid][a][b] * suf[mid][b][a]; //multiply left and right 
                    ans %= mod;
                }
            }
        }
        return ans;
    }
};