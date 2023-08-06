#include "main-window.hpp"

int main(int argc, char **argv)
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.gtkmm.examples.password-generator");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_resource("/org/seutil/passgen/main-window");
    MainWindow* main_window = nullptr;
    builder->get_widget_derived("main_window", main_window);
    return app->run(*main_window);
}
