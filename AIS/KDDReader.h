#pragma once
#include "KDDAntigen.h"

#include <string>
#include <fstream>

namespace AIS
{

class KDDReader
{
public:
	typedef std::pair<KDDAntigenPtr, bool> AntigenWithStatus;
	typedef std::vector<AntigenWithStatus> AntigenWithStatusList;

public:
	KDDReader(const std::string& kdd_set_path);
	~KDDReader();

	AntigenWithStatus  read_line();
	AntigenWithStatusList read_chunk(size_t chunk_size);
	AntigenWithStatusList read_all();

	bool eof() const;
private:
	std::ifstream kdd_set_;
};

} // namespace AIS