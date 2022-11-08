#include<bits/stdc++.h>
using namespace std;

static int cnt=0;
struct employee
{
    int id;
	char name[50];
	float salary;
	struct employee *next;
}*head=NULL,*last=NULL;

void countEmployee()
{
	cout<<"\nTotal Employee count is = "<<cnt;
}
void readLinkedList()
{
	FILE* file;
    file = fopen ("database.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nLocal Employee Database not found.'\n");
    }
	else
	{
		cout<<"\nLocal Employee Database founded.";
		cout<<"\nLoading employee data.";
		struct employee *temp=new struct employee;
		head=last=NULL;
		cnt=0;
		while(fread(temp, sizeof(struct employee), 1, file))
    	{

        	if(head==NULL)
        	{
            	head = last = new struct employee;

        	}
        	else
        	{
            	last->next = new struct employee;
            	last = last->next;
        	}
        	last->id = temp->id;
			cout<<"hiiiiii"<<endl;
        	strcpy(last->name,temp->name);
			last->salary = temp->salary;
        	last->next = NULL;
			cnt++;
        
    	}
		cout<<"\nLoading completed.\n";
    	fclose(file);
	}
}

void writeLinkedList(){
    
    struct employee* temp = head;
    
    FILE* file;
    file = fopen ("database.txt", "w");
	cout<<"\nSaving in database.";
    while(temp!=NULL)
    {
        fwrite(temp, sizeof(struct employee), 1, file);
        temp = temp->next;
    }
    
    if(fwrite != 0)
    {
        cout<<"\nEmployee data updated in the database.";
    }
    else
    {
        cout<<"\nError While Writing";
    }
    
    fclose(file);
    
}

void create()
{
	struct employee *t;
	int num;
	cout<<"\nHow many Employee do you want's to add:- ";
	cin>>num;

	while(num--)
	{
		if(head!=NULL)
		{
			t=new struct employee;
		}
		else
		{
			t=new struct employee;
			head=t;
			last=t;
		}
		cout<<flush;
		cout<<"Enter employee name:- ";
		scanf(" %[^\n]s",&t->name);
		cout<<flush;
		cout<<"Enter employee id:- ";
		cin>>t->id;
		cout<<"Enter employee salary:- ";
		cin>>t->salary;
        cout<<"\n";
        if(cnt>0)
        {
            t->next=NULL;
		    last->next=t;
		    last=t;
        }
        else
        {
            t->next=NULL;
            last=t;
        }
		cnt++;
	}
	writeLinkedList();

}

bool deleteById()
{
	int id;
	cout<<"Input id:- ";
	cin>>id;

	struct employee *p=NULL,*q=NULL;
	p=head;
	while (p)
	{
		if(p->id==id)
		{
			if(q!=NULL)
			{
				q->next=p->next;
				cnt--;
				free(p);
				
			}
			else
			{
				head=NULL;
				cnt--;
				free(p);
				
			}
			cout<<"\nEmployee removed.";
			writeLinkedList();
			return true;
		}
		q=p;
		p=p->next;
	}
	cout<<"\nEmployee not found.";
	return false;
	
}

bool deleteByName()
{
	char name[50];
	cout<<flush;
	cout<<"Input name:- ";
	scanf(" %[^\n]s",name);
	cout<<flush;
	struct employee *p=NULL,*q=NULL;
	p=head;

	while (p)
	{
		if(strcmp(p->name,name)==0)
		{
			if(q!=NULL)
			{
				q->next=p->next;
				cnt--;
				free(p);
				
			}
			else
			{
				head=NULL;
				cnt--;
				free(p);
				
			}
			cout<<"\nEmployee removed.";
			writeLinkedList();
			return true;
		}
		q=p;
		p=p->next;
		
	}
	cout<<"\nEmployee not found.";
	return false;
	
}


bool searchById()
{
	int id;
	cout<<"Input id:- ";
	cin>>id;
	struct employee *p=NULL;
	p=head;
	while (p)
	{
		if(p->id==id)
		{
			cout<<"\nEmployee founded, details of employee are\n";
			cout<<"Name of the employe is:- "<<p->name<<"\nId is:- "<<p->id<<"\nSalary is:- "<<p->salary;
			return true;
		}
		p=p->next;
	}
	cout<<"\nEmployee not found";
	return false;
	
}


bool searchByName()
{
	char name[50];
	cout<<flush;
	cout<<"Input name:- ";
	scanf(" %[^\n]s",&name);
	cout<<name;
	cout<<flush;
	struct employee *p=NULL;
	p=head;
	while (p)
	{
		if(strcmp(p->name,name)==0)
		{
			cout<<"\nEmployee founded, details of employee are\n";
			cout<<"Name of the employe is:- "<<p->name<<"\nId is:- "<<p->id<<"\nSalary is:- "<<p->salary;
			return true;
			
		}
		p=p->next;
	}
	cout<<"\nEmployee not found";
	return false;
	
}

bool updateDetails()
{
	struct employee *p=NULL;
	p=head;
	int id;
	cout<<"Input id:- ";
	cin>>id;
	while (p)
	{
		if(p->id==id)
		{
			cout<<"Employee found.\n";
			bool flag=true;
			while(flag)
			{
				int choice;
				cout<<flush;
				cout<<"\n0.Exit \n1.Update Name:- \n2.Update Id:- \n3.Update salary:- \n";
				cin>>choice;
				if(choice==1)
				{
					cout<<flush;
					cout<<"Enter new name:- ";
					scanf(" %[^\n]s",&p->name);
					cout<<flush;
					cout<<"Name updated:- \n";
				}
				else if(choice==2)
				{
					cout<<"Enter new id:- ";
					cin>>p->id;
					cout<<"Id updated:- \n";
				}
				else if(choice==3)
				{
					cout<<"Enter new salary:- ";
					cin>>p->salary;
					cout<<"Salary updated:- \n";
				}
				else if(choice==0)
				{
					flag=false;
				}
				else
				{
					cout<<"Wrong choice \n";
					flag=false;
				}
			}
			writeLinkedList();
			cout<<"Exiting...\n";
			return true;
	
		}
		p=p->next;
	}
	cout<<"Employee not found.\n";
	return false;
	
}



void display()
{
	if(cnt==0)
	{
		cout<<"\nEmpty database";
		return ;
	}
	struct employee *p;
	p=head;
    printf("\n");
	while(p!=NULL)
	{
		cout<<"Name of the employe is:- "<<p->name<<"\nId is:- "<<p->id<<"\nSalary is:- "<<p->salary;

		cout<<"\n\n";
		p=p->next;
	}
}


int main()
{
	int terminate=100;
	cout<<"\nLoading Program......";
	cout<<"\nChecking for local database.";
	readLinkedList();
	while(terminate--)
	{
		cout<<"\n\n--------------------Menu--------------------";
		cout<<"\nChoose any one from below options\n";
		cout<<"\n1. Load Employee data from database\n2. Save Employee data to database";
		cout<<"\n3. Create or add employee data\n4. Upadate Employee data";
		cout<<"\n5. Search Employee\n6. Remove Employee data\n7. Display Employee data";
		cout<<"\n8. Employee cnt\n9. Exit\n";
		cout<<"\nChoose option:- ";
		int choice,s=0;
		cin>>choice;
		switch (choice)
		{
		case 1:
			readLinkedList();
			break;
		case 2:
			writeLinkedList();
			break;
		case 3:
			create();
			break;
		case 4:
			updateDetails();
			break;
		case 5:
			cout<<"\n1. Search by Name: \n2. Search by id:";
			cout<<"\nchoose option:- ";
			cin>>s;
			if(s==1)
				searchByName();
			else if(s==2)
				searchById();
			else
				printf("\nWrong input.");
			break;
		case 6:
			cout<<"\n1. Delete by name:\n2. Delete by id:";
			cout<<"\nchoose option:- ";
			cin>>s;
			if(s==1)
				deleteByName();
			else if(s==2)
				deleteById();
			else
				cout<<"\nWrong input.";
			break;
		case 7:
			display();
			cout<<"\nPress any key to continue";
			cout<<flush;
			getchar();
			break;
		case 8:
			countEmployee();
			break;
		case 9:
			writeLinkedList();
			return 0;
		default:
			cout<<"\nWrong input, try again.";
			break;
		}

	}

}