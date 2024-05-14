#include "pkg.h"

SEXP new_connection_xptr;

SEXP read_connection_xptr;

void tc_init_(SEXP nc_xptr, SEXP rc_xptr) {
    new_connection_xptr = nc_xptr;
    R_PreserveObject(nc_xptr);
    read_connection_xptr = rc_xptr;
    R_PreserveObject(rc_xptr);
}

SEXP new_connection(const char* description, const char* mode,
                    const char* class_name, Rconnection* ptr) {
    auto new_connection_ptr =
        reinterpret_cast<SEXP (*)(const char*, const char*,
                                  const char*, Rconnection*)>(R_ExternalPtrAddr(new_connection_xptr));
    return new_connection_ptr(description, mode, class_name, ptr);
}
