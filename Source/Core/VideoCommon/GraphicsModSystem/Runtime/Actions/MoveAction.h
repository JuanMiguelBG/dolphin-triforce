// Copyright 2022 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <memory>

#include <picojson.h>

#include "VideoCommon/GraphicsModSystem/Runtime/GraphicsModAction.h"

class MoveAction final : public GraphicsModAction
{
public:
  static std::unique_ptr<MoveAction> Create(const picojson::value& json_data);
  explicit MoveAction(Common::Vec3 position_offset);
  void OnProjection(GraphicsModActionData::Projection* projection) override;
  void OnProjectionAndTexture(GraphicsModActionData::Projection* projection) override;

private:
  Common::Vec3 m_position_offset;
};
