/*                                                                              
 * Filename   lru_test.cc                                                       
 * CreateTime 2018-11-28 13:17:10                                               
 *                                                                              
 * Copyright  (C) Zhao Huanzhen                                                 
 * Copyright  (C) zhzcsp@gmail.com                                              
 */                                                                             
                                                                                
#include <iostream>                                                             
#include <list>                                                                 
#include <unordered_map>                                                           
using namespace std;                                                               
                                                                                   
class LRUCache {                                                                   
private:                                                                           
    struct CacheNode {                                                             
        int key;                                                                   
        int value;                                                                 
        CcheNode(int key, int v): key(k), value(v) {}                              
    };                                                                             
                                                                                   
public:                                                                            
    LRUCahce(int capacity)                                                         
    {                                                                              
        this.capacity = capacity;                                                  
    }                                                                              
                                                                                   
    int get(int key)                                                               
    {                                                                              
        if (cacheMap.find(key) == cacheMap.end()) return -1;                       
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);             
        cacheMap[key] = cacheList.begin();                                         
        return cacheMap[key]->value;                                               
    }                                                                              
                                                                                   
    int set(int key, int value)                                                    
    {                                                                              
        if (cacheMap.find(key) == cacheMap.end()) {                                
            if (cacheMap.size() == capacity) {                                     
                cacheMap.erase(cacheList.back().key);                              
                cacheList.pop_back();                                              
            }                                                                      
            cacheList.put_front(CacheNode(key, value));                            
            cacheMap[key] = cacheList.begin();                                     
        } else {                                                                   
            cacheMap[key]->value = value;                                          
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);      
            cacheMap[key] = cacheList.begin()                                   
        }                                                                       
    }                                                                           
                                                                                
private:                                                                        
    int capacity;                                                               
    list<CacheNode> cacheList;                                                  
    unordered_map<int, list<CacheNode>::iterator> cacheMap;                     
}
