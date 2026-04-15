#pragma once

#include <fstream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct BinSave {
	string username;
	unsigned int points = 0;
};

class FileManager
{
private:
	static const unsigned short maxRegisters;
	static const string saveFile;
	static void SortLoadedPoints(vector<BinSave>& _ToSort);

public:
	static bool BinSaveSys(BinSave& tmp);
	static bool BinLoadingSys(vector<BinSave>& ALL_RANKINGS);

	FileManager();
	~FileManager();
};