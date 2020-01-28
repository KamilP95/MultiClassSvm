#pragma once
#include<vector>

namespace MultiClassSvm {

	class SvmData
	{
	public:
		int Count;
		std::vector<int> Labels;
		std::vector<std::vector<double>> Values;

		SvmData();
		~SvmData();
	};

}
