#include "FileDataSource.h"
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace MultiClassSvm {

	FileDataSource::FileDataSource(const char* filePath, char dataSeparator, int indexOfLabel)
	{
		std::fstream file;
		std::string line;

		file.open(filePath);

		while (std::getline(file, line))
		{
			if (dataSeparator != ' ') 
			{
				std::replace(line.begin(), line.end(), dataSeparator, ' ');
			}

			std::vector<double> values;
			std::stringstream stringStream(line);
			double tmp;

			while (stringStream >> tmp)
			{
				values.push_back(tmp);
			}

			this->data.Labels.push_back((int)values[indexOfLabel]);
			
			values.erase(values.begin() + indexOfLabel);
			values.shrink_to_fit();

			this->data.Values.push_back(values);
		}

		this->data.Labels.shrink_to_fit();
		this->data.Values.shrink_to_fit();
		this->data.Count = this->data.Labels.size();
	}


	FileDataSource::~FileDataSource()
	{
	}

	SvmData FileDataSource::GetData()
	{
		return this->data;
	}

}