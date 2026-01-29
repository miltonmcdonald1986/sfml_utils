#include "pch.h"
#include "null_argument_exception.h"

namespace sfml_utils::null_argument_exception
{

	NullArgumentException::NullArgumentException()
		: m_StackTrace(std::stacktrace::current())
	{
	}

	const std::stacktrace& NullArgumentException::Trace() const noexcept
	{
		return m_StackTrace;
	}

	const char* NullArgumentException::what() const noexcept
	{
		return "A null argument was provided where a non-null argument was expected.";
	}

}
