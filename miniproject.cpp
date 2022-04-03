//Write a program showing ATM functionalities using OOP
//1. Check balance
//2. Cash Widthraw
//3. User Details
//4. Update Mobile No

#include<iostream>
#include<conio.h>//use getch()
#include<string>// string
using namespace std;

class Atm  //class atm
{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
   //setData function is setting the data into private member function
   void setData(long int a, string b, int c, double d, int e)
   {
       account_no = a; //assign formal argument to private member
       name = b;
       PIN = c;
       balance = d;
       mobile_no = e;
   }
   // All function returning the value
   long int getAccountNo()
   {
       return account_no;
   }

   string getName()
   {
       return name;
   }

   int getPIN()
   {
       return PIN;
   }

   double getBalance()
   {
       return balance;
   }

   string getMobileNo()
   {
       return mobile_no;
   }

   //setMobile function is updating user mobile number
   void setMobile (string mob_prev, string mob_new)
   {
       if(mob_prev == mobile_no)
       {
           mobile_no = mob_new;
           cout<<endl<<"Successfully updated.";
           _getch();//getch is to hold the screen (until user press any key)

       }
       else
       {
           cout<<"Incorrect old mobile number"<<endl;
           _getch();
       }
   }
   //cashWithdraw function is use to withdraw money from
   void cashWithdraw(int amount_a)
   {
       if(amount_a>0 && amount_a<balance)
       {
           balance-=amount_a;
           cout<<"Please collect your cash"<<endl;
           cout<<"Available Balance : "<<balance<<endl;
           _getch();
       }
       else
       {
          cout<<"Invalid input or insufficient balance" <<endl;
          _getch();
       }
   }

};

int main()
{
    int choice=0;
    int enterPIN;
    long int enterAccountNo;

    system("cls");

    //created User 
    Atm user1;
    user1.setData(1234567,"Lee Rang",201412,60000.50,"012345678");

    do
    {
        system("cls");
        cout<<"WELCOME TO ATM"<<endl;
        cout<<"Account number: ";
        cin >>enterAccountNo;
        cout<<"Enter PIN: ";
        cin>>enterPIN;

        if((enterAccountNo==user1.getAccountNo())&&(enterPIN==user1.getPIN()))
           do
           {
             int amount =0;
             string oldMobileNo, newMobileNo;

             system("cls");
             //user interface
             cout<<"WELCOME TO ATM"<<endl;
             cout<<"Select options"<<endl;
             cout<<"1. Check Balance"<<endl;
             cout<<"2. Cash Widthraw"<<endl;
             cout<<"3. Cash Widthraw"<<endl;
             cout<<"4.Update Mobile No"<<endl;
             cout<<"5. Exit"<<endl;
             cin >> choice;

             switch(choice)
             {
                 case 1:
                    cout<<"Your account balance is "<<user1.getBalance();
                       _getch();
                       break;
                case 2:
                    cout<<"Enter your amount: "
                      cin >> amount;
                      user1.cashWithdraw(amount);
                      break;
                case 3:
                    cout<<"User Detail"<<endl;
                    cout<<"Name: "<<user1.name<<endl;
                    cout<<"Account Number: "<<user1.account<<endl;
                    cout<<"Balance: "<<user1.balance<<endl;
                    cout<<"Mobile No: "<<user1.mobileNo<<endl;

                    _getch();
                    break;
                case 4:
                     cout<<"Enter old mobile no: ";
                     cin >>oldMobileNo;
                     cout<<"Enter new mobile no: "
                     cin >>newMobileNo;

                     user1.setMobile(oldMobileNo,newMobileNo);
                     break;
                case 5:
                    exit(0);

                default:
                    cout<<"Enter Valid Data"<<endl;
      
             }
             else
             {
                 cout<<"User Detail Invalid"<<endl;
                 _getch();
             }

           } while (1);
           

    } while (1);
    




    return 0;
}
