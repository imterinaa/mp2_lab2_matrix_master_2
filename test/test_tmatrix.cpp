#include "utmatrix.h"

#include "gtest.h"

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> a(5);
    a[0][0] = 1;
    TMatrix<int> b(a);
    EXPECT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> a(5);
    TMatrix<int> b(a);
    b[0][0] = 2;
    a[0][0] = 4;
    EXPECT_NE(b[0][0], a[0][0]);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> a(5);
    EXPECT_EQ(5, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> a(5);
    a[0][1] = 22;
    EXPECT_EQ(22, a[0][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> a(5);
    ASSERT_ANY_THROW(a[-1][0]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> a(10);
    ASSERT_ANY_THROW(a[11][11]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> a(3);
    for (int i = 0; i < 3; i++)
        a[i][i] = 14;
    a = a;
    EXPECT_EQ(14, a[0][0]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> a(3);
    TMatrix<int> b(3);
    for (int i = 0; i < 3; i++)
        a[i][i] = 14;
    b = a;
    EXPECT_EQ(14, b[2][2]);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> a(3);
    TMatrix<int> b(6);
    for (int i = 0; i < 3; i++)
        a[i][i] = 14;
    b = a;
    EXPECT_EQ(3, b.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> a(3);
    TMatrix<int> b(3);
    for (int i = 0; i < 3; i++)
        a[i][i] = 14;
    b = a;
    EXPECT_EQ(14, b[0][0]);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    EXPECT_EQ(a, b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> a(5);
    EXPECT_EQ(a, a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> a(5);
    TMatrix<int> b(8);
    EXPECT_NE(a, b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> V1(5), V2(5), V3(5);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++) {
            V1[i][j] = 1;
            V2[i][j] = 2;
            V3[i][j] = 3;
        }

    V1 = V1 + V2;
    EXPECT_EQ(V1 , V3);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> V1(5), V2(7), V3(7);
    ASSERT_ANY_THROW(V3 = V2 + V1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> V1(5), V2(5), V3(5);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++) {
            V1[i][j] = 1;
            V2[i][j] = 2;
            V3[i][j] = 3;
        }

    V3 = V3- V2;
    EXPECT_EQ(V1, V3);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> a(5), b(7), c(7);
    ASSERT_ANY_THROW(c = b - a);
}

