#include<iostream>
#include<fstream>

using namespace std;

class Student{
    int RollNo;
    char Name[30];
    char Class[30];
    char Division[2];
    char Dept[15];
public:
    void AddRecord(){
        ofstream out;
        out.open("Student.dat", ios::app);
        cout<<"\n Enter Details(Roll No, Name, Class, Division, Dept): ";
        Student S;
        cin>>S.RollNo>>S.Name>>S.Class>>S.Division>>S.Dept;
        out.write((char*)&S, sizeof(S));
        out.close();
    }
    void Display(){
        Student S;
        ifstream in;
        in.open("Student.dat", ios::in);
        while(1){
            in.read((char*)&S, sizeof(S));
            if(in.eof())
                break;
            cout<<"\n "<<S.RollNo<<" "<<S.Name<<" "<<S.Class<<" "<<S.Division<<" "<<S.Dept;
        }
        in.close();
    }
    int Search(int n){
        int flag = 0;
        ifstream in;
        in.open("Student.dat", ios::in);
        Student S;
        while(1){
            in.read((char*)&S, sizeof(S));
            if(in.eof())
                break;
            if(S.RollNo == n){
                cout<<"\n "<<S.RollNo<<" "<<S.Name<<" "<<S.Class<<" "<<S.Division<<" "<<S.Dept;
                in.close();
                return 1;
            }
        }
        cout<<"\n Record Not Present.";
        in.close();
        return 0;
    }
    void Delete(int n){
        Student S;
        if(Search(n) == 1){
            ifstream in;
            in.open("Student.dat", ios::in);
            ofstream out;
            out.open("temp.dat", ios::out);
            while(1){
                in.read((char*)&S, sizeof(S));
                if(in.eof())
                    break;
                if(S.RollNo == n)
                    cout<<"\n Deleting...";
                else
                    out.write((char*)&S, sizeof(S));
            }
            in.close();
            out.close();
            remove("Student.dat");
            rename("temp.dat", "Student.dat");
            cout<<"\n Deletion Successful.";
        }
        else
            cout<<"\n No such record exist.";
    }
};

int main(){
    Student R;
    int ch, n;
    while(1){
        cout<<"\n\n\n 1. Add Record";
        cout<<"\n 2. Display all Records";
        cout<<"\n 3. Search Record";
        cout<<"\n 4. Delete Record";
        cout<<"\n 5. exit";
        cout<<"\n Enter your choice: ";
        cin>>ch;

        switch(ch){
            case 1: R.AddRecord();
                    break;
            case 2: R.Display();
                    break;
            case 3: cout<<"\n Enter Roll Number to be searched: ";
                    cin>>n;
                    R.Search(n);
                    break;
            case 4: cout<<"\n Enter Roll Number to be deleted: ";
                    cin>>n;
                    R.Delete(n);
                    break;
            case 5: return 1;
        }
    }
    return 0;
}


