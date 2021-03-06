#pragma once
#include "BitsArray.h"
#include "Antigen.h"
#include "Detector.h"
#include "DetectorGenerator.h"

#include <vector>

namespace AIS
{
namespace Algorithms
{

/*************************** Distances ***************************/
std::vector<unsigned int> BinaryDistance(const BitsArray& bits_1, const BitsArray& bits_2);
size_t HammingDistance(const BitsArray& bits_1, const BitsArray& bits_2);
double RusselAndRaoDistance(const BitsArray& bits_1, const BitsArray& bits_2);
double JacardAndNeedhamDistance(const BitsArray& bits_1, const BitsArray& bits_2);
double KulzinskiDistance(const BitsArray& bits_1, const BitsArray& bits_2);
double RogersAndTanimotoDistance(const BitsArray& bits_1, const BitsArray& bits_2);
double YuleDistance(const BitsArray& bits_1, const BitsArray& bits_2);
double SokalAndMichenerDistance(const BitsArray& bits_1, const BitsArray& bits_2);


/*************************** Matching Rules ***************************/
bool RContiguousBitsMatchingRule(const BitsArray& d, const BitsArray& x, size_t R);
bool RChunkMatchingRule(const BitsArray& d, const BitsArray& x, size_t p, size_t R);

/*************************** Negative Selection ***************************/
void NegativeSelection(std::vector<DetectorPtr>& detectors, const std::vector<AntigenPtr>& self_antigens);
bool NegativeSelection(DetectorPtr detector, const std::vector<AntigenPtr>& self_antigens);

/*************************** Positive Selection ***************************/
void PositiveSelection(std::vector<DetectorPtr>& detectors, const std::vector<AntigenPtr>& mhc);
bool PositiveSelection(DetectorPtr detector, const std::vector<AntigenPtr>& mhc);

/*************************** Clonal Selection ***************************/
void ClonalSelection(std::vector<DetectorPtr>& detectors, DetectorGeneratorPtr generator, const std::vector<AntigenPtr>& self_antigens);
//void ClonalSelection(std::vector<DetectorPtr>& detectors, const std::vector<AntigenPtr>& self_antigens);

} // namepsace Algorithm
} // namespace AIS