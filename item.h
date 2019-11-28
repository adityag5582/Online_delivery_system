#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;


string to_string(char *ch){
string s(ch);
return s;
}


class item
{
public:
	string vendorID;
string category;
string subcategory;
string name;
string productID;
float rating;
int MRP,Discount,DiscountPrice,itemCount;
bool inStock;
friend class Vendor;
string details;
//friend void addItems(int vendorNo);
public:
	void disp(){
		cout<< "\t\t category : "<<category<<endl;
		cout<<"\t\t subcategory : "<<subcategory<<endl;
		cout<<"\t\t name : "<<name<<endl<<endl;
		cout<<"\n \t\tMRP : "<<MRP<<"\t Discount : "<<Discount<<endl;
		cout<<"\t\t NET PAYABLE PRICE : "<<DiscountPrice<<endl;
		cout<<endl;
	}
protected:
void updateItem(){
	int x;
	cout<<"choose from the options to update"<<endl;
	cout<<"1. category\n2. subcategory\n3. name"<<endl;
	cout<<"4. productID<<5. rating\n6. MRP\n7. Discount\n";
	cout<<"8. inStock\n9. details"<<endl;
	int i;
	cout<<"Choose : ";
	cin>>x;
	cin.ignore();
	string str;
	switch(x){
		case 1:
		cout<<"Enter new category : ";
	
		getline(cin,str);
		
		 category=str;

		 cout<<"done!!\n";
		 break;
		 case 2:
		 cout<<"Enter new subcategory :";
		 
		 getline(cin,str);
		
		subcategory=str;
		break;
		case 3:
		cout<<"Enter new Name : ";
	
			getline(cin,str);
	
		break;
		case 4:
		cout<<"Enter new productID : ";
			cin>>i;
			productID=i;
			break;
		case 5:
		cout<<"Enter new rating : ";
		cin>>i;
		i=rating;
		break;
		case 6:
		cout<<"Enter new MRP : ";
		cin>>i;
		MRP=i;
		break;
		case 7:
		cout<<"Enter new Discount : ";
		cin>>i;
		Discount=i;
		DiscountPrice=MRP-(Discount*MRP)/100;
		break;
		case 8:
		cout<<"is item is inStock(0:false;1:true) : ";
		cin>>i;
		if(i==0)
		inStock=false;
		else
		inStock=true;
		break;
		case 9:
		cout<<"Enter new Details : ";
		
			getline(cin,str);
		
		details=str;
		break;
		default:
		cout<<"Wrong input"<<endl;

	}
}


   bool store(){
    FILE *fp;
    char LI[100];
    char PI[100];
    strcpy(LI,vendorID.c_str());
    strcpy(PI,productID.c_str());
    int i;

    char ch1[300]="support/vendors/";

    strcat(ch1,LI);
    strcat(ch1,"/");
    strcat(ch1,"items/");
    strcat(ch1,PI);
    printf("1. %s\n",ch1);

    fp=fopen(ch1,"w");
    if(fp==NULL){
      printf("Erron storing\n");
      return(false);
    }
    fprintf(fp, "%s,%s,%s,%s,%s,%s*%f,%d,%d,%d,%d\n",vendorID.c_str(),category.c_str(),subcategory.c_str(),name.c_str(),productID.c_str(),details.c_str(),rating,MRP,Discount,DiscountPrice,itemCount);
    cout<<"\t"<<"Data recorded\n";
    fclose(fp);

    return(true);

   }
public:
    bool load(string logi,string pi){
    FILE *fp;
    char LI[100];
    char PI[100];
    strcpy(LI,logi.c_str());
    strcpy(PI,pi.c_str());
    int i;

    char ch1[300]="support/vendors/";

    strcat(ch1,LI);
    strcat(ch1,"/");
    strcat(ch1,"items/");
    strcat(ch1,PI);
    printf("1. %s\n",ch1);

    fp=fopen(ch1,"r");
    if(fp==NULL){
      printf("Erron loading\n");
      return(false);
    }
    char one[100],two[100],three[100],four[100],five[100],six[500];
    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^*]*%f,%d,%d,%d,%d\n",one,two,three,four,five,six,&rating,&MRP,&Discount,&DiscountPrice,&itemCount);

    vendorID=to_string(one);
    category=to_string(two);
    subcategory=to_string(three);
    name=to_string(four);
    productID=to_string(five);
    details=to_string(six);
        inStock=itemCount?true:false;
    cout<<"\t"<<"Data loaded\n";
    fclose(fp);

    return(true);

   }

   void display()
{
    cout<<"vendorId = "<<vendorID<<"  "<<"category = "<<category<<endl;
    cout<<"subcategory = "<<subcategory<<"  "<<"name = "<<name<<endl;
    cout<<"productID = "<<productID<<"  "<<"rating = "<<rating<<endl;
    cout<<"MRP = "<<MRP<<"  "<<"Discount = "<<Discount<<endl;
    cout<<"DiscountPrice = "<<DiscountPrice<<"  "<<"itemCount = "<<itemCount<<endl;
    cout<<details<<endl;
    if(itemCount)
        cout<<"In stock"<<endl;
    else
        cout<<"out of stock"<<endl;
}

};


