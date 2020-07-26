//Assuming expression given in product of sum form
//first integer input as number of clauses, second number of variables
//Then continuous inputs for each variable. 1 if variable is a, -1 is abar, and 0 if variable not present in expression
//Example:
//(a+b)(abar+c)
//2 3 --no. of clauses no. of variables
//1 -1 --a
//1 0 --b
//0 1 --c


#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){

int n, v; //n=no. of clauses, v=no. of variables
cin >> n >> v;
int a[v][n];
bool sat = 0;
for (int i=0; i<v; i++)
	for(int j=0; j<n; j++)
		cin >> a[i][j];
int flip=1;
int ctrue[n], var[v];
for(int i=0; i<n; i++)
		ctrue[i] = 0;
for(int i=0; i<v; i++)
		var[i] = 1;
long long iter=0;
while(true){
	for(int i=0; i<n; i++){
		for(int j=0; j<v; j++){
		if(a[j][i]==var[j]){
			ctrue[i] = 1;
			break;
			}
		}
		if(ctrue[i] == 0)
			break;
		if(ctrue[n-1] == 1){
			sat = 1;
		}			
	}
	if (sat==1)
		break;
	iter=iter+1;
	for(int i=1; i<v+1; i++){
		long long power = pow(2,i);
		if(iter%power!=0){
			flip=i;
			break;	
	}
	}
	for(int i=0; i<flip; i++){
		if (var[i] == 1)
			var[i]= -1;
		else
			var[i]=1;
	}
	if (iter==pow(2,v))
		break;	
	for(int i=0; i<n; i++)
		ctrue[i] = 0;
}

if (sat==1){
	cout <<"SAT"<<endl;
	for(int i=0; i<v; i++)
		cout<<var[i]<< " ";
}
else
	cout << "UNSAT" << endl;

}
