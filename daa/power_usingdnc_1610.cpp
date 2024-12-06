#include<iostream>
using namespace std;
float power(int base,int pow)
{
float temp;

  if (pow==1)
  {
   return base;
  }
  if(pow==-1)
  {
   return (1.0/base);
  }
   temp=power(base,pow/2);
    if (pow % 2 == 0) {
        return temp * temp;
    } else {
        // If power is odd and positive
        if (pow > 0) {
            return base * temp * temp;
        }
        // If power is odd and negative
        else {
            return (1.0 / base) * temp * temp;
        }
    }

   
}
int main()
{
   float c=power(2,-8);
   cout<<"c "<<c<<endl;
   return 0;
}
