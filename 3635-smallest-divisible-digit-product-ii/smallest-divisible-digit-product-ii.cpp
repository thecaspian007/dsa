class Solution {
public:
    struct State {
        int a, b, c, d;
    };

    // Prime factor contribution of each digit.
    // Order: 2, 3, 5, 7
    vector<State> factor = {
        {0, 0, 0, 0}, // 0 - unused
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    int A, B, C, D;
    vector<int> dp;

    int encode(int a, int b, int c, int d) {
        return ((a * B + b) * C + c) * D + d;
    }

    State decode(int id) {
        State s;

        s.d = id % D;
        id /= D;

        s.c = id % C;
        id /= C;

        s.b = id % B;
        id /= B;

        s.a = id;

        return s;
    }

    void buildDP() {

        int totalStates = A * B * C * D;

        const int INF = 1e9;

        dp.assign(totalStates, INF);

        int start = encode(0, 0, 0, 0);

        dp[start] = 0;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {

            int cur = q.front();
            q.pop();

            State s = decode(cur);

            for (int digit = 2; digit <= 9; digit++) {

                State f = factor[digit];

                int na = min(A - 1, s.a + f.a);
                int nb = min(B - 1, s.b + f.b);
                int nc = min(C - 1, s.c + f.c);
                int nd = min(D - 1, s.d + f.d);

                int nxt = encode(na, nb, nc, nd);

                if (dp[nxt] > dp[cur] + 1) {
                    dp[nxt] = dp[cur] + 1;
                    q.push(nxt);
                }
            }
        }
    }

    // Remove the contribution of one digit from required factors.
    State subtractFactors(State need, State have) {

        need.a = max(0, need.a - have.a);
        need.b = max(0, need.b - have.b);
        need.c = max(0, need.c - have.c);
        need.d = max(0, need.d - have.d);

        return need;
    }

    // Build the lexicographically smallest suffix
    // of exactly 'length' digits which satisfies 'need'.
    //
    // We are allowed to use digit 1, so if the required
    // factors can be satisfied in fewer digits, remaining
    // positions can simply be filled with 1.
    string buildSuffix(State need, int length) {

        if (dp[encode(need.a, need.b, need.c, need.d)] > length)
            return "";

        string ans;

        for (int pos = 0; pos < length; pos++) {

            int remainingPositions = length - pos - 1;

            for (int digit = 1; digit <= 9; digit++) {

                State nextNeed = subtractFactors(
                    need,
                    factor[digit]
                );

                int id = encode(
                    nextNeed.a,
                    nextNeed.b,
                    nextNeed.c,
                    nextNeed.d
                );

                if (dp[id] <= remainingPositions) {

                    ans.push_back(char('0' + digit));

                    need = nextNeed;

                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {
        State need = {0, 0, 0, 0};

    long long x = t;

    while (x % 2 == 0) {
        need.a++;
        x /= 2;
    }

    while (x % 3 == 0) {
        need.b++;
        x /= 3;
    }

    while (x % 5 == 0) {
        need.c++;
        x /= 5;
    }

    while (x % 7 == 0) {
        need.d++;
        x /= 7;
    }

    // If t contains any prime other than
    // 2, 3, 5, 7, it is impossible.
    if (x != 1)
        return "-1";


    // ------------------------------------------------
    // 2. Initialize DP dimensions
    // ------------------------------------------------

    A = need.a + 1;
    B = need.b + 1;
    C = need.c + 1;
    D = need.d + 1;

    buildDP();


    // ------------------------------------------------
    // 3. Check if num itself is already valid
    // ------------------------------------------------

    State current = {0, 0, 0, 0};

    bool zeroFree = true;

    for (char ch : num) {

        int digit = ch - '0';

        if (digit == 0) {
            zeroFree = false;
            break;
        }

        State f = factor[digit];

        current.a += f.a;
        current.b += f.b;
        current.c += f.c;
        current.d += f.d;
    }

    if (zeroFree &&
        current.a >= need.a &&
        current.b >= need.b &&
        current.c >= need.c &&
        current.d >= need.d) {

        return num;
    }


    // ------------------------------------------------
    // 4. Calculate prefix factor counts
    // ------------------------------------------------

    int n = num.size();

    vector<State> prefix(n + 1);

    // validPrefix[i] means:
    // num[0 ... i-1] contains no zero.
    vector<bool> validPrefix(n + 1, true);

    for (int i = 0; i < n; i++) {

        prefix[i + 1] = prefix[i];

        if (num[i] == '0') {

            validPrefix[i + 1] = false;

        } else {

            validPrefix[i + 1] =
                validPrefix[i];

            int digit = num[i] - '0';

            prefix[i + 1].a += factor[digit].a;
            prefix[i + 1].b += factor[digit].b;
            prefix[i + 1].c += factor[digit].c;
            prefix[i + 1].d += factor[digit].d;

            // We only care about values up to the
            // required exponent.
            prefix[i + 1].a =
                min(prefix[i + 1].a, need.a);

            prefix[i + 1].b =
                min(prefix[i + 1].b, need.b);

            prefix[i + 1].c =
                min(prefix[i + 1].c, need.c);

            prefix[i + 1].d =
                min(prefix[i + 1].d, need.d);
        }
    }


    // ------------------------------------------------
    // 5. Try to construct a valid number
    //    having the SAME length as num.
    //
    //    We change a digit from RIGHT to LEFT.
    // ------------------------------------------------

    for (int i = n - 1; i >= 0; i--) {

        // Prefix must be zero-free.
        if (!validPrefix[i])
            continue;

        int originalDigit = num[i] - '0';

        // To make the number greater, this digit
        // must become strictly larger.
        for (int digit = originalDigit + 1;
             digit <= 9;
             digit++) {

            // Start with the full requirement.
            State remaining = need;

            // Remove contribution of prefix.
            remaining =
                subtractFactors(
                    remaining,
                    prefix[i]
                );

            // Remove contribution of new digit.
            remaining =
                subtractFactors(
                    remaining,
                    factor[digit]
                );

            int id = encode(
                remaining.a,
                remaining.b,
                remaining.c,
                remaining.d
            );

            // Number of positions remaining after
            // choosing this digit.
            int suffixLength = n - i - 1;

            // Can the suffix satisfy the requirement?
            if (dp[id] <= suffixLength) {

                string ans;

                // Keep prefix.
                ans += num.substr(0, i);

                // Put the larger digit.
                ans.push_back(
                    char('0' + digit)
                );

                // Fill suffix with smallest possible
                // digits.
                ans += buildSuffix(
                    remaining,
                    suffixLength
                );

                return ans;
            }
        }
    }


    // ------------------------------------------------
    // 6. Same length is impossible.
    //
    //    We need a LONGER number.
    //
    //    Minimum possible length is:
    //
    //    max(n + 1, minimum digits required)
    // ------------------------------------------------

    int targetState = encode(
        need.a,
        need.b,
        need.c,
        need.d
    );

    int requiredDigits = dp[targetState];

    // Even an arbitrarily long number cannot
    // satisfy the requirement.
    if (requiredDigits == 1e9)
        return "-1";

    int length = max(
        n + 1,
        requiredDigits
    );


    // ------------------------------------------------
    // 7. Construct the smallest number of this length.
    //
    //    Since length > n, ANY number with this length
    //    is automatically greater than num.
    //
    //    Therefore we simply construct the smallest
    //    zero-free number satisfying t.
    // ------------------------------------------------

    for (int firstDigit = 1;
         firstDigit <= 9;
         firstDigit++) {

        // Remove factors contributed by first digit.
        State remaining =
            subtractFactors(
                need,
                factor[firstDigit]
            );

        int id = encode(
            remaining.a,
            remaining.b,
            remaining.c,
            remaining.d
        );

        // We already used one digit.
        int remainingLength = length - 1;

        // Can the remaining positions satisfy
        // the remaining prime-factor requirement?
        if (dp[id] <= remainingLength) {

            string ans;
            // Smallest feasible first digit.
            ans.push_back(
                char('0' + firstDigit)
            );
            // Construct smallest possible suffix.
            ans += buildSuffix(
                remaining,
                remainingLength
            );
            return ans;
        }
    }
    return "-1";
    }
};