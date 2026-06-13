#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int flag1 = 0, flag2 = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z')flag1 |= (1 << (s[i] - 'a'));
        else if(s[i] >= 'A' && s[i] <= 'Z')flag2 |= (1 << (s[i] - 'A')) ;
    }
    cout<<(flag1?"Lowercase":(flag2?"Uppercase":"None"))<<endl;
}