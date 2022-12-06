# VIRSA Dependencies

## Boost 1.78.0

VIRSA uses boost to outsource minor functionality. Boost can be downloaded [here](https://www.boost.org/users/history/version_1_78_0.html).

### Building Boost on Windows

To build Boost on Windows:

1. Run the `bootstrap.bat` script to configure boost to your environment

2. Run the follwoing command depending on your target environment.

    ```cmd
    .\b2 toolset=msvc variant=release link=static threading=multi runtime-link=static
    ```

## Google Test

Google Test is used for unit testing of VIRSA. The library is tracked with git and should not require any setup.

Google Test will only link to VIRSA when a `debug` configuration is specified for the build environment.
