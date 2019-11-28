#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
//using namespace std;

class ShoppingCart{
protected:
	int CartID;
	string CustID;
	item items[100];
	int amount;
	int noOfItems;
	int Quantity[100];
public:
	friend class Customer;
	ShoppingCart(){
		//items=NULL;
		CartID=0;
		amount=0;
		noOfItems=0;
	}
//	friend class Customer;

void AddItem(string str1,string str2){
		if(noOfItems==100)
		{
			cout<<"maximum Cart limit reached";
			return;
		}
		//cout<<"Enter product id of the item";
		//string str1,str2;
		//cin.ignore();
		//cin>>str1;
		//cout<<"Enter vendorID of the product :";
		//cin.ignore();
		//cin>>str2;
		bool l=items[noOfItems].load(str2,str1);
		if(!l){
			cout<<"Error adding...";
			//return false;
		}
		cout<<"Enter no. of Quantity :";
		cin>>Quantity[noOfItems];
		amount+=items[noOfItems].DiscountPrice*Quantity[noOfItems];
		//items[noOfItems]=i;
		//Quantity[noOfItems]=Q;
		noOfItems++;
		cout<<"item added succesfully"<<endl;
		//return(true);
	/*	cout<<"\n"<<CustID<<endl;
		while(getchar()!='q')
			;*/
		store();
	}

	bool AddItems(){
		if(noOfItems==100)
		{
			cout<<"maximum Cart limit reached";
			return(false);
		}
		cout<<"Enter product id of the item";
		string str1,str2;
		cin.ignore();
		cin>>str1;
		cout<<"Enter vendorID of the product :";
		cin.ignore();
		cin>>str2;
		bool l=items[noOfItems].load(str2,str1);
		if(!l){
			cout<<"Error adding...";
			return false;
		}
		cout<<"Enter no. of Quantity :";
		cin>>Quantity[noOfItems];
		amount+=items[noOfItems].DiscountPrice*Quantity[noOfItems];
		//items[noOfItems]=i;
		//Quantity[noOfItems]=Q;
		noOfItems++;
		cout<<"item added succesfully"<<endl;
		return(true);
	}
	bool removeItem(){
		int k;
		string str1;
		cout<<"Enter productID of the item to remove :";
		cin.ignore();
		cin>>str1;
		for(k=0;k<noOfItems;k++){
			if(items[k].productID.compare(str1)==0)
				break;
		}
		if(k==noOfItems){
			cout<<"item not in Cart"<<endl;
			return(false);
		}
		for(k++;k<noOfItems;k++){
			items[k-1]=items[k];
			Quantity[k-1]=Quantity[k];
		}
		noOfItems--;
		cout<<"remove succesfull"<<endl;
    return(true);
	}
	bool updateQuantity(){
		int k;
		string str;
		int Q;
		cout<<"Enter the productID of the item :";
		cin.ignore();
		cin>>str;
		cout<<"Enter new Quantity :";
		cin>>Q;
		for(k=0;k<noOfItems;k++){
			if(items[k].productID.compare(str)==0){
				Quantity[k]=Q;
				return(true);
			}
		}
		cout<<"Item not in Cart."<<endl;
		return(false);
	}
	void viewCartDetails(){
		int k;
		cout<<"  Cart ID : "<<CartID<<endl;
		cout<<"  No. of items : "<<noOfItems<<endl;
		if(noOfItems==0)
		{
			cout<<"\t No items in the cart."<<endl;
			return;
		}
		for(k=0;k<noOfItems;k++){
			printf("   NAME        productID        MRP      Payable_price\n");
			cout<<"   "<<items[k].name<<"\t   "<<items[k].productID<<" \t    "<<items[k].MRP<<" \t  "<<items[k].DiscountPrice*Quantity[k]<<endl;
		}
	}

	bool placeOrder(){
		FILE *fp;
		char ch[300]="support/customers/";
		strcat(ch,CustID.c_str());
		char ch1[300];
		strcpy(ch1,ch);
		strcat(ch1,"/");
		strcat(ch1,"oi");
		fp=fopen(ch1,"r");
		if(fp==NULL){
			cout<<"Error executing order.\nTry again...";
			return(false);
		}
		strcat(ch,"/receipt/");

		int i,j,k;

		fscanf(fp,"%d",&i);
		fclose(fp);
		string str=to_string(i);
		i++;
		orderReceipt abc;
		abc.orderId=str;
		abc.customerId=CustID;
		cin.ignore();
		cout<<"Enter shipping address : ";
		getline(cin,abc.shippingAddress);
		cout<<"Enter shipping info(special remarks) :";
		getline(cin,abc.shippingInfo);
		abc.status="Pending";
		abc.amount=amount;
		abc.paymentMethod="COD";
		abc.noOfItems=noOfItems;
		j=0;
		for(k=0;k<noOfItems;k++){
			if(items[k].itemCount>0){
			abc.Quantity[k-j]=Quantity[k];
			abc.items[k-j].load(items[k].vendorID,items[k].productID);
			items[k].itemCount--;
			if(items[k].itemCount==0)
				items[k].inStock=false;
			}
			else{
				j++;
				abc.noOfItems--;
			}
		}


		abc.store();
		
		fp=fopen(ch1,"w");

		fprintf(fp,"%d",i);
		fclose(fp);
		strcat(ch,str.c_str());
		fp=fopen("support/delivery_person/pending","a");

		
		fprintf(fp,"%s\n",ch);
		
		fclose(fp);
		noOfItems=0;
		amount=0;

		store();
/*	string orderId;
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
    item items[100];*/

return(true);
	}


	bool store(){
    FILE *fp;
    char LI[100];
    strcpy(LI,CustID.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
    //char ch1[100]="cd support/customers/";
    //char ch2[100]="mkdir support/customers/";
    char ch3[200]="support/customers/";
    char ch[150]="mkdir support/customers/";
    strcat(ch3,LI);
    //strcat(ch3,"/cart");
  //  printf("1. %s\n",ch3);
    //i=system(ch1);
   /* if(i!=0)
    {
      strcat(ch2,LI);
      printf("3. %s\n",ch2);
      system(ch2);

    }*/

  strcat(ch3,"/cart");
    fp=fopen(ch3,"w");
    if(fp==NULL){
      printf("Erron storing\n");
      return(false);
    }
    fprintf(fp, "%d,%d,%d\n",CartID,amount,noOfItems);
    int k;
    for(k=0;k<noOfItems;k++){
    	fprintf(fp, "%s,%s,%d\n",items[k].vendorID.c_str(),items[k].productID.c_str(),Quantity[k]);
    }
    cout<<"\t"<<"Data recorded\n";
    fclose(fp);

    

    return(true);
    
   }

    bool load(string id){
    FILE *fp;
    char LI[100];
    strcpy(LI,id.c_str());
    int i;
    //sscanf(LoginId,"%s",*LI);
   // char ch1[100]="cd support/customers/";
   // char ch2[100]="mkdir support/vendors/";
    char ch3[200]="support/customers/";
    strcat(ch3,LI);
    //strcat(ch1,LI);
    printf("1. %s\n",ch3);
   // i=system(ch1);
  /*  if(i!=0)
    {
      printf("Error loading...\n");
      return(false);

    }*/
  strcat(ch3,"/cart");
    fp=fopen(ch3,"r");
    if(fp==NULL)
    {
      printf("Error loading...\n");
      return(false);
    }
    char temp1[100],temp2[100],temp3[100],temp4[50];
   // int a,b;
    fscanf(fp,"%d,%d,%d\n",&CartID,&amount,&noOfItems);
    printf("res : %d,  %d,  %d\n",CartID,amount,noOfItems);

    for(int k=0;k<noOfItems;k++){
    	fscanf(fp,"%[^,],%[^,],%d\n",temp1,temp2,&Quantity[k]);
    	string li,pi;
    	li=to_string(temp1);
    	pi=to_string(temp2);
    	items[k].load(li,pi);
    	//items[k].load(li,pi);
    }
  

   /* LoginId=to_string(temp1);
    Password=to_string(temp2);
    name=to_string(temp3);
    email=to_string(temp4);*/
    fclose(fp);
    
    return(true);
    }
};
