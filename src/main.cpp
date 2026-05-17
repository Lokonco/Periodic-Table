//--------------Imports----------//
#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Used to read data from file
#include <ranges>
#include <sstream>
#include "Element.h"
#include <algorithm>
#include <map>
#include <optional>
//--------------------------------//

// This function will be used to parse the csv file we seprate the data at each ,
// We use a reference for line (std::string& line) to save memory since we dont need
// to store the whole line of text. We can think of it as the parse function is just borrowing the line variable
std::vector<std::string> parse(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;

    //while loop args: ss = line from csv = 1, H, Hydrogen / field = result after parsing so
    // field = ["1", "H", "Hydrogen"] / ','= delimiter
    while (std::getline(ss, field, ',')) {
        fields.push_back(field);
    }
    return fields;
}

std::optional<double> safeStod(const std::string& str) {
    if (str.empty()) return std::nullopt;  // Return empty/null
    return std::stod(str);
}

std::optional<int> safeStoi(const std::string& str) {
    if (str.empty()) return std::nullopt;  // Return empty/null
    return std::stoi(str);
}


int main(int argc, char* argv[]) {
    // Open the file
    std::ifstream file("data/PeriodicTable.csv");

    // Set extra mode to false unless user request it
    bool extraMode = false;
    if (argc > 1 && std::string( argv[1]) == "-extra") {
        extraMode = true;
    }

    // check if file could be opened
    if (!file.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    /*
     string line, will hold a entire line from the csv
     then we use getline to grab that line and store it
     we dont use cin since that will stop at the whitespace.
     parse the line when we read it.
     */
    std::string line;
    std::vector<Element> allElements;
    int lineNum = 0;
    while (std::getline(file, line)) {
        lineNum++;
        /*----------------------------------- Test ---------------------------------------
        | 1 - Display each line and make sure data is read                                  |
        | std::cout << line << std::endl;                                                   |
        | 2 - Parse the file lines                                                          |
        | std::vector<std::string> fields = parse(line); // fields = ["1", "H", "Hydrogen"] |
        | 3 - print examples of parsed text                                                 |
        | Test that the text was parsed correctly                                           |
        |                                                                                   |
        | std::cout << "Atomic #: " << fields[0] << std::endl;                              |
        | std::cout << "Symbol: " << fields[1] << std::endl;                                |
        | std::cout << "Name: " << fields[2] << std::endl;                                  |
        | std::cout << "---" << std::endl;                                                  |
        ----------------------------------------------------------------------------------
        */

        // Read each line and parse
        std::vector<std::string> fields = parse(line); // fields = ["1", "H", "Hydrogen"]


        // Data goes into memory
        Element e;
        try {
            e.atomicNumber = fields[0].empty() ? "N/A" : fields[0];
            e.element = fields[1].empty() ? "N/A" : fields[1];
            e.symbol = fields[2].empty() ? "N/A" : fields[2];
            e.atomicMass = fields[3].empty() ? "N/A" : fields[3];
            e.numberOfNeutrons = fields[4].empty() ? "N/A" : fields[4];
            e.numberOfProtons = fields[5].empty() ? "N/A" : fields[5];
            e.numberOfElectrons = fields[6].empty() ? "N/A" : fields[6];
            e.period = fields[7].empty() ? "N/A" : fields[7];
            e.group = fields[8].empty() ? "N/A" : fields[8];
            e.phase = fields[9].empty() ? "N/A" : fields[9];
            e.radioactive = fields[10].empty() ? "N/A" : fields[10];
            e.natural = fields[11].empty() ? "N/A" : fields[11];
            e.metal = fields[12].empty() ? "N/A" : fields[12];
            e.nonmetal = fields[13].empty() ? "N/A" : fields[13];
            e.metalloid = fields[14].empty() ? "N/A" : fields[14];
            e.type = fields[15].empty() ? "N/A" : fields[15];
            e.atomicRadius = fields[16].empty() ? "N/A" : fields[16];
            e.electronegativity = fields[17].empty() ? "N/A" : fields[17];
            e.firstIonization = fields[18].empty() ? "N/A" : fields[18];
            e.density = fields[19].empty() ? "N/A" : fields[19];
            e.meltingPoint = fields[20].empty() ? "N/A" : fields[20];
            e.boilingPoint = fields[21].empty() ? "N/A" : fields[21];
            e.numberOfIsotopes = fields[22].empty() ? "N/A" : fields[22];
            e.discoverer = fields[23].empty() ? "N/A" : fields[23];
            e.year = fields[24].empty() ? "N/A" : fields[24];
            e.specificHeat = fields[25].empty() ? "N/A" : fields[25];
            e.numberOfShells = fields[26].empty() ? "N/A" : fields[26];
            e.numberOfValence = fields[27].empty() ? "N/A" : fields[27];

            allElements.push_back(e);
        } catch (const std::exception& ex) {
            std::cerr << "Error parsing line " << lineNum << ": " << ex.what() << std::endl;
            continue;
        }
    }

    // Map
    std::map<std::string, Element*> elementsBySymbol;
    std::map<std::string, Element*> elementsByAtomicNumber;

    for (auto& elem : allElements) {
        std::string upperSymbol = elem.symbol;
        std::transform(upperSymbol.begin(), upperSymbol.end(), upperSymbol.begin(), ::toupper);
        elementsBySymbol[upperSymbol] = &elem;
        // Convert atomic number to string for the map key
        elementsByAtomicNumber[elem.atomicNumber] = &elem;
    }
    std::cout << "DEBUG: Symbol in map = '" << elementsBySymbol.begin()->first << "'" << std::endl;std::cout << "DEBUG: Symbol in map = '" << elementsBySymbol.begin()->first << "'" << std::endl;
    file.close(); // Close file when done

    //-------------- User Input ------------//
    std::string userInput;

    while (true) {
        //-----------------UI-------------//
        std::cout << R"(
                    Periodic Table of Elements
        1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
        1 H                                                  He
        2 Li Be                               B  C  N  O  F  Ne
        3 Na Mg                               Al Si P  S  Cl Ar
        4 K  Ca Sc Ti V  Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr
        5 Rb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I  Xe
        6 Cs Ba La Hf Ta W  Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn
        7 Fr Ra Ac Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og

                Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu
                Th Pa U  Np Pu Am Cm Bk Cf Es Fm Md No Lr
    )" << std::endl;

        //--------------------- ------------//
        std::cout << "Enter a symbol or atomic number (or 'Quit' to exit)";
        std::getline(std::cin, userInput);

        // Make sure input is valid
        if (userInput.empty()) {
            std::cout << "Enter a symbol or atomic number";
            continue;
        }

        // Uppercase conversion
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

        if (userInput == "QUIT") {
            break;
        }

    //-------------------------------------//


        // This input is for testing
        //std::string userInput = "H";

    //---------------------Look up logic-----------------------//
        Element* result = nullptr;

        // Try finding by symbol first
        if (elementsBySymbol.find(userInput) != elementsBySymbol.end()) {
            result = elementsBySymbol[userInput];
        }
        // Try finding by atomic num
        else if (elementsByAtomicNumber.find(userInput) != elementsByAtomicNumber.end()) {
            result = elementsByAtomicNumber[userInput];
        }

        if (result) {
            extraMode ? printElement(*result) : printElementBasic(*result);
        } else {
            std::cout << "Could not find element" << std::endl;
        }
        //---------------------------------------------------------//
    }

    return 0;
}








/*
Phase 1
Load file
Print raw lines

Phase 2
Parse CSV into a struct

Phase 3
Store elements in a vector

Phase 4
Implement lookup by atomic number only

Phase 5
Add symbol lookup map

Phase 6
Add CLI loop

Phase 7
Improve formatting + cleanup

UI
                        Periodic Table of Elements
        1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
        1 H                                                  He
        2 Li Be                               B  C  N  O  F  Ne
        3 Na Mg                               Al Si P  S  Cl Ar
        4 K  Ca Sc Ti V  Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr
        5 Rb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I  Xe
        6 Cs Ba La Hf Ta W  Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn
        7 Fr Ra Ac Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og

                Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu
                Th Pa U  Np Pu Am Cm Bk Cf Es Fm Md No Lr''')
    ('Enter a symbol or atomic number to examine, or QUIT to quit.')


Feature idea: allow for user to pick between a basic version or a full version



*/

