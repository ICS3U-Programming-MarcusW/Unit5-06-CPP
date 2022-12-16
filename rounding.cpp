// Copyright (c) 2022 Marcus Wehbi All rights reserved.
//
// Created by: Marcus Wehbi
// Created on: Dec 8 2022
// This program asks the user to enter a decimal
// it then sends it to a function that rounds it


#include <cmath>
#include <iostream>

// Function to round decimal
void roundDecimal(float &decNum, int &decPlaces) {
    // Calculations for rounding the number
    decNum = decNum * (pow(10, decPlaces));
    decNum += 0.5;
    decNum = static_cast<int>(decNum);
    decNum = decNum / (pow(10, decPlaces));
}

// Function to get the users number
int main() {
    // Explain what the program is about
    std::cout << "This program rounds a decimal to the number of "
                 "decimal places entered.";
    std::cout << std::endl;
    std::cout << std::endl;

    // Declare the variables
    std::string decNumString, decPlacesString;
    float decNumFloat;
    int decPlacesInt;

    // Get the users decimal number
    std::cout << "Enter a decimal number: ";
    std::cin >> decNumString;

    // Checks for erroneous input
    try {
        // Convert the users input to a float
        decNumFloat = std::stof(decNumString);

        // Get the amount of decimal places for the user numbers from the user
        std::cout << "Enter the number of decimal places: ";
        std::cin >> decPlacesString;

        // Checks for erroneous input
        try {
            // Convert the users input to an integer
            decPlacesInt = std::stoi(decPlacesString);

            // Checks if the users number is negative
            if (decPlacesInt < 0) {
                // Message for negative number
                std::cout << decPlacesInt << " is not a positive integer.";
            } else {
                // Calls the function that rounds the decimal number
                roundDecimal(decNumFloat, decPlacesInt);

                // Displays the rounded number
                std::cout << std::endl;
                std::cout << decNumString << " rounded to " << decPlacesInt;
                std::cout << " decimals is " << decNumFloat;
            }
        } catch (std::invalid_argument) {
            // Message for invalid input
            std::cout << "Invalid input!";
        }
    } catch (std::invalid_argument) {
        // Message for invalid input
        std::cout << decNumString << " is not a decimal number.";
    }
}
