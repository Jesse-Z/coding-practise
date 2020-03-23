/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-23 
*/
#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX;

// 能否出三连对
bool liandui(int start, int cards[], int &rest, int &cnt){
    if(*(cards+start)>=2 and *(cards+start+1)>=2 and *(cards+start+2)>=2){
        *(cards+start)-=2;
        *(cards+start+1)-=2;
        *(cards+start+2)-=2;
        rest -= 4;
        cnt++;
        return true;
    }
    return false;
}

// 能否出五顺子
bool shunzi(int start, int cards[], int &rest, int &cnt){
    if(*(cards+start)>=1 and *(cards+start+1)>=1 and *(cards+start+2)>=1 and *(cards+start+3)>=1 and *(cards+start+4)>=1){
        *(cards+start)-=1;
        *(cards+start+1)-=1;
        *(cards+start+2)-=1;
        *(cards+start+3)-=1;
        *(cards+start+4)-=1;
        rest-=5;
        cnt++;
        return true;
    }
    return false;
}

// 能否出对子
bool duizi(int start, int cards[], int &rest, int &cnt){
    if(*(cards+start)>=2){
        *(cards+start)-=2;
        rest-=2;
        cnt++;
        return true;
    }
    return false;
}

// 能否出单张
bool danzhang(int start, int cards[], int &rest, int &cnt){
    if(*(cards+start)>=1){
        *(cards+start)-=1;
        rest-=1;
        cnt++;
        return true;
    }
    return false;
}

// 每次递归一种可能的出牌情况
void dfs(int cards[], int rest, int cnt){
    if(rest == 0){
        if(cnt<ans)
            ans = cnt;
        return;
    }
    for(int i=0; i<10; ++i){
        if(i<=7 and liandui(i, cards, rest, cnt))
            dfs(cards, rest, cnt);
        else if(i<=5 and shunzi(i, cards, rest, cnt))
            dfs(cards, rest, cnt);
        else if(duizi(i, cards, rest, cnt))
            dfs(cards, rest, cnt);
        else if(danzhang(i, cards, rest, cnt))
            dfs(cards, rest, cnt);
    }
}

int main(){
    int temp;
    int cards[10]={0}, num=0;
    while(cin>>temp){
        cards[temp]++;
        num++;
    }
    dfs(cards, num, 0);
    cout<<ans;
    return 0;
}