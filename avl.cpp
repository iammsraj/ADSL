#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class node {
public:
    char k[20];
    char m[20];
    int bf;
    class node* left;
    class node* right;
};

class dict {
public:
    node* root;
    node* insert(char k[20], char m[20], int c_flag);
    node* create(class node* root, char k[20], char m[20], int c_flag);
    void display(class node* root);
    void search();
    int update(node* root, char k[20]);
    node* del(node* root, char k[20]);
    node* min(node* q);
};

node* dict::insert(char k[20], char m[20], int c_flag)
{

    root = create(root, k, m, c_flag);
    return (root);
}

class node* dict::create(class node* root, char k[20], char m[20], int c_flag)
{

    class node *t1, *t2;

    if (root == NULL) {
        root = new node;
        strcpy(root->k, k);
        strcpy(root->m, m);
        root->left = NULL;
        root->right = NULL;
        root->bf = 0;
        c_flag = 1;
        return (root);
    }
    if (strcmp(k, root->k) <= 0) {
        root->left = create(root->left, k, m, c_flag);

        if (c_flag == 1) {
            switch (root->bf) {
            case -1:
                root->bf = 0;
                break;
            case 0:
                root->bf = 1;
                break;
            case 1:
                t1 = root->left;
                if (t1->bf == 1) {
                    cout << "\nLL rotation";
                    root->left = t1->right;
                    t1->right = root;
                    root->bf = 0;
                    root = t1;
                }
                else {
                    cout << "\nLR Rotation";

                    t2 = t1->right;
                    t1->right = t2->left;
                    t2->left = t1;
                    root->left = t2->right;
                    t2->right = root;

                    if (t2->bf == -1)
                        t1->bf = 1;
                    else
                        t1->bf = 0;

                    if (t2->bf == 1)
                        root->bf = -1;
                    else
                        root->bf = 0;

                    root = t2;
                }
                root->bf = 0;
                c_flag = 0;
                break;
            }
        }
    }
    if (strcmp(k, root->k) > 0) {
        root->right = create(root->right, k, m, c_flag);

        if (c_flag == 1) {
            switch (root->bf) {
            case 1:
                root->bf = 0;
                break;
            case 0:
                root->bf = -1;
                break;
            case -1:
                t1 = root->right;
                if (t1->bf == -1) {
                    cout << "\nRR rotation";
                    root->right = t1->left;
                    t1->left = root;
                    root->bf = 0;
                    root = t1;
                }
                else {
                    cout << "\nRL Rotation";

                    t2 = t1->left;
                    t1->left = t2->right;
                    t2->right = t1;
                    root->right = t2->left;
                    t2->left = root;

                    if (t2->bf == 1)
                        t1->bf = -1;
                    else
                        t1->bf = 0;

                    if (t2->bf == -1)
                        root->bf = 1;
                    else
                        root->bf = 0;

                    root = t2;
                }
                root->bf = 0;
                c_flag = 0;
                break;
            }
        }
    }

    return (root);
}

void dict::display(class node* root)
{
    if (root != NULL) {
        display(root->left);
        cout << root->k << "\t";
        cout << root->m << "\n";
        display(root->right);
    }
}

void dict::search()
{
    char k[20];
    int f = 0;

    cout << "\nEnter Keyword which u want to search:";
    cin >> k;

    node* temp = root;

    while (temp != NULL) {
        if (strcmp(k, temp->k) == 0) {
            cout << "\nKeyword is Present";
            f = 1;
            break;
        }
        if (strcmp(k, temp->k) <= 0)
            temp = temp->left;
        if (strcmp(k, temp->k) > 0)
            temp = temp->right;
    }
    if (f == 0)
        cout << "\nKeyword not present";
}
int dict::update(node* root, char k[20])
{
    while (root != NULL) {
        if (strcmp(k, root->k) == 0) {
            cout << "\nEnter New Meaning of Keyword" << root->k;
            cin >> root->m;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;
        if (strcmp(k, root->k) > 0)
            root = root->right;
    }
    return -1;
}

node* dict::del(node* root, char k[20])
{
    node* temp;

    if (root == NULL) {
        cout << "\nElement No Found";
        return root;
    }

    if (strcmp(k, root->k) < 0) {
        root->left = del(root->left, k);
        return root;
    }
    if (strcmp(k, root->k) > 0) {
        root->right = del(root->right, k);
        return root;
    }

    if (root->right == NULL && root->left == NULL) {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL) {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    else if (root->left == NULL) {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }
    temp = min(root->right);
    strcpy(root->k, temp->k);
    root->right = del(root->right, temp->k);
    return root;
}

node* dict::min(node* q)
{
    while (q != NULL) {
        q = q->left;
    }
    return q;
}

int main()
{
    dict t;
    t.root = NULL;
    class node* root;
    int ch, c, c_flag = 1;
    char k[20], m[20];

    do {
        cout << "\n Enter ur choice";
        cout << "\n 1.Insert 2. Display 3.Search 4.Update 5.Delete";
        cin >> ch;
        switch (ch) {
        case 1:
            do {
                cout << "\n Enter Keyword";
                cin >> k;
                cout << "\n Enter Meaning";
                cin >> m;
                root = t.insert(k, m, c_flag);
                cout << "\n Do you want to add more";
                cin >> c;
            } while (c == 1);
            break;
        case 2:
            cout << "AVL TREE:";
            t.display(root);
            break;
        case 3:
            t.search();
            break;
        case 4:
            if (t.root == NULL) {
                cout << "\nDictionary is Empty. First add keywords then try again ";
            }
            else {
                cout << "\nEnter Keyword which meaning  want to update:";
                char k[20];
                cin >> k;
                if (t.update(t.root, k) == 1)
                    cout << "\nMeaning Updated";
                else
                    cout << "\n Keyword Not Found, Meaning can't updated";
            }
            break;
        case 5:
            if (t.root == NULL) {
                cout << "\nDictionary is Empty. First add keywords then try again ";
            }
            else {
                cout << "\nEnter Keyword which u want to delete:";
                char k[20];
                cin >> k;
                if (t.root == NULL) {
                    cout << "\nNo any Keyword";
                }
                else {
                    t.root = t.del(t.root, k);
                }
            }
            break;
        }

    } while (ch <= 5);

    t.search();

    return 0;
}


