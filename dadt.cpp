#include<iostream>
#include<cstdlib>
using namespace std;
const int tablesize=10;
class hashentry {
public:
	int key;
	long int value;
	hashentry(int key,int value) {
		this->key=key;
		this->value=value;
	}
};

class hashmap {
private:
	hashentry **table;
public:
	hashmap() {
		table= new hashentry *[tablesize];
		for(int i=0;i<tablesize;i++) {
			table[i]=NULL;
		}
	}
	int hashfunc(int key);
	int insert(int key,int value);
	int search(int key);
	void remove(int key);
	void display();
};

int hashmap :: hashfunc(int key) {
		return key%tablesize;
	}
int hashmap :: insert(int key,int value) {
		int hash =hashfunc(key);
		while(table[hash] != NULL && table[hash]->key != key) {
			hash=hashfunc(hash+1);
		}
		if (table[hash]== NULL) {
			delete table[hash];
			table[hash]=new hashentry(key,value);
			return 1;
		}
	}
int hashmap :: search(int key) {
		int hash =hashfunc(key);
		while(table[hash] != NULL && table[hash]->key !=key) {
			hash=hashfunc(hash+1);
		}
		if(table[hash]==NULL) {
			return -1;
		}
		else
			return table[hash]->value;
	}
void hashmap :: remove(int key) {
		int hash =hashfunc(key);
		while(table[hash] != NULL) {
			if (table[hash]->key==key) {
				break;
			}
			else
				hash=hashfunc(hash+1);
		}
		if(table[hash]==NULL) {
			cout<<"Element Not Found at "<<key<<endl;
		}
		else
			table[hash]=NULL;
			delete table[hash];
		cout<<"Element deleted"<<endl;
	}
void hashmap :: display() {
		int i=0;
		for(i=0;i<tablesize;i++) {
			if(table[i]!= NULL) {
				cout<<"Index of Hash Table: "<<i<<endl;
				cout<<"Key: "<<table[i]->key<<endl;
				cout<<"Value: "<<table[i]->value<<endl;
				cout<<"\n";
			}
		}
	}

int main() {
	hashmap hash;
	    int key, value;
	    int choice;
	    while (1)
	    {
	        cout<<"1.Insert element into the table"<<endl;
	        cout<<"2.Search element from the key"<<endl;
	        cout<<"3.Delete element at a key"<<endl;
	        cout<<"4.Display Hash Table"<<endl;
	        cout<<"5.Exit"<<endl;
	        cout<<"Enter your choice: ";
	        cin>>choice;
	        switch(choice)
	        {
	        case 1:
	            cout<<"Enter element to be inserted: ";
	            cin>>value;
	            cout<<"Enter key at which element to be inserted: ";
	            cin>>key;
	            hash.insert(key, value);
	            break;
	        case 2:
	            cout<<"Enter key of the element to be searched: ";
	            cin>>key;
	            if (hash.search(key) == -1)
	            {
	            cout<<"No element found at key "<<key<<endl;
	            continue;
				}
				else
				{
					cout<<"Element at key "<<key<<" : ";
					cout<<hash.search(key)<<endl;
				}
	            break;
	        case 3:
	            cout<<"Enter key of the element to be deleted: ";
	            cin>>key;
	            hash.remove(key);
	            break;
	        case 4:
	        	cout<<"***Displaying Hash Table***"<<endl;
	        	hash.display();
	        	break;
	        case 5:
	            exit(1);
	        default:
	           cout<<"nEnter correct option";
	       }
	    }
	return 0;
}


#include <iostream>
#include <cstdlib>
using namespace std;
#define max 10
typedef struct list {
    int data;
    struct list* next;
} node_type;
node_type *ptr[max], *root[max], *temp[max];

class Dictionary {
public:
    int index;

    Dictionary();
    void insert(int);
    void search(int);
    void delete_ele(int);
};

Dictionary::Dictionary()
{
    index = -1;
    for (int i = 0; i < max; i++) {
        root[i] = NULL;
        ptr[i] = NULL;
        temp[i] = NULL;
    }
}

void Dictionary::insert(int key)
{
    index = int(key % max);
    ptr[index] = (node_type*)malloc(sizeof(node_type));
    ptr[index]->data = key;
    if (root[index] == NULL) {
        root[index] = ptr[index];
        root[index]->next = NULL;
        temp[index] = ptr[index];
    }
    else {
        temp[index] = root[index];
        while (temp[index]->next != NULL)
            temp[index] = temp[index]->next;
        temp[index]->next = ptr[index];
    }
}

void Dictionary::search(int key)
{
    int flag = 0;
    index = int(key % max);
    temp[index] = root[index];
    while (temp[index] != NULL) {
        if (temp[index]->data == key) {
            cout << "\nSearch key is found!!";
            flag = 1;
            break;
        }
        else
            temp[index] = temp[index]->next;
    }
    if (flag == 0)
        cout << "\n search key not found.......";
}
void Dictionary::delete_ele(int key)
{
    index = int(key % max);
    temp[index] = root[index];
    while (temp[index]->data != key && temp[index] != NULL) {
        ptr[index] = temp[index];
        temp[index] = temp[index]->next;
    }
    ptr[index]->next = temp[index]->next;
    cout << "\n" << temp[index]->data << " has been deleted.";
    temp[index]->data = -1;
    temp[index] = NULL;
    free(temp[index]);
}
int main()
{
    int ch, n, num;
    char c;
    Dictionary d;
    do {
        cout << "\nMENU:\n1.Create";
        cout << "\n2.Search for a value\n3.Delete an value";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "\nEnter the number of elements to be inserted:";
            cin >> n;
            cout << "\nEnter the elements to be inserted:";
            for (int i = 0; i < n; i++) {
                cin >> num;
                d.insert(num);
            }
            break;
        case 2:
            cout << "\nEnter the element to be searched:";
            cin >> n;
            d.search(n);
            break;
        case 3:
            cout << "\nEnter the element to be deleted:";
            cin >> n;
            d.delete_ele(n);
            break;

        default:
            cout << "\nInvalid choice....";
            break;
        }
        cout << "\nEnter y to continue......";
        cin >> c;
    } while (c == 'y');
}


