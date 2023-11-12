#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,i,left=0,right=0,subCount=0,subLen;
    scanf("%lld",&n);
    int arr[n];
    for(i=0;i<=n-1;i++)
        scanf("%d",&arr[i]);

    while(right<=n-1){
        if(arr[right]!=0){
            if(arr[left]==0)
                left=right;
            if(right==n-1){
                subLen=right-left+1;
                subCount+=(subLen*(subLen+1))/2;
            }
        }
        else{
            if(arr[left]!=0){
                subLen=(right-1)-left+1;
                subCount+=(subLen*(subLen+1))/2;
                left=right;
            }
        }
        right++;
    }
    cout<<((n*(n+1))/2)-subCount<<endl;
}


// OLD solution using 'Counting elements of Subrray' technique instaed of two pointers
/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
        long long int e,n,i,ans=0,cnt=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&e);
            if(e!=0){
                cnt++;
                if(i==n-1) ans=ans+(cnt*(cnt+1))/2;
            }
            else if(e==0&&cnt!=0){
                ans=ans+(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        printf("%lld\n",(n*(n+1))/2-ans);
    
}
*/
