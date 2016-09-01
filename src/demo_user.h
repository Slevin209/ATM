#ifndef DEMO_USER_H
#define DEMO_USER_H

#include <string>

#include "user_input.h"
#include "messanger.h"



class DemoUser {
  using string = std::string;

 public:
  void ShowDemoMode();
  bool UserWantToRegistrate() const;
  bool UserWantToExitProgram() const;

 private:
  bool UserDecideToExit();

  bool DemoAccountInfo() const;
  bool DemoRefill() const;
  bool DemoCreditApp() const;
  bool DemoWidthdrawal() const;
  bool DemoStatement() const;

  bool StartRegistration();
  bool user_want_to_registrate_ = false;
  UserInput user_input_;
  Messanger demo_statement_;
};

#endif  // DEMO_USER_H
