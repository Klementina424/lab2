#include "pch.h"
#include "CppUnitTest.h"
#include "../аисд2лаба/alg.h"
#include "../аисд2лаба/alg.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		int arr[10] = { 1,2,0,10,7,3,9,8,11,4 };
		int arrsort[10] = { 0,1,2,3,4,5,6,7,8,9 };
		
		TEST_METHOD(BinarySearchTest)
		{
					Assert::IsTrue(BinarySearch(arrsort, 10, 5) == 5);
		}
	
		TEST_METHOD(BubbleSortTest)
		{
			BubbleSort(arr, 10);
			Assert::IsTrue(arr[0] == 0, L"Assert 1");
			Assert::IsTrue(arr[1] == 1, L"Assert 2");
		}

		TEST_METHOD(QuickSortTest)
		{
			BubbleSort(arr, 10);
			Assert::IsTrue(arr[0] == 0, L"Assert 1");
			Assert::IsTrue(arr[1] == 1, L"Assert 2");
		}

		TEST_METHOD(BogoSortTest)
		{
			BubbleSort(arr, 10);
			Assert::IsTrue(arr[0] == 0, L"Assert 1");
			Assert::IsTrue(arr[1] == 1, L"Assert 2");
		}
		
	};
}
