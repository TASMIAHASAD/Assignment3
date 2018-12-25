
#include"Person.h"
#include"Customer.h"
#include"Call.h"
#include<iostream>
#include<list>
#include<queue>
#include<string>
using namespace std;

Customer CustomerA(){
Customer customerA( "Tasmiah");
CustomerA.PhoneNumber("01711-123456", "GP");

std::cout << CustomerA;

    return CustomerA;
}
Customer CustomerB(){
Customer customerB("Toma");
CustomerB.PhoneNumber("01711-123456", "GP");

std::cout << CustomerB;

    return CustomerB;
}
Customer CustomerC(){
Customer customerC("Tonny");
CustomerC.PhoneNumber("01711-123456", "GP");

std::cout << CustomerC;

    return CustomerC;
}
Customer CustomerD(){
Customer customerD("Tapty");
CustomerD.PhoneNumber("01711-123456", "GP");

std::cout << CustomerD;

    return CustomerD;
}






struct Phone_Number
{

	string phoneNumber;
	string operatorName;
	Phone_Number() {}
};
int main(void)
{
 Company PhoneCompany()
    PhoneCompany.AddCustomer(CreateCustomerA());
    PhoneCompany.AddCustomer(CreateCustomerB());
    PhoneCompany.AddCustomer(CreateCustomerC());
    PhoneCompany.AddCustomer(CreateCustomerD());


    PhoneCompany.AddNumberForExistingCustomer("34512323412","02315-090304","TEST");
    PhoneCompany.UpdateOperatorForExistingNumber("34512323412","02315-090304","GP");

    std::cout << company;
}

    while(!que.empty())
	{
		pair<int, string> top = que.top();
		cout << top.first << " , " <<top.second<<"\n"<< endl;
		que.pop();
	}

	priority_queue <pair<int, string>> que;
	que.push(make_pair(1,"Spouse"));
	que.push(make_pair(2,"Child"));
	que.push(make_pair(3,"Child"));
	que.push(make_pair(4,"Sibling"));
	que.push(make_pair(5,"Uncle"));
	que.push(make_pair(6,"Cousins"));
	que.push(make_pair(7,"SignificantOther"));
	que.push(make_pair(8,"Friend"));
	que.push(make_pair(9,"Boss"));
	que.push(make_pair(10,"Subordinate"));
	que.push(make_pair(11,"Acquaintance"));
	que.push(make_pair(12,"Blocked"));


	call.printQueueContent();


