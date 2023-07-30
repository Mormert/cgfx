#include "cSineWave.h"

JLE_EXTERN_TEMPLATE_CEREAL_CPP(cSineWave)

template <class Archive>
void
cSineWave::serialize(Archive &ar)
{
    ar(CEREAL_NVP(_magnitudeY), CEREAL_NVP(_position), CEREAL_NVP(_speed));
}