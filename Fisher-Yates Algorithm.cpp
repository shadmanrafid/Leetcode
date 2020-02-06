#include<bits/stdc++.h>
 using namespace std;


 int main()
 {

    int arr[5] = {1,2,3,4,5};
    int anew[5];
    int i,temp;
    for(i = 0; i<5;i++)
    {
        anew[i] = arr[i];
    }
    srand(time(NULL));
    for(i = 4; i>= 0; i--)
    {
        int s_elem = rand()%(i+1);
        temp = anew[i];
        anew[i] = anew[s_elem];
        anew [s_elem] = temp;
    }

    for(i = 0; i< 5; i++)
    {
        cout<< anew[i] << " ";

    }
    return 0;
 }
