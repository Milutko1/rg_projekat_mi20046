#include "MyApp.hpp"
#include "GuiController.hpp"
#include "MainController.hpp"

#include <spdlog/spdlog.h>

void MyApp::app_setup() {
    auto main_controller = register_controller<MainController>();
    main_controller->after(engine::core::Controller::get<engine::core::EngineControllersEnd>());
    auto gui_controller = register_controller<GuiController>();
    gui_controller->after(main_controller);
    spdlog::info("Hello, setup!");
}