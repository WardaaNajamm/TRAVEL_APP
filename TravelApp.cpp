#include "TravelApp.h"
#include<bits/stdc++.h>
#include <conio.h>
#include <stdio.h>
#define Max_Size 1500
using namespace std;

int c_cluster1=0,c_cluster2=0,c_cluster3=0,c_cluster4=0,c_cluster5=0;
int evening=0,morning=0;
static int stack_number=0;

void FileTrim()
{
	string line;
	string word;
	string Array[13]; 
	string medallion;
	string hack_license;
	string vendor_id;
	string pickup_date;
	string pickup_time;
	string time_mode;
	string payment_type;
	string fare_amount;
	string surcharge;
	string mta_tax;
	string tip_amount;
	string tolls_amount;
	string total_amount;
	int count=0;
	fstream fin("trip_fare_1.csv",ios::in);
	fstream f1("trainingdata.csv",ios::out);
	if (fin.is_open()){
		while (getline(fin,line)){
			count++;
			stringstream s(line);
			int i=0;
			while (getline(s,word,',')){
				Array[i] = word;
				i++;
			} 
			 medallion= Array[0];
			 hack_license=Array[1];
			 vendor_id=Array[2];
			 pickup_date=Array[3];
			 pickup_time=Array[4];
			 time_mode=Array[5];
			 payment_type=Array[6];
			 
			 fare_amount= (Array[7]);
			 surcharge= (Array[8]);
			 mta_tax= (Array[9]);
			 tip_amount= (Array[10]);
			 tolls_amount= (Array[11]);
			 total_amount= (Array[12]);
         f1<< medallion<<","<<hack_license<<","<<vendor_id<<","<<pickup_date<<","<<pickup_time<<","<<time_mode<<","<<payment_type<<","<<fare_amount<<","<< surcharge << "," << mta_tax << "," <<tip_amount<<","<< tolls_amount << "," << total_amount << endl;
			if(count==Max_Size)
			{
				break;
			}
			
		}
	}
	else {
		cout << "\nFile doesnot exist." << endl;
	}
	fin.close();
}
void clustering(){
	
	string line;
	string word;
	string Array[13]; 
	string medallion;
	string hack_license;
	string vendor_id;
	string pickup_date;
	string pickup_time;
	string time_mode;
	string payment_type;
	string fare_amount;
	string surcharge;
	string mta_tax;
	string tip_amount;
	string tolls_amount;
	string total_amount;
	int count=0;
	fstream fin("trainingdata.csv",ios::in);
	fstream f1("cluster1.csv",ios::out);
	fstream f2("cluster2.csv",ios::out);
	fstream f3("cluster3.csv",ios::out);
	fstream f4("cluster4.csv",ios::out);
	fstream f5("cluster5.csv",ios::out);
	if (fin.is_open()){
		while (getline(fin,line)){
			count++;
			stringstream s(line);
			int i=0;
			while (getline(s,word,',')){
				Array[i] = word;
				i++;
			} 
			 medallion= Array[0];
			 hack_license=Array[1];
			 vendor_id=Array[2];
			 pickup_date=Array[3];
			 pickup_time=Array[4];
			 time_mode=Array[5];
			 payment_type=Array[6];
			 
			 fare_amount= (Array[7]);
			 int fare= stoi (Array[7]);
			 surcharge= (Array[8]);
			 mta_tax= (Array[9]);
			 tip_amount= (Array[10]);
			 tolls_amount= (Array[11]);
			 total_amount= (Array[12]);
			 if(fare>=3 && fare<=24){
			 	c_cluster1++;
			 	f1<< medallion<<","<<hack_license<<","<<vendor_id<<","<<pickup_date<<","<<pickup_time<<","<<time_mode<<","<<payment_type<<","<<fare_amount<<","<< surcharge << "," << mta_tax << "," <<tip_amount<<","<< tolls_amount << "," << total_amount << endl;
			 }
			 else if(fare>=25 && fare<=46){
			 	c_cluster2++;
			 	f2<< medallion<<","<<hack_license<<","<<vendor_id<<","<<pickup_date<<","<<pickup_time<<","<<time_mode<<","<<payment_type<<","<<fare_amount<<","<< surcharge << "," << mta_tax << "," <<tip_amount<<","<< tolls_amount << "," << total_amount << endl;
			 }
			 else if(fare>=47 && fare<=68){
			 	c_cluster3++;
			 	f3<< medallion<<","<<hack_license<<","<<vendor_id<<","<<pickup_date<<","<<pickup_time<<","<<time_mode<<","<<payment_type<<","<<fare_amount<<","<< surcharge << "," << mta_tax << "," <<tip_amount<<","<< tolls_amount << "," << total_amount << endl;
			 }
			 else if(fare>=69 && fare<=90){
			 	c_cluster4++;
			 	f4<< medallion<<","<<hack_license<<","<<vendor_id<<","<<pickup_date<<","<<pickup_time<<","<<time_mode<<","<<payment_type<<","<<fare_amount<<","<< surcharge << "," << mta_tax << "," <<tip_amount<<","<< tolls_amount << "," << total_amount << endl;
			 }
			 else if(fare>=91 && fare<=108){
			 	c_cluster5++;
			 	f5<< medallion<<","<<hack_license<<","<<vendor_id<<","<<pickup_date<<","<<pickup_time<<","<<time_mode<<","<<payment_type<<","<<fare_amount<<","<< surcharge << "," << mta_tax << "," <<tip_amount<<","<< tolls_amount << "," << total_amount << endl;
			 }
		}
	}
	else {
		cout << "\nFile doesnot exist." << endl;
	}
	fin.close();
	f1.close();
	f2.close();
	f3.close();
	f4.close();
	f5.close();
}

void Stats_calculator()
{
	float stat_1=0.0,stat_2=0,stat_3=0,stat_4=0,stat_5=0;
	stat_1=float(c_cluster1)/float(Max_Size);
	stat_2=float(c_cluster2)/float(Max_Size);
	stat_3=float(c_cluster3)/float(Max_Size);
	stat_4=float(c_cluster4)/float(Max_Size);
	stat_5=float(c_cluster5)/float(Max_Size);
	cout<<"Around "<<stat_1*100<<"% People Book A Ride In The Range Of 3 to 24 USD\n\n";
	cout<<"Around "<<stat_2*100<<"% People Book A Ride In The Range Of 25 to 46 USD\n\n";
	cout<<"Around "<<stat_3*100<<"% People Book A Ride In The Range Of 47 to 68 USD\n\n";
	cout<<"Around "<<stat_4*100<<"% People Book A Ride In The Range Of 69 to 90 USD\n\n";
	cout<<"Around "<<stat_5*100<<"% People Book A Ride In The Range Of 91 to 108 USD\n\n";
}

Node::Node()
{
	medallion=" ";
	hack_license=" ";
	vendor_id=" ";
	pickup_date=" ";
	pickup_time=" ";
	time_mode=" ";
	payment_type=" ";
	fare_amount=" ";
	surcharge=" ";
	mta_tax=" ";
	tip_amount=" ";
	tolls_amount=" ";
	total_amount=" ";
	pickup_time1=0;
	prev=NULL;
	next=NULL;
	left=NULL;
	right=NULL;
	height=0;
};
		
Node::Node(string m,string l,string v,string pd,string pt,string tm,string t,string famt,string s,string mta,string tamt,string tollamt,string total,int x)
{
	medallion=m;
	hack_license=l;
	vendor_id=v;
	pickup_date=pd;
	pickup_time=pt;
	time_mode=tm;
	payment_type=t;
	fare_amount=famt;
	surcharge=s;
	mta_tax=mta;
	tip_amount=tamt;
	tolls_amount=tollamt;
	total_amount=total;
	pickup_time1=x;
	prev=NULL;
	next=NULL;
};


TravelApp::TravelApp()
{
	head=NULL;
	root=NULL;
	top=NULL;
};
		
bool TravelApp::isempty()
{
	if(root==NULL)
	{
 		return true;
	}
	else
	{
	 	return false;
	}
};
		 
int TravelApp::height(Node *root)
{
 	if(root==NULL)
 	{
 		return -1;
	}
 	 
 	else
	{
 	 	int lh=height(root->left);
 	 	int rh=height(root->right);
 	 	
 	 	if(lh>rh)
		{
 	 		return(lh+1);
		}
		else
		{
			return(rh+1);
		}
	}
};
		 
int TravelApp::getbalance(Node *node)
{
 	if(node==NULL)
	{
 		return -1;
	}
	return (height(node->left)-height(node->right));
};
		 
		 
Node *TravelApp::leftrotate(Node *x)
{
 	Node *n1=x->right;
 	Node *n2=n1->left;
 	
 	//rotation
 	n1->left=x;
 	x->right=n2;
 	
 	int h=height(x);
	h = max(height(x->left), height(x->right)) + 1;
 	h=height(n1);
	h= max(height(n1->left),height(n1->right)) + 1;

	return n1;
};
		 
Node *TravelApp::rightrotate(Node *y)
{
 	Node *n1=y->left;
 	Node *n2=n1->right;
 	
 	//rotation
 	n1->right=y;
 	y->left=n2;
 	
 	int h=height(y);
	h = max(height(y->left),height(y->right)) + 1;
 	h=height(n1);
	h = max(height(n1->left),height(n1->right)) + 1;
 	return n1;
};
		
Node *TravelApp::Insert1(Node *root,int x,string l,string tm,string pt,string famt)
{
	if(root==NULL)
	{
		root=new Node();
		root->pickup_time1=x;
		root->hack_license=l;
		root->pickup_time=pt;
		root->time_mode=tm;
		root->fare_amount=famt;
		root->left=NULL;
		root->right=NULL;
	}
	
	if(x < root->pickup_time1)
	{
		root->left = Insert1(root->left,x,l,tm,pt,famt);
	}
	else if(x > root->pickup_time1)
	{
		root->right = Insert1(root->right, x,l,tm,pt,famt);
	}
	return root;
	
	int h=height(root);
	h = 1 + max(height(root->left),height(root->right));

	int balance = getbalance(root);
	// Left Left Case
	if (balance > 1 && x < root->left->pickup_time1)
	{
		return rightrotate(root);
	}
	// Right Right Case
	if (balance < -1 && x > root->right->pickup_time1)
	{
		return leftrotate(root);
	}
	// Left Right Case
	if (balance > 1 && x > root->left->pickup_time1)
	{
	   root->left = leftrotate(root->left);
	   return rightrotate(root);
	}
	// Right Left Case
	if (balance < -1 && x < root->right->pickup_time1)
	{
	   root->right = rightrotate(root->right);
	   return leftrotate(root);
	}

	return root;
};
		
bool TravelApp::NodeExist(string m)
{
	Node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->medallion==m)
		{
			return true;
		}
		ptr=ptr->next;
	}
	
	return false;
};
		
void TravelApp::Insert(Node *n)
{
	if(head==NULL)
	{
		head=n;
		n->next=NULL;
		n->prev=NULL;
	}
	else
	{
		//append
		Node *ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=n;
		n->prev=ptr;
		n->next=NULL;
	}
};
		
void TravelApp::Delete(string m,string l,string pt, string t)
{
	if(!NodeExist(m))
	{
		cout<<"Doesnt Exist."<<endl;
	}
	else
	{
		if(m==head->medallion && head->hack_license==l && head->pickup_time==pt && head->total_amount==t)
		{
			head=head->next;
			head->prev=NULL;
		}
		else
		{
			Node *ptr=head;
			Node *temp=NULL;
			while(ptr->next!=NULL)
			{
				if((m==ptr->next->medallion) && (ptr->next->hack_license==l) && (ptr->next->pickup_time==pt) && (ptr->next->total_amount==t))
				{
					temp=ptr->next;
					break;
				}
				ptr=ptr->next;
			}
			if(temp!=NULL)
			{
				if(temp->next==NULL)
				{
					ptr->next=NULL;
					temp->prev=NULL;
				}
				else
				{
					temp->next->prev=ptr;
					ptr->next=temp->next;
				}
			}
		}
	}
	
};
		
void TravelApp::AddItemtoFile(Node *n)
{
	string line;
	string word;
	fstream f1;
	f1.open("trainingdata.csv", ios::out | ios::app);
	if (f1.is_open())
	{
		f1<<n->medallion<<","<<n->hack_license<<","<<n->vendor_id<<","<<n->pickup_date<<","<<n->pickup_time<<","<<n->time_mode<<","<<n->payment_type<<","<<n->fare_amount<<","<<n->surcharge << "," <<n->mta_tax << "," <<n->tip_amount<<","<<n->tolls_amount << "," <<n->total_amount << endl;
	}
	else 
	{
		cout << "\nFile doesnot exist." << endl;
	}
	f1.close();
};
		
void TravelApp::DeleteItemFromFile(string m,string l,string pt, string t)
{
	string line;
	string word;
	string Array[13]; 
	string medallion1;
	string hack_license1;
	string vendor_id1;
	string pickup_date1;
	string pickup_time1;
	string time_mode1;
	string payment_type1;
	string fare_amount1;
	string surcharge1;
	string mta_tax1;
	string tip_amount1;
	string tolls_amount1;
	string total_amount1;
	
	fstream fin("trainingdata.csv",ios::in);
	fstream f1("temp.csv",ios::out);
	if (fin.is_open())
	{
		while (getline(fin,line))
		{
			stringstream s(line);
			int i=0;
			while (getline(s,word,','))
			{
				Array[i] = word;
				i++;
			} 
			 medallion1= Array[0];
			 hack_license1=Array[1];
			 vendor_id1=Array[2];
			 pickup_date1=Array[3];
			 pickup_time1=Array[4];
			 time_mode1=Array[5];
			 payment_type1=Array[6];
			 
			 string fare_amount1= Array[7];
			 surcharge1= (Array[8]);
			 mta_tax1= (Array[9]);
			 tip_amount1= (Array[10]);
			 tolls_amount1= (Array[11]);
			 total_amount1= (Array[12]);
			 
			if ((medallion1!=m) || (hack_license1!=l) || (pickup_time1!=pt) || (total_amount1!=t))
			{
				f1<< medallion1<<","<<hack_license1<<","<<vendor_id1<<","<<pickup_date1<<","<<pickup_time1<<","<<time_mode1<<","<<payment_type1<<","<<fare_amount1<<","<< surcharge1 << "," << mta_tax1 << "," <<tip_amount1<<","<< tolls_amount1 << "," << total_amount1 << endl;
			}
			//f1<< medallion<<","<<hack_license<<","<<vendor_id<<","<<pickup_date<<","<<pickup_time<<","<<time_mode<<","<<payment_type<<","<<fare_amount<<","<< surcharge << "," << mta_tax << "," <<tip_amount<<","<< tolls_amount << "," << total_amount << endl;
		}
	}
	else 
	{
		cout << "\nFile doesnot exist." << endl;
	}
	f1.close();
	fin.close();
   remove("trainingdata.csv");//Deletes contacts.csv file
   rename("temp.csv" , "trainingdata.csv");//Rename temp file as Contacts.csv
};
		
void TravelApp::Push(Node *n)
{
	if(top==NULL)
	{
		top=n;
		n->next=NULL;
	}
	else
	{
		Node *ptr=top;
		top=n;
		n->next=ptr;
	}
};
		
Node *TravelApp::Pop()
{
	if(top==NULL)
	{
		cout<<"Stack is empty."<<endl;
	}
	else
	{
		Node *temp=top;
		top=top->next;
		return temp;
	}
};
		
string TravelApp::removeCharacters(string S, char c)
{
    S.erase(remove(S.begin(), S.end(), c),S.end());		 
    return S;
};

void TravelApp::FILING()
{
	string line;
	string word;
	string Array[13]; 
	int count=0;
	fstream fin("trainingdata.csv",ios::in);
	if (fin.is_open()){
		while (getline(fin,line)){
			count++;
			stringstream s(line);
			int i=0;
			while (getline(s,word,',')){
				Array[i] = word;
				i++;
			} 
			Node *n1=new Node();
			n1->medallion= Array[0];
			n1->hack_license=Array[1];
			n1->vendor_id=Array[2];
			n1->pickup_date=Array[3];
			n1->pickup_time=Array[4];
			n1->time_mode=Array[5];
			n1->payment_type=Array[6];
			 
			n1->fare_amount= (Array[7]);
			n1->surcharge= (Array[8]);
			n1->mta_tax= (Array[9]);
			n1->tip_amount= (Array[10]);
			n1->tolls_amount= (Array[11]);
			n1->total_amount= (Array[12]);
			n1->pickup_time1=stoi(n1->pickup_time);
			
			Insert(n1);
			string remove=removeCharacters(n1->pickup_time,':');
			int x=stoi(remove);
			root=Insert1(root,x,n1->hack_license,n1->time_mode,n1->pickup_time,n1->fare_amount);
			
			if(count==500)
			{
				break;
			}
			
		}
	}
	else {
		cout << "\nFile doesnot exist." << endl;
	}
	fin.close();
};
		
Node *TravelApp::recursiveSearch(Node *r, int val) 
{
   if (r==NULL || r->pickup_time1==val)
   {
   	return r;
	} 
	else if (val< r->pickup_time1)
   {
   	return recursiveSearch(r->left, val);
	}   
   else
   {
   	return recursiveSearch(r->right, val);
	}
};
	   
void TravelApp::inorder(Node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->hack_license<<"  "<<root->pickup_time<<"  "<<root->time_mode<<"  "<<root->fare_amount<<endl;
   inorder(root->right);
	return;
};
		
void TravelApp::SearchLicenseNo(string l,int option) //customer admin both
{
	int sum=0;
	int flag=0;
	int found=0;
	Node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->hack_license==l)
		{
			cout<<"\n\n"<<ptr->hack_license<<"  "<<ptr->vendor_id<<"  "<<ptr->payment_type<<"  "<<ptr->pickup_date<<"  "<<ptr->pickup_time<<"  "<<ptr->total_amount;
			int x=stoi(ptr->total_amount);
			sum=sum+x;
			cout<<endl;
			found=1;
			if(flag==0)
			{
				Node *n1=new Node();
				n1->hack_license=l;
				Push(n1);
				stack_number++;
				flag=1;
			}
		}
		ptr=ptr->next;
	}
	if(option==1){
		if(found==1)
		{
			cout<<"\nTotal Earning by driver(Rounded off): "<<sum;
			return;
		}
		else
		{
			cout<<"Not Found."<<endl;
			return;
		}
	}
	
};
		
void TravelApp::Search(string pd) 
{
	Node *ptr=head;
	while(ptr->next!=NULL)
	{
		if(ptr->pickup_date==pd)
		{
			cout<<"\n\n"<<ptr->hack_license<<"  "<<ptr->vendor_id<<"  "<<ptr->payment_type<<"  "<<ptr->pickup_date<<"  "<<ptr->pickup_time<<"  "<<ptr->total_amount;
			cout<<endl;
		}
		ptr=ptr->next;
	}
};

void TravelApp::TrafficHours(Node *root)
{
	if(root==NULL)
	{
		return;
	}
	TrafficHours(root->left);
	if(root->pickup_time1>60000)
	{
		evening++;
	}
	else
	{
		morning++;
	}
   TrafficHours(root->right);
   
   
	return;
};

void TravelApp::AvgFare(string pt)
{
	int sum=0,count=0;
	Node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->pickup_time==pt)
		{
			int x=stoi(ptr->total_amount);
			sum=sum+x;
			count++;
		}
		ptr=ptr->next;
	}
	
	int avg=(sum/count);
	cout<<"\nThe average fare for this "<<pt<<" is: "<<avg<<endl;
};

void TravelApp::AvgIncomePerDay(string pd)
{
	int sum=0,count=0;
	Node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->pickup_date==pd)
		{
			int x=stoi(ptr->total_amount);
			sum=sum+x;
			count++;
		}
		ptr=ptr->next;
	}
	
	int avg=(sum/count);
	cout<<"\nThe average income on the date "<<pd<<" is: "<<avg<<endl;
	cout<<"\nNumber of rides on this day: "<<count<<endl;
};
		
void TravelApp::Display()
{
	Node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\n\n"<<ptr->medallion<<","<<ptr->total_amount<<endl;
		ptr=ptr->next;
	}
};

void TravelApp::Help()
{
		cout<<"\nOur Contacts: \n";
		cout<<"support@travelapp.com \n+92-3312984507 ";
		cout<<"\n1.LEAVE THE REVIEW \n After each trip , you will be asked to leave a feedback about your trip \n";
		cout<<"2.HOW DID YOU LIKE THE TRIP? Is there anything we can do to make it better?\nIf you feel like there is a room for growth for us,share your thoughts and suggestions through the email at suuport@travelapp.com\n";
		cout<<"3.LOST ITEMS \nEmail us at support@travelapp.com.\n Inorder for us to better assist you, please have the following information ready : pickup_date,pickup_time,and car details: license\nWE WILL DO OUR BEST TO HELP YOU :) \n";
};


void NaiveBayes::Filing()
{
	string line;
	string word;
	string Array[5];
	fstream fin("Symptom.csv",ios::in);
	if (fin.is_open())
	{
		int i = 0;
		while(getline(fin,line))
		{	
			stringstream s(line);
			int j=0;
			while (getline(s,word,','))
			{
				Array[j] = word;
				j++;
			}
			this->Total_Cases = stoi (Array[0]);
			this->Fever_Cases = stoi (Array[1]);
			this->Cough_Cases = stoi (Array[2]);
			this->Shortness_Breath_Cases = stoi (Array[3]);
			this->Tiredness_Cases = stoi (Array[4]);
			i++;	
		}
	}
};

void NaiveBayes::Calculate_Probability()
{	
	this->Probability_Cough_Cases=this->Cough_Cases/this->Total_Cases;
	this->Probability_Fever_Cases=this->Fever_Cases/this->Total_Cases;
	this->Probability_ShortnessBreath_Cases=this->Shortness_Breath_Cases/this->Total_Cases;
	this->Probability_Tiredness_Cases=this->Tiredness_Cases/this->Total_Cases; 
};

void NaiveBayes::Predict_Covid(int num_symp,char *symp)
{
	int flag=0;
	double probab=0;
	double calc_probab=0;
	for (int i=0;i<num_symp;i++)
	{
		if (toupper(symp[i]=='F'))
		{
			flag=1;
			break;
		}
	}
	if (flag==0|| (num_symp==1 && toupper(symp[num_symp-1]=='F')))
	{
		cout<<"Very Minimal Chances Of Covid19";
		return;
	}
	for (int i=0;i<num_symp;i++)
	{
		if (toupper(symp[i])=='C')
		{ 	if (probab!=0)
				probab*=this->Probability_Cough_Cases; 
			else
				probab=this->Probability_Cough_Cases;
		}
		else if (toupper(symp[i])=='S')
		{
			if (probab!=0)
				probab*=this->Probability_ShortnessBreath_Cases;
			else
				probab=this->Probability_ShortnessBreath_Cases;
		}
		else if (toupper(symp[i])=='T')
		{
			if (probab!=0)
			probab*=this->Probability_Tiredness_Cases;
			else
			probab=this->Probability_Tiredness_Cases;		
		}
	}
	calc_probab=probab/this->Probability_Fever_Cases;  //conditional 
	if (calc_probab<0.50)
	{
		cout <<"  "<<setprecision(4)<<calc_probab*100 <<"% chance Of Covid 19. Very Less Chance Of Covid.No Need To Worry :)";
		return;
	}
	if (calc_probab>=0.50 && calc_probab<0.80)
	{
		cout <<"  "<<setprecision(4)<<calc_probab*100 <<"% Chance Of Covid 19. Get Yourself Tested. Chances That You Have Covid19 :)";
		return;
	}
	if (calc_probab>0.80)
	{
		cout <<"  "<<setprecision(4)<<calc_probab*100 <<"% Chance Of Covid 19. You Probably Have Covid19. Better Quarantine Yourself And Get Tested :)";
		return;
	}
};
