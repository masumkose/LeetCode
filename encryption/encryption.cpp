

#include "../include/include.hpp"

std::vector<std::string> split(const std::string &s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::stringstream ss(s); // Create a stringstream object with the input string

	while (getline(ss, token, delimiter))
	{
		tokens.push_back(token); // Extract each substring separated by the delimiter
	}

	return tokens;
}



bool isSame(const std::string& text, const std::string& knownWord)
{
	if (text.size() == knownWord.size())
	{
		int dif = 0;
		for (int i = 0; i < text.size(); i++)
		{
			if (i == 0)
				dif = text[i] - knownWord[i];
			if (text[i] - dif != knownWord[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

std::string decipher(const std::string& ciphertext, const std::string& knownWord)
{
	std::vector<std::string> res = split(ciphertext, ' ');

	std::string keyword;
	for (auto text : res)
	{
		if (isSame(text, knownWord) == true)
		{
			keyword = text;
			break;
		}
	}
	std::cout << keyword << '\n';
	return (keyword);
}

int main() {
    std::string ciphertext;
    std::string knownWord;

    // Input the ciphertext
    std::getline(std::cin, ciphertext);
    // Input the knownWord
    std::cin >> knownWord;

    // Call the decipher function
    std::string result = decipher(ciphertext, knownWord);
    std::cout << result << std::endl;

    return 0;
}
