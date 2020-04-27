#pragma once

namespace klib {
    template <typename T> class RefPtr
    {
    private:
        T * _ptr;
        int * _ref_count;
        bool _is_array;

        void release()
        {
            if (--(*_ref_count) == 0) {
                if (_ptr != nullptr) {
                    if (_is_array) {
                        delete[] _ptr;
                    }
                    else {
                        delete _ptr;
                    }
                }
                delete _ref_count;
            }
        }

        void assign(const RefPtr & other)
        {
            _ptr = other._ptr;
            _ref_count = other._ref_count;
            _is_array = other._is_array;
            (*_ref_count)++;
        }

    public:
        RefPtr() : RefPtr(nullptr, false)
        {
        }

        RefPtr(T * ptr, bool is_array = false)
        {
            _ptr = ptr;
            _ref_count = new int(1);
            _is_array = is_array;
        }

        RefPtr(const RefPtr & other)
        {
            assign(other);
        }

        ~RefPtr()
        {
            release();
        }

        RefPtr & operator = (const RefPtr & other)
        {
            release();
            assign(other);
            return *this;
        }

        T * operator ->()
        {
            return _ptr;
        }

        const T * operator ->() const
        {
            return _ptr;
        }

        T * ptr()
        {
            return _ptr;
        }

        const T * ptr() const
        {
            return _ptr;
        }

        int ref_count()
        {
            return *_ref_count;
        }
    };
}