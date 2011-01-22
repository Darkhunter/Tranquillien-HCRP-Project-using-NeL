// NeL - MMORPG Framework <http://dev.ryzom.com/projects/nel/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#import <Cocoa/Cocoa.h>

namespace NL3D 
{
	class CDriverGL;
	void viewDidResize(NSView*, CDriverGL*);
}

@interface CocoaOpenGLView : NSOpenGLView<NSTextInputClient>
{
	NSMutableAttributedString* _characterStorage;
	NSRange _markedRange;
	NL3D::CDriverGL* _driver;
}

-(id)initWithFrame:(NSRect)frame;
-(void)dealloc;
-(void)keyDown:(NSEvent*)event;
-(void)setDriver:(NL3D::CDriverGL*)driver;
-(void)resizeWithOldSuperviewSize:(NSSize)oldBoundsSize;

@end
