#pragma once

#include "i_video_mode_provider.h"

namespace sfml_utils::sfml_video_mode_provider
{

	struct SFMLVideoModeProvider : public i_video_mode_provider::IVideoModeProvider
	{
		~SFMLVideoModeProvider() override = default;
		sf::VideoMode GetDesktopMode() const override;
		const std::vector<sf::VideoMode>& GetFullscreenModes() const override;
	};

}
