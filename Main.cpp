#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	// Initialization
	std::string ppmName;

	std::fstream configFile;
	configFile.open("settings.txt");
	while(!configFile.eof()){
		std::getline(configFile, ppmName);
		std::cout << ppmName;
	}
	configFile.close();	
	// Image file
	std::fstream ppm;
	int WIDTH, HEIGHT, MAXCOLOUR;
	int lineInd;
	std::string currentLine;
	std::vector<std::string> colourContents;
	ppm.open(ppmName, std::fstream::out);

	while(!ppm.eof()){
		std::getline(ppm, currentLine);
		lineInd++;
		if(lineInd == 2) WIDTH = std::stoi(currentLine);
		if(lineInd == 3) HEIGHT = std::stoi(currentLine);
		if(lineInd == 4) MAXCOLOUR = std::stoi(currentLine);
		if(lineInd >= 5){
			colourContents.push_back(currentLine);
		}
	}	
	std::string finalProduct = "P3\n" + std::to_string(WIDTH) + "\n" + std::to_string(HEIGHT) + "\n" + std::to_string(MAXCOLOUR) + "\n";
	for(int i = 0; i < colourContents.size(); i++){
		std::reverse(colourContents[i].begin(), colourContents[i].end());
		finalProduct += colourContents[i] + '\n';
	}
	ppm << finalProduct;
	ppm.close();
}
