#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<string.h>
//using namespace std;

class DeliveryPerson
{
public:
    string name;
    string Id;
    string Password;
    string email;
    long int contact;
    friend bool deliveryRegister();
   // bool status;
   // int whul;
   // int whll;
    void getOrderDetails()
    {
        int i;
      //  char ch[300];
        FILE *fp;
        char ch[300]="support/delivery_person/pending";
        fp=fopen(ch,"r");
        if(fp==NULL){
            cout<<"NO orders";
            return;
        }
        char str[200];
        while(1){
        fscanf(fp,"%s\n",str);
        if(strcmp(str,"")==0)
            break;
      //  cout<<"str : "<<str<<endl;
       
        orderReceipt odr;
       bool b= odr.load(str);
       if(!b)
       {
        cout<<"No orders available at the moment \n";
        return;
       }
        if(odr.status.compare("Pending")==0){
        cout<<"Enter 1 if you want to take the order and 0 to pass :";
        cin>>i;
        if(i){
            odr.status="Out for Delivery";
            odr.store();
            }
        }
        strcpy(str,""); 


    }


    }
    void deliverOrder(){

         int i;
       // char ch[300];
        FILE *fp;
        FILE *ff;
        ff=fopen("pending","w");
        char ch[300]="support/delivery_person/pending";
        fp=fopen(ch,"r");
        if(fp==NULL){
            cout<<"NO orders";
            return;
        }
        char str[200];
        while(1){
        fscanf(fp,"%s\n",str);
        if(strcmp(str,"")==0)
            break;
        orderReceipt odr;
        bool b=odr.load(str);
        if(!b){
            cout<<"No orders available at the time"<<endl;
        }
        if(odr.status.compare("Out for Delivery")==0){
        cout<<"Enter 1 if you want to confirm delivery and payment :";
        cin>>i;
        if(i){
            odr.status="Delivered";
            odr.store();
            }
            else{
                fprintf(ff,"%s\n",str );
            }
        }
        strcpy(str,""); 


    }
fclose(ff);
system("rm support/delivery_person/pending");
system("mv pending support/delivery_person/");



    }

 bool store(){
    FILE *fp;
    int i;

    char ch1[100]="cd support/delivery_person/";
    char ch2[100]="mkdir support/delivery_person/";
    char ch3[200]="support/delivery_person/";
    //char ch[150]="mkdir support/delivery_person/";
    strcat(ch3,Id.c_str());
    strcat(ch1,Id.c_str());
    printf("1. %s\n",ch1);
    i=system(ch1);
    if(i!=0)
    {
      strcat(ch2,Id.c_str());
      printf("3. %s\n",ch2);
      system(ch2);

    }
  strcat(ch3,"/data");
    fp=fopen(ch3,"w");
    if(fp==NULL){
      printf("Erron storing\n");
      return(false);
    }
   fprintf(fp, "%s,%s,%s,%s,%ld,\n",name.c_str(),Id.c_str(),Password.c_str(),email.c_str(),contact);
    cout<<"\t"<<"Data recorded\n";
    fclose(fp);

    return(true);
    
   }

    bool load(string id){
    FILE *fp;
    char LI[100];
    strcpy(LI,id.c_str());
    int i;
   
    char ch1[100]="cd support/delivery_person/";
  
    char ch3[200]="support/delivery_person/";
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
    fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%ld,\n",temp1,temp2,temp3,temp4,&contact);
    printf("res : %s,  %s,  %s,  %s,  %ld\n",temp1,temp2,temp3,temp4,contact);
    name=to_string(temp1);
    Id=to_string(temp2);
    Password=to_string(temp3);
    email=to_string(temp4);
    fclose(fp);
     return(true);
   }
   
   bool deliveryVerifyLogin(string li,string Pass){
int i;
string str;
//Vendor v;
char ch[100]="cd support/delivery_person/";
strcat(ch,li.c_str());
i=system(ch);
if(i!=0)
{
  cout<<"\tID dosen't exist\n";
  return false;
}
load(li);
if(Pass.compare(Password)==0)
{
 // active_vendor=v;
  //cout<<"\t Login successfull"<<endl;
  return true;
}
cout<<"\t Password didn't matched"<<endl;

return false;
}


   
};