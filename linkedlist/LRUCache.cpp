class LRUCache {
public:
    class Node{
       public:
	int key; 
	int value; 
	Node *pre; 
	Node *next; 
  
	
	Node(int k, int v) 
	{ 
		key = k; 
		value = v;
		pre=NULL;next=NULL;
	} 
    };

 unordered_map<int, Node*> map; 
	int capacity, count; 
	Node *head, *tail; 
     	void deleteNode(Node *node) 
	{ 
		node->pre->next = node->next; 
		node->next->pre = node->pre; 
	} 

	void addToHead(Node *node) 
	{ 
		node->next = head->next; 
		node->next->pre = node; 
		node->pre = head; 
		head->next = node; 
	}
	
    LRUCache(int cap)
    {
        // code here
        	capacity = cap; 
		head = new Node(0, 0); 
		tail = new Node(0, 0); 
		head->next = tail; 
		tail->pre = head; 
		head->pre = NULL; 
		tail->next = NULL; 
		count = 0; 
    }
    
    //Function to return value corresponding to the key.
 int get(int key)
    {
        // your code here
        if (map[key] != NULL) { 
			Node *node = map[key]; 
			int result = node->value; 
			deleteNode(node); 
			addToHead(node); 
		
			return result; 
		} 
	
		return -1; 
    }
    
     //Function for storing key-value pair.
  void put(int key, int value)
    {
        // your code here   
       
		if (map[key] != NULL) { 
			Node *node = map[key]; 
			node->value = value; 
			deleteNode(node); 
			addToHead(node); 
		} 
		else { 
			Node *node = new Node(key, value); 
			map[key]= node; 
			if (count < capacity) { 
				count++; 
				addToHead(node); 
			} 
			else { 
				map.erase(tail->pre->key); 
				deleteNode(tail->pre); 
				addToHead(node); 
			} 
		} 
    }
       

};
