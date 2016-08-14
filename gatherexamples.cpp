/*
  Copyright (c) 2016 by unibosy@gmail.com 
  This file is part of the unibosy library. https://github.com/bitodd

  This software is distributed under a license. The full license
  agreement can be found in the file LICENSE in this distribution.
  This software may not be copied, modified, sold or distributed
  other than expressed in the named license agreement.

  This software is distributed without any warranty.
*/

#include "executor.h"

#include "string"

int main()
{
	ExecuteExamples* example = new ExecuteExamples;
	example->do_examples();
	getchar();
	return 0;
}