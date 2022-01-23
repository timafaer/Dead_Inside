#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<functional>
#include"../../Header.h"
#include"../Core.h"
class Editor
{
private:
	std::map<std::string, std::function<void()>> tags;
	std::string file;
	std::ifstream fin;
	std::string ignores;
	Game* core;
public:
	Editor();
	Editor(std::string filename,Game* cor);
	~Editor();
	void setter();

	void set_file(std::string filename);
	
	
	void read();

	void map();
	void map0();
	/*
	void layout();
	void object();
	void live();
	void collision();
	*/
};