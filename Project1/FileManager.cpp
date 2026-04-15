#include "FileManager.h"

using namespace std;

const string FileManager::saveFile = "binsave.dat";

void FileManager::BinSaveSys(BinSave& SAVE) {
	vector<BinSave> actualSavesFile;
	BinLoadingSys(actualSavesFile);
	actualSavesFile.push_back(SAVE);

	fstream FileBin;
	FileBin.open(saveFile, ios::binary | ios::out);
	if (!FileBin.is_open()) {
		exit(15);
	}

	// SAVING SYS ORDER = SAVE NUM OF PLAYERS REGISTERED -> (WRITE POINTS -> WRITE NAME --> REPEAT)

	// Write number of registered players:
	short registeredPlayersNum = actualSavesFile.size();
	FileBin.write(reinterpret_cast<char*>(&registeredPlayersNum), sizeof(registeredPlayersNum));

	for (short i = 0; i < actualSavesFile.size(); i++)
	{
		// BIN POINTS
		FileBin.write(reinterpret_cast<char*>(&actualSavesFile[i].points), sizeof(actualSavesFile[i].points));
		// BIN STRNG
		// STRNG SIZE SAVING = STRING-TO-SAVE SIZE
		short NameBinsize = actualSavesFile[i].username.size();
		// SAVE STRNG SIZE
		FileBin.write(reinterpret_cast<char*>(&NameBinsize), sizeof(short));
		// SAVE STRNG CHAIN
		FileBin.write(actualSavesFile[i].username.c_str(), sizeof(char) * NameBinsize);
	}

	// FILE CLOSED
	FileBin.close();

	// FEEDBACK, EVERYTHING OK :D
	cout << "\t\t  SAVED" << endl << endl;
}

void FileManager::BinLoadingSys(vector<BinSave>& ALL_RANKINGS) {
	cout << "Now Loading..." << endl << endl; // FEEDBACK

	fstream FileBin;
	FileBin.open(saveFile, ios::binary | ios::in);
	if (!FileBin.is_open()) {
		exit(15);
	}

	// Read number of registered players:
	short registeredPlayersNum;
	FileBin.read(reinterpret_cast<char*>(&registeredPlayersNum), sizeof(short));

	for (short i = 0; i < registeredPlayersNum; i++)
	{
		////// PLAYER DATA READING PROCESS::
		BinSave tmp;
		// READ POINTS
		FileBin.read(reinterpret_cast<char*>(&tmp.points), sizeof(tmp.points));
		short NameBinsize;
		// READ STRNG SIZE
		FileBin.read(reinterpret_cast<char*>(&NameBinsize), sizeof(short));
		tmp.username.resize(NameBinsize);
		// STRNG SIZE RE-SIZE FOR LOADING
		FileBin.read(&tmp.username[0], sizeof(char) * NameBinsize);
		// LAST "END" CAHRACTER OF THE STRNG STRUCTURE
		tmp.username += '\0';
		ALL_RANKINGS.push_back(tmp);
	}

	FileBin.close();
	cout << "LOADED" << endl << endl;
}

vector<BinSave> FileManager::SortLoadedPoints(vector<BinSave>& _ToSort)
{
	int sortSize = _ToSort.size();
	int TMPSort;

	for (int i = 0; i < sortSize - 1; i++)
	{
		for (int j = 0; j < sortSize - i - 1; j++)
		{
			if (_ToSort[j].points < _ToSort[j + 1].points)
			{
				TMPSort = _ToSort[j].points;
				_ToSort[j].points = _ToSort[j + 1].points;
				_ToSort[j + 1].points = TMPSort;
			}
		}
	}

	return _ToSort;
}

// CONSTRUCTOR / DESTRUCTOR

FileManager::FileManager() {

}

FileManager::~FileManager() {

}