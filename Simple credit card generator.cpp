//C++ programe to generate Credit Card Numbers

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

  int type,count = 0,len=16;
  int x[100];
	cout<<"1. Visa \n2. Mastercard\n3. Discover \n\nChoose credit card type (1, 2 ,3) " ;
	cin>>type;

  srand(time(0));
if(type>=1 && type<=3)
{

  while (count < 1)
  {
    int t[16];
    int sum = 0;
	//if selected card is VISA
    if(type==1)
    {
    	x[0]=4;
    t[0]=x[0];
    for (int h = 1; h < len; h++)
    {
      x[h] = rand() % 10;
      t[h] = x[h];
    }
    
	}
	//if selected card is MASTERCARD
	else if(type==2)
	{
	x[0]=5;
    t[0]=x[0];
    x[1]=(rand() % 6)+1;
    t[1]=x[1];
    for (int h = 2; h < len; h++)
    {
      x[h] = rand() % 10;
      t[h] = x[h];
    }
		
	}
	//if selected card is DISCOVER 
	else if(type==3)
	{
	x[0]=6;
    t[0]=x[0];
    x[1]=5;
    t[1]=x[1];
    for (int h = 2; h < len; h++)
    {
      x[h] = rand() % 10;
      t[h] = x[h];
    }
		
	}
    
    

        //PROCESS 2
    //LUNH ALGORTIHAM IMPLIMENTATION
    for (int j = len-2; j >= 0; j -= 2) //loop untill every second number add in itself
    {
      t[j] = t[j] + t[j];

    }
    //PROCESS 3
    for (int p = len-2; p >= 0; p -= 2) //Loop to add every double digit 
    {
      if (t[p] > 9)
      {
        int s = t[p] % 10;
        t[p] = t[p] / 10;
        t[p] = t[p] + s;
      }

    }

    for (int h = 0; h < len-1; h++) //loop to add all numbers
    {
      sum = sum + t[h];
      
    }

    sum = sum % 10;
    sum = (10 - sum) % 10;
    if (sum == t[15]) //checking if last digit is the number we required to make it dividable with 10
    {
      count++; // if that is correct then count++ and loop break.
    }

}
  cout << "Credit Card number is ";

  for (int k = 0; k < len; k++) //showing numbers
  {
    cout << x[k];
    
  }
}
else
cout<<"\n\nInvalid Choice\n";
}
