#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main(){

int base1;
string number;
stringstream convert;

int base2;
int newNumber = 0;
int r = 0;
int a;
string result = "";


vector<string> vectorR;
vector<int> d;

cout << "Please enter the number's base: ";
cin >> base1;
cout <<"Please enter the number: ";
cin >> number;
cout << "Please enter the new base: ";
cin >> base2;



for(unsigned int x = 0 ; x < number.size() ; x++){

switch(number[x]){
    
case 'A':
     d.push_back(10);
     break;
case 'B':
     d.push_back(11);
     break;
case 'C':
     d.push_back(12);
     break;
case 'D':
     d.push_back(13);
     break;
case 'E':
     d.push_back(14);
     break;
case 'F':
     d.push_back(15);
     break;
case 'G':
     d.push_back(16);
     break;
case 'H':
     d.push_back(17);
     break;
case 'I':
     d.push_back(18);
     break;
case 'J':
     d.push_back(19);
     break;
case 'K':
     d.push_back(20);
     break;
case 'L':
     d.push_back(21);
     break;
case 'M':
     d.push_back(22);
     break;
case 'N':
     d.push_back(23);
     break;
case 'O':
     d.push_back(24);
     break;
case 'P':
     d.push_back(25);
     break;
case 'Q':
     d.push_back(26);
     break;
case 'R':
     d.push_back(27);
     break;
case 'S':
     d.push_back(28);
     break;
case 'T':
     d.push_back(29);
     break;
case 'U':
     d.push_back(30);
     break;
case 'V':
     d.push_back(31);
     break;
case 'W':
     d.push_back(32);
     break;
case 'X':
     d.push_back(33);
     break;
case 'Y':
     d.push_back(34);
     break;
case 'Z':
     d.push_back(35);
     break;
default:

d.push_back(number[x]-48);

    }

    
}


reverse(d.begin(),d.end());

for (unsigned x = 0 ; x < d.size(); x++){

   newNumber = (d[x])*pow(base1,x) + newNumber;
   
}

a = newNumber;



while(a != 0){
 
 r = a%base2;
 a = a/base2;
    switch(r){
    
    case 10:
     vectorR.push_back("A");
     break;
    case 11:
     vectorR.push_back("B");
     break;
case 12:
     vectorR.push_back("C");
     break;
case 13:
     vectorR.push_back("D");
     break;
case 14:
     vectorR.push_back("E");
     break;
case 15:
     vectorR.push_back("F");
     break;
case 16:
     vectorR.push_back("G");
     break;
case 17:
     vectorR.push_back("H");
     break;
case 18:
     vectorR.push_back("I");
     break;
case 19:
     vectorR.push_back("J");
     break;
case 20:
     vectorR.push_back("K");
     break;
case 21:
     vectorR.push_back("L");
     break;
case 22:
     vectorR.push_back("M");
     break;
case 23:
     vectorR.push_back("N");
     break;
case 24:
     vectorR.push_back("O");
     break;
case 25:
     vectorR.push_back("P");
     break;
case 26:
     vectorR.push_back("Q");
     break;
case 27:
     vectorR.push_back("R");
     break;
case 28:
     vectorR.push_back("S");
     break;
case 29:
     vectorR.push_back("T");
     break;
case 30:
     vectorR.push_back("U");
     break;
case 31:
     vectorR.push_back("V");
     break;
case 32:
     vectorR.push_back("W");
     break;
case 33:
     vectorR.push_back("X");
     break;
case 34:
     vectorR.push_back("Y");
     break;
case 35:
     vectorR.push_back("Z");
     break;
default:
convert << r;
  
  vectorR.push_back(convert.str());

 convert.str("");
}
}




for(unsigned a = 0 ; a < vectorR.size(); a++){

   
result = vectorR[a] +result;
  
}

cout << number << " base " << base1 << " is " << result << " base "<< base2 << endl;


}
