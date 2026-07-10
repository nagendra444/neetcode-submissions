class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int,Node*> mp;

    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;

        before->next = after;
        after->prev = before;
    }

    void addToFront(Node* node) {
        Node* first = head->next;

        head->next = node;
        node->prev = head;

        first->prev = node;
        node->next = first;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //hashmap lookup
        //add node to the front of DLL
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            moveToFront(node);
            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        //if size exceed -> remove least recently used
        //update or create 
        //move the node to front of DLL
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->value = value;
            moveToFront(node);
            return;
        }

        Node* new1 = new Node(key,value);
        mp[key] = new1;
        addToFront(new1);

        if(mp.size()>cap){
            Node* lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

    }
};
