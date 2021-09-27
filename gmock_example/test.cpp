#include <iostream>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect {
 public:
  virtual bool login(std::string username, std::string password) {return true;}
  virtual bool logout(std::string username) {return true;}
  virtual int fetchRecord() {return -1;}
};

class MockDB : public DataBaseConnect {
 public:
  MOCK_METHOD0(fetchRecord, int());
  MOCK_METHOD1(logout, bool (std::string username));
  MOCK_METHOD2(login, bool (std::string username, std::string password));
};

class MyDatabase {
  DataBaseConnect &dbC;
 public:
  MyDatabase(DataBaseConnect & _dbC) : dbC(_dbC) {}

  int Init(std::string username, std::string password) {
    if(dbC.login(username, password) != true) {
      std::cout << "DB FAILURE" << std::endl;
      return -1;
    } else {
      std::cout << "DB SUCESS" << std::endl;
      return 1;
    }
  }
};

TEST(MyDBTest, LoginTest) {
  // Arrange
  MockDB mdb;
  MyDatabase db(mdb);

  EXPECT_CALL(mdb, login("Terminator", "I'm Back"))
  .Times(1)
  .WillOnce(Return(true));

  // Act
  int retValue = db.Init("Terminator", "I'm Back");
  // Assert
  EXPECT_EQ(retValue, 1);
}
