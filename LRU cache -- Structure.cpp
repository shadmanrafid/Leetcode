class LRUCache {


    struct List_element{
        int key;
        int value;
        List_element *prev;
        List_element *next;
        List_element (int key, int value)
        {
            this->key = key;
            this->value = value;
            next=prev=NULL;
        }
    };
public:

    int capacity;
    int size;
    unordered_map<int,List_element*>cache;
    List_element *anchor = new List_element(NULL,NULL);

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end())
        {
            return -1;
        }
        else
        {
            List_element *node = cache[key];
            move_to_head(node);
            return node->value;
        }

    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end())
        {
            List_element *node = cache[key];
            node->value = value;
            move_to_head(node);
        }
        else
        {
            List_element* node = new List_element(key,value);
            Insert_node(node);
            cache[key] = node;
            if(++size > this->capacity)
            {
                List_element* tail = pop_tail();
                --size;
                cache.erase(tail->key);


            }
        }

    }
    void Insert_node(List_element* node)
    {
        if(anchor->next == NULL)
        {
            anchor->next = node;
            anchor->prev = node;
            node->next = anchor;
            node->prev = anchor;

        }
        else
        {
            anchor->next->prev = node;
            node->next = anchor->next;
            node->prev = anchor;
            anchor->next = node;
        }


    }

    void move_to_head(List_element *node)
    {
        if (anchor->next == node) return;
        else {

            node->prev->next = node->next;
            node->next->prev = node->prev;

            anchor->next->prev = node;
            node->next = anchor->next;
            node->prev = anchor;
            anchor->next = node;
        }
    }

    List_element* pop_tail()
    {
        List_element *temp = anchor->prev;
        anchor->prev->prev->next = anchor;
        anchor->prev = anchor->prev->prev;
        return temp;



    }

    void print_list()
    {
        printf("the list is as follows\n");
        List_element *cur = anchor->next;
        while(cur != anchor)
        {
            printf("key:%d value:%d\n",cur->key,cur->value);
            cur = cur->next;
        }
        printf("\n\n\n");
    }
};
