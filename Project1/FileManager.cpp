#include "FileManager.h"

using namespace std;

const string FileManager::saveFile = "binsave.dat";
const unsigned short FileManager::maxRegisters = 5;

bool FileManager::BinSaveSys(BinSave& SAVE) {
	vector<BinSave> saveRegisters;
	BinLoadingSys(saveRegisters);
	saveRegisters.push_back(SAVE);
	SortLoadedPoints(saveRegisters);

	fstream FileBin;
	FileBin.open(saveFile, ios::binary | ios::out);
	if (!FileBin.is_open()) {
		// The file couldn't be opened, so we return false
		// to let know there was an error, instead of ending the program:
		return false;
	}

	// SAVING SYS ORDER = SAVE NUM OF PLAYERS REGISTERED -> (WRITE POINTS -> WRITE NAME --> REPEAT)

	// Write number of registered players:
	short registeredPlayersNum = saveRegisters.size();
	FileBin.write(reinterpret_cast<char*>(&registeredPlayersNum), sizeof(registeredPlayersNum));

	for (short i = 0; i < saveRegisters.size(); i++)
	{
		// BIN POINTS
		FileBin.write(reinterpret_cast<char*>(&saveRegisters[i].points), sizeof(saveRegisters[i].points));
		// BIN STRNG
		// STRNG SIZE SAVING = STRING-TO-SAVE SIZE
		short NameBinsize = saveRegisters[i].username.size();
		// SAVE STRNG SIZE
		FileBin.write(reinterpret_cast<char*>(&NameBinsize), sizeof(short));
		// SAVE STRNG CHAIN
		FileBin.write(saveRegisters[i].username.c_str(), sizeof(char) * NameBinsize);
	}

	// FILE CLOSED
	FileBin.close();
	return true;
}

bool FileManager::BinLoadingSys(vector<BinSave>& loadedRegisters) {
	fstream FileBin;
	FileBin.open(saveFile, ios::binary | ios::in);
	if (!FileBin.is_open()) {
		// The file couldn't be opened, so we return false
		// to let know there was an error, instead of ending the program:
		return false;
	}

	// The vector will only contain what we give it now:
	loadedRegisters.clear();

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
		loadedRegisters.push_back(tmp);
	}

	FileBin.close();
	return true;
}

void FileManager::SortLoadedPoints(vector<BinSave>& toSort)
{
	int sortSize = toSort.size();

	bool swapped;
	for (int i = 0; i < sortSize - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < sortSize - i - 1; j++)
		{
			if (toSort[j].points < toSort[j + 1].points)
			{
				BinSave tempPoints = toSort[j];
				toSort[j] = toSort[j + 1];
				toSort[j + 1] = tempPoints;
				swapped = true;
			}
		}

		// If the elements weren't swapped break:
		if (!swapped) break;
	}

	// IF SORTED VECTOR HAS MORE THAN 5 REGISTERS DELETE FROM LOWEST DOWNWARDS
	for (size_t i = sortSize - 1; i >= maxRegisters; i--)
		toSort.pop_back();
}

// CONSTRUCTOR / DESTRUCTOR

FileManager::FileManager() {

}

FileManager::~FileManager() {

}