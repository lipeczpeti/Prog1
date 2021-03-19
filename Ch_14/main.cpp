#include "std_lib_facilities.h"

struct A{
	virtual void pvf() = 0;
};

struct B1 : A{
	virtual void vf() {cout << "B1::vf()\n";}
	void f() {cout << "B1::f()\n";}
	void pvf() {cout << "B1::pfv()\n";}
};

struct D1 : B1{
	void vf() override {cout << "D1::vf()\n";}
	void f() {cout << "D1::f()\n";}
};

struct D2 : D1{
	void pvf() override {cout << "D2::pvf()\n";}
};

struct B2{
	virtual void pvf() = 0;
};

struct D21 : B2{
	string s = "szöveg";
	void pvf() override {cout << s << endl;}
};


struct D22 : B2{
	int i = 24;
	void pvf() override {cout << i << endl;}
};

void f(B2& b1){
	b1.pvf();
};

int main(){

    cout<<"B1"<<endl;

    B1 b;
    b.vf();
    b.f();
    b.pvf();

    cout<<"B2"<<endl;

    D1 d;
    d.vf();
    d.f();
    d.pvf();

    cout<<"B1&"<<endl;

    B1& b_ref=d;
    b_ref.vf();
    b_ref.f();
    b_ref.pvf();

    cout<<"D2"<<endl;

    D2 dd;
    dd.vf();
    dd.f();
    dd.pvf();

    cout<<"D21"<<endl;

    D21 d21;
    f(d21);

    cout<<"D22"<<endl;

    D22 d22;
    f(d22);


    return 0;
}