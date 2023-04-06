//
//  PRsqliteDb.h
//  PRsqlite
//
//  Created by Oleg Stepanenko on 23.12.11.
//  Copyright (c) 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@class PRsqliteDb;

/** PRsqliteStatement class
 * This class implements functionality of sqlite statement
 */
@interface PRsqliteStatement : NSObject {
    PRsqliteDb *db;
    struct sqlite3_stmt *stmt;
    NSString *sql;
    NSArray *params;
}
@property (nonatomic, readonly) struct sqlite3_stmt *stmt;

- (instancetype) initWithDb: (PRsqliteDb *) db;
- (BOOL) prepare: (NSString *) sql;
- (BOOL) bind: (NSArray *) params;
- (BOOL) step;
- (void) reset;
- (void) finalizeStatement;

//Return collection of values of current row values where key is name of column 
- (NSDictionary *) row; 
//Name of column by index
- (NSString *) columnName: (NSInteger) iCol;
//Type of column SQLITE_INTEGER, SQLITE_TEXT...
- (NSInteger) columnType: (NSInteger) iCol;
//Value of column
- (NSString *) columnValue: (NSInteger) iCol;
// Count of columns in result set
- (NSInteger) columnCount;
@end

/** PRsqliteDb class
 * This class implements functionality od sqllite database
 */
@interface PRsqliteDb : NSObject
@property (nonatomic, copy) NSString *path;
@property (nonatomic, readonly) struct sqlite3 *sqlite;

- (instancetype) initWithPath: (NSString *) path;

- (BOOL) open;
- (void) close;
- (BOOL) exec: (NSString *) sql;
- (BOOL) exec: (NSString *) sql withParams: (NSArray *) params;
- (PRsqliteStatement *) query: (NSString *) sql;
- (PRsqliteStatement *) query: (NSString *) sql withParams: (NSArray *) params;

@end
