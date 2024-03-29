// Copyright 2011 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <string>
#include "VideoCommon/VideoBackendBase.h"

namespace SW
{
class VideoSoftware : public VideoBackendBase
{
  bool Initialize(const WindowSystemInfo& wsi) override;
  void Shutdown() override;

  std::string GetName() const override;
  std::string GetDisplayName() const override;
  std::optional<std::string> GetWarningMessage() const override;

  void InitBackendInfo() override;

  static constexpr const char* NAME = "Software Renderer";
};
}  // namespace SW
