//
//  AMQPExchange.h
//  Objective-C wrapper for librabbitmq-c
//
//  Copyright 2009 Max Wolter. All rights reserved.
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>

#import "AMQPObject.h"

@class AMQPChannel;

@interface AMQPExchange : AMQPObject

@property (readonly) amqp_bytes_t internalExchange;
@property (readonly) AMQPChannel *channel;

- (id)initDefaultExchange:(AMQPChannel *)theChannel;

- (id)initExchangeOfType:(NSString *)theType withName:(NSString *)theName onChannel:(AMQPChannel*)theChannel isPassive:(BOOL)passive isDurable:(BOOL)durable getsAutoDeleted:(BOOL)autoDelete error:(NSError * __autoreleasing *)error;
- (id)initDirectExchangeWithName:(NSString *)theName onChannel:(AMQPChannel*)theChannel isPassive:(BOOL)passive isDurable:(BOOL)durable getsAutoDeleted:(BOOL)autoDelete error:(NSError * __autoreleasing *)error;
- (id)initFanoutExchangeWithName:(NSString *)theName onChannel:(AMQPChannel*)theChannel isPassive:(BOOL)passive isDurable:(BOOL)durable getsAutoDeleted:(BOOL)autoDelete error:(NSError * __autoreleasing *)error;
- (id)initTopicExchangeWithName:(NSString *)theName onChannel:(AMQPChannel*)theChannel isPassive:(BOOL)passive isDurable:(BOOL)durable getsAutoDeleted:(BOOL)autoDelete error:(NSError * __autoreleasing *)error;
- (void)dealloc;

- (void)publishMessage:(NSString *)body usingRoutingKey:(NSString *)theRoutingKey error:(NSError * __autoreleasing *)error;

@end
