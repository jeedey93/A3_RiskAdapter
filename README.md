# Description #

This is the RISK board game project's repo

| Name                | Student Number|
| ------------------- |:-------------:| 
| Kenny Kwan          | 29591648      | 
| Justin Do           | 26600514      |
| Pirasath Vallipuram |               |
| Renaud Brunet       | 26626742      | 

## Intermediate Release Requirements ##

### Map Creation and editing (16 points) ###
* User-driven creation of map elements, such as country, continent and connectivity between countries. (5 points)
* Saving a map to a file exactly as edited (3 points)
* Loading a map from an existing file, then editing the map (3 points)
* Verification of map correctness before saving (at least 3 types of incorrect maps)

### Game Play ###
* Implementation of a game driver implementing the game phases

### Startup phase ###
* Game starts by user selection of a user-saved map file, then loads the map as a connected graph.
* User chooses the number of players, all countries are randomly assigned to players.

### Reinforcement phase ###
* Calculation of correct number of reinforcement armies.
* User-driven placement of reinforcement armies on the map

### Fortification Phase ###
* Implementation of a valid fortification move according to the Risk rules.


### TASK DISTRIBUTION ###
1. Creating a continent class (control value, name, etc) and integrating it with the player class (Justin)
2. Implementing cards (include it in the player class) - Affects Reinforcement phase (Kenny)
3. Reinforcement Phase (Kenny)
4. Fortification Phase - Easier than reinforcement (Pira)
5. Map Creation/Saving/Loading - Will be a separate piece from the game itself. A decision will be made when the program is run if they would like to play the game or if they would like to create/save/load/modify a map - RENAUD/JUSTIN
6. Verification of map correctness (At least 3 incorrect maps) - RENAUD/JUSTIN
    * Make sure there is at least one continent
    * Make sure there is at least one country
    * Make sure that all the countries connect (no stray nodes)
    * Make sure that all the continents connect (no stray nodes)
    * Make sure a country can only belong to one continent
7. Graphical User Interface (If time allows)