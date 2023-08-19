#pragma once
#include <personal-crm.hpp>
#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow
{
public:
    MainWindow(BaseObjectType* c_object,
               const Glib::RefPtr<Gtk::Builder>& builder);
private:
    Lib::PersonalCrm m_crm;
    void display_employee();

    // Handlers
    void on_cmbt_country_changed();
    void on_cmbt_region_changed();
    void on_cmbt_city_changed();
    void on_btn_back_clicked();
    void on_btn_forward_clicked();
    void on_btn_add_clicked();
    void on_btn_remove_clicked();
    void on_btn_save_clicked();

    // Widgets
    Gtk::Box* m_box_information;

    // Personal information
    Gtk::Image* m_img_avatar;
    Gtk::RadioButton* m_rad_male;
    Gtk::RadioButton* m_rad_female;
    Gtk::Entry* m_entry_name;
    Gtk::Entry* m_entry_surname;
    Gtk::Entry* m_entry_patronomic;
    Gtk::Entry* m_entry_phone;
    Gtk::Entry* m_entry_email;
    Gtk::ComboBoxText* m_cmbt_country;
    Gtk::ComboBoxText* m_cmbt_region;
    Gtk::ComboBoxText* m_cmbt_city;

    // Employee information
    Gtk::Entry* m_entry_supervisor;
    Gtk::ComboBoxText* m_cmbt_department;
    Gtk::ComboBoxText* m_cmbt_position;
    Gtk::SpinButton* m_spin_salary;
    
    // Additional information
    Gtk::TextView* m_tview_notes;

    // Button controlls
    Gtk::Button* m_btn_back;
    Gtk::Button* m_btn_forward;
    Gtk::Button* m_btn_remove;
    Gtk::Button* m_btn_add;
    Gtk::Button* m_btn_save;
    Gtk::Button* m_btn_quit;

    sigc::connection m_con_cmbt_region;
};
