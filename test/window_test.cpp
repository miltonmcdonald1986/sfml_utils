#include "pch.h"

#include "sfml_utils/i_exception.h"
#include "sfml_utils/i_video_mode_provider.h"
#include "sfml_utils/window.h"

using sfml_utils::i_exception::IException;
using sfml_utils::i_video_mode_provider::IVideoModeProvider;
using sfml_utils::window::ScaledDesktopMode;

struct MockVideoModeProvider : public IVideoModeProvider
{
	~MockVideoModeProvider() override = default;
	
	sf::VideoMode GetDesktopMode() const override
	{
		return sf::VideoMode(sf::Vector2u(1920, 1080), 32);
	}

	const std::vector<sf::VideoMode>& GetFullscreenModes() const override
	{
		return {};
	}
};

namespace test::window
{

	TEST(ScaledDesktopMode, NullVideoModeProvider)
	{
		ASSERT_THROW(ScaledDesktopMode(nullptr, 0.75), IException) << "Expected ScaledDesktopMode to throw when provided a null IVideoModeProviderPtr.";
	}

	TEST(ScaledDesktopMode, ValidParameters)
	{
		auto videoModeProvider = std::make_unique<MockVideoModeProvider>();
		double scaleFactor = 0.5;
		unsigned int pixelDepth = 24;
		sf::VideoMode scaledMode = ScaledDesktopMode(std::move(videoModeProvider), scaleFactor, pixelDepth);
		EXPECT_EQ(scaledMode.size.x, 960) << "Scaled width is incorrect.";
		EXPECT_EQ(scaledMode.size.y, 540) << "Scaled height is incorrect.";
		EXPECT_EQ(scaledMode.bitsPerPixel, pixelDepth) << "Pixel depth is incorrect.";
	}

}
