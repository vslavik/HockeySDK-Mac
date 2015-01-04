/*
 * Copyright (c) 2012-2014 HockeyApp, Bit Stadium GmbH.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>

#import <Quartz/Quartz.h>

/**
 * An individual feedback message attachment
 */
@interface BITFeedbackMessageAttachment : NSObject<NSCoding, QLPreviewItem>

@property (nonatomic, copy) NSNumber *identifier;
@property (nonatomic, copy) NSString *originalFilename;
@property (nonatomic, copy) NSString *contentType;
@property (nonatomic, copy) NSString *sourceURL;
@property (nonatomic) BOOL isLoading;
@property (nonatomic, copy, readonly) NSData *data;


@property (readonly) NSImage *thumbnailRepresentation;
@property (weak, readonly) NSImage *imageRepresentation;


+ (BITFeedbackMessageAttachment *)attachmentWithData:(NSData *)data contentType:(NSString *)contentType;

- (NSImage *)thumbnailWithSize:(NSSize)size;

- (void)replaceData:(NSData *)data;

- (void)deleteContents;

- (BOOL)needsLoadingFromURL;

- (BOOL)isImage;

- (NSURL *)localURL;

/**
 Used to determine whether QuickLook can preview this file or not. If not, we don't download it.
 */ 
- (NSString*)possibleFilename;

@end
