#include<stdio.h>

#include<iostream>



using namespace std;

int c = 0;

struct adj_list

{

    int dest;

    adj_list *next;

}*newptr = NULL, *newptr1 = NULL, *p = NULL, *q = NULL;

struct Graph

{

    int v;

    adj_list *ptr;

}array[5];

void addReverseEdge(int src,int dest)

{

    newptr1 = new adj_list;

    newptr1->dest = src;

    newptr1->next = NULL;

    if (array[dest].ptr == NULL)

    {

        array[dest].ptr = newptr1;

        q = array[dest].ptr;

        q->next = NULL;

    }

    else

    {

        q = array[dest].ptr;

        while (q->next != NULL)

        {

            q = q->next;

        }

        q->next = newptr1;

    }

}

void addEdge(int src,int dest)

{

    newptr = new adj_list;

    newptr->dest = dest;

    newptr->next = NULL;

    if (array[src].ptr == NULL)

    {

        array[src].ptr = newptr;

        p = array[src].ptr;

        p->next = NULL;

    }

    else

    {

        p = array[src].ptr;

        while (p->next != NULL)

        {

            p = p->next;

        }

        p->next = newptr;

    }

    addReverseEdge(src,dest);

}

void print_graph(int n)

{

    for (int i = 0; i < n; i++)

    {

        cout<<"Adjacency List of "<<array[i].v<<endl;

        while (array[i].ptr != NULL)

        {

            cout<<(array[i].ptr)->dest<<"\t";

            array[i].ptr = (array[i].ptr)->next;

        }

        cout<<endl;

    }

}

int main()

{

    int n;

    cout<<"Enter the no of vertices\n";

    cin>>n;

    for (int i = 0; i < n; i++)

    {

        array[i].v = i;

        array[i].ptr = NULL;

    }

    addEdge(0, 1);

    addEdge(0, 3);

    addEdge(1, 1);

    addEdge(1, 4);

    addEdge(2,2 );

    addEdge(2, 3);

    addEdge(3, 4);

    addEdge(4, 5);

    print_graph(n);



}

#include<iostream>

using namespace std;

class graph{

public:


	void create();
	void input();
	void print();
	void Edge_Count();
	int G_mat[10][10];
	int entry_mat[10][10];
	int n,i,j;
	int k=0;

};

void graph ::create()
{
	cout<<"\nEnter Vertices number of Vertices:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			G_mat[i][j]=0;
		}
	}

}

void graph ::input()
{

	int a,b,cont;
	do
	{
	cout<<"\nEnter Adjacent Vertices:";
	cin>>a>>b;
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
			   if(i==a && j==b && G_mat[a][b]==0 )
			   {
				   G_mat[i][j]=1;
				   G_mat[j][i]=1;
				   ++k;


			   }
			}
		}
	cout<<"\nDo you want to add Edges[1/0]";
	cin>>cont;
	}while(cont==1);

}


void graph :: print()
{
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<G_mat[i][j]<<" ";
			}
			cout<<"\n";
		}

}
void graph :: Edge_Count()
{
	cout<<"\nNumber of Edges Are:"<<k;

}

int main()
{
	int ch,cont;
	graph G;
	G.create();
	do{
	cout<<"\nWhich Operation to Perform:"
			"\n1.Input"
			"\n2.Print"
			"\n3.Number of Edges";
	cin>>ch;
	if(ch==1)
	{
	G.input();
	}
	if(ch==2)
	{
	G.print();
	}
	if(ch==3)
	{
		G.Edge_Count();
	}
	cout<<"\nDo you Want To Perform operations[1/0]";
	cin>>cont;
	}while(cont==1);
	return 0;
}


