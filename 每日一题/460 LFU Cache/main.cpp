/**
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-04-05 
*
* Brief：设计最不经常使用缓存的数据结构，实现put和get方法，O(1)时间完成两个操作
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int freq, time;
    int key, value;
    Node(int _key, int _value, int _freq, int _time):key(_key), value(_value), freq(_freq), time(_time){}
    bool operator < (const Node &b) const{
        return freq == b.freq ? time < b.time : freq < b.freq;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LFUCache {
    // 哈希表记录，key和对应的Node
    unordered_map<int, Node> cnt_table;
    set<Node> S;
    int capacity, time;
public:
    LFUCache(int capacity) {
        cnt_table.clear();
        S.clear();
        this->time = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(this->capacity==0)
            return -1;
        auto iter = cnt_table.find(key);
        if(iter==cnt_table.end())
            return -1;
        // 旧的内容
        Node old = iter->second;
        // 从BBT中删除旧的
        S.erase(old);
        // 更新旧的内容
        old.freq++;
        old.time = ++this->time;
        // 插入新的
        S.insert(old);
        iter->second = old;
        return old.value;
    }
    
    void put(int key, int value) {
        if(this->capacity==0)
            return;
        auto iter = cnt_table.find(key);
        // 如果不存在，则插入
        if(iter==cnt_table.end()){
            // 如果满了，则需要删除最近最少频率
            if(cnt_table.size()==this->capacity){
                cnt_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            Node new_node = Node(key, value, 1, ++this->time);
            // 插入新节点
            // cnt_table[key] = new_node;
            cnt_table.insert(make_pair(key, new_node));
            S.insert(new_node);
        }
        else{
            // 存在则更新
            Node old = iter->second;
            S.erase(old);
            old.freq++;
            old.time = ++this->time;
            old.value = value;
            S.insert(old);
            iter->second = old;
        }
    }
};

int main(){
    
    return 0;
}