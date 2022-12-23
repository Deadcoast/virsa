# VIRSA Dependencies

## Boost 1.78.0

Boost 1.78.0 is required for some items within VIRSA. The library is not tracked through version control due to it's size and binaries that may need to be built.

**Download:** https://www.boost.org/users/history/version_1_78_0.html

## Google Test

Google Test is used for unit testing of VIRSA. The library is tracked with git and should not require any setup.

Google Test will only link to VIRSA when a `Debug` configuration is specified for the build environment.

**Download:** https://github.com/google/googletest/tree/release-1.12.1
