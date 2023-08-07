#include <password-generator.hpp>
#include "main-window.hpp"

const std::string DIGITS = "0123456789";
const std::string WHITESPACE = " ";
const std::string SPECIAL_CHARACTERS = "<>}{})()?#";

MainWindow::MainWindow(BaseObjectType* c_object,
                       const Glib::RefPtr<Gtk::Builder>& builder)
    : Gtk::ApplicationWindow(c_object),
      m_builder{builder}
{
    m_builder->get_widget<Gtk::Label>("lbl_password", m_lbl_password);
    m_builder->get_widget<Gtk::CheckButton>("chk_use_digits", m_chk_use_digits);
    m_builder->get_widget<Gtk::CheckButton>("chk_use_whitespace", m_chk_use_whitespace);
    m_builder->get_widget<Gtk::CheckButton>("chk_use_special_characters", m_chk_use_special_charactes);
    m_builder->get_widget<Gtk::Scale>("scale_password_length", m_scale_password_length);
    m_builder->get_widget<Gtk::Entry>("entry_additional_characters", m_entry_additional_characters);
    m_builder->get_widget<Gtk::Button>("btn_generate_password", m_btn_generate_password);

    m_chk_use_digits->signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::on_chk_use_digits_toggled));
    m_chk_use_whitespace->signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::on_chk_use_whitespace_toggled));
    m_chk_use_special_charactes->signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::on_chk_use_special_characters_toggled));
    m_btn_generate_password->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_generate_password_clicked));
}

void
MainWindow::on_chk_use_digits_toggled()
{
    if (m_chk_use_digits->get_active())
        m_generator.add(DIGITS);
    else
        m_generator.remove(DIGITS);
}

void
MainWindow::on_chk_use_whitespace_toggled()
{
    if (m_chk_use_whitespace->get_active())
        m_generator.add(WHITESPACE);
    else
        m_generator.remove(WHITESPACE);
}

void
MainWindow::on_chk_use_special_characters_toggled()
{
    if (m_chk_use_special_charactes->get_active())
        m_generator.add(SPECIAL_CHARACTERS);
    else
        m_generator.remove(SPECIAL_CHARACTERS);
}

void
MainWindow::on_btn_generate_password_clicked()
{
    m_lbl_password->set_text(m_generator.generate((int)m_scale_password_length->get_value()));
}
