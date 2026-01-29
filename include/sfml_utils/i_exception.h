#pragma once

#include <exception>
#include <stacktrace>

namespace sfml_utils::i_exception
{

    struct IException : public std::exception {
        virtual ~IException() = default;
        virtual const std::stacktrace& Trace() const noexcept = 0;
        virtual const char* what() const noexcept = 0;
    };

}
