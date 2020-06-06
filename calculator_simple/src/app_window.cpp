/**
 * @file
 * @brief   (Definitions) View Layer of a simple Calculator application.
 * 
 *
 * @author     Tommy Vegetables <leafyrabbet@gmail.com>
 * @date       2020-05-17
 * @copyright  2020, TenonGarden Productions
 */

#include "app_window.hpp"

#include <charconv>
#include <iostream>

#define PROPAGATE_SIG true
#define DO_NOT_PROPAGATE_SIG false


/**
 * @brief   AppWindow Constructor.
 * 
 * There is no return from a class constructor method.
 */
AppWindow::AppWindow():
                    Gtk::Window()
                  , value_x(0.0)
                  , value_y(0.0)
                  , value_z(0.0)
                  , layout_main(Gtk::ORIENTATION_VERTICAL)
                  , layout_display(Gtk::ORIENTATION_VERTICAL)
                  , layout_buttons()
                  , display_area()
                  , radix_label_obj("b")
                  , radix_slider_obj(
                        Gtk::Adjustment::create(10, 0, 16, 1, 0, 0)
                      , Gtk::ORIENTATION_VERTICAL
                    )
                  , btn_num_0_obj("0")
                  , btn_num_1_obj("1")
                  , btn_num_2_obj("2")
                  , btn_num_3_obj("3")
                  , btn_num_4_obj("4")
                  , btn_num_5_obj("5")
                  , btn_num_6_obj("6")
                  , btn_num_7_obj("7")
                  , btn_num_8_obj("8")
                  , btn_num_9_obj("9")
                  , btn_num_a_obj("A")
                  , btn_num_b_obj("B")
                  , btn_num_c_obj("C")
                  , btn_num_d_obj("D")
                  , btn_num_e_obj("E")
                  , btn_num_f_obj("F")
                  , btn_op_add_obj("+")
                  , btn_op_sub_obj("-")
                  , btn_op_mul_obj("*")
                  , btn_op_div_obj("/")
                  , btn_op_mod_obj("%")
                  , btn_solve_obj("=")
                  , btn_arr{{
                       &btn_num_0_obj
                     , &btn_num_1_obj
                     , &btn_num_2_obj
                     , &btn_num_3_obj
                     , &btn_num_4_obj
                     , &btn_num_5_obj
                     , &btn_num_6_obj
                     , &btn_num_7_obj
                     , &btn_num_8_obj
                     , &btn_num_9_obj
                     , &btn_num_a_obj
                     , &btn_num_b_obj
                     , &btn_num_c_obj
                     , &btn_num_d_obj
                     , &btn_num_e_obj
                     , &btn_num_f_obj
                  }}
                  , txt_str_top("")
                  , txt_str_bot("")
                  , txt_str_opr("")
                  , txt_str_res("")
                  , crnt_mode{CALC_MODE::ARG_A}
{
   set_title("Simple Calculator");

   btn_num_0_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_0), false);
   btn_num_1_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_1), false);
   btn_num_2_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_2), false);
   btn_num_3_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_3), false);
   btn_num_4_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_4), false);
   btn_num_5_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_5), false);
   btn_num_6_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_6), false);
   btn_num_7_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_7), false);
   btn_num_8_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_8), false);
   btn_num_9_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_9), false);
   btn_num_a_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_a), false);
   btn_num_b_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_b), false);
   btn_num_c_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_c), false);
   btn_num_d_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_d), false);
   btn_num_e_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_e), false);
   btn_num_f_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_btn_f), false);

   btn_op_add_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_add), false);
   btn_op_sub_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_sub), false);
   btn_op_mul_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_mul), false);
   btn_op_div_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_div), false);
   btn_op_mod_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_mod), false);

   btn_solve_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_solve), false);

   radix_slider_obj.set_digits(1);
   radix_slider_obj.set_round_digits(1);
   radix_slider_obj.set_has_origin(false);

   radix_slider_obj.signal_change_value().connect(
      sigc::mem_fun(*this, &AppWindow::handle_radix_change)
      , true
   );

   short int count = 0;

   for (auto const & btn_ptr : btn_arr)
   {
      btn_ptr->set_sensitive(
         (count < 10)
      );
      count += 1;
   }

   layout_buttons.attach(radix_label_obj, 0, 0, 1, 1);
   layout_buttons.attach(radix_slider_obj, 0, 1, 1, 4);

   layout_buttons.attach(btn_num_0_obj, 1, 0, 1, 1);
   layout_buttons.attach(btn_num_1_obj, 2, 0, 1, 1);
   layout_buttons.attach(btn_num_2_obj, 3, 0, 1, 1);
   layout_buttons.attach(btn_num_3_obj, 4, 0, 1, 1);
   layout_buttons.attach(btn_op_add_obj, 5, 0, 1, 1);

   layout_buttons.attach(btn_num_4_obj, 1, 1, 1, 1);
   layout_buttons.attach(btn_num_5_obj, 2, 1, 1, 1);
   layout_buttons.attach(btn_num_6_obj, 3, 1, 1, 1);
   layout_buttons.attach(btn_num_7_obj, 4, 1, 1, 1);
   layout_buttons.attach(btn_op_sub_obj, 5, 1, 1, 1);

   layout_buttons.attach(btn_num_8_obj, 1, 2, 1, 1);
   layout_buttons.attach(btn_num_9_obj, 2, 2, 1, 1);
   layout_buttons.attach(btn_num_a_obj, 3, 2, 1, 1);
   layout_buttons.attach(btn_num_b_obj, 4, 2, 1, 1);
   layout_buttons.attach(btn_op_mul_obj, 5, 2, 1, 1);

   layout_buttons.attach(btn_num_c_obj, 1, 3, 1, 1);
   layout_buttons.attach(btn_num_d_obj, 2, 3, 1, 1);
   layout_buttons.attach(btn_num_e_obj, 3, 3, 1, 1);
   layout_buttons.attach(btn_num_f_obj, 4, 3, 1, 1);
   layout_buttons.attach(btn_op_div_obj, 5, 3, 1, 1);

   layout_buttons.attach(btn_solve_obj, 4, 4, 1, 1);

   display_area.set_size_request(25, 120);
   display_area.signal_draw().connect(sigc::mem_fun(*this, &AppWindow::handle_display_update), false);

   layout_display.pack_start(display_area);

   layout_main.pack_start(layout_display);
   layout_main.pack_start(layout_buttons);

   add(layout_main);

   show_all_children();
}


/**
 * @brief   Handler method for the display area redraws.
 * 
 * References:
 * - http://developer.gnome.org/pangomm/unstable/classPango_1_1Layout.html
 * 
 */
bool AppWindow::handle_display_update(
   ::Cairo::RefPtr<::Cairo::Context> const & draw_context_ptr
)
{
   display_area_allocation = display_area.get_allocation();
   int const area_x_full = display_area_allocation.get_width();
   // int const area_y_full = display_area_allocation.get_height();

   Pango::FontDescription font;
   font.set_family("Monospace");
   font.set_weight(Pango::WEIGHT_NORMAL);

   auto top_txt_layout = create_pango_layout(txt_str_top.c_str());
   top_txt_layout->set_font_description(font);

   auto bot_txt_layout = create_pango_layout(txt_str_bot.c_str());
   bot_txt_layout->set_font_description(font);

   auto opr_txt_layout = create_pango_layout(txt_str_opr.c_str());
   opr_txt_layout->set_font_description(font);

   auto res_txt_layout = create_pango_layout(txt_str_res.c_str());
   res_txt_layout->set_font_description(font);

   int top_txt_width;
   int top_txt_height;
   int bot_txt_width;
   int bot_txt_height;
   int opr_txt_width;
   int opr_txt_height;
   int res_txt_width;
   int res_txt_height;

   top_txt_layout->get_pixel_size(top_txt_width, top_txt_height);
   float const pen_x_top_txt = (area_x_full - top_txt_width);
   float const pen_y_top_txt = (1.5 * top_txt_height);
   draw_context_ptr->move_to(
        pen_x_top_txt
      , pen_y_top_txt
   );
   top_txt_layout->show_in_cairo_context(draw_context_ptr);

   opr_txt_layout->get_pixel_size(opr_txt_width, opr_txt_height);
   float const pen_x_opr_txt = (1.5 * opr_txt_width);
   float const pen_y_opr_txt = (pen_y_top_txt + (1.5 * opr_txt_height));
   draw_context_ptr->move_to(
        pen_x_opr_txt
      , pen_y_opr_txt
   );
   opr_txt_layout->show_in_cairo_context(draw_context_ptr);

   bot_txt_layout->get_pixel_size(bot_txt_width, bot_txt_height);
   float const pen_x_bot_txt = (area_x_full - bot_txt_width);
   float const pen_y_bot_txt = (pen_y_opr_txt + (1.5 * bot_txt_height));
   draw_context_ptr->move_to(
        pen_x_bot_txt
      , pen_y_bot_txt
   );
   bot_txt_layout->show_in_cairo_context(draw_context_ptr);

   res_txt_layout->get_pixel_size(res_txt_width, res_txt_height);
   float const pen_x_res_txt = (area_x_full - res_txt_width);
   float const pen_y_res_txt = (pen_y_bot_txt + (2.5 * res_txt_height));
   draw_context_ptr->move_to(
        pen_x_res_txt
      , pen_y_res_txt
   );
   res_txt_layout->show_in_cairo_context(draw_context_ptr);

   return PROPAGATE_SIG; // Should propagate to make sure save/restore are processed correctly.
}


/**
 * @brief   Handler method for value changes in the scrollbar.
 * 
 * This method is meant to be registered as the callback to handle the change event for radix (base)
 * selection scrollbar (the `Gtk::Scale` instance). As the scrollbar is moved, the radix (base) for
 * the calculator is changed to whatever the selection is. To handle this, the calculator buttons'
 * "sensitive"-ness is changed, which basically registers them as "enabled" (sensitive) or "disabled"
 * (not sensitive).
 * 
 * See the [Gtk::Range](https://developer.gnome.org/gtkmm/stable/classGtk_1_1Range.html) documentation
 * for details on the `signal_change_value()` method, as well as the
 * [Gtk::ScrollType enum](https://developer.gnome.org/gtkmm/stable/group__gtkmmEnums.html)
 * documentation.
 * 
 * @param[in] scroll_type  The type of "scrolling" event that triggered this callback.
 * @param[in] radix_new    The new value after the "scrolling" event, which will be the new radix value.
 * 
 * @returns    (boolean) Whether this signal should propagate further to other handlers after this.
 */
bool AppWindow::handle_radix_change(
        Gtk::ScrollType const & // scroll_type
      , double const & radix_new
)
{
   short int count = 0;

   for (auto const & btn_ptr : btn_arr)
   {
      btn_ptr->set_sensitive(
         (count < static_cast<short int>(radix_new))
      );
      count += 1;
   }

   return (DO_NOT_PROPAGATE_SIG);
}


/**
 * @brief      { item_description }
 */
void AppWindow::write_digit(char const * digit_str)
{
   switch (crnt_mode)
   {
      case (CALC_MODE::ARG_A):
      {
         txt_str_top.append(digit_str);
      }
      break;

      case (CALC_MODE::ARG_B):
      {
         txt_str_bot.append(digit_str);
      }
      break;
      
      case (CALC_MODE::SOLVE):
      {}
      break;
      
      case (CALC_MODE::AFTER):
      {
         txt_str_top.clear();
         txt_str_opr.clear();
         txt_str_bot.clear();
         txt_str_res.clear();

         txt_str_top.append(digit_str);
         crnt_mode = CALC_MODE::ARG_A;
      }
      break;

      default:
      {}
      break;
   }

   display_area.queue_draw();

   return;
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_0()
{
   write_digit("0");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_1()
{
   write_digit("1");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_2()
{
   write_digit("2");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_3()
{
   write_digit("3");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_4()
{
   write_digit("4");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_5()
{
   write_digit("5");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_6()
{
   write_digit("6");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_7()
{
   write_digit("7");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_8()
{
   write_digit("8");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_9()
{
   write_digit("9");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_a()
{
   write_digit("A");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_b()
{
   write_digit("B");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_c()
{
   write_digit("C");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_d()
{
   write_digit("D");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_e()
{
   write_digit("E");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_f()
{
   write_digit("F");

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_solve()
{
   int a;
   int b;
   int c;

   int r = static_cast<int>(radix_slider_obj.get_value());

   std::cout
      << "r: "
      << r
      << std::endl;

   std::from_chars(txt_str_top.c_str(), txt_str_top.data() + txt_str_top.size(), a, r);
   std::from_chars(txt_str_bot.c_str(), txt_str_bot.data() + txt_str_bot.size(), b, r);

   std::cout
      << "a: "
      << a
      << std::endl;

   std::cout
      << "b: "
      << b
      << std::endl;

    std::array<char, 150> result{'\0'};

   if (txt_str_opr == "+")
   {
      c = a + b;
   }
   else if (txt_str_opr == "-")
   {
      c = a - b;
   }
   else if (txt_str_opr == "x")
   {
      c = a * b;
   }
   else if (txt_str_opr == "/")
   {
      c = a / b;
   }
   else if (txt_str_opr == "%")
   {
      c = a % b;
   }
   else
   {
      c = 0;
   }

   std::cout
      << "c: "
      << c
      << std::endl;

   std::to_chars(result.data(), result.data() + result.size(), c, r);
   std::string result_str(result.data());

   std::cout
      << "result: "
      << result_str
      << std::endl;

   txt_str_res.clear();
   txt_str_res.append(result_str);

   crnt_mode = CALC_MODE::AFTER;

   display_area.queue_draw();

   return;
}


/**
 * @brief      { item_description }
 */
void AppWindow::determine_mode(char const *) // UNUSED ARGUMENT
{
   switch (crnt_mode)
   {
      case (CALC_MODE::ARG_A):
      {
         crnt_mode = CALC_MODE::ARG_B;
      }
      break;

      case (CALC_MODE::ARG_B):
      {
         crnt_mode = CALC_MODE::SOLVE;
      }
      break;
      
      case (CALC_MODE::SOLVE):
      {
         crnt_mode = CALC_MODE::SOLVE;
      }
      break;
      
      case (CALC_MODE::AFTER):
      {
         crnt_mode = CALC_MODE::ARG_A;
      }
      break;

      default:
      {}
      break;
   }

   return;
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_op_add()
{
   char const * add_op = "+\0";

   txt_str_opr = (add_op);

   determine_mode(add_op);

   display_area.queue_draw();

   return;
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_op_sub()
{
   char const * sub_op = "-\0";

   txt_str_opr = (sub_op);

   determine_mode(sub_op);

   display_area.queue_draw();

   return;
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_op_mul()
{
   char const * mul_op = "x\0";

   txt_str_opr = (mul_op);

   determine_mode(mul_op);

   display_area.queue_draw();

   return;
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_op_div()
{
   char const * div_op = "/\0";

   txt_str_opr = (div_op);

   determine_mode(div_op);

   display_area.queue_draw();

   return;
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_op_mod()
{
   char const * mod_op = "%\0";

   txt_str_opr = (mod_op);

   determine_mode(mod_op);

   display_area.queue_draw();

   return;
}
