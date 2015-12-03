#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int nSum(int r);
int formula(int row ,  int col , int num_col);
int main(int argc, const char* argv[]){

int n;
int m;
int temp;
vector <int> matrixA;
vector <int> matrixB;



ifstream file1 (argv[1]);
ifstream file2 (argv[2]);

file1 >> n;
file2 >> m;



while(file1 >> temp){

matrixA.push_back(temp);
}

while(file2 >> temp){

matrixB.push_back(temp);
}



vector <int> result(matrixA.size());

temp = 0;
for(int x = 0 ; x < n ; x++){
for (int row = 0 ; row < n ; row++) {
for (int col = 0 ; col < n ; col++){
 


temp = temp + matrixA[formula(x,col,n)] * matrixB[formula(col,row,n)];


 


}

result.push_back(temp);


temp = 0;

}

}


 
for(unsigned int x = 0 ; x < result.size() ; x++){
if(result[x] != 0){
cout << result[x] << " " ;
}

}

cout << endl;






}

int formula(int row ,  int col , int num_col){

if(row > col){
  return -1;
 }

return row*num_col + col - nSum(row);


}



int nSum(int r){
if(r == 0){
  return 0;
}else{

 r = nSum(r-1) + r;

 return r;

}


}

