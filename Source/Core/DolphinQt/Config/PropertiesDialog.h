// Copyright 2016 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <QDialog>

namespace UICommon
{
class GameFile;
}

class PropertiesDialog final : public QDialog
{
  Q_OBJECT
public:
  explicit PropertiesDialog(QWidget* parent, const UICommon::GameFile& game);

signals:
  void OpenGeneralSettings();
  void OpenGraphicsSettings();
};
