/**
 * @defgroup   MAIN main
 *
 * @brief      GTK+3 (gtkmm, C++ Bindings) example window launcher app.
 * 
 * A minimal-ish proof-of-concept app that confirms that GTK+3 and gtkmm are
 * installed properly by launching a small window with an editable textbox
 * and 2 checkboxes below it.
 * 
 * Implemented based-on the example shown here:
 * https://developer.gnome.org/gtkmm-tutorial/stable/sec-text-entry.html.en
 *
 * @author     Tommy Vegetables <leafyrabbet@gmail.com>
 * @date       2020-05-16
 * @copyright  2020, TenonGarden Productions
 */
#include <gtkmm.h>

int main(int argc, char * argv[])
{
   auto app = Gtk::Application::create(
      argc
      , argv
      , "leafyrabbet_app"
   );

   Gtk::Window window;
   Gtk::Box box_layout(Gtk::ORIENTATION_VERTICAL);
   Gtk::Entry wdgt_textentry;
   Gtk::CheckButton wdgt_btn_success;
   Gtk::CheckButton wdgt_btn_fail;
   
   window.set_default_size(420, 80);

   wdgt_textentry.set_text("Success!");

   box_layout.pack_start(wdgt_textentry);
   box_layout.pack_start(wdgt_btn_success);
   box_layout.pack_start(wdgt_btn_fail);

   window.add(box_layout);

   window.show_all_children();

   auto ret_code = app->run(window);

   return (ret_code);
}
