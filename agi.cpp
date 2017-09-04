Skip to content
This repository
Search
Pull requests
Issues
Marketplace
Explore
 @agi-35
 Sign out
 Watch 0
  Star 0
  Fork 0 Aleesha-Ali/bankingSystem
 Code  Issues 0  Pull requests 0  Projects 0  Wiki Insights 
Branch: master Find file Copy pathbankingSystem/cloudbank.cpp
083f57a  on Jun 22
@Aleesha-Ali Aleesha-Ali Add files via upload
1 contributor
RawBlameHistory     
222 lines (194 sloc)  5.78 KB

    /* NAME:ALEESHA ALI
       SEC:A_ROLL NO.-2010292(32)
       SEM:4th*/


    #include<iostream>
    using namespace std;

    class Account               //ABSTRACT CLASS
    {

        public:
            virtual void get_accinfo() {};      //VIRTUAL FUNCTIONS
            virtual void display_accinfo() {};
            virtual void disp_currbal() {};
            virtual void deposit_currbal() {};
            virtual void withdraw_currbal() {};
            virtual char acc_typeinfo() {};
    };

    class BusinessAccount : public Account      //DERIVED CLASS
    {
        static double balance;

        public:

        void disp_currbal()
        {
          cout<<"\nBalance :- "<<balance;
        }
        void deposit_currbal()
        {
          double deposit;
          cout<<"\nEnter amount to Deposit :- ";
          cin>>deposit;
          balance = balance + deposit;
        }
        void withdraw_currbal()
        {
          double penalty,withdraw;
          cout<<"\n\nBalance :- "<<balance;
          cout<<"\nEnter amount to be withdraw :-";
          cin>>withdraw;
          balance=balance-withdraw;
          if(balance < 500)
          {
          penalty=(500-balance)/10;
          balance=balance-penalty;
          cout<<"\nBalance after deducting penalty : "<<balance;
          }
          else if(withdraw > balance)
          {
          cout<<"\n\nYou have to take permission for Bank Overdraft Facility\n";
          balance=balance+withdraw;
          }
          else
          cout<<"\nAfter Withdrawl your Balance revels : "<<balance;
         }
    };

    class SavingsAccount : public Account
    {
        static double balance;

      public:
        void disp_currbal()
        {
          cout<<"\nBalance :- "<<balance;
        }
        void deposit_currbal()
        {
          double deposit;
          cout<<"\nEnter amount to Deposit :- ";
          cin>>deposit;
          balance = balance + deposit;
        }
        void withdraw_currbal()
        {
          double penalty,withdraw;
          cout<<"\n\nBalance :- "<<balance;
          cout<<"\nEnter amount to be withdraw :-";
          cin>>withdraw;
          balance=balance-withdraw;
         // if(balance < 500)
         // {
         // penalty=(500-balance)/10;
         // balance=balance-penalty;
          //cout<<"\nBalance after deducting penalty : "<<balance;
         // }
          if(withdraw > balance)
          {
          cout<<"\n\nYou have to take permission for Bank Overdraft Facility\n";
          balance=balance+withdraw;
          }
          else
          cout<<"\nAfter Withdrawl your Balance left : "<<balance;
         }
    };

    class CheckingAccount :public Account
    {
        public :
            string cust_name;
            long long int  acc_no;
            char acc_type;



            void get_accinfo()
            {
               cout<<"\n\nEnter Customer Name :- ";
               getline(cin,cust_name);
               cout<<"Enter Account Number :- ";
               cin>>acc_no;
               cout<<"Enter Account Type :- ";
               cin>>acc_type;
            }
            char acc_typeinfo()
            {
                return(acc_type);
            }

            void display_accinfo()
            {
               cout<<"\n\nCustomer Name :- "<<cust_name;
               cout<<"\nAccount Number :- "<<acc_no;
               cout<<"\nAccount Type :- "<<acc_type;
            }
    };

    double BusinessAccount :: balance;
    double SavingsAccount :: balance;

    int main()
    {

        CheckingAccount ca;
        SavingsAccount sa;
        BusinessAccount ba;
        Account *p;

        char type;

        int choice;
        p=&ca;
        p->get_accinfo();
        p=&ca;
        type=p->acc_typeinfo();
        if(type=='s' || type=='S')
        {
        p=&sa;
        while(1)
         {

            cout<<"\nChoose Your Choice for saving account\n";
            cout<<"1)   Deposit\n";
            cout<<"2)   Withdraw\n";
            cout<<"3)   Display Balance\n";
            cout<<"4)   Exit\n";
            cout<<"5)   Choose Your choice:-";
            cin>>choice;
            switch(choice)
            {
            case 1 :
                p->deposit_currbal();

                break;
            case 2 :
                p->withdraw_currbal();

                break;
            case 3 :
                p->disp_currbal();

                break;
            case 4 :
                goto end;
            default:
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
        }
        else
        {
            p=&ba;
           {
               while(1)
               {
                cout<<"\nEnter Your Choice\n";
                cout<<"1)   Deposit\n";
                cout<<"2)   Withdraw\n";
                cout<<"3)   Display Balance\n";
                cout<<"4)   Exit\n";
                cout<<"5)   Choose Your choice:-";
                cin>>choice;
                switch(choice)
                {
                    case 1 :
                            p->deposit_currbal();

                            break;
                    case 2 :
                            p->withdraw_currbal();

                            break;
                    case 3 :
                            p->disp_currbal();

                            break;
                    case 4:
                            goto end;
                    default:
                            cout<<"\n\tEntered choice is invalid,!TRY AGAIN!";
                    }
               }
            }
        end:;
        }
    return 0;
    }
© 2017 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
API
Training
Shop
Blog
About