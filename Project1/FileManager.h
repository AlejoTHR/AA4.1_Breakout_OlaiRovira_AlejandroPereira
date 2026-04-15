#pragma once

#include <fstream>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

struct BinSave {
	string username;
	unsigned int points;
};

class FileManager
{
private:
	static const string saveFile;
public:
	static bool BinSaveSys(BinSave& tmp);
	static bool BinLoadingSys(vector<BinSave>& ALL_RANKINGS);

	FileManager();
	~FileManager();

private:
	stack<BinSave> SortLoadedPoints(vector<BinSave>& _ToSort);
};