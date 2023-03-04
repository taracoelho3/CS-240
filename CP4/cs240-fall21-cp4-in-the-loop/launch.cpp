#include "launch.h"
#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Vote.h"

int main(int argc, char** argv) {

   /* Vote* vote1 = new Vote();
    User* user = new User();
    user->set_id("tara");
    vote1->set_user(user);
    user->set_vote(vote1);


    std::cout << vote1->get_vote() << std::endl;
    std::cout << user->get_vote()->get_vote() << std::endl;
    std::cout << "" << std::endl;
    vote1->incVote(100);
    std::cout << vote1->get_vote() << std::endl;
    std::cout << user->get_vote()->get_vote() << std::endl;
    std::cout << "" << std::endl; 

    Vote* v1 = new Vote();
    Vote* v2 = new Vote();
    Vote* v3 = new Vote();


    v1->set_name("tara");
    v2->set_name("ben");
    v3->set_name("mike");

    v1->incVote(5);
    v2->incVote(10);
    v3->incVote(13);

    voteHeap.insert(*v1);
    voteHeap.insert(*v2);
    voteHeap.insert(*v3);


    scoreboard();

    voteHeap.increase_key(v3, 100);

    scoreboard();

    voteHeap.increase_key(v1, 20);

    scoreboard();

    std::cout << "LAUNCHING MIKE" << std::endl;

    voteHeap.extractMax();

    scoreboard();

    voteHeap.increase_key(v2, 300);

    std::cout << "LAUNCHING BEN" << std::endl;

    voteHeap.extractMax();

    scoreboard();*/
  

    gargc = argc;
    gargv = argv;
    init_prog();
    while (true) {

        std::cin >> in_buff;
        if (in_buff == "register") {
            register_user();
        } 

        else if (in_buff == "vote") {
            vote();
        }

        else if (in_buff == "scoreboard") {
            scoreboard();
        }

        else if (in_buff == "profit") {
            disp_profit();
        }
        
        else if (in_buff == "quit") {
            //userTree.deleteBinaryTree(&userTree);
            exit(1);
        }
    }
}

void init_prog() {
    if (gargc != 2) {
        std::cout << "Incorrect commandline argument." << std::endl;
        exit(0);
    }
    flight_cost = std::atoi(gargv[1]);
}

void register_user() {
    std::string user_id;
    std::getline(std::cin, user_id);
    Vote* vote = new Vote();
    User* user = new User();
    user->set_id(user_id);
    vote->set_user(user);
    user->set_vote(vote);

    if (userTree.find(user_id, &userTree) == NULL){
        userTree.insert(*user, &userTree);
        voteHeap.insert(*vote);
    }
    else{
        std::cout << "cannot register duplicate user " << std::endl;
    }

}

void vote() {
    int vote_num;
    std::string user_id;
    std::cin >> vote_num;
    std::getline(std::cin, user_id);
    if (vote_num % 2 != 0) {
        vote_num -= 1;
        profit += 1;
    }
    int vote_inc = vote_num / 2;
    profit += vote_inc;
    launch_fund += vote_inc;


    if(userTree.find(user_id, &userTree) == NULL){
        std::cout << "user does not exist" << std::endl;
    }
    else{
   
        voteHeap.increase_key(*(userTree.find(user_id, &userTree)->get_vote()), vote_inc);
   
    }
   
     while(launch_fund >= flight_cost){
        if(voteHeap.getSize() == 0){
            break;
        }

        Vote launched = voteHeap.extractMax();
        std::cout << launched.get_user()->get_id()<< " launched" <<std::endl;
        userTree.remove(*(launched.get_user()), &userTree);
        launch_fund -= flight_cost;
    }

}

void scoreboard() {
    int num;
    std::vector<Vote> removed_votes;
    std::cin >> num;


    for(int i = 0; i < num; i++){
        if(voteHeap.getSize() == 0){
            break;
        }
        else{
            Vote temp = voteHeap.extractMax();
            std::cout << temp.get_user()->get_id() << " " << temp << std::endl;
            removed_votes.push_back(temp);
        }
    }
    
    for(int i = 0; i < removed_votes.size(); i++){
        voteHeap.insert(removed_votes[i]);
    }

}

void disp_profit() {
    std::cout << "$" << profit << std::endl;
}

