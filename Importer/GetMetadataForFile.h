//
//  GetMetadataForFile.h
//  Colloquy (Old)
//
//  Created by C.W. Betts on 4/11/13.
//
//

#ifndef Colloquy__Old__GetMetadataForFile_h
#define Colloquy__Old__GetMetadataForFile_h

__private_extern__ Boolean GetMetadataForFile(void *thisInterface, CFMutableDictionaryRef attributes, CFStringRef contentTypeUTI, CFStringRef pathToFile);
__private_extern__ Boolean GetMetadataForURL(void* thisInterface, CFMutableDictionaryRef attributes, CFStringRef contentTypeUTI, CFURLRef urlForFile);


#endif
