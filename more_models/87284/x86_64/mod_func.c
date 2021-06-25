#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _cacumm_reg(void);
extern void _cagk_reg(void);
extern void _cal2_reg(void);
extern void _can2_reg(void);
extern void _cat_reg(void);
extern void _distr_reg(void);
extern void _h_reg(void);
extern void _ipulse2_reg(void);
extern void _kadist_reg(void);
extern void _kaprox_reg(void);
extern void _kdrca1_reg(void);
extern void _na3n_reg(void);
extern void _naxn_reg(void);
extern void _zcaquant_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," \"cacumm.mod\"");
    fprintf(stderr," \"cagk.mod\"");
    fprintf(stderr," \"cal2.mod\"");
    fprintf(stderr," \"can2.mod\"");
    fprintf(stderr," \"cat.mod\"");
    fprintf(stderr," \"distr.mod\"");
    fprintf(stderr," \"h.mod\"");
    fprintf(stderr," \"ipulse2.mod\"");
    fprintf(stderr," \"kadist.mod\"");
    fprintf(stderr," \"kaprox.mod\"");
    fprintf(stderr," \"kdrca1.mod\"");
    fprintf(stderr," \"na3n.mod\"");
    fprintf(stderr," \"naxn.mod\"");
    fprintf(stderr," \"zcaquant.mod\"");
    fprintf(stderr, "\n");
  }
  _cacumm_reg();
  _cagk_reg();
  _cal2_reg();
  _can2_reg();
  _cat_reg();
  _distr_reg();
  _h_reg();
  _ipulse2_reg();
  _kadist_reg();
  _kaprox_reg();
  _kdrca1_reg();
  _na3n_reg();
  _naxn_reg();
  _zcaquant_reg();
}
