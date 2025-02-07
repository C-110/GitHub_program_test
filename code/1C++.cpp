#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<string> qu;
    deque<string> out;
    unordered_map<string,int> name_mp;
    int n,m,q;
    cin >> n >> m >> q;
    while(q--)
    {
        if(n==0)
        {
            string sss;
            cin >> sss;
        }
        int thing;
        string name;
        cin >> thing;
        switch(thing)
        {
            case 1:
            {
                cin >> name;
                qu.push_back(name);
            }
            break;
            case 2:
            {
                cin >> name;
                out.push_front(name);
            }
            case 3:
            {
                int x;
                cin >>x;
                // 清除不存在的对象
                while(out.size() && qu.size())
                {
                    if(qu.front() == out.front())
                    {
                        qu.pop_front();
                        out.pop_front();
                    }
                    else 
                        break;
                }
                // 判断是否要全买
                if(n <= m)
                {
                    if(qu.size())
                    {
                        name_mp[qu.front()]+=n;
                        qu.clear();
                        n=0;
                    }
                }
                else
                {
                    if(qu.size())
                    {
                        name_mp[qu.front()]+=x;
                    }
                }
            }
            case 4:
            {
                cout << qu.size() << endl;
            }
        }

    }
    for(auto moodo : name_mp)
    {
        cout << moodo.first <<" "<<moodo.second<<endl;
    }
    return 0;
}