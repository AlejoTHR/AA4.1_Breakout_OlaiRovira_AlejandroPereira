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
	static void BinSaveSys(BinSave& tmp);
	static void BinLoadingSys(vector<BinSave>& ALL_RANKINGS);
	static vector<BinSave> SortLoadedPoints(vector<BinSave>& _ToSort);

	FileManager();
	~FileManager();
};