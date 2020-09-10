#include<iostream.h>
#include<conio.h>

struct node
{
    int data;
    struct node* next;
    node(int x){
	data=x;
	next=NULL;
    }
};


void insert(struct node*& head,int x){
    if(head==NULL){
	head=new node(x);
	return;
    }
    struct node* temp=new node(x);
    struct node* go=head;
    while(go->next){
	go=go->next;
    }
    go->next=new node(x);
}

void oddeven(struct node*& head){
    struct node* even=NULL;
    struct node* oddhead=NULL;
    struct node* odd=NULL;
    struct node* go=head,*evenhead=NULL;
    while(go){
	if((go->data)%2==0){
	    if(!evenhead){
		evenhead=go;
		even=go;
	    }
	    else {
	     even->next=go;
	     even=go;
	    }
	}
	else {
	    if(!oddhead){
		oddhead=go;
		odd=go;
	    }
	    else {
	      odd->next=go;
	      odd=go;
	    }
	}
	go=go->next;
    }

    if(evenhead){
	head=evenhead;
    }
    else if(oddhead){
	head=oddhead;
    }
    if(even && oddhead){
	 even->next=oddhead;
	 odd->next=NULL;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    struct node* head=NULL;
	    int n,x;
	    cin>>n;
	    for(int i=0;i<n;i++){
		cin>>x;
		insert(head,x);
	    }
	    oddeven(head);
	    while(head){
		cout<<head->data<<" ";
		head=head->next;
	    }
	    cout<<endl;
	}
	getch();
}