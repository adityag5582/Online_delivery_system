#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
//#include "user.h"
//using namespace std;

class Vendor:public User
{
  public:
  // string name;
   //string email;
   int vendorId;
   //item Item[50];
   int numberOfItems;

   Vendor(){
    numberOfItems=0;
   }
   friend bool vendorRegister();
  // friend int vendorLogin();
   void UpdateItems()
   {
       int n;
       string str;
       cout<<"enter the product id of the item you want to update : \n";
       cin>>str;
       item i;
       bool tem=i.load(LoginId,str);
       if(!tem){
        cout<<"Item does not exist.\n";
        return;
       }

       i.updateItem();
       i.store();
       //Item[n].updateItem();
   }
   bool RemoveItem()
   {
       string pid;
       cout<<"enter product id you want to remove\n";
       cin.ignore();
       getline(cin,pid);
      
       item i;
       bool tem=i.load(LoginId,pid);
       if(!tem){
        cout<<"Item does not exist\n";
        return false;

       }
        i.inStock=false;
        i.itemCount=0;
        i.store();
        return(true);     
   }
  // friend void addItems(int vendorNo);
   void updateprofile()
   {
       int x;
       cout<<"choose from the options to update\n";
       cout<<"1-for name  2-for email \n";
       cout<<"3-for loginId 4-for password change";
       cin>>x;
       string s1;
       string e1;
       string l1;
       string p11,p22;
         char ch[200]="support/vendors/";
        char ch2[200]=" support/vendors/";
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
        cout<<"enter LoginId you want to update\n";
        cin.ignore();
        getline(cin,l1);

          strcat(ch,LoginId.c_str());
        
        strcat(ch2, l1.c_str());
        
        strcat(com,ch);
        strcat(com," ");
        strcat(com,ch2);
        system(com);
        LoginId=l1;
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
            cout<<"\tpassword didn't matched\n";
       default:
    cout<<"Wrong input"<<endl;
       }
       store(false);
   }

   bool store(bool iFolder){
    FILE *fp;
    char LI[100];
    strcpy(LI,LoginId.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
    char ch1[100]="cd support/vendors/";
    char ch2[100]="mkdir support/vendors/";
    char ch3[200]="support/vendors/";
    char ch[150]="mkdir support/vendors/";
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
    fprintf(fp, "%s,%s,%s,%s,%d,%d,\n",LI,Password.c_str(),name.c_str(),email.c_str(),vendorId,numberOfItems);
    cout<<"\t"<<"Data recorded\n";
    fclose(fp);
//    system("cd ../..");
    if(iFolder){
      strcat(ch,LI);
      strcat(ch,"/");
      strcat(ch,"items");
      system(ch);
     // cout<<"hello1"<<endl;
      fp=fopen("support/vendors_record","a");
      fprintf(fp,"%s\n",LI);
      fclose(fp);
      //cout<<"hello2"<<endl;

    }
    return(true);
    
   }

    bool load(string id){
    FILE *fp;
    char LI[100];
    strcpy(LI,id.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
    char ch1[100]="cd support/vendors/";
   // char ch2[100]="mkdir support/vendors/";
    char ch3[200]="support/vendors/";
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
    char temp1[50],temp2[50],temp3[50],temp4[50];
   // int a,b;
    fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%d,%d,\n",temp1,temp2,temp3,temp4,&vendorId,&numberOfItems);
    printf("res : %s,  %s,  %s,  %s,  %d,  %d\n",temp1,temp2,temp3,temp4,vendorId,numberOfItems);
    LoginId=to_string(temp1);
    Password=to_string(temp2);
    name=to_string(temp3);
    email=to_string(temp4);
    fclose(fp);
     return(true);
   }
   
   bool vendorVerifyLogin(string LI,string Pass){
int i;
string str;
//Vendor v;
char ch[100]="cd support/vendors/";
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


bool addItem()
{

    item i;
    i.vendorID=LoginId;
    cin.ignore();
    cout<<"enter category\n";
    getline(cin,i.category);
    //  cout<<"\t"<<i.category<<endl;
    cout<<"enter subcategory\n";
    getline(cin,i.subcategory);
      //cout<<"\t"<<i.subcategory<<endl;
    cout<<"enter product name\n";
    getline(cin,i.name);
       //cout<<"\t"<<i.name<<endl;
    cout<<"enter product id\n";
    cin>>i.productID;
      //cout<<"\t"<<i.productID<<endl;
    cout<<"enter product rating and it should be below 5\n";
    cin>>i.rating;
    //cout<<"\t"<<i.rating<<endl;
    cout<<"enter product MRP\n";
    cin>>i.MRP;
      //cout<<"\t"<<i.MRP<<endl;
    cout<<"enter product Discount\n";
    cin>>i.Discount;
      //cout<<"\t"<<i.Discount<<endl;
    //cout<<"enter product DiscountPrice\n";
    i.DiscountPrice=i.MRP-(i.MRP*i.Discount)/100;
    cout<<"enter product itemCount\n";
    cin>>i.itemCount;
     // cout<<"\t"<<i.itemCount<<endl;
    if(i.itemCount)
        i.inStock=true;
    else
       i.inStock=false;
     cout<<"Enter short description about the product : ";
    // cin>>i.details;
    char c[500];
   // do{
    //scanf("%[^\n]s",c);
     //} while(strcmp(c,"\n")==0);
    //i.details=to_string(c);
    //while(getchar()=='\n');
    //do{
    cin.ignore();
    getline(cin,i.details);
    //} while(i.details.compare("\n")==0);
    cout<<i.name<<" has been added successfully added\n";
  //  numberOfItems++;
    FILE *fp;
    char ch[200]="support/vendors/";
    strcat(ch,LoginId.c_str());
    strcat(ch,"/items_record");
    fp=fopen(ch,"a");
    if(fp==NULL)
    {
      cout<<"Error adding...";
      return false;
    }
    fprintf(fp,"%s\n",i.productID.c_str());
    fclose(fp);
    i.store();
    numberOfItems++;
    store(false);
    return true;

}

};



