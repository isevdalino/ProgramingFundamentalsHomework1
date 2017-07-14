#include<iostream>
#include<cmath>
using namespace std;
struct planet{
double x;
double y;
double z;
double m;
};
struct cube{
double x;
double y;
double z;
double side;
};
double dist(cube cube1,planet planet1);
double fitness(cube cube1,planet array1[],int n);
void bestFitnessPoint(cube a,planet array1[],int n);
int main()
{
	int n;
	cube cube1;
	cout<<"Enter the coordinates of the cube:"<<endl;
	cin>>cube1.x;
	cin>>cube1.y;
	cin>>cube1.z;
	cout<<"Enter the lenght of the side of the cube:"<<endl;
	cin>>cube1.side;
	cout<<"Enter the number of planets:"<<endl;
	cin>>n;
	planet planetsArray[100];
	cout<<"Enter the planets information:"<<endl;
	for(int i=0;i<n;i++){
	  cin>>planetsArray[i].x;
	  cin>>planetsArray[i].y;
	  cin>>planetsArray[i].z;
	  cin>>planetsArray[i].m;
	}
	bestFitnessPoint(cube1,planetsArray,n);
	system("pause");
	return 0;
}
void bestFitnessPoint(cube a,planet array1[],int n){
  cube bestPoint;
  double bestFitness=0;
  cube cube2=a;
  cube cube3=a;
  cube cube4=a;
  cube cube5=a;
  cube cube6=a;
  cube cube7=a;
  cube cube8=a;
  cube2.x+=cube2.side;
  cube3.y+=cube3.side;
  cube4.z+=cube4.side;
  cube5.x+=cube5.side;
  cube5.y+=cube5.side;
  cube5.z+=cube5.side;
  cube6.x+=cube6.side;
  cube6.y+=cube6.side;
  cube7.y+=cube7.side;
  cube7.z+=cube7.side;
  cube8.x+=cube8.side;
  cube8.z+=cube8.side;
   if (fitness(a,array1,n)>bestFitness){
    bestFitness=fitness(a,array1,n);
	bestPoint=a;
  }
  if (fitness(cube2,array1,n)>bestFitness){
    bestFitness=fitness(cube2,array1,n);
	bestPoint=cube2;
  }
   if (fitness(cube3,array1,n)>bestFitness){
    bestFitness=fitness(cube3,array1,n);
	bestPoint=cube3;
  }
    if (fitness(cube4,array1,n)>bestFitness){
    bestFitness=fitness(cube4,array1,n);
	bestPoint=cube4;
  }
   if (fitness(cube5,array1,n)>bestFitness){
    bestFitness=fitness(cube5,array1,n);
	bestPoint=cube5;
  }
    if (fitness(cube6,array1,n)>bestFitness){
    bestFitness=fitness(cube6,array1,n);
	bestPoint=cube6;
  }
	 if (fitness(cube7,array1,n)>bestFitness){
    bestFitness=fitness(cube7,array1,n);
	bestPoint=cube7;
  }
   if (fitness(cube8,array1,n)>bestFitness){
    bestFitness=fitness(cube8,array1,n);
	bestPoint=cube8;
  }
   cout<<"The best point for lightspeed jump is ("<<bestPoint.x<<","<<bestPoint.y<<","<<bestPoint.z<<")"<<" and it has a fitness:\n"<<bestFitness<<endl;
   cout<<"Good luck,Solo,kick their ass"<<endl;
}
double fitness(cube cube1,planet array1[],int n){
	double sum=0;
	for (int i=0;i<n;i++){
		sum+=dist(cube1,array1[i])*(array1[i].m);
	}
	return sum;
}
double dist(cube cube1,planet planet1){
  return sqrt((planet1.x-cube1.x)*(planet1.x-cube1.x)+(planet1.y-cube1.y)*(planet1.y-cube1.y)+(planet1.z-cube1.z)*(planet1.z-cube1.z));
}
