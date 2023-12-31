#include <unordered_map>
#include "main-window.hpp"

const std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> COUNTRIES_REGIONS_CITIES =
{
    { "Россия", {
        { "Краснодарский край", { "Краснодар", "Хадыжинск", "Сочи", "Ейск", "Апшеронск" } },
        { "Алтайский край", { "Барнаул", "Бийск", "Горняк" } },
        { "Камчатский край", { "Петропавловск-Камчатский", "Елизово", "Вилючинск" } },
    }},
    { "Беларусь", {
        { "Мінская вобласць", { "Мінск", "Заслаўе", "Смалявічы", "Фаніпаль" } }, 
        { "Віцебская вобласць", { "Віцебск", "Гарадок", "Глыбокае", "Сянно" } },
        { "Магілёўская вобласць", { "Магілёў", "Гаі", "Быхаў", "Гарадшчына" } }
    }},
    { "Україна", {
        { "Одеська область", { "Одеса", "Южне", "Білгород-Дністровський", "Подільськ" } },
        { "Дніпропетровська область", { "Дніпро", "П'ятихатки", "Зеленодольськ", "Новомосковськ" } },
        { "Чернігівська область", { "Чернігів", "Прилуки", "Мена", "Корюківка" } },
        { "Харківська область", { "Харків", "Лозова", "Ізюм", "Ку́п'янськ" } }
    }},
    { "საქართველო", {
        { "აჭარა", { "ბათუმი", "ქობულეთი", "ხულო", "შუახევი" } },
        { "გურია", { "ოზურგეთი", "ლანჩხუთი", "ქვედა ნასაკირალი", "ჯაპანა" } },
        { "სამეგრელო-ზემო სვანეთი", { "ზუგდიდი", "ანაკლია", "რუხი", "უშგული" } }
    }},
    { "Հայաստան", {
        { "Արմավիրի մարզ", { "Վաղարշապատ", "Արաքս", "Հայկաշեն", "Քարակերտ" } },
        { "Շիրակի մարզ", { "Գյումրի", "Մարալիկ", "Արթիկ", "Ամասիա" } },
        { "Արագածոտնի մարզ", { "Աշտարակ", "Սասունիկ", "Կարբի", "Փարպի" } }
    }},
    { "Қазақстан", {
        { "Ақмола облысы", { "Атбасар", "Мариновка", "Сергеевка", "Ақан Құрманов" } },
        { "Алматы облысы", { "Қонаев", "Ерейментау", "Ақкө́л", "Көкшетау" } },
        { "Ақтөбе облысы", { "Ақтөбе", "Алға", "Талғар", "Алмалық" } }
    }}
};

MainWindow::MainWindow(BaseObjectType* c_object,
                       const Glib::RefPtr<Gtk::Builder>& builder)
    : Gtk::ApplicationWindow(c_object)
{
    builder->get_widget<Gtk::Image>("img_avatar", m_img_avatar);
    builder->get_widget<Gtk::Box>("box_information", m_box_information);
    builder->get_widget<Gtk::RadioButton>("rad_male", m_rad_male);
    builder->get_widget<Gtk::RadioButton>("rad_female", m_rad_female);
    builder->get_widget<Gtk::Entry>("entry_name", m_entry_name);
    builder->get_widget<Gtk::Entry>("entry_surname", m_entry_surname);
    builder->get_widget<Gtk::Entry>("entry_patronomic", m_entry_patronomic);
    builder->get_widget<Gtk::Entry>("entry_phone", m_entry_phone);
    builder->get_widget<Gtk::Entry>("entry_email", m_entry_email);
    builder->get_widget<Gtk::Entry>("entry_supervisor", m_entry_supervisor);
    builder->get_widget<Gtk::ComboBoxText>("cmbt_country", m_cmbt_country);
    builder->get_widget<Gtk::ComboBoxText>("cmbt_region", m_cmbt_region);
    builder->get_widget<Gtk::ComboBoxText>("cmbt_city", m_cmbt_city);
    builder->get_widget<Gtk::ComboBoxText>("cmbt_department", m_cmbt_department);
    builder->get_widget<Gtk::ComboBoxText>("cmbt_position", m_cmbt_position);
    builder->get_widget<Gtk::SpinButton>("spin_salary", m_spin_salary);
    builder->get_widget<Gtk::TextView>("tview_notes", m_tview_notes);
    builder->get_widget<Gtk::Button>("btn_open_avatar", m_btn_open_avatar);
    builder->get_widget<Gtk::Button>("btn_back", m_btn_back);
    builder->get_widget<Gtk::Button>("btn_forward", m_btn_forward);
    builder->get_widget<Gtk::Button>("btn_add", m_btn_add);
    builder->get_widget<Gtk::Button>("btn_remove", m_btn_remove);
    builder->get_widget<Gtk::Button>("btn_save", m_btn_save);
    builder->get_widget<Gtk::Button>("btn_quit", m_btn_quit);

    m_btn_open_avatar->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_open_avatar));
    m_rad_male->signal_clicked().connect([this]{ m_crm.employee().gender = m_rad_male->get_label(); });
    m_rad_female->signal_clicked().connect([this]{ m_crm.employee().gender = m_rad_female->get_label(); });
    m_entry_name->signal_changed().connect([this]{ m_crm.employee().name = m_entry_name->get_text(); });
    m_entry_surname->signal_changed().connect([this]{ m_crm.employee().surname = m_entry_surname->get_text(); });
    m_entry_patronomic->signal_changed().connect([this]{ m_crm.employee().patronomic = m_entry_patronomic->get_text(); });
    m_entry_phone->signal_changed().connect([this]{ m_crm.employee().phone = m_entry_phone->get_text(); });
    m_entry_email->signal_changed().connect([this]{ m_crm.employee().email = m_entry_email->get_text(); });
    m_entry_supervisor->signal_changed().connect([this]{ m_crm.employee().supervisor = m_entry_supervisor->get_text(); });
    m_tview_notes->get_buffer()->signal_changed().connect([this]{ m_crm.employee().notes = m_tview_notes->get_buffer()->get_text(); });
    m_cmbt_country->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_cmbt_country_changed));
    m_con_cmbt_region = m_cmbt_region->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_cmbt_region_changed));
    m_cmbt_city->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_cmbt_city_changed));
    m_cmbt_department->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_cmbt_department_changed));
    m_cmbt_position->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_cmbt_position_changed));
    m_spin_salary->signal_changed().connect([this]{ m_crm.employee().salary = m_spin_salary->get_value(); });
    m_btn_back->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_back_clicked));
    m_btn_forward->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_forward_clicked));
    m_btn_remove->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_remove_clicked));
    m_btn_add->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_add_clicked));
    m_btn_save->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_save_clicked));
    m_btn_quit->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::close));

    m_crm.load("personal.xml");
    display_employee();
}

void
MainWindow::update_avatar()
{
    Glib::RefPtr<Gdk::Pixbuf> pixbuf;
    if (m_crm.employee().avatar_location.empty())
        pixbuf = Gdk::Pixbuf::create_from_resource("/org/seutil/personalcrm/empty_avatar");
    else
        pixbuf = Gdk::Pixbuf::create_from_file(m_crm.employee().avatar_location);
    
    pixbuf = pixbuf->scale_simple(150, 150, Gdk::INTERP_BILINEAR);
    m_img_avatar->set(pixbuf);
}

void
MainWindow::display_employee()
{
    if (m_crm.employees().empty())
    {
        m_box_information->set_visible(false);
        m_btn_back->set_sensitive(false);
        m_btn_forward->set_sensitive(false);
        m_btn_remove->set_sensitive(false);
        return;
    }

    Lib::Employee& e = m_crm.employee();
    update_avatar();
    m_entry_name->set_text(e.name);
    m_entry_surname->set_text(e.surname);
    m_entry_patronomic->set_text(e.patronomic);
    m_entry_phone->set_text(e.phone);
    m_entry_email->set_text(e.email);
    m_entry_supervisor->set_text(e.supervisor);
    if (e.country.empty())
        m_cmbt_country->set_active_id("-1");
    else
        m_cmbt_country->set_active_text(e.country);

    if (e.region.empty())
        m_cmbt_region->set_active_id("-1");
    else
        m_cmbt_region->set_active_text(e.region);

    if (e.city.empty())
        m_cmbt_city->set_active_id("-1");
    else
        m_cmbt_city->set_active_text(e.city);

    if (e.department.empty())
        m_cmbt_department->set_active_id("-1");
    else
        m_cmbt_department->set_active_text(e.department);

    if (e.position.empty())
        m_cmbt_position->set_active_id("-1");
    else
        m_cmbt_position->set_active_text(e.position);

    m_spin_salary->set_value(e.salary);
    m_tview_notes->get_buffer()->set_text(e.notes);

    m_box_information->set_visible();
    m_btn_remove->set_sensitive();
    m_btn_forward->set_sensitive(m_crm.have_next());
    m_btn_back->set_sensitive(m_crm.have_previouse());
}

// Handlers
void
MainWindow::on_btn_open_avatar()
{
    auto dlg = Gtk::FileChooserDialog(*this, "Select avatar", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dlg.set_transient_for(*this);
    dlg.set_modal();
    dlg.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dlg.add_button("_Open", Gtk::RESPONSE_OK);

    // add filters
    auto filter_png = Gtk::FileFilter::create();
    auto filter_jpeg = Gtk::FileFilter::create();
    auto filter_all = Gtk::FileFilter::create();
    filter_png->set_name("PNG");
    filter_png->add_mime_type("image/png");
    filter_jpeg->set_name("JPEG");
    filter_jpeg->add_mime_type("image/jpg");
    filter_all->set_name("All");
    filter_all->add_pattern("*");
    dlg.add_filter(filter_png);
    dlg.add_filter(filter_jpeg);
    dlg.add_filter(filter_all);
    if (dlg.run() != Gtk::RESPONSE_OK)
        return;
    
    m_crm.employee().avatar_location = dlg.get_filename();
    update_avatar();
}

void
MainWindow::on_cmbt_country_changed()
{
    m_con_cmbt_region.block();
    m_cmbt_region->remove_all();
    m_cmbt_city->remove_all();
    if (m_cmbt_country->get_active_id() == "-1")
    {
        m_crm.employee().country.clear();
        m_crm.employee().region.clear();
        m_crm.employee().city.clear();
        m_cmbt_region->set_sensitive(false);
        m_cmbt_city->set_sensitive(false);
        return;
    }

    m_crm.employee().country = m_cmbt_country->get_active_text();
    m_cmbt_region->set_sensitive();
    m_cmbt_city->set_sensitive();

    // populate regions
    int id = -1;
    m_cmbt_region->append(Glib::ustring::format(id++), "Unknown");
    Glib::ustring country = m_cmbt_country->get_active_text();
    for (const auto& r : COUNTRIES_REGIONS_CITIES.at(country))
        m_cmbt_region->append(Glib::ustring::format(id++), r.first);

    m_cmbt_region->set_active_id("-1");
    m_cmbt_city->set_active_id("-1");
    m_con_cmbt_region.unblock();
}

void
MainWindow::on_cmbt_region_changed()
{
    m_cmbt_city->remove_all();
    if (m_cmbt_region->get_active_id() == "-1")
    {
        m_crm.employee().region.clear();
        m_crm.employee().city.clear();
        m_cmbt_city->set_sensitive(false);
        return;
    }

    m_crm.employee().region = m_cmbt_region->get_active_text();
    m_cmbt_city->set_sensitive();
    m_cmbt_city->remove_all();

    // populate cities
    int id = -1;
    m_cmbt_city->append(Glib::ustring::format(id++), "Unknown");
    std::string country = m_cmbt_country->get_active_text().raw();
    std::string region = m_cmbt_region->get_active_text().raw();
    for (const auto& c : COUNTRIES_REGIONS_CITIES.at(country).at(region))
        m_cmbt_city->append(Glib::ustring::format(id++), c);

    m_cmbt_city->set_active_id("-1");
}

void
MainWindow::on_cmbt_city_changed()
{
    if (m_cmbt_city->get_active_id() == "-1")
        m_crm.employee().city.clear();
    else
        m_crm.employee().city = m_cmbt_city->get_active_text();
}

void
MainWindow::on_cmbt_department_changed()
{
    if (m_cmbt_department->get_active_id() == "-1")
        m_crm.employee().department.clear();
    else
        m_crm.employee().department = m_cmbt_department->get_active_text();
}

void
MainWindow::on_cmbt_position_changed()
{
    if (m_cmbt_position->get_active_id() == "-1")
        m_crm.employee().position.clear();
    else
        m_crm.employee().position = m_cmbt_position->get_active_text();
}

void
MainWindow::on_btn_back_clicked()
{
    if (!m_crm.employee().valid())
        return;

    m_crm.previouse_employee();
    display_employee();
}

void
MainWindow::on_btn_forward_clicked()
{
    if (!m_crm.employee().valid())
        return;

    m_crm.next_employee();
    display_employee();
}

void
MainWindow::on_btn_remove_clicked()
{
    m_crm.remove_employee();
    display_employee();
}

void
MainWindow::on_btn_add_clicked()
{
    if (!m_crm.employees().empty() && !m_crm.employee().valid())
        return;
    
    m_crm.add_employee();
    display_employee();
}

void
MainWindow::on_btn_save_clicked()
{
    if (!m_crm.employee().valid())
        return;

    m_crm.save();
}
