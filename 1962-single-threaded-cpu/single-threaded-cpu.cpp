class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // {enqueueTime, processingTime, originalIndex}
        vector<vector<long long>> allTasks;

        for (int i = 0; i < n; i++) {
            allTasks.push_back({
                tasks[i][0],
                tasks[i][1],
                i
            });
        }

        // Sort by enqueue time
        sort(allTasks.begin(), allTasks.end());

        // {processingTime, index}
        priority_queue<pair<long long, long long>,vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<int> answer;
        long long currentTime = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                currentTime = max(currentTime, allTasks[i][0]);
            }
            while (i < n && allTasks[i][0] <= currentTime) {
                pq.push({allTasks[i][1], allTasks[i][2]});
                i++;
            }
            auto [processingTime, index] = pq.top();
            pq.pop();
            answer.push_back(index);
            currentTime += processingTime;
        }
        return answer;
    }
};