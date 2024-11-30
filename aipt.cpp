#include <fstream>
#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <typeinfo>

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
struct node2 {
  student info;
  node2* next;
};
struct node{
    node *next;
    student info;
};

node* read(){
    node *p, *lst;
    lst = NULL;
    int i, n;
    float *sum = new float;
    string *filename = new string;
    string strInput;
    cin>>*filename;
    ifstream file(*filename);
    n=1;
    if(!file.is_open()){
        cout << "File not found" << '\n';
        return NULL;
    }
    while (file){
        n++;
        *sum=0;
        p = new node;
        file>>strInput;
        if (!file)
            break;
        p->info.p.second = strInput;
        cout << p->info.p.second << '\n';
        file>>strInput;
        p->info.p.first = strInput;
        cout << p->info.p.first << '\n';
        file>>strInput;
        p->info.p.otch = strInput;
        cout << strInput << '\n';
        file>>strInput;
        p->info.group = strInput;
        cout << strInput << '\n';
        for (i=0;i<5;i++){
            file>>strInput;
            p->info.u.marks[i] = stoi(strInput);
            *sum+=p->info.u.marks[i];
            cout << strInput << '\n';
        }
        p->info.u.average = (float)*sum/5.0;
        cout << p->info.u.average << '\n';
        p->next = lst;
        lst = p;
    }
    cout << n<<'\n';

    delete(sum);
    file.close();
    return lst;
}
void free_memory(node *lst, node *first){
    node *now=lst, *next=lst;
    while (next){
        next=now->next;
        delete(now);
        now=next;
    }
    now = first;
    ofstream file;
    file.open("kekww.txt");
    while (first){
        file<<now->info.p.second<<"\n";
        file<<now->info.p.first<<"\n";
        file<<now->info.p.otch<<"\n";
        file<<now->info.group<<"\n";
        file<<now->info.u.marks[0]<<" ";
        file<<now->info.u.marks[1]<<" ";
        file<<now->info.u.marks[2]<<" ";
        file<<now->info.u.marks[3]<<" ";
        file<<now->info.u.marks[4]<<"\n";
        file<<now->info.u.average<<"\n";
        first=first->next;
        delete(now);
        now=first;
    }
    cout<<"\nNow memory is free\n";
}

void dop(node *lst){
    node2 *lst1, *fst, *p1;
    node *now=lst, *p=lst, *head=lst, *cur=lst;
    int n, k=0,l=0;
    while(head!=NULL){
        n=0;
        now=head;
        p=head;
        while (p->next!=NULL){
            if (now->info.u.average<p->next->info.u.average){
                now=p->next;
                cur=p;
                n=1;
            }
            p=p->next;
        }
        p1 = new node2;
        p1->info = now->info;
        if (n!=1){
            head=head->next;
            delete(now);
        }
        else{
            cur->next=now->next;
            delete(now);
        }
        cout<<p1->info.group<<endl;
        if (k==0){
            lst1=p1;
            p1->next=p1;
            fst=p1;
            k=1;
        }
        else{
            p1->next=lst1;
            lst1=p1;
            fst->next=lst1;
        }
        l++;
    }
    ofstream file;
    file.open("kekww.txt");
    while (l!=0){
        file<<lst1->info.p.second<<"\n";
        file<<lst1->info.p.first<<"\n";
        file<<lst1->info.p.otch<<"\n";
        file<<lst1->info.group<<"\n";
        file<<lst1->info.u.marks[0]<<" ";
        file<<lst1->info.u.marks[1]<<" ";
        file<<lst1->info.u.marks[2]<<" ";
        file<<lst1->info.u.marks[3]<<" ";
        file<<lst1->info.u.marks[4]<<"\n";
        file<<lst1->info.u.average<<"\n";
        fst=lst1->next;
        delete(lst1);
        lst1=fst;
        l--;
    }
}

int main(){
    node *lst;
    lst=read();
    dop(lst);
    
    return 0;
}