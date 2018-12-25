#ifndef PHONENUMBER_H_INCLUDED
#define PHONENUMBER_H_INCLUDED

#include <string>

class PhoneNumber
{
public:
	PhoneNumber(const std::string& number = {}
	        , const std::string& operatorName = {})
		:   digits(number)
		,   operatorName(operatorName)
	{
	}

	PhoneNumber(const PhoneNumber& ob)
	    :   digits(ob.digits)
	    ,   operatorName(ob.operatorName)
	{
	}

    PhoneNumber(PhoneNumber&& src){
        *this = std::move(src);
	}
		PhoneNumber& operator=(const PhoneNumber& src){
		if(this == &src)
			return *this;

		this->digits = src.digits;
		this->operatorName = src.operatorName;

		return *this;
	}

	~PhoneNumber() {}

	std::string GetNumber() const{
		return this->digits;
	}

	std::string GetOperatorName() const{
		return this->operatorName;
	}

	void SetOperatorName(const std::string &operatorName) {
this->operatorName = operatorName;
	}

	bool operator== (const PhoneNumber& rhs) const {
        return (this->digits== rhs.digits);
	}

    bool operator!= (const PhoneNumber& rhs) const {
        return (this->digits!= rhs.digits);
    }

	bool operator<(const PhoneNumber& rhs) const {
		return (this->digits < rhs.digits);
	}
	bool operator>(const PhoneNumber& rhs) const {
		return (this->digits > rhs.digits);
	}


	friend std::ostream &operator<<(std::ostream &output, const PhoneNumber &number ){
        std::string str;
        str += "---Number:";
        str += number.digits;
        str += "|Operator:";
        str += number.operatorName;
        str += "\n";

        output << str;
        return output;
    }

private:
	std::string digits;
	std::string operatorName;
};


#endif //PHONENUMBER_H_INCLUDED
