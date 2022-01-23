#include"../libs/editor/Edit.h"

Editor::Editor() {
	setter();
}

void Editor::setter() {
	tags["map"] = std::bind(&Editor::map, this);
	tags["/map"] = std::bind(&Editor::map0, this);
}

Editor::Editor(std::string filename,Game* cor) {
	core = cor;
	fin.open(filename);
	file = filename;
	if (!fin.is_open())
		throw;
	setter();
}

Editor::~Editor() {
	fin.close();
}

void Editor::set_file(std::string filename) {
	file = filename;
	if (!fin.is_open())
		fin.open(file);
	if (!fin.is_open())
		throw;
}

void Editor::read() {
	while (!fin.eof()) {
		char nn;
		fin >> nn;
		std::string f_name;
		fin >> f_name;
		tags[f_name]();
	}
}

void Editor::map0() {
	core->redact = core->redact->prev;
}
void Editor::map() {
	int x, y;
	std::string texturname;
	std::string mapfile;
}