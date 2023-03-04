#include "User.h"

User::User(std::string idp){
    id = idp;
    v_ptr = nullptr;
}

User::User(){
    id = "";
    v_ptr = nullptr;
}


Vote* User::get_vote(){
    return v_ptr;

}

void User::set_vote(Vote* v_ptrp){
    v_ptr = v_ptrp;
}



std::string User::get_id(){
    return id;
}

bool User::operator< (const User& other) const{
    return id < other.id;
}

bool User::operator> (const User& other) const{
    return id > other.id;
}

bool User::operator== (const User& other) const{
    return id == other.id;
}

void User::set_id(std::string s){
    id = s;
}

User& User::operator=(const User& other){
    this->id = other.id;
    this->v_ptr = other.v_ptr;
    return *this;
}