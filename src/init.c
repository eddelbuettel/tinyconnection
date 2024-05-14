
#include <R.h>
#include <Rinternals.h>

extern SEXP vfile_(SEXP description_, SEXP mode_, SEXP verbosity_);
extern SEXP tc_init_(SEXP, SEXP);

static const R_CallMethodDef CEntries[] = {
    {"vfile_",   (DL_FUNC) &vfile_,   3},
    {"tc_init_", (DL_FUNC) &tc_init_, 2},
    {NULL, NULL, 0}
};

void R_init_tinyconnection(DllInfo *info) {
    R_registerRoutines(info,      // DllInfo
                       NULL,      // .C
                       CEntries,  // .Call
                       NULL,      // Fortran
                       NULL);     // External
    R_useDynamicSymbols(info, FALSE);
    R_forceSymbols(info, TRUE);
}
