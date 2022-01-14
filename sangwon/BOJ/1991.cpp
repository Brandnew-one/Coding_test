//BOJ 1991(트리순회)
#include <iostream>
#include <string>
using namespace std;

int n;
char lc[26];
char rc[26];

void preorder_traversal(char cur){
    cout<<cur;
    if(lc[cur-'A']!='\0')preorder_traversal(lc[cur-'A']);
    if(rc[cur-'A']!='\0')preorder_traversal(rc[cur-'A']);
}

void inorder_traversal(char cur){
    if(lc[cur-'A']!='\0')inorder_traversal(lc[cur-'A']);
    cout<<cur;
    if(rc[cur-'A']!='\0')inorder_traversal(rc[cur-'A']);
}

void postorder_traversal(char cur){
    if(lc[cur-'A']!='\0')postorder_traversal(lc[cur-'A']);
    if(rc[cur-'A']!='\0')postorder_traversal(rc[cur-'A']);
    cout<<cur;
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    cin.ignore();//이를 처리하지않으면 개행이 버퍼로 남아있어서 하나가 생략된다.
    //https://jhnyang.tistory.com/107에서 cin,getline 입력방식비교
    for(int i=0; i<n; i++){
        string s;
        getline(cin,s);
        if(s[2]!='.')lc[s[0]-'A']=s[2];
        if(s[4]!='.')rc[s[0]-'A']=s[4];
    }
    preorder_traversal('A');
    cout<<'\n';
    inorder_traversal('A');
    cout<<'\n';
    postorder_traversal('A');

    return 0;
}