//
//  TaggerController.h
//  Tagger
//
// Copyright (C) 2008-2009 Ali Rantakari
// You can contact the author at http://hasseg.org
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>
#import "NSImage+QuickLook.h"
#import "OpenMeta.h"
#import "OpenMetaPrefs.h"
#import "OpenMetaBackup.h"
#import "TaggerDefines.h"


@interface TaggerController : NSObject
{
	// UI elements
	IBOutlet NSWindow *mainWindow;
	IBOutlet NSWindow *aboutWindow;
	IBOutlet NSWindow *preferencesWindow;
	IBOutlet NSWindow *fileListSheet;
	IBOutlet NSTableView *fileListTable;
	IBOutlet NSImageView *iconImageView;
	IBOutlet NSImageView *appIconImageView;
	IBOutlet NSTextField *infoLabel;
	IBOutlet NSTextField *filenameLabel;
	IBOutlet NSTextField *fileCountLabel;
	IBOutlet NSButton *updateButton;
	IBOutlet NSButton *okButton;
	IBOutlet NSTokenField *tagsField;
	IBOutlet NSProgressIndicator *progressIndicator;
	IBOutlet NSTextField *aboutWindowVersionLabel;
	IBOutlet NSWindow *addScriptSheet;
	IBOutlet NSTextField *appIDField;
	IBOutlet NSTextField *scriptFilenameField;
	
	BOOL setTagsAndQuitCalled;
	
	NSMutableArray *filesToTag;
	NSArray *originalTags;
	NSURLConnection *versionCheckConnection;
	NSString *customTitle;
	
	NSString *weblocFilesFolderPath;
	NSString *appDataDirPath;
	NSString *scriptsDirPath;
	
	NSDictionary *scriptsCatalog;
	
	NSString *addedScriptPath;
}

@property(retain) NSMutableArray *filesToTag;
@property(retain) NSArray *originalTags;
@property(retain) NSURLConnection *versionCheckConnection;
@property(copy) NSString *customTitle;
@property(copy) NSString *weblocFilesFolderPath;
@property(copy) NSString *appDataDirPath;
@property(copy) NSString *scriptsDirPath;
@property(copy) NSDictionary *scriptsCatalog;
@property(copy) NSString *addedScriptPath;


- (NSString *) getVersionString;

- (void) addFileToTag:(NSString *)aFilePath;

- (void) ensureScriptsCatalogFileExists;

- (NSString *) getWeblocFilePathForTitle:(NSString *)title URL:(NSString *)url;


- (IBAction) aboutSelected:(id)sender;
- (IBAction) preferencesSelected:(id)sender;
- (IBAction) okSelected:(id)sender;
- (IBAction) updateSelected:(id)sender;
- (IBAction) showFileListSelected:(id)sender;
- (IBAction) closeFileListSelected:(id)sender;
- (IBAction) goToWebsiteSelected:(id)sender;
- (IBAction) readAboutFrontAppScriptsSelected:(id)sender;
- (IBAction) revealScriptsFolderSelected:(id)sender;
- (IBAction) frontAppScriptsPrefToggled:(id)sender;

- (IBAction) addScriptSheetSubmit:(id)sender;
- (IBAction) addScriptSheetCancel:(id)sender;

- (void) setTagsAndQuit;
- (void) setFileIconToView:(NSString *)pathToFile;

- (void) terminateAppSafely;


- (void) checkForUpdates;
- (void) connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
- (void) connection:(NSURLConnection *)connection didReceiveResponse:(NSHTTPURLResponse *)response;
- (void) connectionDidFinishLoading:(NSURLConnection *)connection;



@end
