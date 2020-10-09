#include <vector>
#include <queue>

using namespace std;

int solution(int len, int weight, vector<int> tw) {
    // 트럭 무게, 다리에 들어간 시각
    queue<pair<int, int>> q;
    int nowWeight = tw[0];
    int nowTime = 1;
    q.push({tw[0], nowTime});
    int wIdx = 1;
    
    while (!q.empty() || wIdx < tw.size()) {
        nowTime++;
        while (!q.empty() && nowTime - q.front().second >= len) {
            nowWeight -= q.front().first;
            q.pop();
        }
        if (wIdx < tw.size() && tw[wIdx] + nowWeight <= weight) {
            q.push({tw[wIdx], nowTime});
            nowWeight += tw[wIdx];
            wIdx++;
        }
    }
    return nowTime;
}
