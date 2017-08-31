﻿#include <console_main_menu_presenter.h>

#include <atm_interactor.h>

void ConsoleMainMenuPresenter::RunMainMenu() {
  for (;;) {
    ResetManipulationFlags();

    console_main_menu_.RunMainMenu();

    PerformMenuItem();

    if (user_want_log_out_ || user_want_quit_) {
      break;
    }
  }
}

bool ConsoleMainMenuPresenter::UserWantQuit() const { return user_want_quit_; }

void ConsoleMainMenuPresenter::PerformMenuItem() {
  if (console_main_menu_.UserWantAccountInfo()) {
    account_informer_.SetAccountInfo(AtmInteractor::AccountInfo());
    account_informer_.ShowAccountInfo();
    user_want_quit_ = account_informer_.UserWantQuit();
  }
  if (console_main_menu_.UserWantRefill()) {
    // run item
  }
  if (console_main_menu_.UserWantCredit()) {
    // run item
  }
  if (console_main_menu_.UserWantWithdraw()) {
    // run item
  }
  if (console_main_menu_.UserWantStatement()) {
    // run item
  }
  if (console_main_menu_.UserWantLogOut()) {
    // reset user data?
    console_main_menu_.DisplayLogOutMessage();
    user_want_log_out_ = true;
  }
  if (console_main_menu_.UserWantQuit()) {
    user_want_quit_ = true;
    // run item
  }
}

void ConsoleMainMenuPresenter::ResetManipulationFlags() {
  user_want_log_out_ = false;
  user_want_quit_ = false;
}
