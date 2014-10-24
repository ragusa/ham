#ifndef HAMAPP_H
#define HAMAPP_H

#include "MooseApp.h"

class HamApp;

template<>
InputParameters validParams<HamApp>();

class HamApp : public MooseApp
{
public:
  HamApp(const std::string & name, InputParameters parameters);
  virtual ~HamApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HAMAPP_H */
