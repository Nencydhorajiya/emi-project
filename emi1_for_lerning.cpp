// EMI - project
// HOME Loan Calculation
// (calculate EMI) calculate the monthly payment of the loan.
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
class emi
{
    long double emi, loan_amount, interest_rate, loan_period, Total_payment, payable_interest, balance, monthly_interest, z, h;  //p=loan amount, r=interest rate, n=loan period, i=payable interest,T=total payment
    public:
    void getdata();
    float calcdata();
    float calcdata1();
    float calcdata2();
    float cadata1(); 
};
void emi::getdata()
{
    cout<<"\n Enter loan amount : ";    
    cin>>loan_amount;                            
    cout<<"\n Enter rate of interest : ";  
    cin>>interest_rate;
    cout<<"\n Enter time period in month : ";   //n=loan period
    cin>>loan_period;
}
float emi::calcdata()
{
    interest_rate=interest_rate/(12*100);     //r=interest rate
   // loan_period=loan_period*12;         // if enter year, need it.
    emi=(loan_amount*interest_rate*pow(1+interest_rate,loan_period)/(pow(1+interest_rate,loan_period)-1));   // n=loan period, r=interest rate
    return emi;
}
float emi::calcdata1()
{
    
    payable_interest = emi * loan_period - loan_amount;     
    return payable_interest;
}
float emi::calcdata2()
{
    Total_payment = loan_amount + payable_interest;        
    return Total_payment;
}

float emi::cadata1()    
{
    cout<<"\n\n\n             month"<<"             principal"<<"                   interest"<<"                  balance"<<"\n"; 
       //h=month, m=interest, z=emi-interest, a=balance

    for(int h=1;h<=loan_period;h++)    // h=month
    {
        monthly_interest = loan_amount * interest_rate;    
        z = emi - monthly_interest;          
        balance = loan_amount - (z);     // balance=loan_amount-(emi-monthly_interest);
       // cout<<"\n\n           "<<h<<"               "<<monthly_interest<<"            "<<z<<"                 "<<balance;   //h=month, z=emi-interest 
        // cout<<fixed(6)<<h<<endl;                  //h=month
        // cout<<fixed(6)<<monthly_interest<<endl;
        // cout<<fixed(6)<<z<<endl;                  //z=emi-interest 
        // cout<<fixed(6)<<balance<<endl;   

        // cout <<std::fixed<<h<<endl;
        // cout<<std::fixed<<monthly_interest<<endl;   
        // cout<<std::fixed<<z<<endl;  
        // cout<<std::fixed<<balance<<endl;  
        cout<<std::fixed<<"\n\n\n              "<<h<<"              "<<z<<"               "<<monthly_interest<<"               "<<balance;
        loan_amount = balance;              
    }                            

}

int main()
{
    emi a1;
    float emi,Total_payment,payable_interest;
    
    a1.getdata();

    emi = a1.calcdata();
   // cout<<"\n\n Monthly EMI : "<<emi;
    cout<<std::fixed<<"\n\n Monthly EMI : "<<emi;

    payable_interest = a1.calcdata1();
   // cout<<"\n\n Payable Interest : "<<payable_interest;
    cout<<std::fixed<<"\n\n Payable Interest : "<<payable_interest;

    Total_payment = a1.calcdata2();
    //cout<<"\n\n Total Payment : "<<Total_payment;
    cout<<std::fixed<<"\n\n Total Payment : "<<Total_payment;

    cout<<"\n";
    a1.cadata1();

    return 0;
}

