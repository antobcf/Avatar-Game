#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <stdexcept>

class Eccezioni : public std::runtime_error {
public:
    Eccezioni();
};

#endif // ECCEZIONI_H
