# COMP_345_A1_v9
Group Project Risk-Based Game: Warzone for Advanced program design with C++; Winter 2022 COMP 345

## COMP345 : Advanced program design with C++ 

### Team Project
* Date: Winter 2022
* Instructor: Dr. Amin Ranj Bar, amin.ranjbar@.concordia.ca
---
### Problem statement
<span "font-size:8;">This is a team assignment. It is divided into distinct parts. Each part is about the development of a part of the topic 
presented as the team project. Even though it is about the development of a part of your team project, each 
assignment is to be developed/presented/tested separately. The description of each part describes what are the 
features that the part should implement, and what you should demonstrate. Note that the following descriptions 
describe the baseline of the assignment, and are related to the project description. See the course web page for a 
full description of the team project, as well as links to the details of the game rules to be implemented.</span>
---
#### Assignment 1: 
* Specific design requirements
  1. All data members of user-defined class type must be of **pointer type**.
  2. All file names and the content of the files must be according to what is given in the description below.
  3. All different parts must be implemented in their own separate .cpp/.h file duo. All functions’ implementation must be provided in the .cpp file 
    (i.e. no inline functions are allowed).
  4. All classes must implement a correct copy constructor, assignment operator, and stream insertion operator.
  5. **Memory leaks must be avoided**.
  6. Code must be documented using comments (user-defined classes, methods, free functions, operators).
  7. If you use third-party libraries that are not available in the labs and require setup/installation, you may not assume to have help using them 
     and you are entirely responsible for their proper installation for grading purposes.
---
#### 5 Parts to be implemented
 **Part 1 : Map**
  Implement a group of C++ classes that implement the structure and operation of a map for the game Warzone https://www.warzone.com/.
*  **Map Class : Map.h, Map.cpp, MapDriver.cpp**                                                                            
    - The **Map class** is implemented as a **connected graph**. The graph’s nodes represents a territory (implemented as a **Territory class**). 
    - Edges between nodes represent adjacency between territories.
    - Continents are connected subgraphs. Each territory belongs to one and only one continent.                                                         
    - A **territory** is owned by a player and contain a number of armies.                                      
    - The **Map** class can be used to represent any map graph configuration.                                      
    - The Map class includes a **validate()** method that makes the following checks: 
        1 the map is a connected graph,
        2 continents are connected subgraphs and
        3 each country belongs to one and only one continent.
    - Map loader can read any Domination map file
    - Map loader creates a map object as a graph data structure.
    - Map loader should be able to read any text file (even invalid ones).
    - Driver that reads many different map files, creates a Map object for valid files and rejects the 
invalid ones. 
 **Part 2 : Player**
  Implement a group of C++ classes that implement the structure and operation of a map for the game Warzone https://www.warzone.com/.
*  **Map Class : Map.h, Map.cpp, MapDriver.cpp**                                                                            
    - The **Map class** is implemented as a **connected graph**. The graph’s nodes represents a territory (implemented as a **Territory class**). 
    - Edges between nodes represent adjacency between territories.
    - Continents are connected subgraphs. Each territory belongs to one and only one continent.                                                         
    - A **territory** is owned by a player and contain a number of armies.                                      
    - The **Map** class can be used to represent any map graph configuration.                                      
    - The Map class includes a **validate()** method that makes the following checks: 
        1 the map is a connected graph,
        2 continents are connected subgraphs and
        3 each country belongs to one and only one continent.
    - Map loader can read any Domination map file
    - Map loader creates a map object as a graph data structure.
    - Map loader should be able to read any text file (even invalid ones).
    - Driver that reads many different map files, creates a Map object for valid files and rejects the 
invalid ones. 
  ---
#### Assignment 2: 
* Specific design requirements
  1. All data members of user-defined class type must be of **pointer type**.
  2. All file names and the content of the files must be according to what is given in the description below.
  3. All different parts must be implemented in their own separate .cpp/.h file duo. All functions’ implementation must be provided in the .cpp file 
    (i.e. no inline functions are allowed).
  4. All classes must implement a correct copy constructor, assignment operator, and stream insertion operator.
  5. **Memory leaks must be avoided**.
  6. Code must be documented using comments (user-defined classes, methods, free functions, operators).
  7. If you use third-party libraries that are not available in the labs and require setup/installation, you may not assume to have help using them 
     and you are entirely responsible for their proper installation for grading purposes.
---
#### 5 Parts to be implemented
 **Part 1 : Map**
  Implement a group of C++ classes that implement the structure and operation of a map for the game Warzone https://www.warzone.com/.
*  **Map Class : Map.h, Map.cpp, MapDriver.cpp**                                                                            
    - The **Map class** is implemented as a **connected graph**. The graph’s nodes represents a territory (implemented as a **Territory class**). 
    - Edges between nodes represent adjacency between territories.
    - Continents are connected subgraphs. Each territory belongs to one and only one continent.                                                         
    - A **territory** is owned by a player and contain a number of armies.                                      
    - The **Map** class can be used to represent any map graph configuration.                                      
    - The Map class includes a **validate()** method that makes the following checks: 
        1 the map is a connected graph,
        2 continents are connected subgraphs and
        3 each country belongs to one and only one continent.
    - Map loader can read any Domination map file
    - Map loader creates a map object as a graph data structure.
    - Map loader should be able to read any text file (even invalid ones).
    - Driver that reads many different map files, creates a Map object for valid files and rejects the 
invalid ones. 
 **Part 2 : Player**
  Implement a group of C++ classes that implement the structure and operation of a map for the game Warzone https://www.warzone.com/.
*  **Map Class : Map.h, Map.cpp, MapDriver.cpp**                                                                            
    - The **Map class** is implemented as a **connected graph**. The graph’s nodes represents a territory (implemented as a **Territory class**). 
    - Edges between nodes represent adjacency between territories.
    - Continents are connected subgraphs. Each territory belongs to one and only one continent.                                                         
    - A **territory** is owned by a player and contain a number of armies.                                      
    - The **Map** class can be used to represent any map graph configuration.                                      
    - The Map class includes a **validate()** method that makes the following checks: 
        1 the map is a connected graph,
        2 continents are connected subgraphs and
        3 each country belongs to one and only one continent.
    - Map loader can read any Domination map file
    - Map loader creates a map object as a graph data structure.
    - Map loader should be able to read any text file (even invalid ones).
    - Driver that reads many different map files, creates a Map object for valid files and rejects the 
invalid ones. 
---
#### Assignment 3: 
* Specific design requirements
  1. All data members of user-defined class type must be of **pointer type**.
  2. All file names and the content of the files must be according to what is given in the description below.
  3. All different parts must be implemented in their own separate .cpp/.h file duo. All functions’ implementation must be provided in the .cpp file 
    (i.e. no inline functions are allowed).
  4. All classes must implement a correct copy constructor, assignment operator, and stream insertion operator.
  5. **Memory leaks must be avoided**.
  6. Code must be documented using comments (user-defined classes, methods, free functions, operators).
  7. If you use third-party libraries that are not available in the labs and require setup/installation, you may not assume to have help using them 
     and you are entirely responsible for their proper installation for grading purposes.
---
#### 2 Parts to be implemented
 **Part 1 : Map**
  Implement a group of C++ classes that implement the structure and operation of a map for the game Warzone https://www.warzone.com/.
*  **Map Class : Map.h, Map.cpp, MapDriver.cpp**                                                                            
    - The **Map class** is implemented as a **connected graph**. The graph’s nodes represents a territory (implemented as a **Territory class**). 
    - Edges between nodes represent adjacency between territories.
    - Continents are connected subgraphs. Each territory belongs to one and only one continent.                                                         
    - A **territory** is owned by a player and contain a number of armies.                                      
    - The **Map** class can be used to represent any map graph configuration.                                      
    - The Map class includes a **validate()** method that makes the following checks: 
        1 the map is a connected graph,
        2 continents are connected subgraphs and
        3 each country belongs to one and only one continent.
    - Map loader can read any Domination map file
    - Map loader creates a map object as a graph data structure.
    - Map loader should be able to read any text file (even invalid ones).
    - Driver that reads many different map files, creates a Map object for valid files and rejects the 
invalid ones. 
 **Part 2 : Player**
  Implement a group of C++ classes that implement the structure and operation of a map for the game Warzone https://www.warzone.com/.
*  **Map Class : Map.h, Map.cpp, MapDriver.cpp**                                                                            
    - The **Map class** is implemented as a **connected graph**. The graph’s nodes represents a territory (implemented as a **Territory class**). 
    - Edges between nodes represent adjacency between territories.
    - Continents are connected subgraphs. Each territory belongs to one and only one continent.                                                         
    - A **territory** is owned by a player and contain a number of armies.                                      
    - The **Map** class can be used to represent any map graph configuration.                                      
    - The Map class includes a **validate()** method that makes the following checks: 
        1 the map is a connected graph,
        2 continents are connected subgraphs and
        3 each country belongs to one and only one continent.
    - Map loader can read any Domination map file
    - Map loader creates a map object as a graph data structure.
    - Map loader should be able to read any text file (even invalid ones).
    - Driver that reads many different map files, creates a Map object for valid files and rejects the 
invalid ones. 

