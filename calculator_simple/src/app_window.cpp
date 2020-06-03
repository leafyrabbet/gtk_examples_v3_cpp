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
                        Gtk::Adjustment::create(10, 0, 16, 1, 5, 0)
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
                  , btn_alt_dot_obj(".")
                  , btn_alt_inv_obj("1/x")
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

   // btn_op_add_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_add));
   // btn_op_sub_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_sub));
   // btn_op_mul_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_mul));
   // btn_op_div_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_div));
   // btn_op_mod_obj.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::handle_op_mod));

   radix_slider_obj.set_digits(0);
   radix_slider_obj.set_has_origin(true);

   radix_slider_obj.signal_change_value().connect(
      sigc::mem_fun(*this, &AppWindow::handle_radix_change)
      , true
   );

   layout_buttons.attach(radix_label_obj, 0, 0, 1, 1);
   layout_buttons.attach(radix_slider_obj, 0, 1, 1, 4);

   layout_buttons.attach(btn_num_0_obj, 1, 0, 1, 1);
   layout_buttons.attach(btn_num_1_obj, 2, 0, 1, 1);
   layout_buttons.attach(btn_num_2_obj, 3, 0, 1, 1);
   layout_buttons.attach(btn_num_3_obj, 4, 0, 1, 1);
   layout_buttons.attach(btn_op_add_obj, 5, 0, 2, 1);

   layout_buttons.attach(btn_num_4_obj, 1, 1, 1, 1);
   layout_buttons.attach(btn_num_5_obj, 2, 1, 1, 1);
   layout_buttons.attach(btn_num_6_obj, 3, 1, 1, 1);
   layout_buttons.attach(btn_num_7_obj, 4, 1, 1, 1);
   layout_buttons.attach(btn_op_sub_obj, 5, 1, 2, 1);

   layout_buttons.attach(btn_num_8_obj, 1, 2, 1, 1);
   layout_buttons.attach(btn_num_9_obj, 2, 2, 1, 1);
   layout_buttons.attach(btn_num_a_obj, 3, 2, 1, 1);
   layout_buttons.attach(btn_num_b_obj, 4, 2, 1, 1);
   layout_buttons.attach(btn_op_mul_obj, 5, 2, 2, 1);

   layout_buttons.attach(btn_num_c_obj, 1, 3, 1, 1);
   layout_buttons.attach(btn_num_d_obj, 2, 3, 1, 1);
   layout_buttons.attach(btn_num_e_obj, 3, 3, 1, 1);
   layout_buttons.attach(btn_num_f_obj, 4, 3, 1, 1);
   layout_buttons.attach(btn_op_div_obj, 5, 3, 2, 1);

   layout_buttons.attach(btn_alt_dot_obj, 1, 4, 1, 1);
   layout_buttons.attach(btn_alt_inv_obj, 4, 4, 1, 1);

   display_area.set_size_request(360, 120);
   display_area.signal_draw().connect(sigc::mem_fun(*this, &AppWindow::handle_display_update), false);

   layout_display.pack_start(display_area);

   layout_main.pack_start(layout_display);
   layout_main.pack_start(layout_buttons);

   add(layout_main);

   show_all_children();
}

/**
 * @brief   AppWindow Destructor.
 * 
 * There is no return from a class destructor method.
 */
AppWindow::~AppWindow()
{
}


/**
 * @brief   Handler method for the display area redraws.
 */
bool AppWindow::handle_display_update(
   ::Cairo::RefPtr<::Cairo::Context> const & draw_context_ptr
)
{
   display_area_allocation = display_area.get_allocation();
   int const area_x_full = display_area_allocation.get_width();
   // int const area_y_full = display_area_allocation.get_height();

   // int const lft_x = (0);
   // int const top_y = (0);

   // int const center_x = (area_x_full / 2);
   // int const center_y = (area_y_full / 2);

   // // int const rght_x = (area_x_full);
   // int const bot_y = (area_y_full);

   // draw_context_ptr->set_line_width(10.0);
   // draw_context_ptr->set_source_rgb(0.8, 0.0, 0.5);
   // draw_context_ptr->move_to(lft_x, top_y);
   // draw_context_ptr->line_to(center_x, center_y);
   // draw_context_ptr->line_to(lft_x, bot_y);
   // draw_context_ptr->stroke();

   Pango::FontDescription font;

   font.set_family("Monospace");
   font.set_weight(Pango::WEIGHT_BOLD);

   // http://developer.gnome.org/pangomm/unstable/classPango_1_1Layout.html
   auto layout = create_pango_layout(txt_str_top.c_str());

   layout->set_font_description(font);

   int text_width;
   int text_height;

   //get the text dimensions (it updates the variables -- by reference)
   layout->get_pixel_size(text_width, text_height);

   // Position the text in the middle
   draw_context_ptr->move_to(
        (area_x_full - text_width)
      , (1.5 * text_height)
   );

   layout->show_in_cairo_context(draw_context_ptr);

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
         (count <= static_cast<short int>(radix_new))
      );
      count += 1;
   }

   return (DO_NOT_PROPAGATE_SIG);
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_0()
{
   txt_str_top.append("0");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_1()
{
   txt_str_top.append("1");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_2()
{
   txt_str_top.append("2");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_3()
{
   txt_str_top.append("3");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_4()
{
   txt_str_top.append("4");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_5()
{
   txt_str_top.append("5");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_6()
{
   txt_str_top.append("6");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_7()
{
   txt_str_top.append("7");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_8()
{
   txt_str_top.append("8");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_9()
{
   txt_str_top.append("9");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_a()
{
   txt_str_top.append("A");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_b()
{
   txt_str_top.append("B");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_c()
{
   txt_str_top.append("C");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_d()
{
   txt_str_top.append("D");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_e()
{
   txt_str_top.append("E");

   display_area.queue_draw();

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_f()
{
   txt_str_top.append("F");

   display_area.queue_draw();

   return;
}
