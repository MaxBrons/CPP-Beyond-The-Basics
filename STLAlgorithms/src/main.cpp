#include "Core.h"

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

// Easy method for printing a gui header to the console.
inline void DisplayHeader(const std::string& header) {
	std::cout << GUI::CreateHeader(header, Colour::Background::Green) << std::endl;
}

// Easy method for printing a gui sub header to the console.
inline void DisplaySubHeader(const std::string& header) {
	std::cout << GUI::CreateHeader(header, Colour::Background::Blue, 1) << std::endl;
}

// Easy method for printing to the console.
inline void PrintLine(const std::string& body = "") {
	std::cout << body << std::endl;
}

int main() {
	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
		// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na

		// Copy the vector to then sort it, so it doesn't mess up the original vector.
		auto copy = std::vector<std::string>(colours);
		std::sort(copy.begin(), copy.end(), std::less<std::string>());

		auto partition = std::partition(copy.begin(), copy.end(), [](const std::string& colour) { return colour < "purple"; });
		// Create a vector with entries before 'purple' and one after 'purple' (alfabetically).
		auto before = std::vector<std::string>(copy.begin(), partition);
		auto after = std::vector<std::string>(partition, copy.end());

		// Print out the result of the the two split vectors.
		DisplayHeader(" Alfabetic Splitting ");
		DisplaySubHeader("Before 'purple'");

		for (const auto& colour : before)
			PrintLine(GUI::CreateHeader(colour, 2));

		PrintLine();

		DisplaySubHeader("After 'purple'");
		for (const auto& colour : after)
			PrintLine(GUI::CreateHeader(colour, 2));

		PrintLine();
	}
	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// 2) alle elementen UPPERCASE te maken.

		// Copy the vector to then sort it, so it doesn't mess up the original vector.
		auto copy = std::vector<std::string>(colours);

		// Transform every character from the vector of strings to an uppercase character.
		std::transform(copy.begin(), copy.end(), copy.begin(), [](std::string& colour) {
			std::transform(colour.begin(), colour.end(), colour.begin(), toupper);
			return colour;
			});

		// Print out the result of the the uppercase vector.
		DisplayHeader(" Convert the strings to uppercase ");
		for (const auto& colour : copy)
			PrintLine(GUI::CreateHeader(colour, 1));

		PrintLine();
	}
	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// 3) alle dubbele te verwijderen

		// Copy the vector to then sort it, so it doesn't mess up the original vector.
		auto copy = std::vector<std::string>(colours);
		std::sort(copy.begin(), copy.end(), std::less<std::string>());

		auto unique = std::unique(copy.begin(), copy.end());
		copy.erase(unique, copy.end());

		// Print out the result of the the uppercase vector.
		DisplayHeader(" Delete the duplicate numbers ");
		for (const auto& colour : copy)
			PrintLine(GUI::CreateHeader(colour, 1));

		PrintLine();
	}

	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 1) alle negatieve elementen te verwijderen

		// Copy the vector to then sort it, so it doesn't mess up the original vector.
		auto copy = std::vector<double>(numbers);

		// Remove all elements from the vector of doubles that are less than 0.
		auto removed = std::remove_if(copy.begin(), copy.end(), [](double number) { return number < 0; });
		copy.erase(removed, copy.end());

		// Print out the result of the the uppercase vector.
		DisplayHeader(" Delete the negative numbers ");
		for (const double& number : copy)
			PrintLine(GUI::CreateHeader(std::to_string(number), 1));

		PrintLine();
	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 2) voor alle elementen te bepalen of ze even of oneven zijn

		// Copy the vector to then sort it, so it doesn't mess up the original vector.
		auto copy = std::vector<double>(numbers);

		// Print out the result of the even or uneven elements in the vector.
		DisplayHeader(" Check for even or uneven numbers ");

		std::for_each(copy.begin(), copy.end(), [&](double number)
			{
				bool isEven = static_cast<int>(number) % 2 == 0;
				PrintLine(GUI::CreateHeader(std::to_string(number ) + ": " + (isEven ? "Even" : "Uneven"), 1));
			});

		PrintLine();
	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 3) de som, het gemiddelde, en het product van alle getallen te berekenen

		// Copy the vector to then sort it, so it doesn't mess up the original vector.
		auto copy = std::vector<double>(numbers);

		DisplayHeader(" Calculations ");

		// Print the sum of the vector of doubles.
		DisplaySubHeader("The sum");
		double sum = std::accumulate(copy.begin(), copy.end(), 0.0);
		PrintLine(GUI::CreateHeader(std::to_string(sum), 2) + "\n");

		// Print the average of the vector of doubles.
		DisplaySubHeader("The average");
		double average = sum / copy.size();
		PrintLine(GUI::CreateHeader(std::to_string(average), 2) + "\n");

		// Print the product of the vector of doubles.
		DisplaySubHeader("The product");
		double product = std::accumulate(copy.begin(), copy.end(), 1.0, std::multiplies<double>());
		PrintLine(GUI::CreateHeader(std::to_string(product), 2) + "\n");
		
		PrintLine();
	}

	return 0;
}