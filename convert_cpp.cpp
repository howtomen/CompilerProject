/*
	File: convert_cpp.cpp
	By: Group 5
	Date: 5/8/2018
	Course: CPSC 323
*/


#include "convert_cpp.h"

void convert_cpp::outheader(ofstream & output)
{
	output << "#include <iostream>\nusing namespace std;\nint main()\n{\n";
}

void convert_cpp::outending(ofstream & output)
{
	output << "return 0;\n}\n";
}

void convert_cpp::integer(ofstream & output, string line)
{
	int endPos = line.find(":");

	output << "int " << line.substr(0, endPos) << ";" << endl;
}

void convert_cpp::assign(ofstream & output, string line)
{
	output << line << endl;
}

void convert_cpp::print(ofstream & output, string line)
{
	int stPos, len;

	if (line.find("'") != string::npos) {

		stPos = line.find("'");
		len = (line.find("=")) - stPos;

		output << "cout << \"" << line.substr(stPos + 1, len) << "\" << " << line.substr(stPos + 1, len - 1) << ";" << endl;
	}

	else {

		stPos = line.find("(");
		len = (line.find(")")) - (stPos + 2);

		output << "cout << " << line.substr(stPos + 2, len - 1) << ";" << endl;
	}
}

void convert_cpp::translate(ofstream & output, string line)
{
	if (line.find("INTEGER") != string::npos) {
		integer(output, line);
	}
	else if (line.find("PRINT") != string::npos) {
		print(output, line);
	}
	else if (line.find("=") != string::npos){
		assign(output, line);
	}

}

void convert_cpp::output_cpp(string fname_input, string fname_output)
{
	output.open(fname_output, ios_base::out | ios_base::trunc);
	input.open(fname_input, ios_base::in);
	
	std::cout << "Converting to cpp...... " << fname_input << " -> " << fname_output << std::endl;

	outheader(output);

	while (!input.eof()) {
		getline(input, line);

		translate(output, line);
	}

	outending(output);

	output.close();
	input.close();

	std::cout << "Success! \n\n";
}

