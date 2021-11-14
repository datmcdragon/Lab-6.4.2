#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-6.4.2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int A[] = {0,3, 9, 10};
			int t = ModSum(A, 4, 0);
			Assert::AreEqual(0, t);
		}
	};
}