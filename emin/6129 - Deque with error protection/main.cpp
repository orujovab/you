#include <iostream>
#include <deque>
using namespace std;

deque <int> dq;
int a;
string str;

int main(){
    while(cin>>str)
    {
        if(str=="push_front")
        {
            cin>>a;
            dq.push_front(a);
            cout<<"ok"<<endl;
        }
        else
        if(str=="push_back")
        {
            cin>>a;
            dq.push_back(a);
            cout<<"ok"<<endl;
        }
        else
        if(str=="pop_front" && !dq.empty())
        {
            cout<<dq.front()<<endl;
            dq.pop_front();
        }
        else
        if(str=="pop_back"&& !dq.empty())
        {
            cout<<dq.back()<<endl;
            dq.pop_back();
        }
        else
        if(str=="front"&& !dq.empty())
        {
            cout<<dq.front()<<endl;
        }
        else
        if(str=="back"&& !dq.empty())
        {
            cout<<dq.back()<<endl;
        }
        else
        if(str=="size")
        {
            cout<<dq.size()<<endl;
        }
        else
        if(str=="clear")
        {
            while(!dq.empty()) dq.pop_back();
            cout<<"ok"<<endl;
        }
        else
        if(str=="exit")
        {
            cout<<"bye"<<endl;
            break;
        }
        else
            cout<<"error"<<endl;
    }
    return 0;
}