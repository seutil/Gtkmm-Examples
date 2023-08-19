#include "main-window.hpp"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "com.gtkmm.examples.personal-crm");
    auto builder = Gtk::Builder::create_from_resource("/org/seutil/personalcrm/main-window");
    MainWindow* main_window = nullptr;
    builder->get_widget_derived("main_window", main_window);
    return app->run(*main_window);
}
