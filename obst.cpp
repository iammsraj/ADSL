#include <iostream>
using namespace std;
int main()
{
    float e[100][100], w[100][100], p[100], t;
    int i, n, j, l, r, root[100][100], k[100];
    cout << "this is optimal binary search tree\n";
    cout << "enter the value of n\n";
    cin >> n;
    cout << "enter the values of the keys & probability\n";
    for (i = 1; i <= n; i++) {
        cin >> k[i];
        cin >> p[i];
    }
    for (i = 1; i <= n + 1; i++) {
        e[i][i - 1] = 0;
        w[i][i - 1] = 0;
    }

    for (l = 1; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            e[i][j] = 100.0;
            w[i][j] = w[i][j - 1] + p[j];
            for (r = i; r <= j; r++) {
                t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "the result is\n";
    cout << "values of e are:\n";
    for (i = 1; i <= n + 1; i++) {
        for (j = 0; j <= n; j++) {
            cout << "\t" << e[i][j];
        }
        cout << "\n";
    }
    cout << "\n values of root are:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << root[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "value of optimal search cost is:\n";
    cout << e[1][n];
    cout << "\n";
    cout << "\n value of root is:\n";
    cout << root[1][n];
    cout << "\n";
    return 0;
}

#include <iostream>
#define infi 999
using namespace std;
class obst {
public:
	int n;
	int *keys;
	int *freqs;
	obst(int n) {
		this->n=n;
		this->keys = new int[n];
		this->freqs = new int[n];
	}
	void accept() {
		for(int i=0;i<n;i++) {
			cout<<"Enter "<<i+1<<" key: \n";
			cin>>keys[i];
		}
		for(int i=0;i<n;i++) {
			cout<<"Enter "<<i+1<<" Frequency: \n";
			cin>>freqs[i];
		}
	}
	int optcost(int i,int j)
	{
	    int sumfreq=0;
	    for(int k=i;k<=j;k++)
	    sumfreq+=freqs[k];
	    int min=infi;

	    if (j<i)
	        return 0;
	    if(j==i)
	    {
	        return freqs[i];
	    }
	    for (int r = i; r <= j; ++r)
	       {
	               int cost = optcost(i, r-1) + optcost(r+1, j);
	               if (cost < min)
	                  min = cost;
	       }
	    return min + sumfreq;
	}
};

int main() {
    int n;
    cout<<"enter no of keys \n";
    cin>>n;
    obst o(n);
    o.accept();
    cout<<"Optimal Binary Tree Cost: \t";
    cout<<o.optcost(0,n-1);
    return 0;
}


