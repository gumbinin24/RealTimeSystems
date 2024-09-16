#include <iostream>

int main() {
	std::string s = "01234";

	for (int i = s.size() - 1; i >= 0; --i) 
	{
		std::cout << s[i] << std::endl;
	}
}
