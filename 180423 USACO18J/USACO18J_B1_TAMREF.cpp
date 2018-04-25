/*

Contest name : USACO 2018 January
Problem ID (in the contest) : Bronze #1
Task name : Blocked Billboard II
BOJ ID : #15592

Author : TAMREF
Time Complexity : O(1)
Space Complexity : O(1)

*/

#include <bits/stdc++.h>
using namespace std;

struct pt{
    int x, y;
    pt(int x = 0, int y = 0):x(x),y(y){}
    bool operator<= (pt z){
        return x <= z.x && y <= z.y;
    }
};

int area(pt u, pt v){
    return abs( (v.x - u.x) * (v.y - u.y) );
}

pt Food[4], Mow[4];

bool inFood(pt x){
    return Food[0] <= x && x <= Food[3];
}

int q[4];

void init(){
    for(int i = 0; i < 4; i++){
        cin >> q[i];
    }
    for(int i = 0; i < 4; i++){
        Mow[i] = pt(q[2*(i/2)],q[1+2*(i&1)]);
    }
    for(int i = 0; i < 4; i++){
        cin >> q[i];
    }
    for(int i = 0; i < 4; i++){
        Food[i] = pt(q[2*(i/2)],q[1+2*(i&1)]);
    }
}

void pro(){
    int c = 0;
    for(int i = 0; i < 4; i++){
        c += inFood(Mow[i]);
    }
    if(c > 2){
        cout << 0 << endl;
        return;
    }
    if(c < 2){
        cout << area(Mow[0], Mow[3]) << endl;
        return;
    }
    pt tmp;
    if(inFood(Mow[0]) && inFood(Mow[1])){
        tmp = pt(Food[2].x, Mow[0].y);
        cout << area(Mow[3], tmp) << endl;
        return;
    }
    if(inFood(Mow[0]) && inFood(Mow[2])){
        tmp = pt(Mow[0].x, Food[1].y);
        cout << area(Mow[3], tmp) << endl;
        return;
    }
    if(inFood(Mow[1]) && inFood(Mow[3])){
        tmp = pt(Mow[3].x,Food[0].y);
        cout << area(Mow[0], tmp) << endl;
        return;
    }
    if(inFood(Mow[2]) && inFood(Mow[3])){
        tmp = pt(Food[0].x,Mow[3].y);
        cout << area(Mow[0], tmp) << endl;
        return;
    }
}

void debug(){
    for(int i = 0; i < 4; i++){
        cout << Food[i].x << ' ' << Food[i].y << '\n';
    }
    cout << '\n';
    for(int i = 0; i < 4; i++){
        cout << Mow[i].x << ' ' << Mow[i].y << '\n';
    }
}

int main(){
    init();
    pro();
    //debug();
}
