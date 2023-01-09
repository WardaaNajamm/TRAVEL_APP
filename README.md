# TRAVEL_APP | <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C Language"> C++ Language </img>
Travel App is basically a program written in C++ that has two interfaces; Admin and Customer. It helps both of them track rides each day.

## Description
The project is based on a dataset of 1.56 GB consisting of around 14 million rows having 13 attributes. The project is basically a Travel App that deals with two interfaces, Admin and Customers involving various concepts of Data Structures, and OOP.CSV filing format is used in the project. The program is designed by using different searching, sorting techniques, classification, and clustering using the K-means clustering algorithm. Initially, the data is stored in the Doubly Link list, Stacks, and AVL Tree. The algorithm of NaiveBayes is used to predict Covid for users who are about to travel. The Statistics of Travel app will be displayed at the end of the program as an application of clustering.

## Data Structure Concepts Used
1. AVL Tree
2. Stack using Link List
3. Doubly Linked List
4. K-Mean Clustering
5. Naive Bayes Algorithm
6. CSV Filing
7. Statistics of Travel App

![](https://github.com/WardaaNajamm/TRAVEL_APP/blob/main/pic1.png)

## Admin Interface
1. Insert a new Ride Record
2. Delete a Ride Record
3. Search a Ride by License Number
4. Search Rides of a Specific Day
5. Search Traffic Timings
6. Average Income per Day
7. Recent Searches 
8. Display File for all the Rides (from morning to evening)
9. Search by Time, Details of a Ride

![](https://github.com/WardaaNajamm/TRAVEL_APP/blob/main/pic2.png)

## Customer Interface
1. Search Details of Ride via a License Number
2. Check Average Fare at a Particular Time
3. Check If You Have Covid19 Symptoms before traveling
4. Help and Support

![](https://github.com/WardaaNajamm/TRAVEL_APP/blob/main/pic3.png)

## Naive Bayes Algorithm
The class of Naive Bayes contains three functions:
-Filing
-Calculate Probability
-Predict Covid
The program will ask the user to input the number of symptoms, here Fever is considered as the basic symptom. The CSV filing will provide the total number of cases of each symptom Fever, Tiredness, Shortness of Breath, and Cough, the probab variable will store probability of each symptom and at the end, it will be divided by the probability of Fever, the formula will be used to produce an output.

![](https://github.com/WardaaNajamm/TRAVEL_APP/blob/main/pic4.png)

![](https://github.com/WardaaNajamm/TRAVEL_APP/blob/main/pic5.png)

## Statistics of Travel App
A feature of K-mean clustering will be used to produce statistics. Clusters are made on the basis of fare amount, each cluster will store the ride lying in one of the ranges (difference of fare is around 21 based on the maximum and minimum value). CSV Filing will store respective clusters.

![](https://github.com/WardaaNajamm/TRAVEL_APP/blob/main/pic6.png)

## Conclusion
Most of the Data Structure concepts have been used here. The travel app provides different functionalities to admin and customers through which they both can perfrom each task. This program uses K-mean clustering and Naive Bayes Algorithm adding more of a statistical approach towards the project.


