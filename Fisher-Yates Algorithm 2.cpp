#include<bits/stdc++.h>
 using namespace std;


 void randomize(int anew[])
 {
    int i,temp;

    srand(time(NULL));
    for(i = 4; i>= 0; i--)
    {
        int s_elem = rand()%(i+1);
        swap(anew[i],anew[s_elem]);

    }
 }

 int main()
 {

    int arr[5] = {1,2,3,4,5};
    int i;
    randomize(arr);
    for(i = 0; i< 5; i++)
    {
        cout<< arr[i] << " ";

    }
    return 0;
 }
