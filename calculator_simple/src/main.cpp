/**
 * @file
 * @brief   GTK+3 (gtkmm, C++ Bindings) example Calculator app.
 * 
 *
 * @author     Tommy Vegetables <leafyrabbet@gmail.com>
 * @date       2020-05-16
 * @copyright  2020, TenonGarden Productions
 */
#include "app_window.hpp"

int main(int argc, char * argv[])
{
   auto app = Gtk::Application::create(
      argc
      , argv
      , "dev.leafyrabbet.calculator.simple"
   );

   AppWindow app_window_obj;

   auto ret_code = app->run(app_window_obj);

   return (ret_code);
}
