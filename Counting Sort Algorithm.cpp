#include<bits/stdc++.h>

using namespace std;
int counting_sort(int arr[],int len)
{

    int i ;
    int cnt[10];
    memset(cnt,0,sizeof(cnt));

    for(i = 0; i<len; i++)
    {
        cnt[arr[i]]++;
    }


    for(i= 0; i<10;i++)
    {
        if(i == 0)
            continue;
        else cnt[i] += cnt[i-1];
    }

    int output[len];
    for(i = 0;i<len;i++)
    {
        output[cnt[arr[i]]-1] = arr[i];
        --cnt[arr[i]];
    }
    for(i = 0;i<len;i++)
        printf("%d ",output[i]);
//    for(i=0;i<len;i++)
//        arr[i] = output[i];
//    for(int i = 0; i<10; i++)
//        cout<<arr[i]<< " ";
}


int main()
{
    int arr[] = {1, 4, 1, 2, 7, 5, 2,9,0,3};

    int len = sizeof(arr)/sizeof(arr[0]);
    counting_sort(arr,len);


    return 0;
}
