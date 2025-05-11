#include <iostream>
#include <sstream>
using namespace std;

class Student {
  private:
    int student_age;
    int student_standard;
    string student_first_name;
    string student_last_name;
    
    public:
        void set_age(int age){
            student_age = age;
        }
        
        void set_standard(int standard) {
            student_standard = standard;
        }
        
        void set_first_name(string first_name) {
            student_first_name = first_name;
        }
        
        void set_last_name(string last_name) {
            student_last_name = last_name;
        }
        
        int get_age() {
            return student_age;
        }
        
        int get_standard() {
            return student_standard;
        }
        
        string get_first_name() {
            return student_first_name;
        }
        
        string get_last_name() {
            return student_last_name;
        }
        
        string to_string() {
            std::stringstream ss;

            ss << student_age << "," << student_first_name << "," << student_last_name << "," << student_standard;
            return ss.str();
        }
      
};


int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}