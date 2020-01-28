#pragma once
#include "DataSource.h"

namespace MultiClassSvm {

	class FileDataSource : DataSource
	{
	private:
		SvmData data;

	public:
		FileDataSource(char* filePath, char dataSeparator = ' ', int indexOfLabel = 0);
		~FileDataSource();

		SvmData GetData();
	};

}