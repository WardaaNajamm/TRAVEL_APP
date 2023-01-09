#include <conio.h>
#include <stdio.h>
#include<bits/stdc++.h>
#include "TravelApp.cpp"
#include "interface2.h"

main()
{
	system("color E5");	
	interface();
	FileTrim();
	clustering();
	TravelApp d;
	d.FILING();
   int option;
	cout<<"\n\n====================CHOOSE AN OPTION TO PROCEED:========================="<<endl;
	cout<<"1.Admin"<<endl;
	cout<<"2.Customer"<<endl;
	cout<<"3.Statistics About Our App"<<endl;
	cin>>option;
	
	if(option==1)
	{
		while(1)
		{
			system("cls");
			cout<<"\n**********************************TRAVEL APP PORTAL MENU(ADMIN)****************************************\n=====================================================\n";
			cout<<"\n1)Insert a new Ride Record\n\n";
			cout<<"2)Delete a Ride Record\n\n"; 
			cout<<"3)Search a Ride by License Number\n\n"; 
			cout<<"4)Search Rides of a Specific Day\n\n";
			cout<<"5)Search Traffic Timings\n\n"; 
			cout<<"6)Average Income per Day\n\n";  
			cout<<"7)Recent Searches\n\n";  
			cout<<"8)Display File for all the Rides (from morning to evening)\n\n";   
			cout<<"9)Search by Time, Details of a Ride\n\n";  
			cout<<"0)Exit\n\n";
			cout<<"\n======================================================";
			cout<<"\nChoose Option: ";
			cin >> option;
			system("cls");
			switch(option)
			{
				case 1:
				{
					//we can take input from the user
//					int m,l,vid,pd,pt,tm,pt,mta,s,tamt,total,famt,tipamt;
//					cout<<"To add a new Record, please provide the following information:"<<endl;
//					cout<<"medallion\n"<<"hack_license\n"<<"vendor_id\n"<<"pickup_date\n"<<"pickup_time\n"<<"time_mode\n"
//					<<"payment_type\n"<<"mta_tax\n"<<"surcharge\n"<<"tolls_amount\n"<<"total_amount\n"<<"fare_amount\n"
//					<<"tip_amount\n";
//					cin>>m>>l>>vid>>pd>>pt>>tm>>pt>>mta>>s>>tamt>>total>>famt>>tipamt;

               //to avoid delays we have hardcoded the input values
					Node *temp=new Node();
					temp->medallion="89D227B655E5C82AECF13C3F540D4CF4";
					temp->hack_license="BA96DE419E711691B9445D6A6307C170";
					temp->vendor_id="VTS";
					temp->pickup_date="10-01-13";
					temp->pickup_time="4:36:00";
					temp->time_mode="AM";
					temp->payment_type="CSH";
					temp->mta_tax="3";
					temp->surcharge="0";
					temp->tolls_amount="0";
					temp->total_amount="321";
					temp->fare_amount="6";
					temp->tip_amount="3";
					d.Insert(temp);
					d.AddItemtoFile(temp);
					cout<<"Item Added."<<endl;												
					getch();
					break;
				}
				case 2:
				{
					//delete by comparing medallion,hack_license,pickup_time,total_fare
					d.Delete("89D227B655E5C82AECF13C3F540D4CF4","BA96DE419E711691B9445D6A6307C170","4:36:00","321");
					d.DeleteItemFromFile("89D227B655E5C82AECF13C3F540D4CF4","BA96DE419E711691B9445D6A6307C170","4:36:00","321");
				   cout<<"Item Deleted."<<endl;
					getch();
					break;
				}
				case 3:
				{
					string l;
					cout<<"Enter License Number of the Ride, you need details for: "<<endl;
					cin.ignore();
					getline (cin,l);
//					l="D2363240A9295EF570FC6069BC4F4C92";  //hardcoding for now
					d.SearchLicenseNo(l,1);
					cout<<endl;
					getch();
					break;
				}
				case 4:
				{
					string pd;
//					cout<<"Enter date of the day you want to find details of all rides for: "<<endl;
//					cin.ignore();
//					getline (cin,pd);
					pd="07-01-13"; //hardcoded for now
					d.Search(pd);
					getch();
					break;
				}
				case 5:
				{
					d.TrafficHours(d.root);
					cout<<"Number of Rides Booked in Evening: "<<evening<<endl;
					cout<<"Number of Rides Booked in Morning: "<<morning<<endl<<endl;
					if(morning>evening)
					{
						cout<<"More Traffic in morning hours."<<endl;
					}
					else
					{
						cout<<"More Traffic in evening hours."<<endl;
					}
					getch();
					break;
				}
				case 6:
				{
					string pd;
//					cout<<"Enter date of the day you want to find average income for: "<<endl;
//					cin.ignore();
//					getline (cin,pd);
					pd="07-01-13"; //hardcoded for now
					d.AvgIncomePerDay(pd);
					getch();
					break;
				}
				case 7:
				{
					Node *temp=NULL;
					cout<<"Recent Searches: "<<endl;
					for(int i=0;i<stack_number;i++)
					{
						temp=d.Pop();
						stack_number--;
				   	cout<<temp->hack_license<<endl;
					}
					getch();
					break;
				}
				case 8:
				{
					d.inorder(d.root);
					cout<<endl<<endl<<"Sorted File by Time"<<endl;
					getch();
					break;
				}
				case 9:
				{
					int y;
					string x;
					cout<<"Enter a time :"<<endl;
					cin>>x;
					x="10:51:00";
					x=d.removeCharacters(x,':');
					y=stoi(x);
					Node *found=d.recursiveSearch(d.root,y);
					cout<<found->hack_license<<" "<<found->pickup_time<<" "<<found->time_mode<<" "<<found->fare_amount<<endl;
					getch();
					break;
				}
				case 0:
				{
					return 0;
				}
			}
		}
	}
	else if(option==2)//customer
	{
		
		while(1)
		{
			system("cls");
			cout<<"\n**********************************TRAVEL APP PORTAL MENU(CUSTOMER)****************************************\n=====================================================\n";
			cout<<"\n1)Search Details of Ride via a License Number\n\n"; 
			cout<<"2)Check Average Fare at a Particular Time\n\n";
			cout<<"3)Check If You Have Covid19 Symptoms\n\n";
			cout<<"4)Help and Support\n\n";  
			cout<<"0)Exit\n\n";
			cout<<"\n======================================================";
			cout<<"\nChoose Option: ";
			cin >> option;
			system("cls");
			switch(option)
			{
				case 1:{
					cout<<"======================Search Details of Ride via a License Number===========================\n";
					string l;
//					cout<<"Enter License Number of the Ride, you need details for: "<<endl;
//					cin.ignore();
//					getline (cin,l);
					l="D2363240A9295EF570FC6069BC4F4C92";  //hardcoding for now
					d.SearchLicenseNo(l,2);
					cout<<endl;
					getch();
					break;
				}
				case 2:{
					cout<<"======================Check Average Fare at a Particular Time===========================\n";
					string time;
//					cout<<"Enter time of ride to check average fare : "<<endl;
//					cin.ignore();
//					getline (cin,time);
					time="11:25:03"; //hardcoded for now
					d.AvgFare(time);
					getch();
					break;
				}
				case 3:{
					cout<<"=======================Check If You Have Covid19 Symptoms Before Travelling==========================\n";
					int maxsymptom=4;
					int symptoms=0;
					NaiveBayes NB;
					NB.Filing();
					NB.Calculate_Probability();
					while(1)
					{
					    system("cls");
						cout<<"\nEnter Number Of Symptoms: ";
						cin>>symptoms;
						if (symptoms>maxsymptom)
						{
							cout<<"Kindly Stay in the Limit of 4 Symptoms.Press Any Key To Retry";
							getch();
						}
						else
						break;
					}
					char *arr=new char[symptoms];
					cout<<"Choose Symptoms From The List Below\n=====================================\n";
					cout<<"1)Fever(F)\n2)Cough(C)\n3)Tiredness(T)\n4)Shortness Of Breath (S)\n";
					for (int i=0;i<symptoms;i++)
					{
						cout<<"\nPress Letter Indicated in Bracket For Option "<<i+1<<": ";
						cin>>arr[i];
					}
					cout<<"\n====================================================================\n";
					NB.Predict_Covid(symptoms,arr);
					cout<<"\n====================================================================\n";
					getch();
					break;
				}
				case 4:{
					cout<<"\n\n======================HELP AND SUPPORT===========================\n";
					d.Help();
					getch();
					break;
				}
				case 0:{
					cout<<"\t\t\t\t\tSAFE TRAVELS!"<<endl;
					exit(1);
					break;
				}		
			}
		}
	}
	else if(option==3){
		system("cls");
		cout<<"\n\n========================Statistics Of Travel App================================\n\n";
		Stats_calculator();
	}
	else{
		cout<<"Wrong Input Exiting..\n";
		exit(1);
	}
}
