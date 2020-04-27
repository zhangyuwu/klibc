#pragma once

namespace klib {
    class Exception
    {
    private:
        char _buf[256];

    public:
        Exception(const char *msg = nullptr);
        Exception(const Exception& other);
        ~Exception();
        const char *message();
    };

    class ArgumentError : public Exception
    {
    public:
        ArgumentError(const char *msg = nullptr);
    };

    class IndexError : public Exception
    {
    public:
        IndexError(const char *msg = nullptr);
    };

    class NoMemoryError : public Exception
    {
    public:
        NoMemoryError(const char *msg = nullptr);
    };

    class SecurityError : public Exception
    {
    public:
        SecurityError(const char *msg = nullptr);
    };

    class IOError : public Exception
    {
    public:
        IOError(const char *msg = nullptr);
    };

    class EncodingError : public Exception
    {
    public:
        EncodingError(const char *msg = nullptr);
    };

    class RangeError : public Exception
    {
    public:
        RangeError(const char *msg = nullptr);
    };

    class RuntimeError : public Exception
    {
    public:
        RuntimeError(const char *msg = nullptr);
    };
}
