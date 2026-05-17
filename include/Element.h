#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#pragma once

struct Element {
    // Identification
    std::string atomicNumber;
    std::string symbol;
    std::string element;
    std::string type;

    // Atomic Structure
    std::string numberOfProtons;
    std::string numberOfNeutrons;
    std::string numberOfElectrons;
    std::string numberOfShells;
    std::string numberOfValence;

    // Physical Properties
    std::string phase;
    std::string density;
    std::string meltingPoint;
    std::string boilingPoint;
    std::string atomicRadius;
    std::string specificHeat;

    // Chemical Properties
    std::string atomicMass;
    std::string electronegativity;
    std::string firstIonization;

    // Periodic Table Position
    std::string period;
    std::string group;

    // Classification
    std::string metal;
    std::string nonmetal;
    std::string metalloid;
    std::string radioactive;
    std::string natural;

    // Discovery Information
    std::string discoverer;
    std::string year;
    std::string numberOfIsotopes;
};

void printElement(const Element& elem) {
    std::cout << std::endl;
    std::cout << "Atomic Number: " << elem.atomicNumber << std::endl;
    std::cout << "Symbol: " << elem.symbol << std::endl;
    std::cout << "Element: " << elem.element << std::endl;
    std::cout << "Atomic Mass: " << elem.atomicMass << std::endl;
    std::cout << "Number of Protons: " << elem.numberOfProtons << std::endl;
    std::cout << "Number of Neutrons: " << elem.numberOfNeutrons << std::endl;
    std::cout << "Number of Electrons: " << elem.numberOfElectrons << std::endl;
    std::cout << "Period: " << elem.period << std::endl;
    std::cout << "Group: " << elem.group << std::endl;
    std::cout << "Phase: " << elem.phase << std::endl;
    std::cout << "Type: " << elem.type << std::endl;
    std::cout << "Atomic Radius: " << elem.atomicRadius << std::endl;
    std::cout << "Electronegativity: " << elem.electronegativity << std::endl;
    std::cout << "First Ionization: " << elem.firstIonization << std::endl;
    std::cout << "Density: " << elem.density << std::endl;
    std::cout << "Melting Point: " << elem.meltingPoint << std::endl;
    std::cout << "Boiling Point: " << elem.boilingPoint << std::endl;
    std::cout << "Number of Isotopes: " << elem.numberOfIsotopes << std::endl;
    std::cout << "Discoverer: " << elem.discoverer << std::endl;
    std::cout << "Year Discovered: " << elem.year << std::endl;
    std::cout << "Specific Heat: " << elem.specificHeat << std::endl;
    std::cout << "Number of Shells: " << elem.numberOfShells << std::endl;
    std::cout << "Number of Valence Electrons: " << elem.numberOfValence << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(); // Wait for user to press Enter
}

void printElementBasic(const Element& elem) {
    std::cout << std::endl;
    std::cout << elem.symbol << std::endl;
    std::cout << "Symbol: " << elem.symbol << std::endl;
    std::cout << "Name: " << elem.element << std::endl;
    std::cout << "Atomic Number: " << elem.atomicNumber << std::endl;
    std::cout << "Atomic Mass: " << elem.atomicMass << " Da" << std::endl;
    std::cout << "Type: " << elem.type << std::endl;
    std::cout << "Electronegativity: " << elem.electronegativity << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore();
}

#endif //ELEMENT_H

