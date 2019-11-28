#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
//using namespace std;


class User{
protected:
std::string Password;
public:
long int contact;
std::string LoginId;
std::string name;
std::string email;
//time_t Regestration_Date;
//public:
//friend bool Login();

/*bool ChangePassword(string newPassword){
	Password=newPassword;
	return(true);
 }*
bool verifyPassword(string inpPassword){
	if(Password.compare(inpPassword)==0)
		return(true);
	return(false);
}
*/
//string getLoginId(){
//	return LoginId;
//}

};