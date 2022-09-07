/**
 * Header file for VIRSA class.
 * 
 * @file VIRSA.h
 */

#ifndef VIRSA_H
#define VIRSA_H

// System includes
#include <cstdint>

class VIRSA
{

public:

    enum Role
    {
        eStreamer = 0,
        eViewer = 1
    };

    /**
     * Constructor for VIRSA.
     * 
     * @param role Role of versa instance.
     */
    VIRSA(Role role);

    /**
     * Destructor for VIRSA.
     */
    ~VIRSA();

private:

    /**
     * Role of the VIRSA application.
     */
    Role role;

};

#endif // VIRSA_H
