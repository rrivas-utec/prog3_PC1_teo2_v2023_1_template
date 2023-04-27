//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P1.h"
using namespace std;

static void question_11() {
    FlexMatrix<int, 3, 3> fm1("1,2,3,4,5,6", ',');
    for (int i = 0; i < fm1.rows(); ++i) {
        for (int j = 0; j < fm1.cols(); ++j)
            cout << setw(3) << fm1(i, j);
        cout << endl;
    }
}

static void question_12() {
    FlexMatrix<int, 3, 3> fm1("1 2 3 4 5 6", ' ');
    cout << fm1;
}

static void question_13() {
    FlexMatrix<double, 3, 3> fm1("1,2,3,4,5,6", ',');
    fm1.resize(3, 2);
    cout << fm1;
}

static void question_14() {
    FlexMatrix<float, 4, 3> fm1("1|2|3|4|5|6|7|8|9|10|11|12", '|');
    auto fm2 = fm1;
    fm1.resize(3, 4);
    auto fm3 = fm2;
    fm3.resize(2, 2);
    cout << "----";
    cout << fm1;
    cout << "----";
    for (int i = 0; i < fm1.rows(); ++i) {
        for (int j = 0; j < fm1.cols(); ++j)
            cout << setw(3) << fm1(i, j);
        cout << endl;
    }
    cout << "----";
    cout << fm3;
    cout << "----";
}

TEST_CASE("Question #1.1") {
    execute_test("test_11.in", question_11);
}
TEST_CASE("Question #1.2") {
    execute_test("test_12.in", question_12);
}
TEST_CASE("Question #1.3") {
    execute_test("test_13.in", question_13);
}
TEST_CASE("Question #1.4") {
    execute_test("test_14.in", question_14);
}
