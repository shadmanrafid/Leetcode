#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'segment' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x
 *  2. INTEGER_ARRAY arr
 */

int segment(int x, vector<int> arr) {
    deque</*index=*/int> q;
    for (int i = 0; i < x; ++i) {
        while(!q.empty() && arr[i] <= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    int result = -1;
    for (int i = x; i < arr.size(); ++i) {
        result = max(result, arr[q.front()]);
        while (!q.empty() && q.front() <= i - x)
            q.pop_front();
        while (!q.empty() && arr[i] <= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    return max(result, arr[q.front()]);
}
int main()