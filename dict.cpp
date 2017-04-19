#include<iostream>
#include<cstring>

using namespace std;

class node{
public:

	char key[20],meaning[70];
	class node*left,*right;
};

class Dictionary
{
public:
	node*root,*temp;
	void Create();
	void Insert(node*root,node*temp);
	node * Delnode(node *root,char key[]);
	int Update(node*root,char key[]);
	int Search(node*root,char key[]);
	void Disp(node*root);
	void min(node*);

};

void Dictionary :: Create()
{
	class node *temp;
	int ch;
	do{
		temp =new node;
		cout<<"Enter Keyword:";
		cin>>temp->key;
		cout<<"Enter Meaning:";
		cin>>temp->meaning;
		temp->left=NULL;
		temp->right=NULL;

		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			Insert(root,temp);
		}

		cout<<"\nDo you want to continue insertion(1/0)";
        cin>>ch;
	}while(ch==1);

}

void Dictionary :: Insert(node *root, node*temp)
{
 if(strcmp (temp->key,root->key)<0)
 {
	 if(root->left==NULL)
	 {
		 root->left=temp;

	 }
	 else
	 {
		 Insert(root->left,temp);
	 }

 }
 else
 {
	if(root->right==NULL)
	{
		root->right=temp;
	}
	else
	{
		Insert(root->right,temp);
	}
 }

}

void Dictionary :: Disp(node *root)
{

	if(root!=NULL)
	{
		Disp(root->left);
		cout<<"\nKeyword:  "<<root->key;
		cout<<"\nMeaning:  "<<root->meaning;
		Disp(root->right);

	}

}


int Dictionary :: Search(node*root,char key[])
{
	if(root==NULL)
	{
		cout<<"\nTree is Empty:";
	}
	else
	{
	cout<<"\nEnter Key to Search:";
				cin>>key;

	int c=1;
		while(root != NULL)
		{

			if(strcmp(key,root->key) == 0)
			{
				cout<<"\nNo of Comparisons:"<<c;
				return 1;
			}
			if(strcmp (key, root->key) < 0)
			{
				root = root->left;
				c++;
			}
			if(strcmp (key, root->key) > 0)
			{
				root = root->right;
				c++;
			}
		}
	}
		return -1;

}

int Dictionary :: Update(node * root,char key[20])
{
	if(root==NULL)
	{
		cout<<"\nTree is Empty";
	}
	while(root != NULL)
	{
		if(strcmp (key,root->key) == 0)
		{
			cout<<"\nEnter New Meaning ofKeyword"<<root->key;
			cin>>root->meaning;
			return 1;
		}
		if(strcmp (key, root->key) < 0)
			root = root->left;
		if(strcmp (key, root->key) > 0)
			root = root->right;
	}
	return -1;
}
node*  Dictionary :: Delnode(node *root,char key[20])
{
	node *temp;


	if (strcmp(key,root->key) < 0)
		{
			root->left = Delnode(root->left, key);
			return root;
		}
		if (strcmp(key,root->key) > 0)
		{
			 root->right = Delnode(root->right, key);
			 return root;
		}

		if (root->right==NULL&&root->left==NULL)
		{
			temp = root;
			delete temp;
			return NULL;
		 }
		 if(root->right==NULL)
		 {
			temp = root;
			root = root->left;
			delete temp;
			return root;
		 }
		 else if(root->left==NULL)
		 {
			temp = root;
			root = root->right;
			delete temp;
			return root;
		 }
		 return root;
}

void Dictionary  :: min(node *m)
{
	m=root;
	while(m->left!=NULL)
	{
		m=m->left;

	}
	cout<<"\nMinimum Element is:"<<m->key;

}

int main()
{
	Dictionary D;
	D.root=NULL;

	int choice,var;

	do{
		cout<<"\nWhich Operation do You Want To Perform:"
				"\n1.Create"
				"\n2.Display"
				"\n3.Search"
				"\n4.Update"
				"\n5.Delete"
				"\n6.Minimum Element"
				"\n7.Exit";
		cin>>choice;

		switch(choice)
		{
		case 1:
			D.Create();
			break;
		case 2://Display
			if(D.root==NULL)
			{
				cout<<"\nTree is Empty:";
			}
			D.Disp(D.root);
			break;
		case 3://Search
			char key[20];

			if( D.Search(D.root,key) == 1)
					cout<<"\nKeyword Found";
			else
					cout<<"\nKeyword Not Found";

			break;
		case 4://Update

			cout<<"\nEnter Keyword To Update Meaning:";
			cin>>key;
			if(D.Update(D.root,key)==1)
			{
				cout<<"Keyword found And Meaning Updated Successfully";
			}
			else
			{
				cout<<"\nKeyword Not Found";
			}

			break;



		case 5://Delete
			if(D.root == NULL)

			{
	 		cout<<"\nNo Element to Delete";
			}

				else
				{
					cout<<"\nEnter Keyword To Delete:";
									cin>>key;
				D.root = D.Delnode(D.root,key);
				}
			break;

		case 6:
			//MIN

			if(D.root==NULL)
			{
				cout<<"\nTree is Empty";
			}
			else
			{
				D.min(D.root);


			}


			break;

		case 7:
			//Exit
			break;
		}
		cout<<"\nDo you want to continue performing Operations(1/0)";
		cin>>var;
	}while(var==1);


	return 0;
}



