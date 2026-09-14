#include <engine/core/Engine.hpp>
#include <memory>
#include <spdlog/spdlog.h>

class MainController : public engine::core::Controller {
protected:
    void initialize() override {
        engine::graphics::OpenGL::enable_depth_testing();
    }
    void begin_draw() override {
        engine::graphics::OpenGL::clear_buffers();
    }
    void draw() override {
        auto resources = engine::core::Controller::get<engine::resources::ResourcesController>();
        auto shader = resources->shader("basketball");
        auto basketball = resources->model("basketball");
        basketball->draw(shader);
    }
    void end_draw() override {
        engine::core::Controller::get<engine::platform::PlatformController>()
                ->swap_buffers();
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
