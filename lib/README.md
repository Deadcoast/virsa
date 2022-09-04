# VIRSA Dependencies

## Boost 1.80.0

Boost 1.80.0 is required for some items within VIRSA. The library is not tracked through version control due to it's size and binaries that may need to be built.

Boost can be downloaded [here](https://www.boost.org/users/history/version_1_80_0.html).

## Google Test

Google Test is used for unit testing of VIRSA. The library is tracked with git and should not require any setup.

Google Test will only link to VIRSA when a `debug` configuration is specified for the build environment.
