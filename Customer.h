#ifndef CUSTOMERINFO_H_INCLUDED
#define CUSTOMERINFO_H_INCLUDED

#include "Person.h"
#include "PhoneNumber.h"
#include <iostream>
#include <list>

class CustomerInfo :  public Person
{
public:

    CustomerInfo(const std::string& nationalIDNumber = {}
            ,   const std::string& firstname = {}
            ,   const std::string& lastname = {}
            ,   const std::string& fathersname = {}
            ,   const std::string& mothersname = {}
            ,   const std::string& presentaddr = {}
            ,   const std::string& permanentaddr = {}
            ,   const int& dob = 1
            ,   const int& mob = 1
            ,   const int& yob = 1975
            ,   const std::list<PhoneNumber>& numberList = std::list<PhoneNumber>());

	CustomerInfo(const CustomerInfo& obj);
	CustomerInfo(CustomerInfo&& src);
	~CustomerInfo();

    bool HasNumber(const std::string &number) const;
    int CanInsertNewNumber() const;
    int HasAnyNumber() const;

    void InsertNewNumber(const std::string &number, const std::string &operatorName);
	void ChangeOperatorForNumber(const std::string &number, const std::string &operatorName);

    CustomerInfo& operator=(const CustomerInfo& src);

    bool operator== (const CustomerInfo& rhs) const;
	bool operator!= (const CustomerInfo& rhs) const;
	bool operator< (const CustomerInfo& rhs) const;
	bool operator> (const CustomerInfo& rhs) const;


    friend std::ostream &operator<<(std::ostream &output, const CustomerInfo &customer );


protected:

    //Private Functions
    void RemoveAllNumbers();

    //Private Fields
	std::list<PhoneNumber> allNumbers;
};

#endif
