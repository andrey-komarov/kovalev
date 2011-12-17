#include <iostream>
#include <fstream>
#include <memory>
#include "common.h"


using namespace std;

struct TestInput 
{
   virtual int get_int() = 0;
   virtual double get_double() = 0;
   virtual ~TestInput() {};
};

class RandomInput: public TestInput
{
   int seed;

   static const int a = 1664525;
   static const int c = 1013904223;
public:
   RandomInput(int seed) 
      :seed(seed)
   { }

   // return random integer in range 0 .. 2^31-1 
   int get_int() 
   {
      return (seed = seed * a + c) & 0x7fffffff;
   }

   double get_double() 
   {
      const double lo = -1000;
      const double hi = 1000;
      const double scale = 1. / (1 << 30);
      return (lo + (hi - lo) * scale * (get_int() & 0x3fffffff));
   }
};

class StandardInput: public TestInput
{
public:
   int get_int() 
   {
      int res;
      cin >> res;
      return res;
   }

   double get_double() 
   {
      double res;
      cin >> res;
      return res;
   }
};


bool has_intersection(
      double x1, double y1, double x2, double y2,
      double x3, double y3, double x4, double y4)
{
   return false;
}


int main(int argc, char ** argv)
{   
   auto_ptr<TestInput> in(new StandardInput());
   int n = in->get_int();

   int type = in->get_int();

   if (type == 1) {
      int seed = in->get_int();
      in = auto_ptr<TestInput>(new RandomInput(seed));
   }

   int res = 0;
   int p = 1;
   for (int i = 0; i < n; ++i, p *= 239)
   {
      double x1 = in->get_double();
      double y1 = in->get_double();
      double x2 = in->get_double();
      double y2 = in->get_double();
      double x3 = in->get_double();
      double y3 = in->get_double();
      double x4 = in->get_double();
      double y4 = in->get_double();
      if (has_intersection(x1, y1, x2, y2, x3, y3, x4, y4))
      {
         res += p;
      }

   }
   cout << res << "\n";
   return 0;
}
