#pragma once
#include "KDDAntigen.h"

namespace AIS
{
namespace Utilities
{

std::vector< std::pair<KDDAntigenPtr, bool /* is Normal */> > KDDRead(const std::string& csv_file_path);

} // namespace Algorihtm
} // namespace AIS