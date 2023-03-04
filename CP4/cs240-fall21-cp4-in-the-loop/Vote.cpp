#include "Vote.h"
#include <iostream>
#include <ostream>

Vote::Vote(User* u_ptrp) {
    v_cnt = 0;
    u_ptr = u_ptrp;
}

Vote::Vote() {
    v_cnt = 0;
    u_ptr = nullptr;
}

bool Vote::operator<(const Vote& v){
    return v_cnt < v.v_cnt;
}

bool Vote::operator>(const Vote& v){
    return v_cnt > v.v_cnt;
}

void Vote::set_user(User* u_ptrp) {
    u_ptr = u_ptrp;
}

void Vote::add_votes(int num_votes) {
    v_cnt += num_votes;
}

User* Vote::get_user() {
    return u_ptr;
}

int Vote::get_vote() {
    return v_cnt;
}

void Vote::incVote(int i){
    v_cnt += i;
} 

void Vote::set_name(std::string name){
    user_id = name;
}

std::ostream& operator<<(std::ostream &r, const Vote &u){
    r << u.v_cnt << std::endl;
    return r;
}

Vote& Vote::operator*(){
    return *this;
}

bool Vote::operator==(const Vote& other){
    if(this->v_cnt == other.v_cnt && this->u_ptr == other.u_ptr ){
        return true;
    }
    else{
        return false;
    }
}

Vote& Vote::operator=(const Vote& other){
    this->v_cnt = other.v_cnt;
    this->user_id = other.user_id;
    this->u_ptr = other.u_ptr;
    return *this;
}