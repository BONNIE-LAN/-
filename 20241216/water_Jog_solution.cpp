#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

// 定义状态 (水壶A中的水量, 水壶B中的水量)
typedef tuple<int, int> State;

// 哈希函数，解决 unordered_set 和 unordered_map 无法使用自定义类型的问题
struct StateHash {
    size_t operator()(const State& state) const {
        return hash<int>()(get<0>(state)) ^ hash<int>()(get<1>(state));
    }
};

// 定义操作序列
vector<string> actions;

// 判断是否已经访问过某个状态
unordered_set<State, StateHash> visited;

// 用于记录每一步的父状态和操作
unordered_map<State, pair<State, string>, StateHash> parent;

// BFS算法寻找操作序列
bool bfs(int Ca, int Cb, int N) {
    queue<State> q;
    State start = {0, 0};
    q.push(start);
    visited.insert(start);

    // 目标状态是B壶有N升水
    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int a = get<0>(current);
        int b = get<1>(current);

        // 如果达到了目标，恢复操作路径
        if (b == N) {
            while (current != start) {
                string op = parent[current].second;
                actions.push_back(op);
                current = parent[current].first;
            }
            reverse(actions.begin(), actions.end());
            return true;
        }

        // 所有可能的操作
       vector<pair<State, string>> nextStates = {
    make_pair(State(Ca, b), "Fill A"),
    make_pair(State(a, Cb), "Fill B"),
    make_pair(State(0, b), "Empty A"),
    make_pair(State(a, 0), "Empty B"),
    make_pair(State(a - min(a, Cb - b), b + min(a, Cb - b)), "Pour A B"),
    make_pair(State(a + min(b, Ca - a), b - min(b, Ca - a)), "Pour B A")
};


        for (auto& next : nextStates) {
            State nextState = next.first;
            string action = next.second;
            if (visited.find(nextState) == visited.end()) {
                visited.insert(nextState);
                parent[nextState] = {current, action};
                q.push(nextState);
            }
        }
    }

    return false;  // 未找到解
}

int main() {
    int Ca, Cb, N;
    cin >> Ca >> Cb >> N;

    if (bfs(Ca, Cb, N)) {
        for (const string& action : actions) {
            cout << action << endl;
        }
        cout << "Success" << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}

    