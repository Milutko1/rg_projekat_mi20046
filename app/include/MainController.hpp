#include <engine/core/Engine.hpp>

class MainController : public engine::core::Controller {
public:
    float point_intensity() const;
    void set_point_intensity(float intensity);

protected:
    float m_point_intensity = 1.0f;
    bool m_animation_active = false;
    float m_animation_time = 0.0f;
    float m_ball_height = 0.0f;
    float m_ball_angle = 0.0f;

    void initialize() override;
    void poll_events() override;
    void update() override;
    void begin_draw() override;
    void draw() override;
    void end_draw() override;
};