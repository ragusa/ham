#include "HamApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<HamApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

HamApp::HamApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  HamApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  HamApp::associateSyntax(_syntax, _action_factory);
}

HamApp::~HamApp()
{
}

extern "C" void HamApp__registerApps() { HamApp::registerApps(); }
void
HamApp::registerApps()
{
  registerApp(HamApp);
}

void
HamApp::registerObjects(Factory & factory)
{
}

void
HamApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
