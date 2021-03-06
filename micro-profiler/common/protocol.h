#pragma once

#include "primitives.h"

#include <string>
#include <vector>

namespace micro_profiler
{
	enum commands {
		init,
		modules_loaded,
		update_statistics,
		modules_unloaded
	};

	typedef std::pair<std::wstring /* executable */, timestamp_t /* tick_resolution */> initializaion_data;

	typedef std::pair<address_t /* module_address */, std::wstring /* module_path */> module_info;
	typedef std::vector<module_info> loaded_modules;

	typedef std::vector<address_t> unloaded_modules;
}
