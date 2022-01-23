//Diana Plosnita 2018526

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "File name or action not provided, execute again" << endl;
		return 1;
	}
	
	string action = argv[1];
	string input_name = argv[2];
	if(action == "v")
	{
		ifstream input_file;
		input_file.open(input_name);
		if (!input_file) 
		{
			cout << "Error in reading file" << "\n";
			return 1;
		}
		string line;

		while ( getline (input_file, line) )
		{
			cout << line << '\n';
		}
		input_file.close();
	}
	else if(action == "f")
	{
		string output_name = argv[3]; 
		ifstream input_file;
		ofstream output_file;
		input_file.open(input_name);
		if (!input_file) 
		{
			cout << "Error in reading file" << "\n";
			return 1;
		}
		output_file.open(output_name);
		string line;

		while ( getline (input_file, line) )
		{
			output_file << line << '\n';
		}
		input_file.close();
		output_file.close();
	}
}