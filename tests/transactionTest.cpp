#include <Transaction.h>
#include <gtest/gtest.h>

TEST(Transaction, DataBase) {
	Account from(123, 200);
	Account to(456, 100);
	Transaction transaction;
	transaction.set_fee(50);
	EXPECT_TRUE(transaction.Make(from, to, 100));
	EXPECT_FALSE(transaction.Make(from, to, 1000));
	EXPECT_EQ(from.GetBalance(), 50);
	EXPECT_EQ(to.GetBalance(), 200);
}

TEST(Transaction, Exceptions) {
	Account from(123, 1);
	Account to(456, 100);
	Transaction transaction;
	transaction.set_fee(200);
	EXPECT_THROW(transaction.Make(from, from, 100), std::logic_error);
	EXPECT_THROW(transaction.Make(from, to, -100), std::invalid_argument);
	EXPECT_THROW(transaction.Make(from, to, 1), std::logic_error);
	EXPECT_FALSE(transaction.Make(from, to, 300));
}
