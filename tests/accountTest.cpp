#include <Account.h>
#include <gtest/gtest.h>

TEST(Account, Balance) {
    Account account(12345, 100);
    EXPECT_EQ(account.GetBalance(), 100);
    account.Lock();
    account.ChangeBalance(100);
    account.Unlock();
    EXPECT_EQ(account.GetBalance(), 200);
}

TEST(Account, Lock) {
    Account account(12345, 150);
    EXPECT_THROW(account.ChangeBalance(50),std::runtime_error);
    account.Lock();
    EXPECT_THROW(account.Lock(), std::runtime_error);
    EXPECT_NO_THROW(account.ChangeBalance(100));
    EXPECT_EQ(account.GetBalance(), 250);
}
