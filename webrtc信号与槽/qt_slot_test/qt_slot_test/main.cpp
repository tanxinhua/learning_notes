#include <QtWidgets/QApplication>

#include <iostream>
#include "qt_slot_test.h"

 int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_slot_test w;
    auto thd = w.thread();
    w.show();
    return a.exec();
}
 

//class IEvent {
// public:
//  virtual void OnPressDown() = 0;
//};
//
//class Button {
// public:
//  void SetIEvent(IEvent* event) { event_ = event; }
//  void PressDown() {
//    if (event_) event_->OnPressDown();
//  };
//
// private:
//  IEvent* event_ = nullptr;
//};
//
//class Lable : public IEvent {
// public:
//  void OnPressDown() override { std::cout << "press down\n"; };
//};
//
//int main(int argc, char *argv[]) {
//  auto* btn = new Button;
//  auto* lab = new Lable;
//  btn->SetIEvent(lab);
//  btn->PressDown();
//  return 0;
//}

//#include "sigslot.h"
//class Button {
// public:
//  sigslot::signal1<int> PressDown;
//};
//
//class Lable : public sigslot::has_slots<>{
// public:
//  void OnPressDown(int i) { std::cout << "press down" << i; };
//};
//
//int main(int argc, char* argv[]) {
//  auto* btn = new Button;
//  auto* lab = new Lable;
//  btn->PressDown.connect(lab, &Lable::OnPressDown);
//  btn->PressDown.connect([](int i) {
//	  std::cout << "press down" << i;
//	  });
//  btn->PressDown(2);
//  return 0;
//}