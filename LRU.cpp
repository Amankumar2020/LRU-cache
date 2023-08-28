// this class will contain the main function to run the code;
#include <bits/stdc++.h>
using namespace std;
#include "LRU.hpp"

int main()
{

    LRUCache<int> cache(5);
    cache.put(8, 100);
    cache.put(10, 16);
    cache.put(1, 50);
    cache.put(11, 20);
    cache.get(8);
    cache.put(73, 98);
    cache.put(25, 26);

    cout << cache.get(10) << endl;

    return 0;
}