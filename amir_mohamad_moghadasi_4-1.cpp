//امیر محمد مقدسی 4-1
#include <iostream>
using namespace std;
int factorer(int);
int main()
 {
    cout<<"please enter a number:"<<endl;
    int number;
    cin>>number;
    if (number>=0)
    //n!=n(n-1)!
    cout <<endl<<factorer(number);
    else
        cout <<endl<<number;
 return 0;
 }
// فانکشن فاکتوریر
int factorer(int number)
 {
    if(number==0)
        return 1;
    else
        return number*factorer(number-1);
 }