#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

struct node{
	double prob, range_from, range_to;
};

double encoding(unordered_map<char, node> arr, string s){
	cout<<"\nEncoding\n";
	double low_v=0.0, high_v=1.0, diff= 1.0;
	cout<<"Symbol\tLow_v\tHigh_v\tdiff\n";
	for(int i=0; i<s.size(); i++){
		high_v= low_v+ diff* arr[s[i]].range_to;
		low_v= low_v+ diff* arr[s[i]].range_from;
		diff= high_v- low_v;
		cout<<s[i]<<"\t"<<low_v<<"\t"<<high_v<<"\t"<<diff<<endl;
	}
	return low_v;
}

string decoding(unordered_map<char, node> arr, double code_word, int len){
	cout<<"\nDecoding: \n";
	char ch;
	string text= "";
	int j=0;
	unordered_map<char, node>:: iterator it;
	cout<<"Code\tOutput\tRange_from\tRange_to\n";
	while(j<len){
		cout<<code_word<<"\t";
		for(it= arr.begin(); it!=arr.end(); it++){
			char i= (*it).first;
			if(arr[i].range_from<= code_word && code_word< arr[i].range_to){
				ch= i;
				code_word= (code_word-arr[i].range_from)/(arr[i].range_to- arr[i].range_from);
				break;
			}
		}
		cout<<ch<<"\t"<<arr[ch].range_from<<"\t\t"<<arr[ch].range_to<<endl;
		text+= ch;
		j++;
	}
	return text;
}

