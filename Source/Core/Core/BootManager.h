// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <memory>

struct BootParameters;
struct WindowSystemInfo;

namespace BootManager
{
bool BootCore(std::unique_ptr<BootParameters> parameters, const WindowSystemInfo& wsi);

// Synchronise Dolphin's configuration with the SYSCONF (which may have changed during emulation),
// and restore settings that were overriden by per-game INIs or for some other reason.
void RestoreConfig();
}  // namespace BootManager
