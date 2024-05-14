.onLoad <- function(libname, pkgname) {
    lib_path <- system.file("lib", .Platform$r_arch, paste0("libconnection", .Platform$dynlib.ext), package = "tinyconnection")
    res <- dyn.load(lib_path)

    .Call(tc_init_, res$new_connection$address, res$read_connection$address)
}

.onUnload <- function(libname) {
    lib_path <- system.file("lib", .Platform$r_arch, paste0("libconnection", .Platform$dynlib.ext), package = "tinyconnection")
    dyn.unload(lib_path)
}
