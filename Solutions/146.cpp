#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <functional>

using namespace std;

//https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/lru-suan-fa
//https://gblobscdn.gitbook.com/assets%2F-LrtQOWSnDdXhp3kYN4k%2F-M3U3aNXgGJVkKZ-TldN%2F-LrtQZl7GS7jq-2gWFp6%2F4.jpg?generation=1585364289698544&alt=media

class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> list;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(map.count(key)==0) return -1;
        auto iter = map[key];
        list.splice(list.begin(), list, iter);
        return iter->second;
    }

    void put(int key, int value) {
        if(map.count(key)==0){
            if(list.size()>=capacity){ //delete last node, delete key
                map.erase(list.back().first);
                list.pop_back();
            }
            list.push_front({key, value});
            map[key] = list.begin();
        }
        else{
            auto iter = map[key];
            iter->second = value;
            list.splice(list.begin(), list, iter);
        }
    }
};
