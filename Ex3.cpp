#include<iostream>
using namespace std;
const int ls = 100;
int n=5;
bool cantStepOn(int map[ls][ls],int startRow , int startCol);
void findBuildingSize( int map [ls ][ ls], int startRow , int startCol ,int& counter,int& cor1,int& cor2);
void findEntranceCoordinates(int map[ls][ls]);
int main()
{
  int map [ls ][ ls]={
  {0,0,0,2,1},
  {0,1,0,0,0},
  {2,1,0,0,0},
  {0,0,0,0,0},
  {2,0,0,0,0}
  };
  findEntranceCoordinates(map);  
  cout<<"Good luck,Solo,kick their ass"<<endl;
  system("pause");
  return 0;
}
bool cantStepOn(int map[ls][ls],int startRow , int startCol){
  if (((map[startRow][startCol] ==0)||
(map[startRow][startCol] ==9))||
(startRow < 0) ||
(startCol < 0) ||
(startRow >= n) ||
(startCol >= n))
{
  return true;
}
  return false;
}
void findEntranceCoordinates(int map[ls][ls]){
  int maxSize=0;
  int counter;
  int rowCor=-1;
  int colCor=-1;
  int rowCor1;
  int colCor1;
  for (int i=0;i<n;i++){
    for(int j=0;j<n;j++){
		counter=0;
		rowCor1=0;
        colCor1=0;
		if ((map[i][j]==1)||(map[i][j]==2)){
		  findBuildingSize(map,i,j,counter,rowCor1,colCor1);
		}
		if(counter>maxSize){
		  maxSize=counter;
		  rowCor=rowCor1;
		  colCor=colCor1;
		}
	}
  }
  if ((rowCor==-1)||(rowCor==-1)){
    cout<<"Invalid input!"<<endl;
	return;
  }
  cout<<"The coordinates of the sought entrance are:"<<"["<<rowCor<<"]"<<"["<<colCor<<"]"<<endl;
}
void findBuildingSize( int map [ls ][ ls], int startRow , int startCol ,int& counter,int& cor1,int& cor2)
{
  
if (cantStepOn(map,startRow,startCol))
{
  return;
}
if(map[startRow][startCol] ==2){
cor1=startRow;
cor2=startCol;
}
counter++;
map [startRow ][ startCol] = 9;
findBuildingSize(map , startRow +1, startCol,counter,cor1,cor2);
findBuildingSize(map , startRow , startCol +1,counter,cor1,cor2);
findBuildingSize(map , startRow -1, startCol,counter,cor1,cor2);
findBuildingSize(map , startRow , startCol -1,counter,cor1,cor2);
}
