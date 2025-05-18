#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l,i;
    double ansRadius=0,adjLanternsDist;
    scanf("%d%d",&n,&l);

    int lanternPosArr[n];
    for(i=0;i<=n-1;i++)
        scanf("%d",&lanternPosArr[i]);

    // sort the lantern position array
    // so that TODO
    sort(lanternPosArr,lanternPosArr+n);

    // iterate over each adjacent lanterns and work on the distance between them
    // distance between two lanterns will be covered equally by both of them
    for(i=0;i<=n-2;i++){
        adjLanternsDist=lanternPosArr[i+1]-lanternPosArr[i];

        //
        ansRadius=max(ansRadius, adjLanternsDist/2);
    }

    // handle for position 0 and position L separately
    if(lanternPosArr[0]-0>ansRadius)
        ansRadius=lanternPosArr[0]-0;
    if(l-lanternPosArr[n-1]>ansRadius)
        ansRadius=l-lanternPosArr[n-1];

    printf("%.10f",ansRadius);
}
