/**
 *  Copyright 2014-2015 MongoDB, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
#ifndef __MONGODB_DRIVER_WRITECONCERN_H__
#define __MONGODB_DRIVER_WRITECONCERN_H__

namespace HPHP {

extern const StaticString s_MongoDriverWriteConcern_className;
extern const StaticString s_MongoDriverWriteConcern_debugInfo;
extern const StaticString s_MongoDriverWriteConcern_majority;

class MongoDBDriverWriteConcernData
{
	public:
		static Class* s_class;
		static const StaticString s_className;

		/* properties go here */
		mongoc_write_concern_t *m_write_concern;

		static Class* getClass();

		void sweep() {
			mongoc_write_concern_destroy(m_write_concern);
		}

		~MongoDBDriverWriteConcernData() {
			sweep();
		};
};

bool mongodb_driver_add_write_concern_debug(const mongoc_write_concern_t *wc, Array *retval);

void HHVM_METHOD(MongoDBDriverWriteConcern, __construct, const Variant &w, const Variant &w_timeout, const Variant &journal);
Array HHVM_METHOD(MongoDBDriverWriteConcern, __debugInfo);
Variant HHVM_METHOD(MongoDBDriverWriteConcern, bsonSerialize);
Variant HHVM_METHOD(MongoDBDriverWriteConcern, getJournal);
Variant HHVM_METHOD(MongoDBDriverWriteConcern, getW);
int64_t HHVM_METHOD(MongoDBDriverWriteConcern, getWtimeout);

}
#endif
