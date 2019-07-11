/*
	File: convert_cpp.h 
	By: Group 5
	Date: 5/8/2018
	Course: CPSC 323

*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class convert_cpp
{
public:
	void outheader(ofstream& output);
	void outending(ofstream& output);

	void integer(ofstream& output, string line);
	void assign(ofstream& output, string line);
	void print(ofstream& output, string line);

	void translate(ofstream& output, string line);
	void output_cpp(string fname_input, string fname_output);
private:
	string line;
	ofstream output;
	ifstream input;
};

