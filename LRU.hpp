#include <iostream> 
#include <unordered_map>
#include <stdexcept>
#include <string>

#include "Node.cpp"
template <typename T>

class LRUCache {
public:

  Node <T>* head=new Node <T> (0,0);
  Node<T> *tail=new Node <T> (-1,-1);

  unordered_map<T,Node<T>*>mp;

  int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
    }
    
    T get(T key) {
        if(mp.find(key)!=mp.end()){
            Node<T>* temp=mp[key];
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            
            Node<T>* nextNode=head->next;
            head->next=temp;
            temp->prev=head;
            temp->next=nextNode;
            nextNode->prev=temp;

            return temp->value;
        }
        return -1;
    }
    
    void put(T key, T value) {
        if(mp.find(key)!=mp.end()){

            Node<T>* latestNode=mp[key];
            latestNode->value=value;
            latestNode->prev->next=latestNode->next;
            latestNode->next->prev=latestNode->prev;

            Node<T>* nextNode=head->next;
            head->next=latestNode;
            latestNode->prev=head;
            latestNode->next=nextNode;
            nextNode->prev=latestNode;
        }
        else if(mp.size()<capacity){
            Node<T>* newNode=new Node<T>(key,value);
            mp.insert({key,newNode});

            Node<T>* nextNode=head->next;
            head->next=newNode;
            newNode->prev=head;
            newNode->next=nextNode;
            nextNode->prev=newNode;
        }
        else{
            Node<T>* leastUsed=tail->prev;
            mp.erase(leastUsed->key);

            leastUsed->prev->next=tail;
            tail->prev=leastUsed->prev;

            Node<T>* newNode=new Node<T>(key,value);
            Node<T>* nextNode=head->next;
            head->next=newNode;
            newNode->prev=head;
            newNode->next=nextNode;
            nextNode->prev=newNode;

            mp.insert({newNode->key,newNode});
        }
    }
};

