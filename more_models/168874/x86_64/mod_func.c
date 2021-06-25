#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _cagk_reg(void);
extern void _cal_mig_reg(void);
extern void _can_mig_reg(void);
extern void _cat_mig_reg(void);
extern void _kaprox_reg(void);
extern void _kdrca1_reg(void);
extern void _km_reg(void);
extern void _misc_reg(void);
extern void _na3n_reg(void);
extern void _naf_reg(void);
extern void _NMDA_reg(void);
extern void _stats_reg(void);
extern void _vecst_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," \"cagk.mod\"");
    fprintf(stderr," \"cal_mig.mod\"");
    fprintf(stderr," \"can_mig.mod\"");
    fprintf(stderr," \"cat_mig.mod\"");
    fprintf(stderr," \"kaprox.mod\"");
    fprintf(stderr," \"kdrca1.mod\"");
    fprintf(stderr," \"km.mod\"");
    fprintf(stderr," \"misc.mod\"");
    fprintf(stderr," \"na3n.mod\"");
    fprintf(stderr," \"naf.mod\"");
    fprintf(stderr," \"NMDA.mod\"");
    fprintf(stderr," \"stats.mod\"");
    fprintf(stderr," \"vecst.mod\"");
    fprintf(stderr, "\n");
  }
  _cagk_reg();
  _cal_mig_reg();
  _can_mig_reg();
  _cat_mig_reg();
  _kaprox_reg();
  _kdrca1_reg();
  _km_reg();
  _misc_reg();
  _na3n_reg();
  _naf_reg();
  _NMDA_reg();
  _stats_reg();
  _vecst_reg();
}
