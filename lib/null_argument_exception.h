#pragma once

#include "i_exception.h"

namespace sfml_utils::null_argument_exception
{

	struct NullArgumentException : public i_exception::IException
	{
		NullArgumentException();

		~NullArgumentException() override = default;

		const std::stacktrace& Trace() const noexcept override;
		const char* what() const noexcept override;

		std::stacktrace m_StackTrace{};
	};

}
