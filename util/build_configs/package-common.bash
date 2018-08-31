
# Source this to derive and/or sanity-check some common shell variables useful for building a Chapel package

# This expects bash functions log_debug, log_error, etc to be defined
# (see functions.bash and package-functions.bash)

thiscomm=$( basename ${BASH_SOURCE[0]} )
log_debug "Begin $thiscomm"

if [ -n "${verbose:-}" ]; then
    log_info "Using -v (verbose)"
fi
if [ -n "${dry_run:-}" ]; then
    log_info "Using -n (dry-run)"
fi

# Generic Chapel packaging variables
# - meant to be generally applicable to most or all Chapel packaging formats

# CHPL_HOME     : Existing environment variable. The pre-built source+binaries to be "packaged"
# src_version   : "major.minor.update" e.g. 1.17.1  # read from the version.h in $CHPL_HOME;
# major,
#   minor,
#       update  : The numeric fields in src_version # see above
# version_tag   : An optional string like "local_1". If non-null, it will be added to src_version
#                   to create pkg_version. Alphanumeric only. No dashes or periods allowed.
# pkg_version   : $src_version plus $version_tag, plus something else visible in the package name
#                   to distinguish different source snapshots taken from the same branch;
#                   e.g. "1.17.1.20181016" for a nightly build
# release_type  : nightly or release
# chpl_platform : linux64, cray-xc, etc             # as in, $CHPL_HOME/bin/$chpl_platform
# rc_number     : Release candidate number (0,1,2..); something to distinguish different instances of
#                 otherwise-identical packages. May be applied in different ways dep. on package-format.
# date_ymd,
#   date_hms    : date and time for use within the pkg, in YYYYMMDD and HHMMSS

case "${chpl_platform:=}"   in ( "" | *\ * | */* )  log_error "$thiscomm: Invalid chpl_platform='$chpl_platform'";  exit 2;; esac
case "${date_ymd:=}"        in ( "" | *[!0-9]* )    log_error "$thiscomm: Invalid date_ymd='$date_ymd'";            exit 2;; esac
case "${date_hms:=}"        in ( "" | *[!0-9]* )    log_error "$thiscomm: Invalid date_hms='$date_hms'";            exit 2;; esac
case "${rc_number:=0}"      in ( *[!0-9]* )         log_error "$thiscomm: Invalid rc_number='$rc_number'";          exit 2;; esac

ck_chpl_home_bin "$CHPL_HOME" $chpl_platform

case "${src_version:=}" in
( "" | *[!0-9.]* | *.*.*.* | *..* | .* | *. )
    log_error "$thiscomm: Invalid src_version='$src_version'"; exit 2
    ;;
( *.*.* )
    read major minor update junk <<<$( tr '.' ' ' <<<$src_version )
    ;;
( * )
    log_error "$thiscomm: Invalid src_version='$src_version'"; exit 2
    ;;
esac

# version_tag may be null; if non-null, it must not begin with a _ character
case "${version_tag:=}" in
( *[!0-9a-zA-Z_]* | _* | *_ )
    log_error "$thiscomm: Invalid version_tag='$version_tag'"; exit 2
    ;;
esac

case "${release_type:=}" in
( [nN]* | -n | nightly )
    release_type=nightly
    pkg_version=$src_version${version_tag:+_}$version_tag.$date_ymd
    ;;
( [rR]* | -r | release )
    release_type=release
    pkg_version=$src_version${version_tag:+_}$version_tag
    ;;
( * )
    log_error "$thiscomm: Invalid release_type='$release_type'"
    exit 2
    ;;
esac

log_debug "Using chpl_platform='$chpl_platform'"
log_debug "Using src_version='$src_version'"
log_debug "Using version_tag='$version_tag'"
log_debug "Using pkg_version='$pkg_version'"
log_debug "Using release_type='$release_type'"
log_debug "Using rc_number='$rc_number'"
log_debug "Using date_ymd='$date_ymd'"
log_debug "Using date_hms='$date_hms'"

export chpl_platform
export src_version major minor update
export version_tag
export pkg_version
export release_type
export rc_number
export date_ymd
export date_hms

log_debug "End $thiscomm"
