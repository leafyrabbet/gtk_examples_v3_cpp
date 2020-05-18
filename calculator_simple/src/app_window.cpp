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


/**
 * @brief   AppWindow Constructor.
 */
AppWindow::AppWindow():
                    Gtk::Window()
                  , value_x(0.0)
                  , value_y(0.0)
                  , value_z(0.0)
                  , layout_main()
                  , layout_display()
                  , layout_buttons()
                  , display_area()
                  , radix_label_obj("b")
                  , radix_slider_obj(Gtk::Adjustment::create(10, 0, 16, 1, 5, 0), Gtk::ORIENTATION_VERTICAL)
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

   radix_slider_obj.signal_change_value().connect(sigc::mem_fun(*this, &AppWindow::handle_radix_change), true);

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

   layout_display.pack_start(display_area);

   layout_main.pack_start(layout_display);
   layout_main.pack_start(layout_buttons);

   add(layout_main);

   show_all_children();
}

/**
 * @brief   AppWindow Destructor.
 */
AppWindow::~AppWindow()
{
}


/**
 * @brief   AppWindow Constructor.
 */
void AppWindow::handle_display_update()
{
   return;
}


/**
 * @brief   AppWindow Constructor.
 */
bool AppWindow::handle_radix_change(const Gtk::ScrollType & scroll_type, const double & radix_new)
{
   short int count = 0;
   
   for(const auto & btn_ptr : btn_arr)
   {
      btn_ptr->set_sensitive((count <= static_cast<short int>(radix_new)));
      count += 1;
   }

   return (false);
}


/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_0()
{
   std::cout
         << "Yo!"
         << std::endl;

   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_1()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_2()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_3()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_4()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_5()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_6()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_8()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_7()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_9()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_a()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_b()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_c()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_d()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_e()
{
   return;
}

/**
 * @brief      { item_description }
 */
void AppWindow::handle_btn_f()
{
   return;
}

