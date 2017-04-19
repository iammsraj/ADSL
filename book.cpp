#include<iostream>
#include<cstring>

using namespace std;

class node
{
public:
    string name;
    node *newptr[10];
    int num;


    node()
    {
        num=0;
        for(int i=0;i<10;i++)
        newptr[i]=NULL;
    }

};

class Book
{
public:
node *root;
    void create();
    void display(node *root);

};

void Book::create()
{
    node *temp,*chapter,*section,*subsection;


    temp=new node;
    cout<<"Enter name of Book";
    cin>>temp->name;
    cout<<"\nEnter number of chapters in Book:"<<temp->name;
    cin>>temp->num;
    root=temp;
        for(int i=0;i<root->num;i++)
        {
            chapter=new node;
            cout<<"\nEnter chapter name";
            cin>>chapter->name;
            cout<<"\nEnter number of sections in "<<chapter->name;
            cin>>chapter->num;

            root->newptr[i]=chapter;
            for(int j=0;j<root->newptr[i]->num;j++)
            {
                section=new node;
                cout<<"\nEnter section name";
                cin>>section->name;
                cout<<"\nEnter number of sub section";
                cin>>section->num;

                root->newptr[i]->newptr[j]=section;

                for(int k=0;k<root->newptr[i]->newptr[j]->num;k++)
                {
                       subsection=new node;
                       cout<<"\nEnter subsection name";
                       cin>>subsection->name;
                       root->newptr[i]->newptr[j]->newptr[k]=subsection;
                }
            }
        }
    }


void Book::display(node *root)
{


    cout<<"-------------"<<root->name<<"---------------"<<endl;
    for(int i=0;i<root->num;i++)
    {
        cout<<"\t =>"<<root->newptr[i]->name<<endl;


        for(int j=0;j<root->newptr[i]->num;j++)
        {
            cout<<"\t\t:"<<root->newptr[i]->newptr[j]->name<<endl;




            for(int k=0;k<root->newptr[i]->newptr[j]->num;k++)
            {
                cout<<"\t\t\t-"<<root->newptr[i]->newptr[j]->newptr[k]->name<<endl;
            }
        }
    }




}
int main(void) {

    Book B;
    B.create();
    B.display(B.root);
    return 0;
}

