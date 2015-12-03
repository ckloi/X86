#include "MyFloat.h"

MyFloat::MyFloat(){
  sign = 0;
  exponent = 0;
  mantissa = 0;
}

MyFloat::MyFloat(float f){
  unpackFloat(f);
}

MyFloat::MyFloat(const MyFloat & rhs){
	sign = rhs.sign;
	exponent = rhs.exponent;
	mantissa = rhs.mantissa;
}

ostream& operator<<(std::ostream &strm, const MyFloat &f){
	strm << f.packFloat();
	return strm;

}




MyFloat MyFloat::operator+(const MyFloat& rhs) const{

    MyFloat Left;
    MyFloat Right;		
    MyFloat answer;
    int diff = 0;
    int restoreOne = 8388608;
 

  if((mantissa == rhs.mantissa) && (exponent == rhs.exponent) && (sign != rhs.sign)){


   answer.mantissa = 0;
   answer.exponent = 0;
   answer.sign = 0;




 }else if((exponent == 0) ){


   answer.exponent = rhs.exponent;
   answer.sign = rhs.sign;
   answer.mantissa = rhs.mantissa;


}else if((rhs.exponent == 0) ){


   answer.exponent = exponent;
   answer.sign = sign;
   answer.mantissa = mantissa;


}else{
        if(exponent > rhs.exponent){
         diff = exponent - rhs.exponent;
         
        
         Left.mantissa = mantissa + restoreOne;
         Right.mantissa = rhs.mantissa+ restoreOne;
            if(diff > 8){
            Right.mantissa = Right.mantissa >> diff;
            answer.exponent = exponent;
            }else{
            Left.mantissa = Left.mantissa << diff;
            answer.exponent = rhs.exponent;
            }
           // cout << "1st" << endl;
        }else if (exponent < rhs.exponent){
         diff = rhs.exponent - exponent;
         answer.exponent = rhs.exponent;
         
         Left.mantissa = mantissa + restoreOne;
         Right.mantissa= rhs.mantissa + restoreOne;
            if(diff > 8){
            Left.mantissa = Left.mantissa >> diff;
             answer.exponent = rhs.exponent;
            }else{
            Right.mantissa = Right.mantissa << diff;
              answer.exponent = exponent;
            }    
        // cout << "2nd" << endl;    
        }else{


       
         Left.mantissa = mantissa + restoreOne;
         Right.mantissa = rhs.mantissa + restoreOne;
         answer.exponent = exponent;

        // cout << "3rd" << endl;    
         }
        
//cout << Left.mantissa << " " << Right.mantissa<< " " << answer.mantissa<<endl;
  if(sign == rhs.sign){

    
  answer.mantissa = Left.mantissa + Right.mantissa;
  //cout << answer.mantissa;
  answer.sign = sign;
   
 
 
 //cout << "equal"<<endl;

  }else{
  if(Left.mantissa > Right.mantissa){
   answer.mantissa = Left.mantissa - Right.mantissa;
   answer.sign = sign;
   
   //cout << "Not equal#1"<<endl;
   //cout << Left.mantissa << " " << Right.mantissa<< " " << answer.mantissa<<endl;
  }else if (Left.mantissa < Right.mantissa){

 answer.mantissa = Right.mantissa - Left.mantissa;
 answer.sign = rhs.sign;
 
 //cout << "Not equal#2"<<endl;
// cout << Left.mantissa << " " << Right.mantissa<< endl;
  }

  }

 
//cout << sign << " " << rhs.sign;
if(answer.mantissa >= 16777216){
while(answer.mantissa >= 16777216){
//cout << "hi";
  answer.mantissa = answer.mantissa >> 1;
  answer.exponent++;
 
}
}else{

while(answer.mantissa <= 8388608){
   
  answer.mantissa = answer.mantissa << 1;
  answer.exponent--;

}

}



answer.mantissa = answer.mantissa- 8388608;
//cout << answer.mantissa << " " << answer.exponent << endl;

}
 if(carryWouldHappen(Left.mantissa, Right.mantissa) == true  && (sign == rhs.sign)){
     answer.mantissa = Left.mantissa + Right.mantissa;
     answer.mantissa = answer.mantissa >> (diff+1);
     // cout << "asdasd";
     //cout << answer.mantissa;
   
      if(exponent > rhs.exponent){
     answer.exponent = exponent;
     }else{
     answer.exponent = rhs.exponent;
     }
     answer.exponent++;
     
    
     
   }
 

//cout << answer.exponent << " " << answer.mantissa;
	return answer;
}



MyFloat MyFloat::operator-(const MyFloat& rhs) const{
	
           MyFloat newOne;
            if(rhs.sign == 1){

              newOne.sign = 0;


            }else{
             newOne.sign =1;
            }

           newOne.mantissa = rhs.mantissa;
           newOne.exponent = rhs.exponent;

	return operator+(newOne);
}



void MyFloat::unpackFloat(float f) {


__asm__(
"movl %[input], %[mantissa];"
"shl  $9 , %[mantissa];"
"shr  $9 , %[mantissa];"
"movl %[input], %[exponent];"
"shl  $1,%[exponent];"
"shr $24,%[exponent];"
"movl %[input], %[sign];"
"shr $31,%[sign];":
[sign] "=&r" (sign), [exponent]"=&r"(exponent), [mantissa]"=&r" (mantissa) :
[input]"r"(f):
"cc"
);


//cout << mantissa << endl;
//cout << exponent <<endl;
//cout << sign <<endl;


}//unpackFloat

float MyFloat::packFloat() const{
  //returns the floating point number represented by this
  float f = 0;
  unsigned int temp1;
  unsigned int temp2;


//cout << mantissa << " " << exponent << " " << sign << endl;

__asm__(


"movl %[mantissa],%[temp1];"
"movl %[exponent],%[temp2];"
"shl $23,%[temp2];"
"addl %[temp2],%[temp1];"
"movl %[sign],%[temp2];"
"shl $31,%[temp2];"
"addl %[temp2],%[temp1];"
"movl %[temp1],%[output]":
[output]"=&r"(f),[temp1]"=&r"(temp1),[temp2]"=&r"(temp2):
[sign] "r" (sign), [exponent]"r"(exponent), [mantissa]"r" (mantissa):
"cc"
);


  return f;
}//packFloat
//

bool MyFloat::carryWouldHappen(unsigned int a, unsigned int b){
  bool carry = false;

__asm__(

"addl %[a],%[b];"
"jnc notcarry;"
"movb $1,%[carry];"
"notcarry:":
[carry]"+&r"(carry), [b]"+r"(b):
[a]"r"(a):
"cc"


);

  return carry;
}//carryWouldHappen


