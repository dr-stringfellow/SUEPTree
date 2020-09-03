#ifndef SUEPTree_Objects_PackingHelper_h
#define SUEPTree_Objects_PackingHelper_h

#include "Rtypes.h"

namespace suep {

  class PackingHelper {
  public:
    PackingHelper();

    static PackingHelper const& singleton() { static PackingHelper helper; return helper; }

    static UShort_t packUnbound(Double_t);
    static Double_t unpackUnbound(UShort_t);
    static Char_t pack8LogBound(Double_t, Double_t min, Double_t max, UChar_t baseminus1);
    static Double_t unpack8LogBound(Char_t, Double_t min, Double_t max, UChar_t baseminus1);

  private:
    UInt_t mantissatable[2048];
    UInt_t exponenttable[64];
    UShort_t offsettable[64];
    UShort_t basetable[512];
    UChar_t shifttable[512];
  };

}

#endif
