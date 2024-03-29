// Copyright 2017 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <map>
#include <string>
#include <vector>

#include <QDialog>

class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QProgressBar;
class QVBoxLayout;
class QWidget;

class GameDigestDialog : public QDialog
{
  Q_OBJECT
public:
  explicit GameDigestDialog(QWidget* parent);

  void show(const QString& title);
  void SetProgress(int pid, int progress);
  void SetResult(int pid, const std::string& result);

  void reject() override;

private:
  void CreateWidgets();
  void ConnectWidgets();

  std::map<int, QProgressBar*> m_progress_bars;
  std::map<int, QLabel*> m_status_labels;

  std::vector<std::string> m_results;

  QGroupBox* m_progress_box;
  QVBoxLayout* m_progress_layout;
  QVBoxLayout* m_main_layout;
  QLabel* m_check_label;
  QDialogButtonBox* m_button_box;
};
