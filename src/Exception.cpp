
#include <string.h>
#include <stdlib.h>
#include "klib/Exception.h"

namespace klib {
    Exception::Exception(const char * msg)
    {
        if (msg != nullptr) {
            memset(_buf, 0, sizeof(_buf));
            strncpy(_buf, msg, sizeof(_buf));
        }
    }

    Exception::Exception(const Exception & other) : Exception(other._buf)
    {
    }

    Exception::~Exception()
    {
    }

    const char * Exception::message()
    {
        return _buf;
    }

    ArgumentError::ArgumentError(const char * msg) : Exception(msg) {}
    IndexError::IndexError(const char * msg) : Exception(msg) {}
    NoMemoryError::NoMemoryError(const char * msg) : Exception(msg) {}
    SecurityError::SecurityError(const char * msg) : Exception(msg) {}
    IOError::IOError(const char * msg) : Exception(msg) {}
    EncodingError::EncodingError(const char * msg) : Exception(msg) {}
    RangeError::RangeError(const char * msg) : Exception(msg) {}
    RuntimeError::RuntimeError(const char * msg) : Exception(msg) {}
}