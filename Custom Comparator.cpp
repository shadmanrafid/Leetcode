#include <bits/stdc++.h>
using namespace std;

struct interval{
    int start,end;
    interval(int a,int b){
        start = a;
        end = b;
    }
};

struct sortInterval{
    bool operator()(interval* const& I1,interval* const& I2){
        return I1->end - I1->start > I2->end - I2->start;
    }
};


int main()
{
    priority_queue<interval*,vector<interval*>,sortInterval>pq;

    interval* a = new interval(1,4);
    interval* b = new interval(6,8);
    interval* c = new interval(2,6);
    interval* d = new interval(0,7);

    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    interval* top;
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
        cout<<top->start<<endl;
    }




}