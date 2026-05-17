# Periodic Table of Elements
 
A periodic table built into the terminal. Main reason for building this was me taking a chemistry class and wanting fast access to a periodic table.

<div align="center">

<pre>
     Periodic Table of Elements
    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18
1 H                                                  He
2 Li Be                               B  C  N  O  F  Ne
3 Na Mg                               Al Si P  S  Cl Ar
4 K  Ca Sc Ti V  Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr
5 Rb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I  Xe
6 Cs Ba La Hf Ta W  Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn
7 Fr Ra Ac Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og

        Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu
        Th Pa U  Np Pu Am Cm Bk Cf Es Fm Md No Lr
</pre>

</div>

## Features
 
- Search elements by **symbol** (e.g., "H", "Fe") or **atomic number** (e.g., "1", "26")
- ASCII Periodic table visual
- Two display modes:
  - **Basic mode**: Shows essential information (symbol, name, atomic mass, type, electronegativity)
  - **Extra mode**: Shows comprehensive data (all 28 properties)
- Handles missing/empty data gracefully with "N/A" placeholders
## Prerequisites
 
- C++17 or later
- CMake 3.x
- A CSV file with periodic table data (`PeriodicTable.csv`) (Included)
## Building
 
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
 
## Running
 
**Basic mode** (shows limited element info):
```bash
./PeriodicTable
```
 
**Extra mode** (shows all element properties):
```bash
./PeriodicTable -extra
```
 
## Usage Examples

### Basic mode
 
```
Enter a symbol or atomic number (or 'Quit' to exit): H
 
H
Symbol: H
Name: Hydrogen
Atomic Number: 1
Atomic Mass: 1.007 Da
Type: Nonmetal
Electronegativity: 2.2
```
 
### Extra mode
```
Atomic Number: 1
Symbol: H
Element: Hydrogen
Atomic Mass: 1.007
Number of Protons: 1
Number of Neutrons: 0
Number of Electrons: 1
Period: 1
Group: 1
Phase: gas
Type: Nonmetal
Atomic Radius: 0.79
Electronegativity: 2.2
First Ionization: 13.5984
Density: 8.99E-05
Melting Point: 14.175
Boiling Point: 20.28
Number of Isotopes: 3
Discoverer: Cavendish
Year Discovered: 1766
Specific Heat: 14.304
Number of Shells: 1
Number of Valence Electrons: 1
```
 

 
## Project Structure
 
```
PeriodicTable/
├── CMakeLists.txt           # Build configuration
├── README.md                # Project documentation
├── data/
│   └── PeriodicTable.csv    # Periodic table data
├── include/
│   └── Element.h            # Element struct definition
├── src/
│   └── main.cpp             # Main program logic
└── .gitignore               # Git ignore file
```
 

## Data Source
 
Element data comes from a CSV file containing 118 elements with properties like:
- Atomic number, symbol, name
- Atomic mass, density, electronegativity
- Melting/boiling points
- Discovery information
[CSV SOURCE](https://gist.github.com/GoodmanSciences/c2dd862cd38f21b0ad36b8f96b4bf1ee)

## Future Improvements
 
- Add color output for better terminal display
- Fix table 
