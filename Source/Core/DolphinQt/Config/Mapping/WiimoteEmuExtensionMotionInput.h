// Copyright 2019 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "DolphinQt/Config/Mapping/MappingWidget.h"

#include "Core/HW/WiimoteEmu/ExtensionPort.h"

class QGroupBox;
class QHBoxLayout;

class WiimoteEmuExtensionMotionInput final : public MappingWidget
{
  Q_OBJECT
public:
  explicit WiimoteEmuExtensionMotionInput(MappingWindow* window);

  InputConfig* GetConfig() override;

private:
  void LoadSettings() override;
  void SaveSettings() override;

  void CreateNunchukLayout();
  void CreateMainLayout();

  // Main
  QHBoxLayout* m_main_layout;
  QGroupBox* m_nunchuk_box;
};
