#include <iostream>
#include <fstream>
#include <string>

void	replace(std::string &buffer, std::string s1, std::string s2)
{
	size_t pos = 0;
	while((pos = buffer.find(s1, pos)) != std::string::npos)
	{
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos += s2.length();
	}
	std::cout << buffer << std::endl;
}

int	file_handling(std::string file, std::string s1, std::string s2)
{
	std::ifstream infile(file.c_str());
	if(!infile)
	{
		std::cout << "File not found" << std::endl;
		return (1);
	}
	std::ofstream outfile((file + ".replace").c_str());
	if(!outfile)
	{
		std::cout << "Error creating file" << std::endl;
		return (1);
	}
	std::string buffer;
	while(std::getline(infile, buffer))
	{
		replace(buffer, s1, s2);
		outfile << buffer << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}

int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cout << "Usage: <./nameOfProgram fileName stringToBeReplaced stringToReplace>" << std::endl;
		return (1);
	}
	else
		return(file_handling(av[1], av[2], av[3]));
}