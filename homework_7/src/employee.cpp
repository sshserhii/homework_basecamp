#include "employee.h"
AbstractEmployee::AbstractEmployee():first_name_("none"),last_name_("none"),job_("none"){}
AbstractEmployee::AbstractEmployee(const std::string& fn, const std::string& ln, const std::string& j):first_name_(fn),last_name_(ln),job_(j){}
void AbstractEmployee::showAll() const {
  cout<< "first name "<<first_name_<<" last name"<< last_name_<<" job_"<<job_<<endl;
}
void AbstractEmployee::setAll(){
  cout<<"Enter first name"<<endl;
  cin>>first_name_;
  cout<<"Enter last name"<<endl;
  cin>>last_name_;
  cout<<"Enter job"<<endl;
  cin>>job_;
}
ostream& operator<<(ostream& os, const AbstractEmployee& e){
  os<<e.first_name_<<"  "<<e.last_name_<<endl;
  return os;
}

AbstractEmployee::~AbstractEmployee(){}
Employee::Employee():AbstractEmployee(){}
Employee::Employee(const std::string& fn, const std::string& ln, const std::string& j):AbstractEmployee(fn,ln,j){}
void Employee::data() const {
  AbstractEmployee::showAll();
}
void Employee::showAll() const {
  data();
}
void Employee::setAll(){}
void Manager::data() const {
  cout<<"in change of "<<in_charge_of_<<endl;
}
Manager::Manager():AbstractEmployee(),in_charge_of_(0){}
Manager::Manager(const std::string& fn, const std::string& ln,const std::string& j, int ico):AbstractEmployee(fn,ln,j),in_charge_of_(ico){}
Manager::Manager(const AbstractEmployee& e, int ico):AbstractEmployee(e),in_charge_of_(ico){}
void Manager::showAll() const{
  AbstractEmployee::showAll();
  data();
}
void Manager::setAll(){
  AbstractEmployee::setAll();
}
void Manager::get(){
  cout<<"enter inChargeOf"<<endl;
  cin>>in_charge_of_;
}
Fink::Fink():AbstractEmployee(),reports_to_("none"){}
Fink::Fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo):AbstractEmployee(fn,ln,j),reports_to_(rpo){}
Fink::Fink(const AbstractEmployee& e, const std::string& rpo):AbstractEmployee(e),reports_to_(rpo){}
//Fink::Fink(const Fink & e):AbstractEmployee(e),reports_to_(e.reports_to_){}
void Fink::data() const {
  cout<<"reports to "<<reports_to_<<endl;
}
void Fink::showAll() const {
  AbstractEmployee::showAll();
  data();
}
void Fink::get(){
  cout<<"enter reports to "<<endl;
  cin>>reports_to_;

}
void Fink::setAll(){
  AbstractEmployee::setAll();
  cout<<"enter reports to "<<endl;
  cin>>reports_to_;
}
HighFink::HighFink(){}
HighFink::HighFink(const std::string& fn, const std::string& ln,const std::string& j, const std::string& rpo, int ico)
:AbstractEmployee(fn,ln,j),Manager(fn,ln,j,ico),Fink(fn,ln,j,rpo){}
HighFink::HighFink(const Manager& m, const std::string& rpo):AbstractEmployee(m),Manager(m),Fink(m,rpo){}
HighFink::HighFink(const Fink& f, int ico):AbstractEmployee(f),Fink(f),Manager(f,ico){}
HighFink::HighFink(const HighFink& h):AbstractEmployee(h),Fink(h),Manager(h){}
HighFink::HighFink(const AbstractEmployee& e, const std::string& rpo, int ico):AbstractEmployee(e),Manager(e,ico),Fink(e,rpo){}

void HighFink::showAll() const {
  AbstractEmployee::showAll();
  Fink::data();
  Manager::data();
}
void HighFink::setAll(){
  AbstractEmployee::setAll();
  Manager::get();
  Fink::get();
}
