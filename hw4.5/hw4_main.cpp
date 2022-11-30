// C program for Huffman Coding
#include <stdio.h>
#include <stdlib.h>
#include "hw4_huffman.h"
#include "hw4_arcd.h"
#include<iostream>
#include<unordered_map>
#include<vector>
#include <time.h> 

using namespace std;
char array0[] = { 'a', 'b', 'c', 'd', 'e'};
int frequency[] = { 5, 10, 20, 25, 40};
int size = sizeof(array0) / sizeof(array0[0]);
double BEGIN0,LAST0,BEGIN1,LAST1;
double time0,time1;


//寫個應用程式去測出實際結果
int main(){

	
	BEGIN0 = clock();

	string s;
	cout<<"Please Enter text: ex:abcba \n(only using a,b,c,d,e && length within 5): ";
	cin>>s;

	//arithmetic coding的量測方法
	cout<<"\n\n\n--------------arithmetic coding----------------:\n\n";
	unordered_map<char, node> arrpointer;
	vector<char> arrvector;
	double range_from = 0;
	cout<<"Enter probability of each character:\n";
	double fre[] = { 0.05, 0.1, 0.2, 0.25, 0.4};
	int lim = 5 ;
	for(int i=0; i<lim; i++){
		arrvector.push_back(array0[i]);
		arrpointer[array0[i]].prob = fre[i];
		arrpointer[array0[i]].range_from = range_from;
		arrpointer[array0[i]].range_to = range_from + arrpointer[array0[i]].prob;
		range_from = arrpointer[array0[i]].range_to;
	}
	cout<<"Symbol\tProbability\tRange_from\tRange_to\n";
	cout<<"----------------------------------------------------\n";
	for(int i=0; i<arrvector.size(); i++){
		char ch= arrvector[i];
		cout<<ch<<"\t"<<arrpointer[ch].prob<<"\t\t"<<arrpointer[ch].range_from<<"\t\t"<<arrpointer[ch].range_to<<endl;
	}
	cout<<endl;

	//Huffman的量測方法
	cout<<"-----------------Huffman------------------:\n";
    HuffmanCodes(array0, frequency, size);
	LAST0 = clock();
	time0 = LAST0 - BEGIN0;

	BEGIN1 = clock();
	double code_word= encoding(arrpointer, s);
	LAST1 = clock();
	time1 = LAST1 - BEGIN1;

	cout<<"Code word for "<<s<<" is: "<<code_word<<endl;
	string text= decoding(arrpointer, code_word, s.size());
	cout<<"Text for "<<code_word<<" is: "<<text<<endl;

	cout<<"\n\n--------------兩種不同編碼各自的編碼時間----------------:\n";
	cout << endl << "進行運算的時間(arithmetic coding)：" << time1 / CLOCKS_PER_SEC << " S"  <<endl;
	cout << endl << "進行運算的時間(huffman)：" << time0 / CLOCKS_PER_SEC << " S" << endl<< endl;
}
