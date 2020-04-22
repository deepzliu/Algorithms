#include <iostream>
#include <map>
#include <list>
using namespace std;

#define K int
#define V int

class LRU
{
    map<K, V> _data;
    list<K> _list;
    int _max = 1000;
    
public:
    void set(K &k, V &v)
    {
        if(_data.size() >= _max && _data.find(k) != _data.end())
        {
            trim();
        }
        
        _data[k] = v;
        update_list(k);
    }
    
    V *get(K &k)
    {
        map<K, V>::iterator it = _data.find(k);
        if(it != _data.end())
        {
            update_list(k);
            return &it->second;
        }
        return NULL;
    }
    
private:
    void trim()
    {
        if(!_list.empty())
        {
            _list.erase(_list.begin());
        }
    }
    
    void update_list(K &k)
    {
        map<K, V>::iterator it = _data.find(k);
        if(it != _data.end())
        {
            list<K>::iterator list_it = _list.begin();
            for(; list_it != _list.end(); ++list_it)
            {
                if(*list_it == k)
                {
                    _list.erase(list_it);
                    break;
                }
            }
        }
        _list.push_back(k);
    }
};

int main() {
    //int a;
    //cin >> a;
    cout << "Hello World!" << endl;
}
