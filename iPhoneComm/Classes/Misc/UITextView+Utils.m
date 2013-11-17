//
//  UIScrollView+Utils.m
//  SimpleTelnet
//
//  Copyright (c) 2009 Peter Bakhyryev <peter@byteclub.com>, ByteClub LLC
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//  
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#import "UITextView+Utils.h"


@implementation UITextView (Utils)

- (void)scrollToBottom
{
	CGRect lastLine;
	lastLine.origin.x = 0;
	lastLine.origin.y = self.contentSize.height-1;
	lastLine.size.height = 1;
	lastLine.size.width = 1;
	
	[self scrollRectToVisible:lastLine animated:NO];
}

- (void)appendTextAfterLinebreak:(NSString *)text
{
	self.text = [[self.text stringByAppendingString:@"\n"] stringByAppendingString:text];
}

- (void)prependTextAfterLinebreak:(NSString *)text
{
	self.text = [[text stringByAppendingString:@"\n"] stringByAppendingString:self.text];
}

@end
