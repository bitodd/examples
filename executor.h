/*
  Copyright (c) 2016 by unibosy@gmail.com 
  This file is part of the unibosy library. https://github.com/bitodd

  This software is distributed under a license. The full license
  agreement can be found in the file LICENSE in this distribution.
  This software may not be copied, modified, sold or distributed
  other than expressed in the named license agreement.

  This software is distributed without any warranty.
*/
#ifndef EXECUTOR_h__
#define EXECUTOR_h__

/*
*
* \brief execute these examples
*
*/

class ExecuteExamples
{
public:
	ExecuteExamples();
	~ExecuteExamples();
	void do_examples();
protected:
	//detail example
	void do_filesystem();

private:
};

#endif // EXECUTOR_h__

