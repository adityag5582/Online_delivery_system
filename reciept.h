#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
//using namespace std;

class orderReceipt
{
private:
    string orderId;
    //string dateOfOrder;
    //int customerId;
    string customerId;
    string shippingAddress;
    string shippingInfo;
    string status;
    int amount;
    string paymentMethod;
    int noOfItems;
    int Quantity[100];
    item items[100];
    //string invoice;
public:
    friend class ShoppingCart;
    friend class DeliveryPerson;
    void getInvoice()
    {
    int k;
        cout<<"  Order ID : "<<orderId<<endl;
        cout<<"  No. of items : "<<noOfItems<<endl;
        cout<<" customerId : "<<customerId<<endl;
        cout<<" shippingAddress : "<<shippingAddress<<endl;
        cout<<" shippingInfo : "<<shippingInfo<<endl;
        cout<<" status : "<<status<<endl;
        cout<<" paymentMethod : "<<paymentMethod<<endl;


        for(k=0;k<noOfItems;k++){
            printf("   NAME        productID        MRP      Payable_price\n");
            cout<<items[k].name<<"\t   "<<items[k].productID<<" \t    "<<items[k].MRP<<" \t   \n"<<items[k].DiscountPrice<<endl;
        }

        cout<<"\n"<<"\t\t Net amount : "<<amount<<endl;

    }
    string sendFeedback()
    {
        string feedback;
        cin.ignore();
        getline(cin, feedback);
        cout<<feedback<<endl;
        return feedback;
    }
    void cancelOrder()
    {
      string delv="Delivered";

      if(status.compare(delv)!=0){
        //strcpy(status,"Cancelled");
        status="Cancelled";
      }
      store();

    }
    void updateAddress()
    {
        string newaddress;
        //cin.ignore();
        cout<<"Enter new delivery address :";
        do{
        getline(cin,newaddress);
        } while(newaddress.compare("")==0);
        shippingAddress=newaddress;
    }

    void updateShippingInfo()
    {
        string Info;
        //cin.ignore();
        cout<<"Enter new shippingInfo :";
        do{
        getline(cin,Info);
        } while(Info.compare("")==0);
        shippingInfo=Info;
    }


    bool store(){
    FILE *fp;
    char LI[100];
    strcpy(LI,customerId.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
    //char ch1[100]="cd support/customers/";
    //char ch2[100]="mkdir support/customers/";
    char ch3[200]="support/customers/";
    //char ch[150]="mkdir support/customers/";
    strcat(ch3,LI);
    strcat(ch3,"/receipt/");
    //strcat(ch3,"/cart");
  //  printf("1. %s\n",ch3);
    //i=system(ch1);
   /* if(i!=0)
    {
      strcat(ch2,LI);
      printf("3. %s\n",ch2);
      system(ch2);

    }*/
  strcat(ch3,orderId.c_str());
 
    fp=fopen(ch3,"w");
    if(fp==NULL){
       
      printf("Erron1 storing\n");
      return(false);
    }
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%d,%d\n",orderId.c_str(),customerId.c_str(),shippingAddress.c_str(),shippingInfo.c_str(),status.c_str(),paymentMethod.c_str(),amount,noOfItems);
    int k;
    for(k=0;k<noOfItems;k++){
        fprintf(fp, "%s,%s,%d\n",items[k].vendorID.c_str(),items[k].productID.c_str(),Quantity[k]);
    }
    cout<<"\t"<<"Data recorded\n";
    fclose(fp);

    

    return(true);
    
   }

    bool load(string cid,string rid){
    FILE *fp;
  //  cout<<"cid : "<<cid<<endl;
   // cout<<"rid : "<<rid<<endl;
    char LI[100];
    strcpy(LI,cid.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
   // char ch1[100]="cd support/customers/";
   // char ch2[100]="mkdir support/vendors/";
    char ch3[200]="support/customers/";
    strcat(ch3,LI);
    strcat(ch3,"/receipt/");
    //strcat(ch1,LI);
    printf("1. %s\n",ch3);
   // i=system(ch1);
  /*  if(i!=0)
    {
      printf("Error loading...\n");
      return(false);

    }*/
  strcat(ch3,rid.c_str());
//  cout<<"ch3 :"<<ch3<<endl;
  //while(getchar()!='x')
    //;
    fp=fopen(ch3,"r");
    if(fp==NULL)
    {
      printf("Error loading...\n");
      return(false);
    }
    char temp1[100],temp2[100],temp3[100],temp4[100],temp5[100],temp6[100];
   // int a,b;
    fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d\n",temp1,temp2,temp3,temp4,temp5,temp6,&amount,&noOfItems);
  
    orderId=to_string(temp1);
    customerId=to_string(temp2);
    shippingAddress=to_string(temp3);
    shippingInfo=to_string(temp4);
    status=to_string(temp5);
    paymentMethod=to_string(temp6);

    printf("res : OI: %s,  status: %s,  amount :%d\n",temp1,temp5,amount);

    for(int k=0;k<noOfItems;k++){
        fscanf(fp,"%[^,],%[^,],%d\n",temp1,temp2,&Quantity[k]);
        string vi,pi;
        vi=to_string(temp1);
        pi=to_string(temp2);
        items[k].load(vi,pi);
        //items[k].load(li,pi);
    }
  

   /* LoginId=to_string(temp1);
    Password=to_string(temp2);
    name=to_string(temp3);
    email=to_string(temp4);*/
    fclose(fp);
    
    return(true);
    }

    bool load(char ch[]){
    FILE *fp;
   /* char LI[100];
    strcpy(LI,cid.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
   // char ch1[100]="cd support/customers/";
   // char ch2[100]="mkdir support/vendors/";
    char ch3[200]="support/customers/";
    strcat(ch3,LI);
    strcat(ch3,"/reciept/");
    //strcat(ch1,LI);
    printf("1. %s\n",ch3);
   // i=system(ch1);
    if(i!=0)
    {
      printf("Error loading...\n");
      return(false);

    }*/
  //strcat(ch3,rid.c_str());
    fp=fopen(ch,"r");
    if(fp==NULL)
    {
      printf("Error loading...\n");
      return(false);
    }
    char temp1[100],temp2[100],temp3[100],temp4[100],temp5[100],temp6[100];
   // int a,b;
    fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d\n",temp1,temp2,temp3,temp4,temp5,temp6,&amount,&noOfItems);
  
    orderId=to_string(temp1);
    customerId=to_string(temp2);
    shippingAddress=to_string(temp3);
    shippingInfo=to_string(temp4);
    status=to_string(temp5);
    paymentMethod=to_string(temp6);

    printf("res : OI: %s,  status: %s,  amount :%d\n",temp1,temp5,amount);

    for(int k=0;k<noOfItems;k++){
        fscanf(fp,"%[^,],%[^,],%d\n",temp1,temp2,&Quantity[k]);
        string vi,pi;
        vi=to_string(temp1);
        pi=to_string(temp2);
        items[k].load(vi,pi);
        //items[k].load(li,pi);
    }
  

   /* LoginId=to_string(temp1);
    Password=to_string(temp2);
    name=to_string(temp3);
    email=to_string(temp4);*/
    fclose(fp);
    
    return(true);
    }


/* bool load(string str1,string str2){
    FILE *fp;
   char ch[300]="support/customers/";
   strcat(ch,str1.c_str());
   strcat(ch,"/");
   strcat(ch,str2.c_str());
    fp=fopen(ch,"r");
    if(fp==NULL)
    {
      printf("Error loading...\n");
      return(false);
    }
    char temp1[100],temp2[100],temp3[100],temp4[100],temp5[100],temp6[100];
   // int a,b;
    fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d\n",temp1,temp2,temp3,temp4,temp5,temp6,&amount,&noOfItems);
  
    orderId=to_string(temp1);
    customerId=to_string(temp2);
    shippingAddress=to_string(temp3);
    shippingInfo=to_string(temp4);
    status=to_string(temp5);
    paymentMethod=to_string(temp6);

    printf("res : OI: %s,  status: %s,  amount :%d\n",temp1,temp5,amount);

    for(int k=0;k<noOfItems;k++){
        fscanf(fp,"%[^,],%[^,],%d\n",temp1,temp2,&Quantity[k]);
        string vi,pi;
        vi=to_string(temp1);
        pi=to_string(temp2);
        items[k].load(vi,pi);
        //items[k].load(li,pi);
    }
  

   LoginId=to_string(temp1);
    Password=to_string(temp2);
    name=to_string(temp3);
    email=to_string(temp4);
    fclose(fp);
    
    return(true);
    }
    */


    void display(){
        

    cout<<"\n\t order ID : "<<orderId;
    cout<<"\t customerId : "<<customerId;
    cout<<"\t shippingAddress :\n \t "<<shippingAddress;
    cout<<"\t shippingInfo : "<<shippingInfo;
    cout<<"\t status : "<<status;
    cout<<"\t paymentMethod : "<<paymentMethod;
    cout<<"\t noOfItems : "<<noOfItems;
    int i;
    cout<<"items :\n";
    cout<<endl;

    for(i=0;i<noOfItems;i++){
        items[i].disp();
        cout<<endl<<"Quantity : "<<Quantity[i];
    }
    cout<<endl;
    }

    void edit(){
        if(status.compare("Pending")!=0)
        {
            cout<<"Item is "<<status;
            cout<<"\nReciept cannot be delivered\n";
            return;
        }
        int x;
        while(1){
            cout<<"1. Edit shippingAddress"<<endl;
            cout<<"2. Edit shippingInfo "<<endl;
            cout<<"3. cancle order "<<endl;
            cout<<"4. get Invoice"<<endl;
            cout<<"5. BACK"<<endl;
            cin>>x;
            if(x==5){
                system("clear");
                return;
            }

            switch(x){
                case 1:
                updateAddress();
                break;
                case 2:
                updateShippingInfo();
                break;
                case 3:
                cancelOrder();
                break;
                case 4:
                getInvoice();
                break;
            }
        }
    }

};
