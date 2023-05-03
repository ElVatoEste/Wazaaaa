#include <iostream>
#include <queue>

using namespace std;

void merge(queue<int> &q1, queue<int> &q2, queue<int> &q3) {
    while (!q1.empty() && !q2.empty()) {
        if (q1.front() < q2.front()) {
            q3.push(q1.front());
            q1.pop();
        } else {
            q3.push(q2.front());
            q2.pop();
        }
    }
    while (!q1.empty()) {
        q3.push(q1.front());
        q1.pop();
    }
    while (!q2.empty()) {
        q3.push(q2.front());
        q2.pop();
    }
}

void merge_sort(queue<int> &q) {
    if (q.empty() || q.size() == 1) {
        return;
    }
    queue<int> q1, q2, q3;
    int n = q.size();
    for (int i = 0; i < n / 2; i++) {
        q1.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        q2.push(q.front());
        q.pop();
    }
    merge_sort(q1);
    merge_sort(q2);
    merge(q1, q2, q3);
    while (!q3.empty()) {
        q.push(q3.front());
        q3.pop();
    }
}

int main() {
    queue<int> q;
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> x;
        q.push(x);
    }
    merge_sort(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
