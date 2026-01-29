#pragma once

#include <memory>
#include <vector>

#include "SFML/Window/VideoMode.hpp"

namespace sfml_utils::window
{

	struct IVideoModeProvider
	{
		virtual ~IVideoModeProvider() = default;
		virtual sf::VideoMode GetDesktopMode() const = 0;
		virtual const std::vector<sf::VideoMode>& GetFullscreenModes() const = 0;

	};

	using IVideoModeProviderPtr = std::unique_ptr<IVideoModeProvider>;
	IVideoModeProviderPtr CreateVideoModeProvider();

}
