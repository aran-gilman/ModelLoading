#pragma once

#include <glm/glm.hpp>

namespace constants
{
	namespace vec3
	{
		inline constexpr glm::vec3 Right{ 1.0f, 0.0f, 0.0f };
		inline constexpr glm::vec3 Left{ -1.0f, 0.0f, 0.0f };
		inline constexpr glm::vec3 Up{ 0.0f, 1.0f, 0.0f };
		inline constexpr glm::vec3 Down{ 0.0f, -1.0f, 0.0f };
		inline constexpr glm::vec3 Forward{ 0.0f, 0.0f, 1.0f };
		inline constexpr glm::vec3 Back{ 0.0f, 0.0f, -1.0f };

		inline constexpr glm::vec3 Zero{ 0.0f, 0.0f, 0.0f };
		inline constexpr glm::vec3 One{ 1.0f, 1.0f, 1.0f };
	}
}

