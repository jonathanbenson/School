#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
using namespace std;

enum choice { ALL, NAMES_IDS, ACCOUNTS, QUIT };


choice menu();

void get_lines(const string& FILE_NAME, vector<string>& lines);
void parse_lines(vector<string>& lines, vector<int>& ids, vector<string>& firsts, vector<string>& lasts, vector<double>& savings, vector<double>& checkings);

void output(vector<int>& ids, vector<string>& firsts, vector<string>& lasts, vector<double>& savings, vector<double>& checkings);
void output(vector<int>& ids, vector<string>& firsts, vector<string>& lasts);
void output(vector<double>& savings, vector<double>& checkings);

