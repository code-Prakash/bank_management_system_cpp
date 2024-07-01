#include<iostream>
#include<vector>
using namespace std;
class client{
public:
    long account_num;
    string name;
    int age;
    string address;
    long long phone;
    long long aadhar;
    long password;
    long long balance;
    long long credit;
    long long loan_paid;
    long long loan_left;
    client(){
        credit = 0;
        loan_paid = 0;
        loan_left = 0;
        balance = 0;
    }
};
class login1{
public:
    string name;
    string username;
    long password;
};

vector<client> customers;
login1 admin;
void login(){
    cin.ignore();
    cout<<"Enter your name: ";
    getline(cin,admin.name);
    cout<<"Enter your username: ";
    cin>>admin.username;
    cout<<"Enter your password: ";
    cin>>admin.password;
    cout<<endl;
}

void create(){
    int n;
    cout<<"Enter the Number of accounts you want to create: ";
    cin>>n;
    for(int i=0; i<n; i++){
        client customer;
        cin.ignore();
        cout<<"Enter the Name of the Customer: ";
        getline(cin, customer.name);
        cout<<"Enter the Account number of the Customer: ";
        cin>>customer.account_num;
        cout<<"Enter the Age of the Customer: ";
        cin>>customer.age;
        cin.ignore();
        cout<<"Enter the Address of the Customer: ";
        getline(cin, customer.address);
        cout<<"Enter the Phone number of the Customer: ";
        cin>>customer.phone;
        cout<<"--FOR THE VERIFICATION--"<<endl;
        cout<<"Enter the Aadhar Number: ";
        cin>>customer.aadhar;
        cout<<"Enter the Password: ";
        cin>>customer.password;
        customers.push_back(customer);
        cout<<endl<<"====================================================\n\n";
    }
    cout<<"-----Account created successfully------\n"<<endl;
    for(int i=0;i<customers.size();i++){
        cout<<"Name: "<<customers[i].name<<endl;
        cout<<"Account Number: "<<customers[i].account_num<<endl;
        cout<<"Age: "<<customers[i].age<<endl;
        cout<<"Address: "<<customers[i].address<<endl;
        cout<<"Phone Number: "<<customers[i].phone<<endl;
        cout<<"Aadhar Number: "<<customers[i].aadhar<<endl;
        cout<<"Balance: Rs."<<customers[i].balance<<endl;
        cout<<endl; 
    }
    cout<<"NOTE! Plese Remember Name and Password"<<endl;
    cout<<endl<<"====================================================\n\n";      
}

int search(long user){
    for(int i=0;i<customers.size();i++){
        if(customers[i].account_num==user){
            return i;
        }
    }
    return -1;
}

void deposit(){
    long user;
    long pass;
    long long amount;
    cout<<"Insert Customer's Account Number: ";
    cin>>user;
    long result=search(user);
    if(result==-1){
        cout<<"====INCORRECT ACCOUNT NUMBER====\n";
        cout<<"!!TRY AGAIN!!\n";
    }
    else{
        cout<<"Please Insert Password: ";
        cin>>pass;
        if(customers[result].password==pass){
            cout<<"Please Amount you want to Deposite: Rs.";
            cin>>amount;
            customers[result].balance += amount;
            cout<<"****Amount is Successfully Deposited****\n";
            cout<<"\nYour Total Balance is Rs."<<customers[result].balance<<endl;
        }
        else{
            cout<<"\n======INCORRECT PASSWORD======\n\n";
        }
    }
}

void withdraw(){
    long user;
    long pass;
    long long amount;
    cout<<"Insert Customer's Account Number: ";
    cin>>user;
    long result=search(user);
    if(result==-1){
        cout<<"====INCORRECT ACCOUNT NUMBER====\n";
        cout<<"!!TRY AGAIN!!\n";
    }
    else{
        cout<<"Please Insert Password: ";
        cin>>pass;
        if(customers[result].password==pass){
            cout<<"Please Amount you want to Withdraw: Rs.";
            cin>>amount;
            if(customers[result].balance>=amount){
                customers[result].balance -= amount;
                cout<<"\n\n****Amount is Successfully Withdrawal****\n";
                cout<<"\nYour Total Balance is Rs."<<customers[result].balance<<endl;
            }
            else{
                cout<<"\n====INSUFFICIENT AMOUNT====\n";
            }
        }
        else{
            cout<<"\n====INCORRECT PASSWORD====\n\n";
        }
    }   
}

void transfer(){
    long user;
    long pass;
    long long amount;
    long user2;
    cout<<"Insert Customer's Account Number: ";
    cin>>user;
    long result=search(user);
    if(result==-1){
        cout<<"====INCORRECT ACCOUNT NUMBER====\n";
        cout<<"!!TRY AGAIN!!\n";
    }
    else{
        cout<<"Please Insert Password: ";
        cin>>pass;
        if(customers[result].password==pass){
            cout<<"Please Insert the Account number where you want to tranfer: ";
            cin>>user2;
            long result2 =search(user2);
            if(result2==-1){
                cout<<"====NO RECORD FOUND====\n";
                cout<<"!!TRY AGAIN!!\n";
            }
            else{
                cout<<"Please Insert the Amount you want to tranfer: Rs.";
                cin>>amount;
                if(customers[result].balance>=amount){
                    customers[result].balance-=amount;
                    customers[result2].balance+=amount;
                    cout<<"\n****Amount is Successfully Transferred****\n";
                    cout<<"\nYour Total Balance is Rs."<<customers[result].balance<<endl;
                }
                else{
                    cout<<"\n====INSUFFICIENT AMOUNT====\n";
                }
            }
            
        }
        else{
            cout<<"\n====INCORRECT PASSWORD====\n";
        }
    }          
}

void delete_acc(){
    long user;
    long pass;
    char decision;
    cout<<"Insert Customer's Account Number: ";
    cin>>user;
    long result=search(user);
    if(result==-1){
        cout<<"====INCORRECT ACCOUNT NUMBER====\n";
        cout<<"!!TRY AGAIN!!\n";
    }
    else{
        cout<<"Please Insert Password: ";
        cin>>pass;
        if(customers[result].password==pass){
            cout<<"Do you want to delete your account? (Y/N): ";
            cin>>decision;
            if(decision=='Y'||decision=='y'){    
                customers.erase(customers.begin() + result);
                cout<<"***Account deleted Successfully.***\n";
            } 
            else{
                cout<<"***Account deletion Cancelled.***\n";
            }
        } 
        else {
            cout<<"\n====INCORRECT PASSWORD====\n\n";
        }
    }
}

void update_acc(){
    long user;
    long pass;
    int choice;
    cout<<"Insert Customer's Account Number: ";
    cin>>user;
    long result=search(user);
    if(result==-1){
        cout<<"====INCORRECT ACCOUNT NUMBER====\n";
        cout<<"!!TRY AGAIN!!\n";
    }
    else{
        cout<<"Please Insert Password: ";
        cin>>pass;
        if(customers[result].password==pass){
            cout<<"Select the option which you want to update"<<endl;
            cout<<"1.Name\n2.Password\n3.Address\n4.Phone\n";
            cout<<"Enter your Choice: ";
            cin>>choice;
            if(choice==1){
                cin.ignore();
                cout<<"Enter your new Name: ";
                getline(cin, customers[result].name);;
            }
            else if(choice==2){
                cout<<"Enter your new Password: ";
                cin>>customers[result].password;
            }
            else if(choice==3){
                cin.ignore();
                cout<<"Enter your new Address: ";
                getline(cin, customers[result].name);;
            }
            else if(choice==4){
                cout<<"Enter your new Phone number: ";
                cin>>customers[result].phone;
            }
            else cout<<"Invalid Choice"<<endl;
            cout<<"You have Updated your Account Successfully!!"<<endl;
        }
        else {
            cout<<"\n====INCORRECT PASSWORD====\n\n";
        }
    }
}

void display(){
    for(int i=0; i<customers.size(); i++){
        cout<<"Name: "<<customers[i].name<<endl;
        cout<<"Account Number: "<<customers[i].account_num<<endl;
        cout<<"Age: "<<customers[i].age<<endl;
        cout<<"Address: "<<customers[i].address<<endl;
        cout<<"Phone Number: "<<customers[i].phone<<endl;
        cout<<"Aadhar Number: "<<customers[i].aadhar<<endl;
        cout<<"Balance: Rs."<<customers[i].balance<<endl;
        cout<<endl;
        cout<<"-------------------------------------------------------------\n\n";      
        cout<<endl;
    }
}

void search_cus(){
    long user;
    cout<<"Insert Customer's Account Number: ";
    cin>>user;
    long result=search(user);
    if(result==-1){
        cout<<"====INCORRECT ACCOUNT NUMBER====\n";
        cout<<"!!TRY AGAIN!!\n";
    }
    else{
        cout<<endl;
        cout<<"Name: "<<customers[result].name<<endl;
        cout<<"Account Number: "<<customers[result].account_num<<endl;
        cout<<"Age: "<<customers[result].age<<endl;
        cout<<"Address: "<<customers[result].address<<endl;
        cout<<"Phone Number: "<<customers[result].phone<<endl;
        cout<<"Aadhar Number: "<<customers[result].aadhar<<endl;
        cout<<"Balance: Rs."<<customers[result].balance<<endl;
        cout<<"Password: "<<customers[result].password<<endl;
        cout<<endl;
    }
}

void loan(){
    long user;
    long pass;
    long long principal,loan_deposit;
    int time;
    char decision;
    cout<<"Insert Customer's Account Number: ";
    cin>>user;
    long result=search(user);
    if(result==-1){
        cout<<"====INCORRECT ACCOUNT NUMBER====\n";
        cout<<"!!TRY AGAIN!!\n";
    }
    else{
        cout<<"Please Insert Password: ";
        cin>>pass;
        if(customers[result].password==pass){
            int choice;
            cout<<"--Select your choice-- "<<endl;
            cout<<"1.Apply for loan "<<endl;
            cout<<"2.Check loan status"<<endl;
            cout<<"3.Pay loan"<<endl;
            cout<<"0.Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;
            if(choice==1){
                cout<<"Enter the amount to be loaned: Rs."; 
                cin>>principal;
                cout<<"Enter the duration to be loaned (In Years): ";
                cin>>time;
                if(principal>0 && principal<=10*customers[result].balance){
                    long long si=(principal * time * 10)/100;
                    cout<<"Total Amount you have to pay: Rs."<<si+principal<<endl;
                    cout<<"Do you want to approve this loan(Y/N): ";
                    cin>>decision;
                    if(decision=='Y'|| 'y'){
                        customers[result].credit=principal;
                        customers[result].balance+=customers[result].credit;
                        customers[result].loan_left=principal+si;
                        cout<<endl<<"====Your Loan is approved====\n"<<endl;
                    }
                    else{
                        cout<<"====Your Loan is not approved===="<<endl;
                    }
                }
                else{
                    cout<<"====You are not elegible for loan===="<<endl;
                }
            }
            else if(choice==2){
                cout<<endl<<"Name: "<<customers[result].name<<endl;
                cout<<"Account Number: "<<customers[result].account_num<<endl;
                cout<<"Loan Amount: Rs."<<customers[result].credit<<endl;
                cout<<"Remaining Amount: Rs."<<customers[result].loan_left<<endl;
                cout<<"Amount Paid: Rs."<<customers[result].loan_paid<<endl<<endl;
            }
            else if(choice==3){
                cout<<"Enter the Amount you want to pay: Rs.";
                cin>>loan_deposit;
                if(loan_deposit<customers[result].balance){
                    if(loan_deposit>customers[result].loan_left){
                        cout<<"***Please check the Remainig Amount***\n"<<endl;
                    }
                    else{
                        customers[result].balance-=loan_deposit;
                        customers[result].loan_paid+=loan_deposit;
                        customers[result].loan_left-=loan_deposit;
                        cout<<endl<<"***Your amount paid Successfully.***"<<endl;
                    }
                }
                else{
                    cout<<"====INSUFFICIENT AMOUNT====="<<endl;
                }
            }
            else if(choice==0){
                cout<<"***THANK YOU FOR USING OUR SERVICES***\n"<<endl;
            }
        }
    }
}

int main(){
    int choice,login_choice;
    string username;
    long password;
    char ch='Y',ch_menu='Y';
    while(ch=='Y'){
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout<<"==============WELCOME TO THE WORLD RICHEST BANK=============\n";
        cout<<"====================TYCOON BANKING SYSTEM===================\n\n";
        cout<<"************************************************************\n";
        cout<<"================1.Sign_up===================================\n";
        cout<<"================2.Login=====================================\n";
        cout<<"================3.Exit======================================\n\n";
        cout<<"Enter Your Choice from the Above : ";
        cin>>login_choice;
        if(login_choice==1){
            login();
        }
        else if(login_choice==2){
            cout<<"Enter Your Username: ";
            cin>>username;
            if(username==admin.username){
                cout<<"Enter Your Password: ";
                cin>>password;
                if(password==admin.password){
                    while(ch_menu=='Y'){
                        cout<<endl<<"========================MAIN MENU===========================\n";
                        cout<<"************************************************************\n\n";
                        cout<<"================1.Create new account========================\n";
                        cout<<"================2.Deposite Money============================\n";
                        cout<<"================3.Withdraw Money============================\n";
                        cout<<"================4.Transfer Money============================\n";
                        cout<<"================5.Delete Existing account===================\n";
                        cout<<"================6.Update Existing account===================\n";
                        cout<<"================7.Display Balance===========================\n";
                        cout<<"================8.Search Customer's Information=============\n";
                        cout<<"================9.Loans=====================================\n";
                        cout<<"================0.Quit======================================\n";
                        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                        cout<<"Enter Your Choice from the Above : ";
                        cin>>choice;
                        if(choice==1) create();
                        else if(choice==2) deposit();
                        else if(choice==3) withdraw();
                        else if(choice==4) transfer();
                        else if(choice==5) delete_acc();
                        else if(choice==6) update_acc();
                        else if(choice==7) display();
                        else if(choice==8) search_cus();
                        else if(choice==9) loan();
                        else if(choice==0){
                            cout<<"==============THANK YOU FOR USING OUR SERVICES US=================";
                            ch_menu='N';
                        }
                        else{
                            cout<<"====INVALID CHOICE====\n";
                            cout<<"!!TRY AGAIN!!\n";
                        }
                    }
                }
                else{
                    cout<<"====INCORRECT PASSWORD====\n";
                    cout<<"!!TRY AGAIN!!\n";
                }
            
            }
            else{
                cout<<"====INCORRECT USERNAME====\n";
                cout<<"!!TRY AGAIN!!\n";
            }
        }
        else if(login_choice==3){
            cout<<"==============THANK YOU FOR BANKING WITH US=================";
            break;
        }
        else{
            cout<<"====INVALID CHOICE====\n";
            cout<<"!!TRY AGAIN!!\n";
        }    
    
    }    
    return 0;
}
