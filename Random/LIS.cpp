#include <iostream>
using namespace std;
 
 
int dp[31]; 
int lis;    
 
int LIS(int * arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if(dp[i] > lis)
                {
                    lis = dp[i];
                }
            }
        }
    }
    return lis;
}
 
void outputLIS(int * arr, int index)
{
    bool isLIS = 0;
    if(index < 0 || lis == 0)
    {
        return;
    }
    if(dp[index] == lis)
    {
        --lis;
        isLIS = 1;
    }
 
    outputLIS(arr,--index);
 
    if(isLIS)
    {
        printf("%d ",arr[index+1]);
    }
}
 
//int main()
//{
//    int arr[] = {1,-1,2,-3,4,-5,6,-7};
// 
//   
//    printf("%d\n",LIS(arr,sizeof(arr)/sizeof(int)));
// 
//    outputLIS(arr,sizeof(arr)/sizeof(int) - 1);
//    printf("\n");
//	getchar();
//	return 0;
//}