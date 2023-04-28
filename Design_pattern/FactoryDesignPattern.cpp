#include <bits/stdc++.h>
using namespace std;
enum PersonType{
    PT_Student,
    PT_Engineer,
    PT_Doctor
};
class Person{
public:
    virtual void print() = 0;
};
class Student : public Person{
public:
    void print(){
        cout << " Person is a Student"<<endl;;
    }
};
class Engineer : public Person{
public:
    void print(){
        cout << " Person is a Engineer"<<endl;
    }
};
class Doctor : public Person{
public:
    void print(){
        cout << " Person is a Doctor"<<endl;
    }
};
class Factory{
public:
    Factory(){
        cout << "Factory Class"<<endl;
    }
    static Person* create(PersonType type){
        if(type == PT_Student) return new Student();
        else if(type == PT_Engineer) return new Engineer();
        else if(type == PT_Doctor) return new Doctor();
        else return nullptr;
    }
};
int main(){
    // client code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif


    PersonType type = PT_Engineer;
    Person *p = nullptr;
    p = Factory::create(type);
    p->print();
    return 0;
}
