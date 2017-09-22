﻿#include <console_main_menu_presenter.h>

#include <atm_interactor.h>

#include <cash_operation_validator.h>
#include <console_account_menu.h>
#include <console_credit_presenter.h>
#include <console_refill_menu.h>
#include <console_statement_menu.h>
#include <console_withdrawal_presenter.h>

void ConsoleMainMenuPresenter::RunMainMenu() {
  for (;;) {
    ResetManipulationFlags();

    console_main_menu_.RunMainMenu();

    PerformMenuItem();

    if (user_want_log_out_ || user_want_quit_) {
      if (user_want_log_out_) {
        AtmInteractor::ResetData();
      }
      break;
    }
  }
}

bool ConsoleMainMenuPresenter::UserWantQuit() const { return user_want_quit_; }

void ConsoleMainMenuPresenter::PerformMenuItem() {
  if (console_main_menu_.UserWantAccountInfo()) {
    RunAccountMenu();
  }
  if (console_main_menu_.UserWantRefill()) {
    RunRefillMenu();
  }
  if (console_main_menu_.UserWantCredit()) {
    RunCreditMenu();
  }
  if (console_main_menu_.UserWantWithdraw()) {
    RunWithdrawalPresenter();
  }
  if (console_main_menu_.UserWantStatement()) {
    RunStatementMenu();
  }
  if (console_main_menu_.UserWantLogOut()) {
    console_main_menu_.DisplayLogOutMessage();
    user_want_log_out_ = true;
  }
  if (console_main_menu_.UserWantQuit()) {
    user_want_quit_ = true;
  }
}

void ConsoleMainMenuPresenter::RunAccountMenu() {
  ConsoleAccountMenu console_account_menu_;
  console_account_menu_.SetAccountInfo(AtmInteractor::AccountInfo());
  console_account_menu_.ShowAccountInfo();
  user_want_quit_ = console_account_menu_.UserWantQuit();
}

void ConsoleMainMenuPresenter::RunRefillMenu() {
  ConsoleRefillMenu refill_menu;
  refill_menu.RunRefillMenu();

  if (CashOperationValidator::IsRefillingCorrect(refill_menu.SumOfCash())) {
    AtmInteractor::RefillCash(refill_menu.SumOfCash());
    refill_menu.ShowCorrectRefillingNotification();
  } else if (refill_menu.UserWantMainMenu()) {
    refill_menu.ShowMainMenuQuit();
  } else if (refill_menu.UserWantQuit()) {
    user_want_quit_ = true;
  } else {
    refill_menu.ShowIncorrectRefillingNotification();
  }
}

void ConsoleMainMenuPresenter::RunCreditMenu() {
  ConsoleCreditPresenter console_credit_presenter;
  console_credit_presenter.RunCreditMenu();
  user_want_quit_ = console_credit_presenter.UserWantQuit();
}

void ConsoleMainMenuPresenter::RunWithdrawalPresenter() {
  ConsoleWithdrawalPresenter withdrawal_presenter;
  withdrawal_presenter.RunWithdrawalMenu();
  user_want_quit_ = withdrawal_presenter.UserWantQuit();
}

void ConsoleMainMenuPresenter::RunStatementMenu() {
  ConsoleStatementMenu statement_menu;
  statement_menu.RunStatement(AtmInteractor::Cash());
  user_want_quit_ = statement_menu.UserWantQuit();
}

void ConsoleMainMenuPresenter::ResetManipulationFlags() {
  user_want_log_out_ = false;
  user_want_quit_ = false;
}
