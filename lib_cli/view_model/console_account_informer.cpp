﻿#include <console_account_informer.h>

#include <account_messenger.h>

#include <console_editor.h>

ConsoleAccountInformer::ConsoleAccountInformer() { FillTitles(); }

void ConsoleAccountInformer::SetAccountInfo(
    const std::vector<std::string>& account_info) {
  account_info_ = account_info;
}

void ConsoleAccountInformer::ShowAccountInfo() {
  ConsoleEditor::ClearScreen();

  for (int i = 0; i < info_title_.size(); ++i) {
    AccountMessenger::DisplayInfoLine(info_title_[i], account_info_[i]);
  }

  ProcessUserInput();
}

bool ConsoleAccountInformer::UserWantMainMenu() const {
  return user_want_to_main_menu_;
}

bool ConsoleAccountInformer::UserWantQuit() const { return user_want_to_quit_; }

void ConsoleAccountInformer::ProcessUserInput() {
  ResetManipulationFlags();

  int user_input = submenu_input_handler_.GetSubMenuInputResult();
  if (user_input == kMainMenu) {
    user_want_to_main_menu_ = true;
  }
  if (user_input == kQuit) {
    user_want_to_quit_ = true;
  }
}

void ConsoleAccountInformer::FillTitles() {
  info_title_.push_back(AccountMessenger::LoginText());
  info_title_.push_back(AccountMessenger::CashText());
  info_title_.push_back(AccountMessenger::CreditText());
  info_title_.push_back(AccountMessenger::PaymentText());
  info_title_.push_back(AccountMessenger::InterestRateText());
  info_title_.push_back(AccountMessenger::CreditTermText());
}

void ConsoleAccountInformer::ResetManipulationFlags() {
  user_want_to_quit_ = false;
  user_want_to_main_menu_ = false;
}
