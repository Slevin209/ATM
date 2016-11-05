#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

// atm_operations folder
#include "account_informator.h"
#include "refill.h"
#include "user_credit.h"
#include "user_statement.h"
#include "withdrawal.h"

// demo_mode folder
#include "demo_user.h"

// user folder
#include "user_messenger.h"
#include "user_registrator.h"



class InitialMenu {
 public:
  void RunMenu();

 private:
  enum ProgramMode {
    kDemoMode = 1,
    kRegistration,
  };

  enum MenuSection {
    kAccountSection = 1,
    kRefillSection,
    kCreditSection,
    kWidthdrawalSection,
    kStatementSection,
    kExitSection,
  };

  void RegisterUser();
  void StartMainMenu();
  void DoProgramSection(int choice);
  void DisplayMenu();

  void ShowAccountInfo();
  void RefillOperation();
  void CreditApplication();
  void WithdrawCash();
  void Statement();

  bool is_user_want_to_exit_ = true;

  UserIdentifier user_identifier_;
  CashOperator cash_operator_;
  Refill refill_;
  UserCredit user_credit_;
  Withdrawal withdrawal_;
  UserStatement statement_;
  UserMessenger user_messenger_;
  UserRegistrator registrator_;
  DemoUser demo_mode_;
  AccountInformator account_informator_;
  UserInput user_input_;
};

#endif  // INITIAL_MENU_H
