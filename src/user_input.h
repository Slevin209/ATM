#ifndef CORRECT_INPUT_H
#define CORRECT_INPUT_H

#include <string>

#include "notice_about_error.h"
#include "system_utility.h"

class UserInput {
  using string = std::string;

 public:
  UserInput() {}

  bool SuggestUserToExit() const;
  int GetChoiceFromUser() const;
  bool ShowIncorrectMessage() const;
  bool GetResultFromUserAboutExit() const;
  void ShowExitMessage() const;

  bool SuggestUserToExitWithConfirmationMenu();

 private:
  int ConvertLineToChoice(const string &line) const;
  bool LineNotEmpty(const string &str) const;
  string GetLineFromUser() const;

  SystemUtility utility_;
  NoticeAboutError error_message;
};

#endif  // CORRECT_INPUT_H
