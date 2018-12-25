#ifndef COMPANY_H_INCLUDED
#define COMPANY_H_INCLUDED
#include "CustomerInfo.h"
#include <string>
#include <list>

class Company {
public:
    Company(const std::string& name  = {}
            , const std::list<CustomerInfo>& customerList  = std::list<CustomerInfo>()) ;

    Company(const Company& obj);
    Company& operator=(const Company& src);
    Company(Company&& src);

    bool operator==(const Company& rhs) const;
    bool operator!=(const Company& rhs) const;
    bool operator<(const Company& rhs) const;
    bool operator>(const Company& rhs) const;

    std::string GetCompanyName() const;
        bool AddCustomer(CustomerInfo newCustomer);
    bool AddCustomer(const std::string& customerNID);

    bool DeleteCustomer(CustomerInfo existingCustomer);
    bool DeleteCustomer(const std::string& customerNID);

    bool HasCustomer(CustomerInfo existingCustomer) const;
    bool HasCustomer(const std::string& customerNID) const;


    bool AddNumberForExistingCustomer(const std::string &nid
                                    ,   const std::string &phoneNumber
                                    ,   const std::string &operatorName);
    bool UpdateOperatorForExistingNumber(const std::string &nid
                                    ,   const std::string &phoneNumber
                                    ,   const std::string &operatorName);

    friend std::ostream &operator<<(std::ostream &output
                                ,   const Company& company);

private:
    std::string companyName;
        std::list<CustomerInfo> customerList;
};

#endif // COMPANY_H_INCLUDED
