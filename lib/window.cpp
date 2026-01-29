#include "pch.h"

#include "null_argument_exception.h"
#include "window.h"

using sfml_utils::null_argument_exception::NullArgumentException;

namespace sfml_utils::window
{

    sf::VideoMode ScaledDesktopMode(i_video_mode_provider::IVideoModeProviderPtr upVideoModeProvider, double scaleFactor, std::optional<unsigned int> pixelDepth)
    {
        if (!upVideoModeProvider)
            throw NullArgumentException();

        const sf::VideoMode desktopMode = upVideoModeProvider->GetDesktopMode();
        const sf::Vector2u desktopSize = desktopMode.size;
        const double scaledDesktopWidth = scaleFactor * desktopSize.x;
        const double scaledDesktopHeight = scaleFactor * desktopSize.y;
        const unsigned int width = static_cast<unsigned int>(scaledDesktopWidth);
        const unsigned int height = static_cast<unsigned int>(scaledDesktopHeight);
        const sf::Vector2u newSize(width, height);
        return sf::VideoMode(newSize, pixelDepth.value_or(32U));
    }

}
