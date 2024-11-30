#include <fstream>
#include <iostream>
using namespace std;
#include <string>
#include <cctype>

struct phio{
    string first;
    string second;
    string otch;    
};

struct uspeh{
    float average;
    int marks[5];
};

struct student{
    string group;
    struct phio p;
    struct uspeh u;    
};

struct node{
    node *next;
    student info;
};

node* read(){
    node *p, *lst;
    lst = NULL;
    int *i = new int, *n = new int;
    float *sum = new float;
    string filename;
    string strInput;
    cin>>filename;
    ifstream file(filename);
    while (file){
        *sum=0;
        p = new node;
        file>>strInput;
        p->info.p.second = strInput;
        cout << p->info.p.second << '\n';
        file>>strInput;;
        p->info.p.first = strInput;
        cout << strInput << '\n';
        file>>strInput;;
        p->info.p.otch = strInput;
        cout << strInput << '\n';
        file>>strInput;;
        p->info.group = strInput;
        cout << strInput << '\n';
        file>>strInput;
        file>>strInput;
        file>>strInput;
        file>>strInput;
        file>>strInput;
        cout << strInput << '\n';
        p->next = lst;
        lst = p;
    }
    delete(i);

    delete(n);
    delete(sum);
    file.close();
    return lst;
}
void free_memory(node *lst){
    node *now=lst, *next=lst;
    while (next){
        next=now->next;
        delete(now);
        now=next;
    }
    cout<<"\nNow memory is free\n";
}

int main()
{
    node *lst;
    string filename;
    int n;
    lst=read();
    free_memory(lst);
    return 0;
}
