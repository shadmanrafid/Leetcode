#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'minSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY num
 *  2. INTEGER k
 */

int minSum(vector<int> num, int k) {
    priority_queue<int> pq;
    for (int n : num) {
        pq.push(n);
    }
    for (int i = 0; i < k; ++i) {
        int curr = pq.top();
        pq.pop();
        pq.push((1 + curr) / 2);
    }
    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}
int main()