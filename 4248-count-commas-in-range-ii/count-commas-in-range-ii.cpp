class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000LL){
            return 0;
        }

        if(n < 1000000LL){
            return n - 999;
        }

        if(n < 1000000000LL){
            return 2LL * (n - 999999LL)
                 + (999999LL - 999LL);
        }

        if(n < 1000000000000LL){
            return 3LL * (n - 999999999LL)
                 + 2LL * (999999999LL - 999999LL)
                 + (999999LL - 999LL);
        }

        // 4 commas
        if(n < 1000000000000000LL){
            return 4LL * (n - 999999999999LL)
                 + 3LL * (999999999999LL - 999999999LL)
                 + 2LL * (999999999LL - 999999LL)
                 + (999999LL - 999LL);
        }

        // 5 commas
        if(n < 1000000000000000000LL){
            return 5LL * (n - 999999999999999LL)
                 + 4LL * (999999999999999LL - 999999999999LL)
                 + 3LL * (999999999999LL - 999999999LL)
                 + 2LL * (999999999LL - 999999LL)
                 + (999999LL - 999LL);
        }

        // 6 commas
        return 6LL * (n - 999999999999999999LL)
             + 5LL * (999999999999999999LL - 999999999999999LL)
             + 4LL * (999999999999999LL - 999999999999LL)
             + 3LL * (999999999999LL - 999999999LL)
             + 2LL * (999999999LL - 999999LL)
             + (999999LL - 999LL);
    }
};