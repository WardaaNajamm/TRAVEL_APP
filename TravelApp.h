#include<bits/stdc++.h>
#include <conio.h>
#include <stdio.h>
#include <string>
using namespace std;

void FileTrim();
void clustering();
void Stats_calculator();
class Node{
	public:
		
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
		int pickup_time1;
		Node *prev;
		Node *next;
		Node *left;
		Node *right;
		int height;
		
		Node();
		Node(string m,string l,string v,string pd,string pt,string tm,string t,string famt,string s,string mta,string tamt,string tollamt,string total,int x);
};


class TravelApp{
	public:
		Node *head;
		Node *root;
		Node *top;
		
		TravelApp();
		bool isempty();
		int height(Node *root);
		int getbalance(Node *node);
		Node *leftrotate(Node *x);
		Node *rightrotate(Node *y);
		Node * Insert1(Node *root,int x,string l,string tm,string pt,string famt);
		bool NodeExist(string m);
		void Insert(Node *n);
		void Delete(string m,string l,string pt, string t);
		void AddItemtoFile(Node *n);
		void DeleteItemFromFile(string m,string l,string pt, string t);
		void Push(Node *n);
		Node *Pop();
		string removeCharacters(string S, char c);
		void FILING();
		Node *recursiveSearch(Node *r, int val);
		void inorder(Node *root);
		void SearchLicenseNo(string l,int option);
		void Search(string pd);
		void TrafficHours(Node *root);
		void AvgFare(string time);
		void AvgIncomePerDay(string pd);
		void Display();
   	void Help();
};


class NaiveBayes{ 
private:
	long double Total_Cases;
	long double Fever_Cases;
	long double Cough_Cases;
	long double Shortness_Breath_Cases;
	long double Tiredness_Cases;
	double Probability_Fever_Cases;
	double Probability_Cough_Cases;
	double Probability_ShortnessBreath_Cases;
	double Probability_Tiredness_Cases;
public:
	void Filing();
	void Calculate_Probability();
	void Predict_Covid(int num_symp,char *symp);
};

