/**
 * @file
 * @brief   (Declarations) View Layer of a simple Calculator application.
 * 
 *
 * @author     Tommy Vegetables <leafyrabbet@gmail.com>
 * @date       2020-05-17
 * @copyright  2020, TenonGarden Productions
 */
#ifndef HPP_APP_WINDOW_HPP
#define HPP_APP_WINDOW_HPP

#include <glibmm/ustring.h>

#include <sigc++/sigc++.h>

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/scale.h>
#include <gtkmm/button.h>

#include <cairomm/context.h>

#include <pangomm/fontdescription.h>
#include <pangomm/fontface.h>
#include <pangomm/layout.h>

#include <array>
#include <string>

#include "logic_calculator.hpp"


class AppWindow :
              public Gtk::Window
{
   public:
      AppWindow();
      virtual ~AppWindow();
 
   protected:
      bool handle_display_update(
            ::Cairo::RefPtr<::Cairo::Context> const & draw_context_ptr
      );
      
      bool handle_radix_change(
              Gtk::ScrollType const & scroll_type
            , double const & radix_new
      );
      
      void handle_btn_0();
      void handle_btn_1();
      void handle_btn_2();
      void handle_btn_3();
      void handle_btn_4();
      void handle_btn_5();
      void handle_btn_6();
      void handle_btn_8();
      void handle_btn_7();
      void handle_btn_9();
      void handle_btn_a();
      void handle_btn_b();
      void handle_btn_c();
      void handle_btn_d();
      void handle_btn_e();
      void handle_btn_f();
 
   private:
      double value_x;
      double value_y;
      double value_z;

      Gtk::Box layout_main;
      Gtk::Box layout_display;
      Gtk::Grid layout_buttons;

      Gtk::DrawingArea display_area;
      Gtk::Allocation display_area_allocation;

      Gtk::Label radix_label_obj;
      Gtk::Scale radix_slider_obj;

      Gtk::Button btn_num_0_obj;
      Gtk::Button btn_num_1_obj;
      Gtk::Button btn_num_2_obj;
      Gtk::Button btn_num_3_obj;
      Gtk::Button btn_num_4_obj;
      Gtk::Button btn_num_5_obj;
      Gtk::Button btn_num_6_obj;
      Gtk::Button btn_num_7_obj;
      Gtk::Button btn_num_8_obj;
      Gtk::Button btn_num_9_obj;
      Gtk::Button btn_num_a_obj;
      Gtk::Button btn_num_b_obj;
      Gtk::Button btn_num_c_obj;
      Gtk::Button btn_num_d_obj;
      Gtk::Button btn_num_e_obj;
      Gtk::Button btn_num_f_obj;

      Gtk::Button btn_op_add_obj;
      Gtk::Button btn_op_sub_obj;
      Gtk::Button btn_op_mul_obj;
      Gtk::Button btn_op_div_obj;
      Gtk::Button btn_op_mod_obj;

      Gtk::Button btn_alt_dot_obj;
      Gtk::Button btn_alt_inv_obj;

      std::array<Gtk::Button *, 16> btn_arr;

      std::string txt_str_top;
      // std::string txt_str_bot;
};

#endif // HPP_APP_WINDOW_HPP
