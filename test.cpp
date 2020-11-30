//
// Created by Vlad on 29.11.2020.
//

#include <gtest/gtest.h>
#include "../Vector.h"

TEST(VectorConstructors, ByLen){
    Vector a(3);
    ASSERT_EQ(a.get_len(), 3);
}

TEST(VectorConstructors, ByStr){
    Vector a("X,X,X");
    ASSERT_EQ(a.get_len(),3);
}

TEST(VectorOperators, eq){
    Vector a("X,X,X");
    Vector b("X,X,X");
    bool ans = (a == b);
    ASSERT_EQ(true, ans);
}

TEST(VectorOperators, or){
    Vector a("1,X,0");
    Vector b("0,1,X");
    Vector ans("1,1,X");
    ASSERT_EQ( ans, (a|b));
}

TEST(VectorOperators, and){
    Vector a("1,X,0");
    Vector b("0,1,X");
    Vector ans("0,X,0");
    ASSERT_EQ( ans, (a&b));
}

TEST(VectorOperators, assignment){
    Vector a("1,X,0");
    Vector b = a;
    ASSERT_EQ( a, b);
}

TEST(VectorOperators, negation){
    Vector a("1,X,0");
    Vector b("0,X,1");
    ASSERT_EQ( ~a, b);
}
