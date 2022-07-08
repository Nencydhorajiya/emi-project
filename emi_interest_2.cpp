#include<iostream>
#include<math.h>
using namespace std;
class emi
{
    float emi,p,r,n,T,i,a,x,m,z,h;  //p=loan amount, r=interest rate, n=loan period, i=payable interest,T=total payment
    public:
    void getdata();
    void printdata();
    float calcdata();
    float calcdata1();
    float calcdata2();
    float cadata1(); 
};
void emi::getdata()
{
    cout<<"\n Enter loan amount:";    //p=loan amount
    cin>>p;                            
    cout<<"\n Enter rate of interest:";  //r=interest rate
    cin>>r;
    cout<<"\n Enter time period in month:";   //n=loan period
    cin>>n;
}
void emi::printdata() 
{
    cout<<"\n\n\n           month"<<"           interest"<<"           emi-interest"<<"            balance";
}
float emi::calcdata()
{
    r=r/(12*100);     //r=interest rate
    //n=n*12;         // if enter month,no need it.
    emi=(p*r*pow(1+r,n)/(pow(1+r,n)-1));   //  p=loan amount, n=loan period, r=interest rate
    return emi;
}
float emi::calcdata1()
{
    
    i=emi*n-p;     // i=payable interest
    return i;
}
float emi::calcdata2()
{
    T=p+i;          // T=total payment
    return T;
}

float emi::cadata1()    
{
    for(int h=1;h<=n;h++)    // h=month
    {
    m=p*r;
    z=emi-m;
    a=p-(z);   //a=p-(emi-m);
    cout<<"\n\n           "<<h<<"               "<<m<<"            "<<z<<"             "<<a;  
    p=a;
    }                            

}

int main()
{
    emi a1;
    float emi,T,i;
    a1.getdata();
    emi=a1.calcdata();
    cout<<"\n\n monthly EMI :"<<emi;
    i=a1.calcdata1();
    cout<<"\n\n payable interest :"<<i;
    T=a1.calcdata2();
    cout<<"\n\n Total payment :"<<T;
    a1.printdata();
    a1.cadata1();
    return 0;
}

