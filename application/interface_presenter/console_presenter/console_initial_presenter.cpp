﻿#include <console_initial_presenter.h>

#include <description_messenger.h>

void ConsoleInitialPresenter::RunApplication() {
  initial_menu_.RunSplashScreen();

  for (;;) {
    initial_menu_.RunInitialMenu();
    RunSubMenu(initial_menu_.GetSubMenu());

    if (user_want_to_quit_) {
      break;
    }
  }

  initial_menu_.DisplayFarewellMessage();
}

void ConsoleInitialPresenter::RunSubMenu(ConsoleInitialMenu::SubMenu sub_menu) {
  switch (sub_menu) {
    case ConsoleInitialMenu::kLoginMenu:
      RunLoginMenu();
      break;
    case ConsoleInitialMenu::kRegistrationMenu:
      RunRegistrationMenu();
      break;
    case ConsoleInitialMenu::kDescription:
      ShowDescription();
      break;
    case ConsoleInitialMenu::kQuit:
      user_want_to_quit_ = true;
      break;
    default:
      break;
  }
}

void ConsoleInitialPresenter::RunLoginMenu() { login_menu_.RunLoginMenu(); }

void ConsoleInitialPresenter::ShowDescription() {
  DescriptionMessenger::ShowDescription();
}

void ConsoleInitialPresenter::RunRegistrationMenu() {
  registration_presenter_.RunRegistrationMenu();
  user_want_to_quit_ = registration_presenter_.UserWantQuit();
}
