#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR6.2B/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT62B
{
	TEST_CLASS(UT62B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;

            int first_ = 1;
            int end_ = 3;
            Info a = 2;

            while (first_ <= end_)
            {
                Elem* tmp = new Elem;
                tmp->info = a;
                tmp->link = NULL;
                if (last != NULL)
                    last->link = tmp;
                last = tmp;
                if (first == NULL)
                    first = tmp;
                first_++;
            }
            
            Assert::IsTrue(Scan(first));
		}
	};
}