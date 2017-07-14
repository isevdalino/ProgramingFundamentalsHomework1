#include<iostream>
using namespace std;
void permutate(int currentLoop,int n,char array1[]);
void printArray(int n);
bool areDifferent(char array1[],int n);
char array2[100];
int main()
{
	int n;
	char array1[100];
	cout<<"Enter the suspected lenght of the password:"<<endl;
	cin>>n;
	cout<<"Enter the symbols that you suspect define the password:"<<endl;
	for(int i=0;i<n;i++){
	  cin>>array1[i];
	}
	cout<<"All possible permutations with the given symbols are:"<<endl;
	permutate(0,n,array1);
	cout<<"Good luck,Solo,kick their ass"<<endl;
	system("pause");
	return 0;
}
void permutate(int currentPos,int n,char array1[]) {
if (currentPos == n) {
if(areDifferent(array2,n)){
  printArray(n);
}
return;
}
for (int counter=1; counter<=n; counter++) {
array2[currentPos] = array1[counter-1];
permutate(currentPos + 1,n,array1);
}
}
 void printArray(int n) {
for (int i = 0; i < n; i++) {
cout<<array2[i];
}
cout<<endl;
}
 bool areDifferent(char array1[],int n){
	 for (int i=0;i<n;i++){
		 for(int j=i+1;j<n;j++){
			 if(array1[i]==array1[j]){
			   return false;
			 }
		 }
	 }
   return true;
 }
