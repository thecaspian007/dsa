class Solution {
public:
    #define MOD 1000000007
    long long modpow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> pownums(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; ++i) {
            for (int c = 1; c <= m; ++c)
                pownums[i][c] = (pownums[i][c-1] * nums[i]) % MOD;
        }
        vector<long long> fact(m + 1, 1), invfact(m + 1, 1);
        for (int i = 1; i <= m; ++i) fact[i] = fact[i-1] * i % MOD;
        invfact[m] = modpow(fact[m], MOD - 2);
        for (int i = m; i >= 1; --i) invfact[i-1] = invfact[i] * i % MOD;
        int M = m;
        int K = k;
        auto make3d = [&](long long val){
            return vector<vector<vector<long long>>>(M+1,
                vector<vector<long long>>(M+1, vector<long long>(K+1, val)));
        };
        auto dp = make3d(0LL);
        auto nxt = make3d(0LL);
        dp[0][0][0] = 1; 
        for (int i = 0; i < n; ++i) {
            for (int u = 0; u <= M; ++u)
                for (int c = 0; c <= M; ++c)
                    for (int s = 0; s <= K; ++s)
                        nxt[u][c][s] = 0;
            for (int used = 0; used <= M; ++used) {
                for (int carry = 0; carry <= M; ++carry) {
                    for (int sb = 0; sb <= K; ++sb) {
                        long long cur = dp[used][carry][sb];
                        if (!cur) continue;
                        int maxCnt = M - used;
                        for (int cnt = 0; cnt <= maxCnt; ++cnt) {
                            int newUsed = used + cnt;
                            int sum = cnt + carry;
                            int bit = sum & 1;
                            int newSb = sb + bit;
                            if (newSb > K) break; 
                            int newCarry = sum >> 1;
                            long long add = cur;
                            add = (add * pownums[i][cnt]) % MOD;
                            add = (add * invfact[cnt]) % MOD;
                            nxt[newUsed][newCarry][newSb] += add;
                            if (nxt[newUsed][newCarry][newSb] >= MOD) nxt[newUsed][newCarry][newSb] -= MOD;
                        }
                    }
                }
            }
            dp.swap(nxt);
        }
        long long ans = 0;
        for (int carry = 0; carry <= M; ++carry) {
            for (int sb = 0; sb <= K; ++sb) {
                long long val = dp[M][carry][sb];
                if (!val) continue;
                int totalBits = sb + __builtin_popcount(carry);
                if (totalBits == K) {
                    ans = (ans + val) % MOD;
                }
            }
        }
        ans = ans * fact[M] % MOD;
        return (int)ans;
    }
};