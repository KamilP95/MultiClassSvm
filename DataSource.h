#pragma once
#include "SvmData.h"

namespace MultiClassSvm {
	class DataSource {
	public:
		virtual SvmData GetData() = 0;
	};
}
