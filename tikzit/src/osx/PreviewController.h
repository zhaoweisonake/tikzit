//
//  PreviewController.h
//  TikZiT
//  
//  Copyright 2010 Aleks Kissinger. All rights reserved.
//  
//  
//  This file is part of TikZiT.
//  
//  TikZiT is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  TikZiT is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with TikZiT.  If not, see <http://www.gnu.org/licenses/>.
//  


#import <Cocoa/Cocoa.h>

@class PDFView;
@class PreambleController;

@interface PreviewController : NSWindowController {
	IBOutlet PDFView *pdfView;
	IBOutlet NSProgressIndicator *progressIndicator;
	IBOutlet NSScrollView *errorTextView;
	IBOutlet NSTextView *errorText;
	PreambleController *preambleController;
	NSString *tempDir;
	NSLock *latexLock;
	int typesetCount;
}


- (id)initWithWindowNibName:(NSString*)nib
		 preambleController:(PreambleController*)pc
					tempDir:(NSString*)dir;

- (void)buildTikz:(NSString*)tikz;

+ (void)setDefaultPreviewController:(PreviewController*)pc;
+ (PreviewController*)defaultPreviewController;

@end