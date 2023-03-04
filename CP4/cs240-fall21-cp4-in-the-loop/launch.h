#pragma once

#include "Tree.h"
#include "Heap.h"
#include <string>


/* beg data */

int flight_cost = 0;

int gargc;

char **gargv;

std::string in_buff;

int profit;

int launch_fund;

Tree userTree;

Heap voteHeap;

/* end data */



/* beg func-decl */

void init_prog();

void register_user();

void vote();

void scoreboard();

void disp_profit();


/* end func-decl */