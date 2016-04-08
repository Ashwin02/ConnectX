/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};


TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


// Checks at() if the location is out of bound.
TEST(ConnectXTest, check_at_outOfBound)
{
  ConnectX connect;
  ASSERT_EQ(-1 , (connect.at(-20,30)));
}

// Checks at() for black player.
TEST(ConnectXTest, check_at_blackPlayer)
{
  ConnectX connect;
	connect.placePiece(3);
  ASSERT_EQ(2 , (connect.at(3,5)));
}

// Checks at() for white player.
TEST(ConnectXTest, check_at_whitePlayer)
{
  ConnectX connect;
	connect.placePiece(2);
	connect.placePiece(4);
  ASSERT_EQ(1 , (connect.at(4,5)));
}

// Checks at() if the board is empty
TEST(ConnectXTest, check_at_empty)
{
  ConnectX connect;
  ASSERT_EQ(0 , (connect.at(3,4)));
}

// Checks whose turn it is.
TEST(ConnectXTest, check_whoseTurn)
{
  ConnectX connect;
	ASSERT_EQ((connect.whoseTurn()) , 2);
	connect.placePiece(3);
	ASSERT_EQ((connect.whoseTurn()),1);

}

// Checks if piece is placed at correct place.
TEST(ConnectXTest, check_placePiece)
{
  ConnectX connect;
	connect.placePiece(2);
	ASSERT_EQ(2 , connect.at(2,5));

}


// checks whether second player placed is placed at right place.
TEST(ConnectXTest, check_placePiece2)
{
  ConnectX connect;
	connect.placePiece(2);
	ASSERT_EQ(2 , connect.at(2,5));
	connect.placePiece(2);
	ASSERT_EQ(1 , connect.at(2,4));

}
// Checks if piece is placed out of bounds and wheteher the user is toggeled.
// Also checks toggelturn()
TEST(ConnectXTest, check_placePiece_outofbound)
{
  ConnectX connect;
	ASSERT_EQ((connect.whoseTurn()) , 2);
	connect.placePiece(10);
	ASSERT_EQ((connect.whoseTurn()) , 1);

}

// Checking constructor for negative value.
// It should use default set of values and print the map.
TEST(ConnectXTest, check_constructor)
{
	ConnectX connect((-2),(-3),3);
	connect.showBoard();
}

// Checking inbound function for a negative width value and valid height value.
TEST(ConnectXTest, check_at_ForNegativeW)
{
	ConnectX connect;
	ASSERT_EQ((connect.at(-4,3)),-1);
}

TEST(ConnectXTest, check_placePiece_ForNegativeW)
{
	ConnectX connect;
	connect.placePiece(-4);
	ASSERT_EQ((connect.whoseTurn()) , 1);
}
