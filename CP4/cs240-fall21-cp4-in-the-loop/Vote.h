#pragma once
#include <string>
#include <ostream>

class User;

class Vote{

 public:
  Vote(User* u_ptrp);
  Vote();
  void set_user(User* u_ptrp);
  void add_votes(int num_votes);
  User* get_user();
  int get_vote();
  void incVote(int i);
  void set_name(std::string name);
  std::string get_user_id();
  bool operator<(const Vote& v);
  bool operator>(const Vote& v);
  friend std::ostream& operator<<(std::ostream &r, const Vote &u);
  Vote& operator*();
  bool operator==(const Vote& other);
  Vote& operator=(const Vote& other);

 private:
  int v_cnt;
  std::string user_id;
  User* u_ptr;

};
