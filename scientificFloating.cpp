#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h> 

using namespace std;

int main(){
float f;
vector<int> numbers;
cout << "Please enter a float: ";
cin >> f;



int p = 0;
unsigned int float_int = *((unsigned int*) &f);


bool found = false;
int index = 0;


for (int x = 0 ; x < 32 ; x++){

 p = float_int & 1;
 numbers.push_back(p);
 
 float_int = float_int >> 1;



}




 if (numbers[31] == 1){
    cout << "-";

  

}
if( f != 0){

cout << "1.";

for(int a = 0 ; a < 23 ; a++){


if (numbers[a] == 0 && numbers[a+1] == 1 && !found){
  index = a; 
   found = true;
}

}

if(numbers[0] == 1){

 index = -1;

}


for(int a = 22 ; a > index ; a--){
cout << numbers[a];

}



int exp = 0;
int power = 0;

for (int x = 23 ; x < 31 ; x++){

   exp = exp + numbers[x] * pow(2,power);
   
   power++;
   


}
cout << "E" << exp - 127 << endl;

}else{

cout << "0E0" <<endl ;
}















}
