#include "Company.h"


Company::Company(const std::string& name
        , const std::list<CustomerInfo>& list)
    :   companyName(name)
    ,   customerList(list)
{
}

Company::Company(const Company& obj)
    :   companyName(obj.companyName)
    ,   customerList(obj.customerList)
{
}

Company& Company::operator=(const Company& src){
    if(this==&src)
        return *this;

    companyName = src.companyName;

    while (!customerList.empty())
        customerList.pop_back();

    customerList = src.customerList;

    return *this;
}


Company::Company(Company&& src)
    :   companyName(std::string())
    ,   customerList(std::list<CustomerInfo>())
{
    *this = std::move(src);
}

bool Company::AddCustomer(CustomerInfo newCustomer) {
    if(this->customerList.size() == this->customerList.max_size())
        return false;

    this->customerList.push_back(newCustomer);
    return true;
}

bool Company::AddCustomer(const std::string& customerNID){
    return this->AddCustomer(CustomerInfo(customerNID));
}

bool Company::DeleteCustomer(CustomerInfo existingCustomer) {
    if(this->customerList.empty())
        return false;

    auto iter = std::find(customerList.begin(),customerList.end(), existingCustomer);
    if(iter != customerList.end()){
        customerList.erase(iter);
        return true;
    }
    return false;
}
bool Company::DeleteCustomer(const std::string& customerNID){
    return this->DeleteCustomer(CustomerInfo(customerNID));
}

bool Company::HasCustomer(CustomerInfo existingCustomer) const
{
    if(this->customerList.empty())
        return false;

    auto iter = std::find(customerList.begin(),customerList.end(), existingCustomer);
    return (iter != customerList.end());
}

bool Company::HasCustomer(const std::string& customerNID) const
{
    return this->HasCustomer(CustomerInfo(customerNID));
}
bool Company::AddNumberForExistingCustomer(const std::string &nid, const std::string &phoneNumber,
                                           const std::string &operatorName) {

    if(this->customerList.empty())
        return false;

    CustomerInfo existingCustomer(nid);
    auto iter = std::find(customerList.begin(),customerList.end(), existingCustomer);
    if(iter != customerList.end()){
        if(!iter->CanInsertNewNumber())
            return false;

        iter->InsertNewNumber(phoneNumber,operatorName);
        return true;
    }
    return false;
}

bool Company::UpdateOperatorForExistingNumber(const std::string &nid,
                                              const std::string &phoneNumber,
                                              const std::string &operatorName) {
    if(this->customerList.empty())
        return false;

    CustomerInfo existingCustomer(nid);
    auto iter = std::find(customerList.begin(),customerList.end(), existingCustomer);
    if(iter != customerList.end()){
        iter->ChangeOperatorForNumber(phoneNumber,operatorName);
        return true;
    }
    return false;
}

std::string Company::GetCompanyName() const{
    return this->companyName;
}


bool Company::operator== (const Company& rhs) const{
    return (this->companyName == rhs.companyName);
}

bool Company::operator!= (const Company& rhs) const{
    return (this->companyName != rhs.companyName);
    }

bool Company::operator< (const Company& rhs) const{
    return (this->companyName < rhs.companyName);
}

bool Company::operator> (const Company& rhs) const{
    return (this->companyName > rhs.companyName);
}

std::ostream& operator<<(std::ostream &output, const Company &company) {
    output << "Company Name: " << company.companyName << "\n";
    output << "===============================================" << "\n";
for(auto customer: company.customerList){
        output << customer;
    }
    output << "===============================================" << "\n";
    return output;
}


