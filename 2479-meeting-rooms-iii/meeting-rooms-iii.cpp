class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        // Available rooms (smallest room number first)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int room = 0; room < n; room++)
            available.push(room);
        // {endTime, roomNumber}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        vector<int> meetingCount(n, 0);
        for (auto &meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;
            // Free all rooms whose meetings have ended
            while (!busy.empty() && busy.top().first <= start) {
                int room = busy.top().second;
                busy.pop();

                available.push(room);
            }
            if (!available.empty()) {
                // Assign meeting immediately
                int room = available.top();
                available.pop();

                busy.push({end, room});
                meetingCount[room]++;
            } else {
                // Delay meeting
                auto [freeTime, room] = busy.top();
                busy.pop();

                busy.push({freeTime + duration, room});
                meetingCount[room]++;
            }
        }
        int answer = 0;
        for (int room = 1; room < n; room++) {
            if (meetingCount[room] > meetingCount[answer])
                answer = room;
        }
        return answer;
    }
};