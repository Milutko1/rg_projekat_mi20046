#include <engine/core/Engine.hpp>
#include <memory>
#include <spdlog/spdlog.h>

class MainController : public engine::core::Controller {
protected:
    void initialize() override {
        engine::graphics::OpenGL::enable_depth_testing();
    }
};

class MyApp : public engine::core::App {

public:
    void app_setup() override;
};

void MyApp::app_setup() {
    auto main_controller = register_controller<MainController>();
    main_controller->after(
            engine::core::Controller::get<engine::core::EngineControllersEnd>());
    spdlog::info("Hello, setup!");
}

int main(int argc, char **argv) {
    return std::make_unique<MyApp>()->run(argc, argv);
}
