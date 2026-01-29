#pragma once

#include <optional>

#include "i_video_mode_provider.h"

namespace sfml_utils::window
{

	/**
	 * @brief Return the desktop video mode scaled by scaleFactor.
	 *
	 * @param upVideoModeProvider Provider for the desktop mode (must be non-null).
	 * @param scaleFactor Scale factor applied to width and height (> 0).
	 * @param pixelDepth Optional bits-per-pixel for the returned mode.
	 * @return sf::VideoMode Scaled video mode.
	 */
	sf::VideoMode ScaledDesktopMode(IVideoModeProviderPtr upVideoModeProvider, double scaleFactor, std::optional<unsigned int> pixelDepth = std::nullopt);

}
