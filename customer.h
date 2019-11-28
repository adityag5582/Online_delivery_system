#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
//#include "user.h"
//using namespace std;

class Customer:public User
{
   public:
     int customerid;
    // string name;
     string address;
     //string email;
    ShoppingCart sc;

     friend bool customerRegister();
     friend bool customerLogin();
    // bool UpdateProfile();
    void updateprofile()
   {
       int x;
       cout<<"choose from the options to update\n";
       cout<<"1-for name  2-for email \n";
       cout<<"3-for loginId 4-for password change\n5-for address\n";
       cin>>x;
       string s1;
       string e1;
       string l1;
       string p11,p22;
       string ad;
        char ch[200]="support/customers/";
        char ch2[200]=" support/customers/";
        char com[400]="mv ";
       switch(x)
       {
       case 1:
        cout<<"enter name you want to update\n";
        cin.ignore();
        getline(cin,s1);
        name=s1;
        break;
       case 2:
        cout<<"enter email you want to update\n";
        cin.ignore();
        getline(cin,e1);
        email=e1;
        break;
       case 3:
        cout<<"enter Login ID you want to update\n";
        cin.ignore();
        getline(cin,l1);
        
        strcat(ch,LoginId.c_str());
        
        strcat(ch2, l1.c_str());
        
        strcat(com,ch);
        strcat(com," ");
        strcat(com,ch2);
        system(com);
        LoginId=l1;
      //  store(false);
        break;
       case 4:
        cout<<"enter password\n";
        cin.ignore();
        getline(cin,p11);
        cout<<"enter password again\n";
        getline(cin,p22);
        if(p11.compare(p22)==0)
            Password=p11;
        else
            cout<<"enter same password\n";
       case 5:
        cout<<"Enter new address\n";
        cin.ignore();
        getline(cin,ad);
        address=ad;
        break;
       default:
    cout<<"Wrong input"<<endl;
       }
       store(false);
   }


 bool store(bool icart){
    FILE *fp;
    char LI[100];
    strcpy(LI,LoginId.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
    char ch1[100]="cd support/customers/";
    char ch2[100]="mkdir support/customers/";
    char ch3[200]="support/customers/";
    char ch[150]="mkdir support/customers/";
    strcat(ch3,LI);
    strcat(ch1,LI);
    printf("1. %s\n",ch1);
    i=system(ch1);
    if(i!=0)
    {
      strcat(ch2,LI);
      printf("3. %s\n",ch2);
      system(ch2);

    }
  strcat(ch3,"/data");
    fp=fopen(ch3,"w");
    if(fp==NULL){
      printf("Erron storing\n");
      return(false);
    }
   // fprintf(fp, "%s,%s,%s,%s,%d,%d,\n",LI,Password.c_str(),name.c_str(),email.c_str(),vendorId,numberOfItems);
   fprintf(fp, "%s,%s,%s,%s,%s,%d\n",LoginId.c_str(),Password.c_str(),name.c_str(),address.c_str(),email.c_str(),customerid);
    cout<<"\t"<<"Data recorded\n";
    fclose(fp);

    if(icart)
    {
      char d[300]="support/customers/";
      char f[300]="mkdir support/customers/";
      strcat(f,LI);
      strcat(d,LI);
      strcat(d,"/");
      strcat(f,"/");
      strcat(d,"oi");
      fp=fopen(d,"w");
      int l=1;
      fprintf(fp, "%d\n",l );
      fclose(fp);
        strcat(f,"/receipt");
        system(f);
        sc.CustID=customerid;
      }

    return(true);
    
   }

    bool load(string id){
    FILE *fp;
    char LI[100];
    strcpy(LI,id.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
    char ch1[100]="cd support/customers/";
   // char ch2[100]="mkdir support/vendors/";
    char ch3[200]="support/customers/";
    strcat(ch3,LI);
    strcat(ch1,LI);
    printf("1. %s\n",ch1);
    i=system(ch1);
    if(i!=0)
    {
      printf("Error loading...\n");
      return(false);

    }
  strcat(ch3,"/data");
    fp=fopen(ch3,"r");
    if(fp==NULL)
    {
      printf("Error loading...\n");
      return(false);
    }
    char temp1[50],temp2[50],temp3[50],temp4[100],temp5[100];
   // int a,b;
   fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,],%d\n",temp1,temp2,temp3,temp4,temp5,&customerid);
   // printf("res : %s,  %s,  %s,  %s,  %d,\n",temp1,temp2,temp3,temp4,vendorId,customerid);
    LoginId=to_string(temp1);
    Password=to_string(temp2);
    name=to_string(temp3);
    address=to_string(temp4);
    email=to_string(temp5);
    fclose(fp);
    setCart();
    return(true);
    }
   
   
   bool customerVerifyLogin(string LI,string Pass){
int i;
string str;
//Vendor v;
char ch[100]="cd support/customers/";
strcat(ch,LI.c_str());
i=system(ch);
if(i!=0)
{
  cout<<"\tID dosen't exist\n";
  return false;
}
load(LI);
if(Pass.compare(Password)==0)
{
 // active_vendor=v;
  //cout<<"\t Login successfull"<<endl;
  return true;
}
cout<<"\t Password didn't matched"<<endl;

return false;
}


void item_search(){

  FILE *fp;
  int i=0,x;
  string s;
  char str[200][200];
  Vendor ven;
  cout<<"--------------------------------------------"<<endl;
  fp=fopen("support/vendors_record","r");
  while(1){
    fscanf(fp,"%s\n",str[i]);
    if(strcmp(str[i],"")==0){
      cout<<"--------------------------------------------"<<endl;
      cout<<"Above are the all available vendors.\n";
      cout<<"choose from the above vendors :";
    }

    if(strcmp(str[i],"")==0)
      break;
    ven.load(to_string(str[i]));

    cout<<i<<". "<<ven.name<<" : "<<str[i]<<endl;

    i++;
  }
  fclose(fp);
do{
cin>>x;
if(x>i)
  cout<<"Wrong choice...\nChoose again : ";
} while(x>i);

ven.load(to_string(str[x]));

cout<<"\t Welcome from "<<ven.name<<endl;
cout<<"------------------------------------------"<<endl;
int j,k,l;
i=0;
char ch[300]="support/vendors/";
strcat(ch,ven.LoginId.c_str());
strcat(ch,"/items_record");
fp=fopen(ch,"r");
while(1){
  fscanf(fp,"%s\n",str[i]);
  if(strcmp(str[i],"")==0)
    break;
  i++;
}
item it;

int page=0;
while(1){
  for(j=0;j<10&&(j+10*page)<i;j++){
    it.load(ven.LoginId,to_string((str[j+10*page])));
    cout<<j+page<<".  \n  ";
    it.display();
    cout<<endl;

  }
cout<<endl<<"\t";
cout<<"Current page : "<<page+1<<endl;
cout<<"Enter 'n' for next page 'p' for previous page\n";
cout<<"Enter 'q' to quit and any integer from 0 to 9 to add item to ShoppingCart\n";
do{
cin>>s;
}while(s.compare("")==0);
if(s.compare("n")==0){
if(10*(page+1)<i)
  page++;

}
else if(s.compare("p")==0){
if(page>0)
  page--;
}
else if(s.compare("q")==0){
break;
}
else{
  l=stoi(s);
  if(l>=0&&l<=9){
  it.load(ven.LoginId,to_string(str[10*page+l]));

sc.AddItem(it.productID,ven.LoginId);
}
else{
  cout<<"Wrong choice try again\n";
}
}

}

}

void ri(){
  sc.removeItem();
}

void vcd(){
  sc.viewCartDetails();
}

void uq(){
  sc.updateQuantity();
}

void po(){
  sc.placeOrder();
}

void setCart(){
  sc.CustID=LoginId;
  sc.load(LoginId);
}


void pastOrder(){
  FILE *fp;
  char ch1[300];
  char ch[300]="support/customers/";
  strcat(ch,LoginId.c_str());
  strcpy(ch1,ch);
  strcat(ch,"/recipt/");
  strcat(ch1,"/oi");
  int x,y,i,page;
  fp=fopen(ch1,"r");
  fscanf(fp,"%d",&x);
  fclose(fp);
  if(x==1){
    cout<<"NO orders yet."<<endl;
    return;
  }
 /* cout<<"x = "<<x<<endl;
  while(getchar()!='x')
    ;*/
  orderReceipt recp;
system("clear");
//cout<<"x ="<<x<<endl;
  for(page=0;(page)*10<x;page++){
  //  cout<<"flag1\n";
  for(i=1;(i+page*10<x)&&(i<=10);i++){
    recp.load(LoginId,to_string(10*page+i));
    //cout<<"Caled"<<endl;
 //   while(getchar()!='x')
   //   ;
    cout<<i<<". "<<endl;
    recp.display();
  }
cout<<"choose from the above order to modify(1to10)."<<endl;
cout<<"Press 0 for previous page and 1 for next page and -1 ro quit this page :\n";
cin>>y;
switch(y){
case 0:
if(page>0)
page--;
break;

case 11:
if((page+1)*10<x)
page++;
break;

case -1:
return;
break;

default:
if(y>0&&y<11){
  system("clear");
  recp.load(LoginId,to_string(10*page+y));
  recp.display();
  recp.edit();
  system("clear");
  cout<<"Edit successfull"<<endl;


}

}

}

  fclose(fp);
}

};