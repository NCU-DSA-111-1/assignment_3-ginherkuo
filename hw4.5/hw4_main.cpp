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

//寫個應用程式去測出實際結果
int main(){

	char arr0[] = { 'a', 'b', 'c', 'd', 'e'};
    int freq[] = { 5, 10, 20, 25, 40};
 
    int size = sizeof(arr0) / sizeof(arr0[0]);

 	double START0,END0,START1,END1;
	double time0,time1;
	START0 = clock();

	string s;
	cout<<"Please Enter text: ex:abcba \n(only using a,b,c,d,e && length within 5): ";
	cin>>s;

	//Huffman的量測方法
	cout<<"-----------------Huffman------------------:\n";
    HuffmanCodes(arr0, freq, size);
	END0 = clock();
	time0 = END0 - START0;
	//arithmetic coding的量測方法
	cout<<"\n\n\n--------------arithmetic coding----------------:\n\n";
	int n = 5 ;
	unordered_map<char, node> arr;
	vector<char> ar;
	double range_from = 0;
	cout<<"Enter probability of each character:\n";
	double fre[] = { 0.05, 0.1, 0.2, 0.25, 0.4};
	for(int i=0; i<n; i++){
		ar.push_back(arr0[i]);
		arr[arr0[i]].prob = fre[i];
		arr[arr0[i]].range_from = range_from;
		arr[arr0[i]].range_to = range_from + arr[arr0[i]].prob;
		range_from = arr[arr0[i]].range_to;
	}
	cout<<"Symbol\tProbability\tRange_from\tRange_to\n";
	cout<<"----------------------------------------------------\n";
	for(int i=0; i<ar.size(); i++){
		char ch= ar[i];
		cout<<ch<<"\t"<<arr[ch].prob<<"\t\t"<<arr[ch].range_from<<"\t\t"<<arr[ch].range_to<<endl;
	}
	cout<<endl;

	START1 = clock();
	double code_word= encoding(arr, s);
	END1 = clock();
	time1 = END1 - START1;

	cout<<"Code word for "<<s<<" is: "<<code_word<<endl;
	string text= decoding(arr, code_word, s.size());
	cout<<"Text for "<<code_word<<" is: "<<text<<endl;

	cout<<"\n\n--------------兩種不同編碼各自的編碼時間----------------:\n";
	cout << endl << "進行運算的時間(huffman)：" << time0 / CLOCKS_PER_SEC << " S" << endl;
	cout << endl << "進行運算的時間(arithmetic coding)：" << time1 / CLOCKS_PER_SEC << " S" << endl <<endl;

}
