#include "CustomerInfo.h"

const int MAX_LENGTH = 15;

CustomerInfo::CustomerInfo(const std::string& nationalIDNumber
        ,   const std::string& firstname
        ,   const std::string& lastname
        ,   const std::string& fathersname
        ,   const std::string& mothersname
        ,   const std::string& presentaddr
        ,   const std::string& permanentaddr
        ,   const int& dob
        ,   const int& mob
        ,   const int& yob
        ,   const std::list<PhoneNumber>& numberList)
        :   Person(nationalIDNumber
        ,   firstname
        ,   lastname
        ,   fathersname
        ,   mothersname
        ,   presentaddr
        ,   permanentaddr
        ,   dob
        ,   mob
        ,   yob)
        ,   allNumbers(numberList) {
}

CustomerInfo::CustomerInfo(const CustomerInfo& obj)
	: Person(obj)
	, allNumbers(obj.allNumbers){
}

CustomerInfo::CustomerInfo(CustomerInfo&& src){
    *this = std::move(src);
}

CustomerInfo& CustomerInfo::operator=(const CustomerInfo& src){
    if(this == &src)
        return *this;

    this->nID = src.nID;
    this->firstName = src.firstName;
    this->lastName = src.lastName;
    this->fathersName = src.fathersName;
    this->mothersName = src.mothersName;
    this->presentAddress = src.presentAddress;
    this->permanentAddress = src.permanentAddress;
    this->dateOfBirth = src.dateOfBirth;
    this->monthOfBirth = src.monthOfBirth;
    this->yearOfBirth = src.yearOfBirth;

    RemoveAllNumbers();

    this->allNumbers = src.allNumbers;

    return *this;
}


CustomerInfo::~CustomerInfo(){
}

void CustomerInfo::InsertNewNumber(const std::string& number, const std::string& operatorName){

	//Exception should be thrown.
	if (!CanInsertNewNumber()){
		std::cout << "Can not insert more than " << this->allNumbers.size();
		std::cout << " numbers in the DB for a person." << std::endl;
		return;
	}

	this->allNumbers.push_back(PhoneNumber(number, operatorName));
}

void CustomerInfo::ChangeOperatorForNumber(const std::string& number, const std::string& operatorName){

	auto iter = std::find(allNumbers.begin(),allNumbers.end(),PhoneNumber(number));
	if(iter != allNumbers.end()){
	    iter->SetOperatorName(operatorName);
	}
}

void CustomerInfo::RemoveAllNumbers(){
    while(!this->allNumbers.empty())
        this->allNumbers.pop_back();
}

bool CustomerInfo::HasNumber(const std::string& number) const{
    auto iter = std::find(allNumbers.begin(),allNumbers.end(),PhoneNumber(number));
    return (iter != allNumbers.end());
}

bool CustomerInfo::operator== (const CustomerInfo& rhs) const{
	return (this->nID == rhs.GetNid());
}

bool CustomerInfo::operator!= (const CustomerInfo& rhs) const{
	return (this->nID == rhs.GetNid());
}

bool CustomerInfo::operator< (const CustomerInfo& rhs) const{
    return (this->nID < rhs.GetNid());
}

bool CustomerInfo::operator> (const CustomerInfo& rhs) const{
    return (this->nID > rhs.GetNid());
}

int CustomerInfo::CanInsertNewNumber() const{
    return (this->allNumbers.size() < MAX_LENGTH);
}
int CustomerInfo::HasAnyNumber() const{
    return this->allNumbers.empty();
}

std::ostream &operator<<(std::ostream &output, const CustomerInfo& customer) {
std::string printString("---------------------------------------------\n") ;
    printString += ("Customer NID: " + customer.nID + "\n");
    printString += ("Customer Name: " + customer.firstName +" " + customer.lastName + "\n");
    printString += ("Father's Name: " + customer.fathersName + "\n");
    printString += ("Mother's Name: " + customer.mothersName + "\n");
    printString += ("Present Address: " + customer.presentAddress + "\n");
    printString += ("Permanent Address: " + customer.permanentAddress + "\n");
    printString += ("Date of Birth:" + customer.GetDateOfBirth() + "\n");
    printString += ("---------------------------------------------\n");
    output << printString;

    for(auto number : customer.allNumbers){
        output << number;
    }
    return output;
}
