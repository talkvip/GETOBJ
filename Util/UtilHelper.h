//
//  Util.h
//  TKD Score
//
//  Created by Eagle Du on 12/7/22.
//  Copyright (c) 2012年 GET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBJson.h"

@interface UtilHelper : NSObject
+(NSString *)formateTime:(NSDate *)date;
+(NSString *)formateDate:(NSDate *)date;
+(NSString *)formateDateWithTime:(NSDate *)date;
+(NSString *)formateDate:(NSDate *)date withFormat:(NSString *)format;
+(NSDate *) convertDate:(NSString *)dateString;
+(NSDate *) convertDate:(NSString *)dateString withFormat:(NSString *)format;
+(id)deserializeFromFile:(NSString *)fileName dataKey:(NSString *) dataKey;
+(void)serializeObjectToFile:(NSString *)fileName withObject:(id)obj dataKey:(NSString*) dataKey;
+(NSString *)dataFilePath:(NSString *)fileName;
+(BOOL)isFileExist:(NSString *)fileName;
+ (NSString*) stringWithUUID;
+(void)copyAttributesFromObject:(id)from ToObject:(id)to;
+(NSString *)ArrayToString:(NSArray *)array;
+(NSString *)stringWithInt:(int) v;
+(BOOL) isValidEmail:(NSString*)email;
+(NSString *) toJson:(id)obj;
+(id)fromJson:(NSString *)jsonString;
+(NSString *)deviceName;
@end