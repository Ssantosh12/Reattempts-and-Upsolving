
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int ele,n,i,continuous=0,maxChoice=0;
        scanf("%d",&n);
        map<int,int> choices;
        int arr[n];
        for(i=0;i<=n-1;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<=n-1;i++){
            continuous++;
            if(i==(n-1)){
                if(continuous%2==0)
                    choices[arr[i]]=choices[arr[i]]+continuous/2;
                else choices[arr[i]]=choices[arr[i]]+(continuous/2)+1;
                continuous=0;
            }
            else if(arr[i]!=arr[i+1]){
                if(continuous%2==0)
                    choices[arr[i]]=choices[arr[i]]+continuous/2;
                else choices[arr[i]]=choices[arr[i]]+(continuous/2)+1;
                continuous=0;
            }
        }
        for(auto x: choices){
            if(x.second>maxChoice)
                maxChoice=x.second;
        }
        for(auto x: choices){
            if(x.second==maxChoice){
                cout<<x.first<<"\n";
                break;
            }
        }
    }
}

/*

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,i,cnt,cnd=0,mx=1;
	    scanf("%d",&n);
	    map<int,int> mp;
	    int a[n];
	    for(i=0;i<n;i++)
            scanf("%d",&a[i]);
	    i=0;
	    while(i<n){
            mp[a[i]]++;
            if(a[i]==a[i+1]) i=i+2;
            else i++;
	    }
	    for(auto x: mp){
            if(x.second>mx) mx=x.second;
	    }
	    for(auto x: mp){
            if(x.second==mx){
                printf("%d\n",x.first);
                break;
            }
	    }

	}
	return 0;
}

*/
