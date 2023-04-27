//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P2.h"
#include <vector>
#include <deque>
using namespace std;

static void question_21() {
    vector v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    auto fl1 = get_fibonacci_lists(v1);
    for (const auto& row: fl1) {
        for (const auto& item: row)
            cout << setw(3) << item;
        cout << endl;
    }
}

static void question_22() {
    deque<unsigned int> d1 = {
            1,   2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
            16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35};
    auto fl1 = get_fibonacci_lists(d1);
    for (const auto& row: fl1) {
        for (const auto& item: row)
            cout << setw(3) << item;
        cout << endl;
    }
}

TEST_CASE("Question #2.1") {
    execute_test("test_21.in", question_21);
}

TEST_CASE("Question #2.2") {
    execute_test("test_22.in", question_22);
}