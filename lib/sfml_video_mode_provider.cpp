#include "pch.h"
#include "sfml_video_mode_provider.h"

using sfml_utils::i_video_mode_provider::IVideoModeProviderPtr;

namespace sfml_utils::sfml_video_mode_provider
{

	sf::VideoMode SFMLVideoModeProvider::GetDesktopMode() const
	{
		return sf::VideoMode::getDesktopMode();
	}

	const std::vector<sf::VideoMode>& SFMLVideoModeProvider::GetFullscreenModes() const
	{
		return sf::VideoMode::getFullscreenModes();
	}

}

namespace sfml_utils::i_video_mode_provider
{

	IVideoModeProviderPtr CreateVideoModeProvider()
	{
		return std::make_unique<sfml_video_mode_provider::SFMLVideoModeProvider>();
	}

}
