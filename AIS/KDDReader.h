#pragma once
#include "KDDAntigen.h"

#include <string>
#include <fstream>

namespace AIS
{

class KDDReader
{
public:
	KDDReader(const std::string& kdd_set_path);
	~KDDReader();

	std::vector<std::pair<KDDAntigenPtr, bool>> read_chunk(size_t chunk_size);
	std::vector<std::pair<KDDAntigenPtr, bool>> read_all();

	bool eof() const;
private:
	std::ifstream kdd_set_;
};

} // namespace AIS