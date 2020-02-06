#include<bits/stdc++.h>
using namespace std;


int main(){

    char arr[33] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ',' ',' ',' ',' ',' ',' '};

    string res = "";
    srand(time(NULL));
    int i,j,k,l;
    for(i = 0;i<100;i++) {
        int pos = rand() % 33;
        res += arr[pos];

    }

    stringstream check1(res);
    string intermediate;
    vector<string>comp;

    for(i=0;i<100;i++){

        if(res[i] == ' ')
        {
            if(res[i+1] == ' ')res.erase(i+1,1);
        }
    }
    while(getline(check1, intermediate, ' '))
    {
        comp.push_back(intermediate);
    }

    int len = comp.size();
    priority_queue<pair<int,string>,vector<pair<int,string>>>pq;
    for(i = 0;i<len;i++){
        int sub_cnt = 0;
        for( j = 0;j<len;j++){
            if(i != j){
                int found;
                found= comp[i].find(comp[j]);
                if(found != string::npos){
                    sub_cnt++;

                }
            }

        }
        pq.push({sub_cnt,comp[i]});
    }
    pair<int,string> cur = pq.top();
    int maxx = cur.first;

    while(cur.first == maxx){
        pq.pop();
        cout<<cur.second<<endl;
        cur = pq.top();

    }






    return 0;
}