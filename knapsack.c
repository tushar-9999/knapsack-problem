#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
 
int knapSack(int W, int wt[], int val[], int n)
{
    int i,w;
    
    if (n == 0 || W == 0)
        return 0;
 
    
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], 
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 

int main()
{
    int i, n, val[20], wt[20], W;
    
    printf("Enter number of items:");
    scanf("%d", &n);
    
    printf("Enter value and weight of items:\n");
    for(i = 0;i < n; ++i){
    	scanf("%d%d", &val[i], &wt[i]);
    }
 
    printf("Enter size of knapsack:");
    scanf("%d", &W);
    
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}