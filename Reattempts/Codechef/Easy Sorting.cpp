#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc=1,t;
    scanf("%d",&t);
    while(tc<=t){
        int i,j,n,swapCount=0;
        scanf("%d",&n);
        int arr[n],sortedArr[n];
        for(i=0;i<=n-1;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<=n-1;i++)
            sortedArr[i]=arr[i];

        sort(sortedArr,sortedArr+n);

        for(i=0;i<=n-1;i++){
            if(arr[i]!=sortedArr[i]){
                for(j=i+1;j<=n-1;j++){
                    if(arr[j]==sortedArr[i]){
                        int temp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=temp;
                        swapCount++; // since all elements are from 1 to n and without repeating 'break' is not needed here
                    }
                }
            }
        }
        cout<<"Case "<<tc<<": "<<swapCount<<"\n";
        tc++;
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tc=1,t;
	scanf("%d",&t);
	while(tc<=t){
	    int cnt=0,d,n,i;
	    scanf("%d",&n);
	    int a[n+1];
	    for(i=1;i<=n;i++)
	        scanf("%d",&a[i]);
	    i=1;
	    while(i<=n){
	         if(a[i]!=i){
	              d=a[i]-i;
	              swap(a[i],a[i+d]);
	              cnt++;
	         }
	         else i++;
	    }
	    printf("Case %d: %d\n",tc,cnt);
	    tc++;
	}
	return 0;
}
*/
