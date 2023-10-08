#include<iostream>
using namespace std;
class SignUp;
class CommentStack{
  public:
		CommentStack *Next;
		CommentStack *Previous;
		string Comment;
		string UserName;
	CommentStack(string Comm , string Un)
	{
		Comment=Comm;	
		UserName=Un;
		Next=Previous=NULL;
	}
	void Display()
	{
		cout<<"\t\t\t\t+ BY "<<"("<<UserName<<")"<<" ="<<Comment<<endl;
	}
};
class CommentStackLinking
{
	public:
		CommentStack *Top;
		
	CommentStackLinking()
	{
		Top=NULL;
	}
	bool IsEmpty()
	{
		if(Top==NULL)
			return 1;
		else
			return 0;
	}
	void AddComment(string val , string un)
	{
		CommentStack *New=new CommentStack(val , un); 
		if(IsEmpty())
		{
			Top=New;
		}
		else
		{
			Top->Next=New;
			New->Previous=Top;
			Top=New;
		}
	}
	string Pop()
	{
		if(IsEmpty())
		{
			cout<<"STACK IS EMPTY !! "<<endl;
			return "";
		}
		else
		{
			CommentStack *Temp=Top;
			if(Temp->Previous==NULL) //IF HEAD IS GOING TO POP 
			{
				delete Temp;
				Top=NULL;
				return Temp->Comment;
			}
			else
			{
				string X=Top->Comment;
				Top=Top->Previous;
				Top->Next=NULL;
				delete Temp;
				return X;
			}
		}
	}
	string TopOfStack()
	{
		if(IsEmpty())
		{
			cout<<"STACK IS EMPTY !! "<<endl;
			return "";
		}
		else
		{
			string X=Top->Comment;
			return X;
		}
	}
	void DisplayComment()
	{
		if(Top==NULL)
		{
			cout<<"\t\t\t\tNO COMMENT ADDED YET !! "<<endl;
		}
		else
		{
			CommentStack *Temp=Top;
			while(Temp!=NULL)
			{
				cout<<"\t\t\t\t+ BY "<<"("<<Temp->UserName<<")"<<" = "<<Temp->Comment<<endl;
				Temp=Temp->Previous;
			}
		}
	}
};

int main(){
  cout<<"\t\t\t============================"<<endl;
	cout<<"\t\t\t       SOCIAL MEDIA APP     "<<endl;
	cout<<"\t\t\t============================"<<endl;
	cout<<endl;
}
