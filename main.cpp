#include<iostream>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include "user.h"
#include "item.h"
#include "reciept.h"
#include "cart.h"

#include "vendor.h"
#include "customer.h"
#include "delivery.h"

//using namespace std;
//class User;
//class Customer:public User;

int numberOfCust;
int numberOfVendor;
bool customerVerifyLogin(string LoginId,string Password);
//int vendorVerifyLogin(string LoginId,string Password);

Vendor active_vendor;
Customer active_customer;
DeliveryPerson active_delivery;



 
bool deliveryRegister()
{
  string p1,p2;
  DeliveryPerson dp;
  cout<<"Enter your details\n";
  cout<<"Enter your name\n";
  do{
   getline(cin,dp.name);
   }
   while(dp.name.compare("\n")==0||dp.name.compare("")==0);
   cout<<"Enter your email\n";
  do{
   getline(cin,dp.email);
   }
   while(dp.email.compare("\n")==0||dp.email.compare("")==0);
cout<<"Enter your contact no\n";

   cin>>dp.contact;
   
   
cout<<"Enter your id\n";
  do{
   getline(cin,dp.Id);
   }
   while(dp.Id.compare("\n")==0||dp.Id.compare("")==0);
   cout<<"Enter your password\n";
  do{
   getline(cin,p1);
   }
   while(p1.compare("\n")==0||p1.compare("")==0);
   cout<<"Enter your password again\n";
  do{
   getline(cin,p2);
   }
   while(p2.compare("\n")==0||p2.compare("")==0);
   if(p1.compare(p2)==0)
  {
     dp.Password=p1;
     dp.store();
     active_delivery=dp;
     cout<<"you have been registered successfully as delivery person\n";
     return true;
   }
   else
   {
     cout<<"Register failed,password didn't matched.\nTry again...\n";
return false;
    }
}
bool deliveryLogin()
{
 string l;
 string p;
 DeliveryPerson dp;
 cout<<"Enter your Login Id"<<endl;
 do{
   cin>>l;
   }
 while(l.compare("\n")==0||l.compare("")==0);


 cout<<"Enter your password\n";
  do{
   cin>>p;
} while(p.compare("\n")==0||p.compare("")==0);
if(!dp.deliveryVerifyLogin(l,p))
{
  int v;
cout<<"Enter 1 if you want to login again , 0 for exit"<<endl;
  cin>>v;
  if(v)
    deliveryLogin();
else
 return(false);
}
 active_delivery.load(l);
 cout<<"login successful"<<endl;
 return(true);
}









//Vendor vendors[10];


bool vendorRegister()
     {
         string p1,p2;
         Vendor v;
         v.vendorId=numberOfVendor+1000;
         cout<<"Your assigned id is "<<v.vendorId<<endl;
         cin.ignore();
         cout<<"Enter your name"<< endl;
         do{
         getline(cin,v.name);
           } while(v.name.compare("\n")==0);
         cout<<"Enter your email-id"<< endl;
        do{
         getline(cin,v.email);
            } while(v.email.compare("\n")==0) ;
         cout<<"Enter Login Id\n";
          do{
         getline(cin,v.LoginId);
         } while(v.LoginId.compare("\n")==0);
        // cout<<v.LoginId<<endl;
         int temp;
         char ch[100]="cd support/vendors/";
         strcat(ch,v.LoginId.c_str());
         temp=system(ch);
         if(temp==0){
         	cout<<"\n \t ID already registered"<<endl;
         	return false;
         }
         cout<<"enter password\n";
           do{
         cin>>p1;
     } while(p1.compare("\n")==0);
         //cout<<p1<<endl;
         cout<<"enter password again\n";
          do{
         cin>>p2;
     } while(p2.compare("\n")==0);
         //cout<<p2<<endl;
         if(p1.compare(p2)==0)
         {
              v.Password=p1;
              cout<<"You have been registered successfully as vendor\n";
              numberOfVendor++;
              v.store(true);
              return true;
         }
         else
         {
             cout<<"Password didn't matched. Register again...\n";
             return false;
         }
     }


 bool vendorLogin()
     {
         string l;
         string p;
         Vendor v;
	 system("clear");
         cout<<"Enter your Login id "<<endl;

        do{
         cin>>l;
     } while(l.compare("\n")==0);
         cout<<"Enter your password\n";
            do{
        cin>>p;
     }while(p.compare("\n")==0);
         bool ttp=v.vendorVerifyLogin(l,p);
         if(!ttp)
         {   int v;
             cout<<"Enter 1 if you want to login again , 0 for exit"<<endl;
             cin>>v;
             if(v)
               return vendorLogin();
             else
                return(false);
         }
         
         active_vendor.load(l);
         cout<<"login successful"<<endl;
         return(ttp);
     }


Customer customers[1000];



 bool customerRegister()
     {
         string p1,p2;
         Customer cus;
         cus.customerid=numberOfCust;
         cout<<"Your assigned id is "<<cus.customerid<<endl;
         
         cout<<"Enter your name"<< endl;
         do{
         getline(cin,cus.name);
         
          } while(cus.name.compare("")==0);
         cout<<"Enter your address"<< endl;

         do{
         getline(cin,cus.address);
         } while(cus.address.compare("")==0);

         cout<<"Enter your email-id"<< endl;
        do{
        
         getline(cin,cus.email);
            } while(cus.email.compare("")==0);

         cout<<"Enter Login Id\n";
          do{
         
         getline(cin,cus.LoginId);
        } while(cus.LoginId.compare("")==0);

       //  cout<<cus.LoginId<<endl;
         cout<<"enter password\n";
           //do{
         do{
         cin>>p1;

     } while(p1.compare("\n")==0||p1.compare("")==0);
         //cout<<p1<<endl;
         cout<<"enter password again\n";
          do{
       
         cin>>p2;
     } while(p2.compare("")==0);
         //cout<<p2<<endl;
         cout<<"p1: "<<p1<<"|";
         cout<<"p2: "<<p2<<"|";
         if(p1.compare(p2)==0)
         {
              cus.Password=p1;
              cus.store(true);
              active_customer=cus;//.load(cus.LoginId);
              active_customer.setCart();
              cout<<"You have been registered successfully as a customer\n";
              numberOfCust++;
             	
              return true;
         }
         else
         {
             cout<<"Register failed, Password didn't matched.\nTry again...\n";
             return false;
         }
     return true;
     }
bool customerLogin()
     {
         string l;
         string p;
         Customer cus;
         cout<<"Enter your Login id "<<endl;

        do{
         cin>>l;
     } while(l.compare("")==0);
         cout<<"Enter your password\n";
            do{
        cin>>p;
     }while(p.compare("")==0);
         if(!cus.customerVerifyLogin(l,p))
         {   int v;
             cout<<"Enter 1 if you want to login again , 0 for exit"<<endl;
             cin>>v;
             if(v)
                customerLogin();
             else
                return(false);
         }

         active_customer.load(l);
         cout<<"login successful"<<endl;
         return(true);
     }

void reg(){
	int y;
	system("clear");
 cout<<"\n\t1. Register as a Customer\n";
        cout<<"\t2. Register as a Vendor\n";
        cout<<"\t3. Register as Delivery Person\n";
        cout<<"\t4. BACK\n";
        cout<<"Choose one : ";
        cin>>y; 
        switch(y){

          case 1:
          customerRegister();
          break;

          case 2:
          vendorRegister();
          break;

          case 3:
          deliveryRegister();
          break;

          case 4:
          break;

          default:
          cout<<"Wrong Choice, Try again...\n";
        }
        if(y!=4){
        cout<<"Enter 'c' to continue :  ";
        
        while(getchar()!='c');
        }
        
}

void vendorfun(){
	bool b;
	int i;
      while(1){
          system("clear");
          cout<<"\t\tWelcome Vendore\n";
          cout<<"---------------------"<<endl;
          cout<<"1. UpdateProfile\n";
          cout<<"2. Update Items\n";
          cout<<"3. Add items\n";
          cout<<"4. Remove Items\n";
          //cout<<"5. visit market\n";
          cout<<"5. Logout\n";
          cout<<"Choose one of the above  :  ";
          cin>>i;
          system("clear");
          if(i==5)
          	break;
          switch(i){

            case 1:
            active_vendor.updateprofile();
            break;
            case 2:
            active_vendor.UpdateItems();
            break;
            case 3:
            b=active_vendor.addItem();
            break;
            case 4:
           active_vendor.RemoveItem();
            break;
           
            default:
            cout<<"\tWrong Choice, Try again...\n";


          }
          cout<<"Enter c to continue";
          while(getchar()!='c')
          	;
      }


}

void customerfun(){
int x;

while(1){
system("clear");
cout<<"\n\t1. Update Profile"<<endl;
cout<<"\t2. Item Search"<<endl;
cout<<"\t3. View Cart Details"<<endl;
cout<<"\t4. Remove Item"<<endl;
cout<<"\t5. Update Quantity in Cart"<<endl;
cout<<"\t6. Place Order"<<endl;
cout<<"\t7. Past Orers"<<endl;
cout<<"\t8. Logout"<<endl;
cout<<"Enter one of the above options : ";
cin>>x;
/*if(x==7){
	active_customer=NULL;
}*/
if(x==8)
	break;
switch(x){
	case 1:
	active_customer.updateprofile();
	break;
	case 2:
	system("clear");
	active_customer.item_search();
	break;
	case 3:
	active_customer.vcd();
	break;
	case 4:
	active_customer.ri();
	break;
	case 5:
	active_customer.uq();
	break;
	case 6:
	active_customer.po();
	break;
	case 7:
	active_customer.pastOrder();
	break;
	default:
		cout<<"Wrong choice.\nPlease try again\n";

}

cout<<"Enter 'c' to continue :"<<endl;
while(getchar()!='c')
	;
}
}

void deliveryfun(){
	int x;
system("clear");
while(1){
system("clear");	
cout<<"\n\t1. Get order details"<<endl;
cout<<"\t2. Conirm order deleverys"<<endl;
cout<<"\t3. Logout"<<endl;

cout<<"Enter one of the above options : ";
cin>>x;
/*if(x==3){
	active_delivery=NULL;
}*/
if(x==3)
	break;
switch(x){
	case 1:
	active_delivery.getOrderDetails();
	break;
	case 2:
	active_delivery.deliverOrder();
	break;
	
	default:
		cout<<"Wrong choice.\nPlease try again\n";

}

cout<<"Enter 'c' to continue :"<<endl;
while(getchar()!='c')
	;
}

}

void log(){
	int y;
	bool b;
while(1){
        system("clear");
        cout<<"\n\t1. Login as a Customer\n";
        cout<<"\t2. Login as a Vendor\n";
        cout<<"\t3. Login as Delivery Person\n";
        cout<<"\t4. BACK\n";
        cout<<"Choose one : ";
        cin>>y;
        switch(y){

          case 1:
          b=customerLogin();
          if(!b){
            cout<<"\n\tLogin failed\n";
          }
          if(!b)
            break;

			customerfun();          

          break;

          case 2:
          b=vendorLogin();
          if(!b){
            cout<<"\n\tLogin faied\n";
          }
          if(!b)
            break;
  			vendorfun();

          break;
          case 3:
          b=deliveryLogin();
          if(!b)
          	cout<<"Login Failed"<<endl;
          if(!b)
          	break;
	  system("clear");
          deliveryfun();

          break;
          case 4:
          break;

          default:
          cout<<"Wrong Choice, Try again...\n";
        }
        if(y==4)
          break;
      }
        if(y!=4){
    cout<<"Enter 'c' to continue :  ";
        while(getchar()!='c');
        }
        system("clear");
}



int main(){
numberOfCust=0;
numberOfVendor=0;
int i,j,k,x,y;
bool login_stat;
bool b,stat;
   while(1){
    system("clear");
    cout<<"\n1. Register\n";
    cout<<"2. Login\n";
    cout<<"3. Exit\n";
    cout<<"Choose one : ";
    cin>>x;
    if(x==3)
    	break;
   // system("clear");
    switch(x){

      case 1:
      
       reg();
        
      break;

      case 2:
    log();
        
      break;

      default:
      system("clear");
      cout<<"\nWrong chooice\n"<< "Try again...";
      cout<<"Press c to continue ";
      while(getchar()!='c')
      	;


    }


   }

    return 0;
}
