#include "registration_messenger.h"

#include <iostream>

void RegistrationMessenger::ShowRegistrationScreen() const {
  utility_.ClearScreen();
  std::cout << "\n\t\t   ********************\n"
               "\t\t   *   REGISTRATION   *\n"
               "\t\t   ********************\n";
}
