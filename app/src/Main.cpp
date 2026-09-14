#include <engine/core/Engine.hpp>
#include <engine/graphics/GraphicsController.hpp>
#include <memory>
#include <spdlog/spdlog.h>

class MainController : public engine::core::Controller {
protected:
    void initialize() override {
        engine::graphics::OpenGL::enable_depth_testing();
        auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
        graphics->camera()->Position = glm::vec3(0.0f, 0.0f, 3.0f);
    }
    void begin_draw() override {
        engine::graphics::OpenGL::clear_buffers();
    }
    void draw() override {
        auto resources = engine::core::Controller::get<engine::resources::ResourcesController>();
        auto shader = resources->shader("basketball");
        auto basketball = resources->model("basketball");
        auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
        shader->use();
        shader->set_vec3("point_position", glm::vec3(-1.0f, -0.8f, 1.0f));
        shader->set_vec3("point_color", glm::vec3(1.0f, 1.0f, 1.0f));
        shader->set_vec3("viewPos", graphics->camera()->Position);
        shader->set_mat4("projection", graphics->projection_matrix());
        shader->set_mat4("view", graphics->camera()->view_matrix());
        shader->set_mat4("model", glm::mat4(1.0f));
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
