#pragma once

#include <string.h>
#include <ostream>

class string
{
public:
    string(const char *cstr = 0);
    string(const string &rhs);
    string& operator=(const string &s);

    ~string()
    {
        delete[] data_;
    }

    char* get_c_str() const { return data_; }
    
private:
    char *data_;
};

string::string(const char *cstr)
{
    if (cstr) {
        data_ = new char[strlen(cstr) + 1];
        strcpy(data_, cstr);
    }
    else {
        data_ = new char[1];
        *data_ = '\0';
    }
}

string::string(const string &rhs)
{
    data_ = new char[strlen(rhs.data_) + 1];
    strcpy(data_, rhs.data_);
}

string& string::operator=(const string &str)
{
    if (this == &str)
        return *this;

    delete[] data_;
    data_ = new char[strlen(str.data_) + 1];
    strcpy(data_, str.data_);
    return *this;
}

std::ostream& operator<<(std::ostream &os, const string &rhs)
{
    return os << rhs.get_c_str();
}
