#include "application.h"

void Application::RunProgram() {
  int user_choice = user_input_.GetChoiceFromUser();

  if (user_choice == kDemoMode) {
    demo_mode_.ShowDemoMode();
    if (demo_mode_.UserWantToRegistrate()) {
      RegisterUser();
    }
  } else if (user_choice == kRegistration) {
    RegisterUser();
  } else {
    user_messenger_.ShowIncorrectRegisterData();
  }

  if (registrator_.IsCorrectRegistration()) {
    DisplayMenu();
  }
  user_messenger_.WishAGoodDay();
}

void Application::RegisterUser() {
  registrator_.RegisterUser(cash_operator_, user_identifier_);
}

void Application::DisplayMenu() {
  do {
    StartMainMenu();
  } while (!is_user_want_to_exit_);
}

void Application::StartMainMenu() {
  utility_.ClearScreen();
  user_messenger_.ShowMainMenu();
  DoProgramSection(user_input_.GetChoiceFromUser());
}

void Application::DoProgramSection(int choice) {
  utility_.ClearScreen();

  if (choice == kAccountSection) {
    ShowAccountInfo();
  } else if (choice == kRefillSection) {
    RefillOperation();
  } else if (choice == kCreditSection) {
    CreditApplication();
  } else if (choice == kWidthdrawalSection) {
    WithdrawCash();
  } else if (choice == kStatementSection) {
    Statement();
  } else if (choice == kExitSection) {
    // TODO
    // где еще используется метод объекта user_input?
    // если такого места нет, то вставить мессенджер туда.
    // избавить класс от это мессенджера.
    user_messenger_.SuggestUserToExit();
    is_user_want_to_exit_ = user_input_.SuggestUserToExitWithConfirmationMenu();
  } else {
    is_user_want_to_exit_ = user_input_.ShowIncorrectMessage();
  }
}

void Application::ShowAccountInfo() {
  account_informator_.DisplayAccountInformation(user_identifier_,
                                                cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::RefillOperation() {
  refill_.StartRefillOperation(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::CreditApplication() {
  user_credit_.StartCreditOperation(user_identifier_, cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(cash_operator_, user_identifier_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::Statement() {
  statement_.ShowStatement(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}
