#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <complex>

using namespace std;

class Student {

private:
    std::string name;
    std::string surname;
    std::string album_number;
    std::vector<float> grades;
    float final_grade;
public:
    Student (std::string n, std::string s, std::string an){
        name = n;
        surname = s;
        album_number = an;
        final_grade = 0.0f;
    }

    float calculate_grade() {
        if (grades.empty()) {
            final_grade = 0.0f;
            return 0.0f;
        }
        float sum = 0.0f;
        for (float g : grades) {
            sum += g;
        }
        final_grade = sum / grades.size();
        return final_grade;
    }

    bool add_grade(float grade){
        if (grade != 2.0f && grade != 3.0f && grade != 3.5f && grade != 4.0f && grade != 4.5f && grade != 5.0f) {
            return false;
        }
        else {
            grades.push_back(grade);
            calculate_grade();
            return true;
        }

    }
    void print() {
        std::cout << "Name and surname: " << name << " " << surname << " " << "\n";
        std::cout << "Album number: " << album_number << "\n";
        std::cout << "Grades: ";
        for (auto g : grades)
        {
            std::cout << g << ", ";
        }
        std::cout << endl;
        std:: cout << "Final (mean) grade is: " << final_grade << std::endl;
        cout << "Passed semester: " << (is_passed() ? "Yes" : "No") << "\n";
    }
    std::string get_name() {
        return name;
    }
    void set_name(std::string n) {
        name = n;
    }
    std::string get_surname (){
        return surname;
    }
    void set_surname(std::string s) {
        surname = s;
    }
    bool set_album_number(std::string an) {
        if (an.length() <= 6 && an.length() >= 5) {
            album_number = an;
            return true;
        }
        return false;
    }
    std::string get_album_number() {
        return album_number;
    }
    bool is_passed(){
        int twos = 0;
        for (float g : grades) {
            if (g == 2.0f) twos++;
        }
        return (twos <= 1) && !grades.empty();
    }
};

class Complex {

private:
    float real;
    float imaginary;
public:
    Complex(float re = 0.0, float i = 0.0) {
        real = re;
        imaginary = i;
    }
    float get_re() {
        return real;
    }
    void set_re(float re) {
        real = re;
    }
    float get_im() {
        return imaginary;
    }
    void set_im(float i) {
        imaginary = i;
    }
    void print() {
        if (imaginary < 0) {
            std::cout << real << imaginary << "i";
        }
        else if (imaginary > 0) {
            std::cout << real << "+" << imaginary << "i";
        }
        else {
            std::cout << real;
        }
    }

    Complex add(Complex other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    Complex add(float r) {
        return Complex(real + r, imaginary);
    }

};

int main()
{
    std::cout << "Student exercise: e.g. " << std::endl;
    Student student("John", "Pork", "621379");
    student.add_grade(3.5f);
    student.add_grade(4.0f);
    student.add_grade(2.0f);
    student.add_grade(5.0f);
    student.print();


    std::cout << "\n \n Complex exercise: " << std::endl;
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i
}
