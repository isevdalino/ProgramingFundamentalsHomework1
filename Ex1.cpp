#include<iostream>
#include<cstring>
using namespace std;
char* decodeMessage(char string1[],char string2 []);
int main()
{
	char codedString[100];
	char *decodedString;
	char codingWord[10];
	cout<<"Enter the coded message"<<endl;
	cin>>codedString;
	cout<<"Enter the coding word"<<endl;
	cin>>codingWord;
	decodedString=decodeMessage(codedString,codingWord);
	cout<<"The decoded string is:\n"<<decodedString<<endl;
        cout<<"Good luck,Solo,kick their ass"<<endl;
	system("pause");
	return 0;
}
char* decodeMessage(char string1[],char string2 []){
	char* decodedString=new char[100];
	int j=0;
	for (int i=0;i<strlen(string1);i++){
      int difference=string1[i]-(string2[j]-97);
	  if(difference<97){
	    difference='z'-(97-difference-1);
	  }
      decodedString[i]=difference;
	  if(j<(strlen(string2)-1)){
	    j++;
	  }else{
	    j=0;
	  }
	}
	decodedString[strlen(string1)]=0;
	return decodedString;
}
