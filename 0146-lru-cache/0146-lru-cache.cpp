class LRUCache {
public:
    class Node{
    public:
        int key,val;
        Node* prev;
        Node* next;
        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }
      

    };
      Node* head=new Node(-1,-1);
        Node* tail=new Node(-1,-1);
        unordered_map<int,Node*> m;
        int limit;
    void addnode(Node* newNode){
        Node* oldnext=head->next;
        head->next=newNode;
        oldnext->prev=newNode;
        newNode->next=oldnext;
        newNode->prev=head;
    }
    void deletenode(Node* oldnode){
        Node* oldprev=oldnode-> prev;
        Node* oldnext=oldnode->next;
        oldprev->next=oldnext;
        oldnext->prev=oldprev;
    }
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansnode=m[key];//pointing to the node
        int ans=ansnode->val;//getting its value to return
        deletenode(ansnode);
        addnode(ansnode);
        m[key]=ansnode;
        return ans;
    }
    
    void put(int key, int value) {
        //finding if the key exits or not
        if(m.find(key)!=m.end()){
            Node* oldnode=m[key];
            deletenode(oldnode);
            m.erase(key);
        }
        //finding if capacity is exceeded
        if(m.size()==limit){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        Node* newNode=new Node(key,value);
        addnode(newNode);
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */