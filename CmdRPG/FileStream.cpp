#include "FileStream.h"

vector<string>* FileStream::GetStringFileData(string filePath)
{
	ifstream stream(filePath);

	if (stream.is_open() == false)
		return NULL;

	string strData;
	vector<string>* dataList = new vector<string>();

	while (getline(stream, strData)) 
	{
		dataList->push_back(strData);
	}
	return dataList;
}