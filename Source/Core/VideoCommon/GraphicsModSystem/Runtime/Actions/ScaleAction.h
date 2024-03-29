// Copyright 2022 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <memory>

#include <picojson.h>

#include "VideoCommon/GraphicsModSystem/Runtime/GraphicsModAction.h"

class ScaleAction final : public GraphicsModAction
{
public:
  static std::unique_ptr<ScaleAction> Create(const picojson::value& json_data);
  explicit ScaleAction(Common::Vec3 scale);
  void OnEFB(GraphicsModActionData::EFB*) override;
  void OnProjection(GraphicsModActionData::Projection*) override;
  void OnProjectionAndTexture(GraphicsModActionData::Projection*) override;

private:
  Common::Vec3 m_scale;
};
