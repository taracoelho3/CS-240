#pragma once

#include "Vote.h"
#include <string>
#include <ostream>


class Vote;

class User{
 public:
 User();
  User(std::string idp);
  void set_vote(Vote* v_ptrp);
  Vote* get_vote();
  void inc_vote(std::string, int vote);
  std::string get_id();
  void set_id(std::string s);
  bool operator==(const User& other) const;
  bool operator>(const User& other) const;
  User& operator=(const User& other);
  bool operator<(const User& other) const;

 private:
  std::string id;
  Vote* v_ptr;
};
