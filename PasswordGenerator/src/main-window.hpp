#pragma once
#include <gtkmm.h>
#include <password-generator.hpp>

class MainWindow : public Gtk::ApplicationWindow
{
public:
    MainWindow(BaseObjectType* c_ojbect,
               const Glib::RefPtr<Gtk::Builder>& builder);
private:
    Lib::PasswordGenerator m_generator;
    Glib::ustring m_prev_entry_text;

    // Handlers
    void on_chk_use_digits_toggled();
    void on_chk_use_whitespace_toggled();
    void on_chk_use_special_characters_toggled();
    void on_chk_use_additional_characters_toggled();
    void on_entry_additional_characters_changed();
    void on_btn_generate_password_clicked();

    // Widgets
    Glib::RefPtr<Gtk::Builder> m_builder;
    Gtk::Label* m_lbl_password;
    Gtk::CheckButton* m_chk_use_digits;
    Gtk::CheckButton* m_chk_use_whitespace;
    Gtk::CheckButton* m_chk_use_special_characters;
    Gtk::Scale* m_scale_password_length;
    Gtk::CheckButton* m_chk_use_additional_characters;
    Gtk::Entry* m_entry_additional_characters;
    Gtk::Button* m_btn_generate_password;
};
