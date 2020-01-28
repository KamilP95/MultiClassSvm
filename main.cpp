#include "FileDataSource.h"

int main() {
	const char *filePath = "iris.txt";
	MultiClassSvm::FileDataSource dataSource(filePath);

	return 0;
}