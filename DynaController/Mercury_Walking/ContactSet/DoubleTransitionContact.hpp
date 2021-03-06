#ifndef MERCURY_DOUBLE_TRANSITION_CONTACT
#define MERCURY_DOUBLE_TRANSITION_CONTACT

#include <WBDC/WBDC_ContactSpec.hpp>

class RobotSystem;
class Mercury_StateProvider;

class DoubleTransitionContact: public WBDC_ContactSpec{
public:
  DoubleTransitionContact(RobotSystem*);
  virtual ~DoubleTransitionContact();

  void setFzUpperLimit(double lim);

protected:
  virtual bool _UpdateJc();
  virtual bool _UpdateJcDotQdot();
  virtual bool _UpdateUf();
  virtual bool _UpdateInequalityVector();

  void _setU(double mu, dynacore::Matrix & U);

  const RobotSystem* robot_sys_;
  Mercury_StateProvider* sp_;
};


#endif
