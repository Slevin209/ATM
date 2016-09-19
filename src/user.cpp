#include "user.h"

#include <iostream>
#include <limits>

using std::cin;
using std::cout;

User::User(const string &login, const string &password, double cash, int credit,
           double monthly_payment, int amount_of_credit_month) {
  user_identifier_.SetLogin(login);
  user_identifier_.SetPassword(password);
  cash_operator_.SetCash(cash);
  cash_operator_.SetCredit(credit);
  cash_operator_.SetMonthlyPayment(monthly_payment);
  cash_operator_.SetAmountOfCreditMonth(amount_of_credit_month);
}

void User::Registration() {
  user_messenger_.ShowRegistrationScreen();
  user_messenger_.ShowInitialLoginText();
  user_identifier_.EnterInitialLogin();
  if (!user_identifier_.IsNormalLogin()) {
    error_message_.NoticeAboutIncorrectLoginMessage();
  } else {
    user_messenger_.ShowInitialPasswordText();
    user_identifier_.EnterinitialPassword();
    if (!user_identifier_.IsNormalPass()) {
      error_message_.NoticeAboutIncorrectFormatPasswordMessage();
    } else {
      successful_action_.NoticeAboutSuccessfulRegistration(cash_operator_);
      RunProgramUntilUserWantToExit();
    }
  }
}

void User::RunProgramUntilUserWantToExit() {
  utility_.ClearScreen();
  for (;;) {
    if (RunProgram()) break;
  }
}

bool User::RunProgram() {
  user_messenger_.ShowTransactionMenu();
  return HandleUserChoice(user_input_.GetChoiceFromUser());
}

bool User::HandleUserChoice(int choice) {
  utility_.ClearScreen();

  if (choice == kAccountSection) {
    return ShowAccountInfo();
  } else if (choice == kRefillSection) {
    return RefillOperation();
  } else if (choice == kCreditSection) {
    return CreditApplication();
  } else if (choice == kWidthdrawalSection) {
    return WithdrawCash();
  } else if (choice == kStatementSection) {
    return Statement();
  } else if (choice == kExitSection) {
    user_messenger_.SuggestUserToExit();
    return user_input_.SuggestUserToExitWithConfirmationMenu();
  } else {
    return user_input_.ShowIncorrectMessage();
  }
}

bool User::ShowAccountInfo() {
  return user_messenger_.ShowAccountInformation(user_identifier_,
                                                cash_operator_);
}

bool User::RefillOperation() {
  return refill_.StartRefillOperation(cash_operator_);
}

bool User::CreditApplication() {
  return user_credit_.StartCreditOperation(user_identifier_, cash_operator_,
                                           user_messenger_);
}

bool User::WithdrawCash() {
  return withdrawal_.WithdrawCashFromUser(cash_operator_, user_identifier_);
}

bool User::Statement() { return statement_.ShowStatement(cash_operator_); }
