#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class BankAccount {
	string username;
	int ballance;
	string pincode;
public:
	BankAccount(string username, int ballance, string pincode) {
		this -> username = username ;
		this -> ballance = ballance ;
		this -> pincode = pincode ;
	}
	string get_name(){
	    return username;
	}
	string get_pin(){
	    return pincode;
	}	
	void accountInfo() {
	    if(ballance > 500000){
	        cout << "username:" << username << "|| your balance is out of limith" << endl; 
	    }
		cout << "username:" << username << "||ballance is:" << ballance << endl ;
	}
	void deposit(int sumofmoney) {
		ballance += sumofmoney ;
		cout << "your ballance inqreased to " << ballance << " deposit was " << sumofmoney << endl ;
	}
	void withdraw(int sumofmoney) {
		if(ballance < sumofmoney ) {
			cout << "your ballance is not enough!" << endl;
		} else {
			ballance -= sumofmoney;
			cout << "your ballance deqreased to " << ballance << " withdraw was " << sumofmoney << endl ;
		}
	}
};

int main() {
    BankAccount arr[4]={
        BankAccount("Aram",400000,"0000"),
        BankAccount("Armen",500000,"1111"),
        BankAccount("Ani",300000,"2222"),
        BankAccount("Hakob",200000,"3333")
    } ;
   string name;
   string pin;
   string command;
   int money;
   cout << "enter account name:";
   cin >> name; 
   if(name == "exit"){
       return 0;
   }
   for(int i = 0; i < 4; i++){
       if(name != arr[i].get_name()){
           i++;
           if( name != arr[i].get_name() && i + 1 > 3 ){
               cout << "there is no user with name " << name << endl;
               return main();
           }
       }else{
           int index = i;
           cout<<"enter pin code: ";
           cin>>pin;
           cout << endl ;
           if(pin != arr[index].get_pin()){
               cout << "wrong pincode " << endl ;
               return main();
               
           }else{
               cout << "for checking account input 1" << endl ;
               cout << "for deposit input 2 " << endl ;
               cout << "for cancel write exit " << endl ;
               cin >> command ;
               if(command == "exit") {
                   return 0;
               }               
               if(command == "1") {
                   arr[i].accountInfo();
               }
               if( command == "2"){
                   cout << "how much money you want to add -";
                   cin >> money ;
                   if(money > 200000){
                       cout <<"you cant deposit more than 199999 dram" << endl;
                       cout << "how much money you want to add -";
                       cin >> money;
                   }
                   arr[i].deposit(money);
                   cout<<"thank you for using our bank";
                   return 0;
               }
           }
           
       }
   }
	return 0;
}