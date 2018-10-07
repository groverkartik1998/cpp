#include<iostream>
using namespace std;
void swap(struct node *,struct node *);
struct node
{
	int data;
	node *next;
}*save;
struct 	node *head,*tail;
void add_beg_node()
{
	int i;
	cout<<"enter the data : ";
	cin>>i;
	node *temp=new node;
	temp->data=i;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		save=head;
		head=temp;
		temp->next=save;
	}
}
void add_mid_node()
{
	int i,n;
	cout<<"enter the data : ";
	cin>>i;
    node *temp=new node;
	node *temp1=new node;
	temp->data=i;
	temp->next=NULL;
	cout<<"enter the node after which u want to insert : ";
	cin>>n;
	temp1=head;
    while(temp1->data!=n)
    {
      temp1=temp1->next;
  }
	  temp->next=temp1->next;
	  temp1->next=temp;
  }
void add_end_node()
{
	int i;
	cout<<"enter the data : ";
	cin>>i;
	node *temp=new node;
	temp->data=i;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
	tail->next=temp;
	tail=tail->next;
	}
}
void add_sorted_way()
{
	int i;
	cout<<"enter the data : ";
	cin>>i;
	node *temp=new node;
	temp->data=i;
	temp->next=NULL;
	if(head==NULL)
	{
	   head=temp;	
	}
	else if(head->next==NULL)
	{
		if(temp->data>head->data)
		     head->next=temp;
	    else
	    {
	    	temp->next=head;
	    	head=temp;
		}
	         
	}
	else
	{
		int flag;
		node *ptr=head,*t;
		while(ptr->next!=NULL)
		{
			flag=0;
			t=ptr;
			ptr=ptr->next;
			if(temp->data<ptr->data)
			{
				t->next=temp;
			    temp->next=ptr;
			    flag=1;
			    break;
			}
		
		}
		if(flag==0)
		  {
		  	ptr->next=temp;
		  }
		
	}
}
void delete_beg()
{
	node *temp=new node;
	 if(head==NULL)
        {
            cout<<"\nList is Empty:\n";
        }
     else
        {
            temp=head;
	        head=head->next;
	        delete temp;	
		}	
}
void delete_mid()
{
	int pos;
	node *temp,*ptr;
	 if(head==NULL)
        {
            cout<<"\nList is Empty:\n";
        }
     cout<<"enter the position of the node to be deleted : ";
     cin>>pos;
     if(pos==0)
       delete_beg();
     else
     {
     	ptr=head;
     	for(int i=0;i<pos;i++)
     	{
     		temp=ptr;
     		ptr=ptr->next;
     		if(ptr==NULL)
     		   cout<<"Location not found"<<endl;
		 }
		 temp->next=ptr->next;
		 delete ptr;
	 }
}
void delete_end()
{
	 struct node *temp,*ptr;
     if(head==NULL)
        {
    	    cout<<"\nList is Empty:\n";
    	     exit(0);
	    }
	 else if(head->next==NULL)
	    {
	 	    ptr=head;
	 	    head=NULL;
	 	    delete ptr;
	    }
	 else
	    {
	 	   ptr=head;
	 	   while(ptr->next!=NULL)
	 	   {
	 	    	temp=ptr;
			   ptr=ptr->next;
			}
			temp->next=NULL;
			delete ptr;
	    }
}
void search()
{
	int e,flag=0;
	node *ptr;
	ptr=head;
	cout<<"enter element to be searched : ";
	cin>>e;
	while(ptr!=NULL)
	{
		if(ptr->data==e)
		 flag=1;
		 ptr=ptr->next;
	}
	if(flag==1)
	  cout<<"Found"<<endl;
	else
	  cout<<"Not Found"<<endl;
}
void sort()
{
	int i;
	do
	{
		i=0;
		node *ptr=head;
		node *temp=NULL;
		while(ptr->next!=temp)
		{
			if(ptr->data>ptr->next->data)
			{
				swap(ptr,ptr->next);
			    i=1;	
			}
		  ptr=ptr->next;
		}
		temp=ptr;
	}while(i);
}
void swap(struct node *p,struct node *q)
{
  int temp;
  temp=p->data;
  p->data=q->data;
  q->data=temp;	
}
void reverse()
{
     node *current = head;
        node *prev = NULL, *next = NULL;
         while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;	
}
void display()
{
	if(head==NULL)
        {
    	    cout<<"\nList is Empty:\n";
    	     exit(0);
	    }
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl; 
}
int main()
{
	int i,n,c;
    cout<<" 1  -> Insertion at beginning \n 2  -> Insertion at any position \n 3  -> Insertion at end \n 4  -> Insert in a sorted way \n 5  -> Delete from beginning \n 6  -> Delete at any position \n 7  -> Delete from end \n 8  -> Search \n 9  -> Display \n 10 -> Sort List \n 11 -> Reverse list \n 12 -> Exit "<<endl;
	while(1)
	{
		cout<<endl<<"enter the choice : ";
		cin>>c;
	switch(c)
	{
		case 1:
			{
			    add_beg_node();
				 break;	
		    }
		case 2:
			{
		        add_mid_node();
             	break;
		    }
		case 3:
			{
			     add_end_node();
				 break;	
		    }
		case 4:
			{
			     add_sorted_way();
				 break;	
		    }
		case 5:
		  	{
		    	 delete_beg();
		    		break;
			}
		case 6:
		  	{
		    	 delete_mid();
		    		break;
			}
		case 7:
		  	{
		    	 delete_end();
		    		break;
			}
		case 8:
		  	{
		    	 search();
		    		break;
			}
		case 9:
		  	{
		    	 display();
		    		break;
			}
		case 10:
		    {
		         sort();
		         break;
			}
		case 11:
		    {
		         reverse();
		         break;
			}
		case 12:
	    	{
	    		cout<<endl;
	    		cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - T H A N K S- - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<endl;
			    exit(1);
			}				
			}
	}
	return 0;
}
